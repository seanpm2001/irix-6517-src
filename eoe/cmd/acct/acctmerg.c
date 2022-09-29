/*	Copyright (c) 1993 UNIX System Laboratories, Inc. 	*/
/*	  All Rights Reserved                             	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF     	*/
/*	UNIX System Laboratories, Inc.   	            	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*		copyright	"%c%" 	*/

#ident	"@(#)acct:common/cmd/acct/acctmerg.c	1.10.3.4"
#ident "$Header: /proj/irix6.5.7m/isms/eoe/cmd/acct/RCS/acctmerg.c,v 1.6 1996/06/14 19:52:11 rdb Exp $"

/*
 *	acctmerg [-a] [-i] [-p] [-t] [-u] [-v] [file...]
 *	-a	output in tacct.h/ascii (instead of tacct.h)
 *	-i	input is in tacct.h/ascii (instead of tacct.h)
 *	-p	print input files with no processing
 *	-t	output single record that totals all input
 *	-u	summarize by uid, rather than uid/name
 *	-v	output in verbose tacct.h/ascii
 *	reads std input and 0-maxfiles files, all in tacct.h format,
 *	sorted by uid/name.
 *	merge/adds all records with same uid/name (or same uid if -u,
 *	or all records if -t], writes to std. output
 *	(still in tacct.h format)
 *	note that this can be used to summarize the std input
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/param.h>
#include "acctdef.h"

int	nfile;			/* index of last used in fl */
FILE	**fl;

struct	tacct *tb;		/* current record from each file */
struct	tacct	tt = {
	0,
	"TOTAL"
};

int	asciiout;
int	asciiinp;
int	printonly;
int	totalonly;
int	uidsum;
int	verbose;
int 	exitcode = 0;

struct tacct *getleast(void);
int  getnext(int);
void output(struct tacct *);
void prtacct(struct tacct *);
void sumcurr(struct tacct *);
void tacctadd(struct tacct *, struct tacct *);

main(argc, argv)
int argc;
char **argv;
{
	register i, maxfiles;
	register struct tacct *tp;

#ifdef sgi
	maxfiles = getdtablesize();
	fl = malloc(maxfiles * sizeof(FILE *));
	fl[0] = stdin;
	tb = malloc(maxfiles * sizeof(struct tacct));
#endif
	while (--argc > 0) {
		if (**++argv == '-')
			switch (*++*argv) {
			case 'a':
				asciiout++;
				continue;
			case 'i':
				asciiinp++;
				continue;
			case 'p':
				printonly++;
				continue;
			case 't':
				totalonly++;
				continue;
			case 'u':
				uidsum++;
				continue;
			case 'v':
				verbose++;
				asciiout++;
				continue;
			}
		else {
			if (++nfile >= maxfiles) {
				fprintf(stderr, "acctmerg: >%d files\n", maxfiles);
				exit(1);
			}
			if ((fl[nfile] = fopen(*argv, "r")) == NULL) {
				fprintf(stderr, "acctmerg: can't open %s\n", *argv);
				exitcode = 1;
				/*	exit(1); 	*/
			}
		}
	}

	if (printonly) {
		for (i = 0; i <= nfile; i++)
			while (getnext(i))
				prtacct(&tb[i]);
		exit(exitcode);
	}

	for (i = 0; i <= nfile; i++)
		if(getnext(i) == 0) {
			fprintf(stderr,"acctmerg: read error file %d.  File may be empty.\n", i);
			exitcode = 2;

		}

	while ((tp = getleast()) != NULL)	/* get least uid of all files, */
		sumcurr(tp);			/* sum all entries for that uid, */
	if (totalonly)				/* and write the 'summed' record */
		output(&tt);

	exit(exitcode);
}

/*
 *	getleast returns ptr to least (lowest uid)  element of current 
 *	avail, NULL if none left; always returns 1st of equals
 */
struct tacct *
getleast(void)
{
	register struct tacct *tp, *least;

	least = NULL;
	for (tp = tb; tp <= &tb[nfile]; tp++) {
		if (tp->ta_name[0] == '\0')
			continue;
		if (least == NULL ||
			tp->ta_uid < least->ta_uid ||
			((tp->ta_uid == least->ta_uid) &&
			!uidsum &&
			(strncmp(tp->ta_name, least->ta_name, NSZ) < 0)))
			least = tp;
	}
	return(least);
}

/*
 *	sumcurr sums all entries with same uid/name (into tp->tacct record)
 *	writes it out, gets new entry
 */
void
sumcurr(struct tacct *tp)
{
	struct tacct tc;

	memcpy(&tc, tp, sizeof(struct tacct));
	tacctadd(&tt, tp);	/* gets total of all uids */
	getnext(tp-&tb[0]);	/* get next one in same file */
	while (tp <= &tb[nfile])
		if (tp->ta_name[0] != '\0' &&
			tp->ta_uid == tc.ta_uid &&
			(uidsum || EQN(tp->ta_name, tc.ta_name))) {
			tacctadd(&tc, tp);
			tacctadd(&tt, tp);
			getnext(tp-&tb[0]);
		} else
			tp++;	/* look at next file */
	if (!totalonly)
		output(&tc);
}

void
tacctadd(struct tacct *t1, struct tacct *t2)
{
	t1->ta_cpu[0] = t1->ta_cpu[0] + t2->ta_cpu[0];
	t1->ta_cpu[1] = t1->ta_cpu[1] + t2->ta_cpu[1];
	t1->ta_kcore[0] = t1->ta_kcore[0] + t2->ta_kcore[0];
	t1->ta_kcore[1] = t1->ta_kcore[1] + t2->ta_kcore[1];
	t1->ta_con[0] = t1->ta_con[0] + t2->ta_con[0];
	t1->ta_con[1] = t1->ta_con[1] + t2->ta_con[1];
	t1->ta_du = t1->ta_du + t2->ta_du;
	t1->ta_pc += t2->ta_pc;
	t1->ta_sc += t2->ta_sc;
	t1->ta_dc += t2->ta_dc;
	t1->ta_fee += t2->ta_fee;
}

void
output(struct tacct *tp)
{
	if (asciiout)
		prtacct(tp);
	else
		fwrite(tp, sizeof(*tp), 1, stdout);
}
/*
 *	getnext reads next record from stream i, returns 1 if one existed
 */
int
getnext(int i)
{
	register struct tacct *tp;

	tp = &tb[i];
	tp->ta_name[0] = '\0';
	if (fl[i] == NULL)
		return(0);
	if (asciiinp) {
		if (fscanf(fl[i],
			"%ld\t%s\t%e %e %e %e %e %e %e %lu\t%hu\t%hu\t%hu",
			&tp->ta_uid,
			tp->ta_name,
			&tp->ta_cpu[0], &tp->ta_cpu[1],
			&tp->ta_kcore[0], &tp->ta_kcore[1],
			&tp->ta_con[0], &tp->ta_con[1],
			&tp->ta_du,
			&tp->ta_pc,
			&tp->ta_sc,
			&tp->ta_dc,
			&tp->ta_fee) != EOF)
			return(1);
	} else {
		if (fread(tp, sizeof(*tp), 1, fl[i]) == 1)
			return(1);
	}
	fclose(fl[i]);
	fl[i] = NULL;
	return(0);
}

char fmt[] = "%-7ld %-8.8s %5.0f %7.0f %6.0f %8.0f %6.0f %8.0f %7.0f %6lu %6hu %9hu %4hu\n";
char fmtv[] = "%-7ld %-8.8s %e %e %e %e %e %e %e %lu %hu\t%hu\t%hu\n";

void
prtacct(struct tacct *tp)
{
	printf(verbose ? fmtv : fmt,
		tp->ta_uid,
		tp->ta_name,
		tp->ta_cpu[0], tp->ta_cpu[1],
		tp->ta_kcore[0], tp->ta_kcore[1],
		tp->ta_con[0], tp->ta_con[1],
		tp->ta_du,
		tp->ta_pc,
		tp->ta_sc,
		tp->ta_dc,
		tp->ta_fee);
}