/* ------------------------------------------------------------------ */
/* | Copyright Unpublished, MIPS Computer Systems, Inc.  All Rights | */
/* | Reserved.  This software contains proprietary and confidential | */
/* | information of MIPS and its suppliers.  Use, disclosure or     | */
/* | reproduction is prohibited without the prior express written   | */
/* | consent of MIPS.                                               | */
/* ------------------------------------------------------------------ */

#include <sys/regdef.h>
#include <sys/asm.h>
#include <sys.s>
#include "sys/syscall.h"


#if (_MIPS_SIM == _MIPS_SIM_ABI32)
LOCALSZ=	2		# save ra, gp
#else	/* _MIPS_SIM_ABI64 or _MIPS_SIM_NABI32 */
LOCALSZ=	10		# save ra, gp, home 8 args
#endif
FRAMESZ=	(((NARGSAVE+LOCALSZ)*SZREG)+ALSZ)&ALMASK

#if (_MIPS_SIM == _MIPS_SIM_ABI32)
RAOFF=		FRAMESZ-(1*SZREG)
GPOFF=		FRAMESZ-(2*SZREG)
A0HOME=		FRAMESZ+(0*SZREG)
A1HOME=		FRAMESZ+(1*SZREG)
A2HOME=		FRAMESZ+(2*SZREG)
A3HOME=		FRAMESZ+(3*SZREG)
#else	/* _MIPS_SIM_ABI64 or _MIPS_SIM_NABI32 */
A7HOME=		FRAMESZ-(1*SZREG)
A6HOME=		FRAMESZ-(2*SZREG)
A5HOME=		FRAMESZ-(3*SZREG)
A4HOME=		FRAMESZ-(4*SZREG)
A3HOME=		FRAMESZ-(5*SZREG)
A2HOME=		FRAMESZ-(6*SZREG)
A1HOME=		FRAMESZ-(7*SZREG)
A0HOME=		FRAMESZ-(8*SZREG)
RAOFF=		FRAMESZ-(9*SZREG)
GPOFF=		FRAMESZ-(10*SZREG)
#endif
	.weakext	pcreatel, _pcreatel

NESTED(_pcreatel, FRAMESZ, ra)
        .mask   M_RA, RAOFF-FRAMESZ
	SETUP_GP
	PTR_SUBU sp,FRAMESZ
	SETUP_GP64(GPOFF,_pcreatel)
	SAVE_GP(GPOFF)

	REG_S	ra,RAOFF(sp)
	/* pcreatel is basically a varargs so need to home all args */
	REG_S	a1,A1HOME(sp)
	REG_S	a2,A2HOME(sp)
	REG_S	a3,A3HOME(sp)
#if (_MIPS_SIM != _MIPS_SIM_ABI32)
	REG_S	a4,A4HOME(sp)
	REG_S	a5,A5HOME(sp)
	REG_S	a6,A6HOME(sp)
	REG_S	a7,A7HOME(sp)
#endif
	PTR_ADDIU a1,sp,A1HOME
#if _MIPS_SIM == _MIPS_SIM_NABI32
	/* We will call pcreatel - so we need to roll up the doubleword
	 * aligned pointers to be only word aligned, since this is what
	 * pcreatel (and the kernel) expects. Since these are pointers,
	 * and pointers are 32bits, there is no data loss.
	 * The idea is to compact the doubleword args to be a vector
	 * of char *, in place.
	 */
	move	a2,a1		# a2 points to our source area. (A1HOME)
	move	t0,a1		# t0 points to our target area. (A1HOME)
	addu	a2,4		# a2 points to A1HOME + 4
1:	PTR_L	v0,0(a2)
	PTR_ADDU a2,SZREG	# Step to next doubleword aligned arg.
	PTR_S	v0,0(t0)	# store arg as singleword
	addu	t0,4		# step to next singleword alignment.
	bne	v0,zero,1b
#endif	/* _MIPS_SIM_NABI32 */
	jal	_pcreatev		# _pcreatel(file, argv)
	REG_L	ra,RAOFF(sp)
	RESTORE_GP64
	PTR_ADDU sp,FRAMESZ
	j	ra
	END(_pcreatel)		# _pcreatel(file, arg1, arg2, ..., 0);