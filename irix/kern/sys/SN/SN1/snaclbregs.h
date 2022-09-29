/**************************************************************************
 *                                                                        *
 *            Copyright (C) 1996-1998, Silicon Graphics, Inc.             *
 *                                                                        *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *                                                                        *
 **************************************************************************/



/**************************************************************************
 *                                                                        *
 * WARNING!!!  WARNING!!!  WARNING!!!  WARNING!!!  WARNING!!!  WARNING!!! *
 *                                                                        *
 * This file is created by an automated script. Any changes made          *
 * manually to this  file will be lost.					  *
 *                                                                        *
 *               DO NOT EDIT THIS FILE MANUALLY			          *
 *                                                                        *
 **************************************************************************/



#ifndef __SYS_SN_SN1_SNACLBREGS_H__
#define __SYS_SN_SN1_SNACLBREGS_H__



#define    LB_REV_ID                 0x00000    /*
                                                  * Hub network status,
                                                  * revision. ID
                                                  */
#define    LB_CPU_PROTECT            0x00100    /* CPU PIO protection bits */
#define    LB_CPU_PROT_OVRRD         0x00108    /*
                                                  * CPU PIO protection bit
                                                  * override
                                                  */
#define    LB_IO_PROTECT             0x00110    /* IO PIOprotection bits   */
#define    LB_RESET                  0x00118    /* Reset the SNC           */
#define    LB_REGION_PRESENT         0x00120    /*
                                                  * Region Present for
                                                  * Invalidates
                                                  */
#define    LB_NODES_ABSENT           0x00128    /*
                                                  * Nodes Absent for
                                                  * Invalidates
                                                  */
#define    LB_INTERRUPT              0x00130    /*
                                                  * Interrupt Control
                                                  * Register
                                                  */
#define    LB_SCRATCH_REG0           0x00200    /* Scratch Register 0      */
#define    LB_SCRATCH_REG1           0x00208    /* Scratch Register 1      */
#define    LB_SCRATCH_REG2           0x00210    /* Scratch Register 2      */
#define    LB_SCRATCH_REG3           0x00218    /* Scratch Register 3      */
#define    LB_SCRATCH_REG4           0x00220    /* Scratch Register 4      */
#define    LB_SCRATCH_REG01          0x00300    /* Scratch Register 0      */
#define    LB_SCRATCH_REG11          0x00308    /* Scratch Register 1      */
#define    LB_SCRATCH_REG21          0x00310    /* Scratch Register 2      */
#define    LB_SCRATCH_REG31          0x00318    /* Scratch Register 3      */
#define    LB_SCRATCH_REG41          0x00320    /* Scratch Register 4      */
#define    LB_VECTOR_PARMS           0x00400    /* Vector PIO parameters   */
#define    LB_VECTOR_ROUTE           0x00408    /* Vector PIO Vector Route */
#define    LB_VECTOR_DATA            0x00410    /* Vector PIO Write Data   */
#define    LB_VECTOR_STATUS          0x00420    /*
                                                  * Vector PIO Return
                                                  * Status
                                                  */
#define    LB_VECTOR_RETURN          0x00428    /* Vector PIO Return Route */
#define    LB_VECTOR_READ_DATA       0x00430    /* Vector PIO Read Data    */
#define    LB_STATUS_CLEAR           0x00438    /*
                                                  * Clear Vector PIO Return
                                                  * Status
                                                  */


#ifdef _LANGUAGE_C

typedef union lb_rev_id_u {
	__uint64_t	lb_rev_id_regval;
	struct  {
		__uint64_t	lri_reserved              :	16;
		__uint64_t	lri_region_size           :	 2;
		__uint64_t	lri_reserved_1            :	 3;
		__uint64_t	lri_node_id               :	11;
		__uint64_t	lri_revision              :	 4;
		__uint64_t	lri_part_number           :	16;
		__uint64_t	lri_manufacturer          :	11;
		__uint64_t	lri_unused                :	 1;
	} lb_rev_id_fld_s;
} lb_rev_id_u_t;


typedef union lb_cpu_protect_u {
	__uint64_t	lb_cpu_protect_regval;
	struct  {
		__uint64_t	lcp_cpu_protect           :	64;
	} lb_cpu_protect_fld_s;
} lb_cpu_protect_u_t;


typedef union lb_cpu_prot_ovrrd_u {
	__uint64_t	lb_cpu_prot_ovrrd_regval;
	struct  {
		__uint64_t	lcpo_io_prot_ovr          :	64;
	} lb_cpu_prot_ovrrd_fld_s;
} lb_cpu_prot_ovrrd_u_t;


typedef union lb_io_protect_u {
	__uint64_t	lb_io_protect_regval;
	struct  {
		__uint64_t	lip_io_protect            :	64;
	} lb_io_protect_fld_s;
} lb_io_protect_u_t;


typedef union lb_reset_u {
	__uint64_t	lb_reset_regval;
	struct  {
		__uint64_t	lr_reserved               :	63;
		__uint64_t	lr_localreset             :	 1;
	} lb_reset_fld_s;
} lb_reset_u_t;


typedef union lb_region_present_u {
	__uint64_t	lb_region_present_regval;
	struct  {
		__uint64_t	lrp_present_bits          :	64;
	} lb_region_present_fld_s;
} lb_region_present_u_t;


typedef union lb_nodes_absent_u {
	__uint64_t	lb_nodes_absent_regval;
	struct  {
		__uint64_t	lna_node_3_valid          :	 1;
		__uint64_t	lna_reserved              :	 4;
		__uint64_t	lna_node_3                :	11;
		__uint64_t	lna_node_2_valid          :	 1;
		__uint64_t	lna_reserved_3            :	 4;
		__uint64_t	lna_node_2                :	11;
		__uint64_t	lna_node_1_valid          :	 1;
		__uint64_t	lna_reserved_6            :	 4;
		__uint64_t	lna_node_1                :	11;
		__uint64_t	lna_node_0_valid          :	 1;
		__uint64_t	lna_reserved_9            :	 4;
		__uint64_t	lna_node_0                :	11;
	} lb_nodes_absent_fld_s;
} lb_nodes_absent_u_t;


typedef union lb_interrupt_u {
	__uint64_t	lb_interrupt_regval;
	struct  {
		__uint64_t	li_reserved               :	16;
		__uint64_t	li_in_progress            :	16;
		__uint64_t	li_reserved_1             :	 7;
		__uint64_t	li_enable                 :	 1;
		__uint64_t	li_reserved_3             :	 5;
		__uint64_t	li_node_id                :	11;
		__uint64_t	li_reservedcurrentvalueis :	 1;
		__uint64_t	li_level                  :	 7;
	} lb_interrupt_fld_s;
} lb_interrupt_u_t;


typedef union lb_vector_parms_u {
	__uint64_t	lb_vector_parms_regval;
	struct  {
		__uint64_t	lvp_busy                  :	 1;
		__uint64_t	lvp_reserved              :	10;
		__uint64_t	lvp_pio_id                :	13;
		__uint64_t	lvp_write_id              :	 8;
		__uint64_t	lvp_address               :	29;
		__uint64_t	lvp_reserved_4            :	 1;
		__uint64_t	lvp_type                  :	 2;
	} lb_vector_parms_fld_s;
} lb_vector_parms_u_t;


typedef union lb_vector_route_u {
	__uint64_t	lb_vector_route_regval;
	struct  {
		__uint64_t	lvr_vector                :	64;
	} lb_vector_route_fld_s;
} lb_vector_route_u_t;


typedef union lb_vector_data_u {
	__uint64_t	lb_vector_data_regval;
	struct  {
		__uint64_t	lvd_write_data            :	64;
	} lb_vector_data_fld_s;
} lb_vector_data_u_t;


typedef union lb_vector_status_u {
	__uint64_t	lb_vector_status_regval;
	struct  {
		__uint64_t	lvs_status_valid          :	 1;
		__uint64_t	lvs_overrun               :	 1;
		__uint64_t	lvs_source                :	11;
		__uint64_t	lvs_pio_id                :	11;
		__uint64_t	lvs_write_id              :	 8;
		__uint64_t	lvs_address               :	29;
		__uint64_t	lvs_type                  :	 3;
	} lb_vector_status_fld_s;
} lb_vector_status_u_t;


typedef union lb_return_route_u {
	__uint64_t	lb_return_route_regval;
	struct  {
		__uint64_t	lrr_return_vector         :	64;
	} lb_return_route_fld_s;
} lb_return_route_u_t;


typedef union lb_vector_read_data_u {
	__uint64_t	lb_vector_read_data_regval;
	struct  {
		__uint64_t	lvrd_read_data            :	64;
	} lb_vector_read_data_fld_s;
} lb_vector_read_data_u_t;


typedef union lb_vector_clear_u {
	__uint64_t	lb_vector_clear_regval;
	struct  {
		__uint64_t	lvrd_rsvd_0               :	64;
	} lb_vector_clear_fld_s;
} lb_vector_clear_u_t;




#endif /* _LANGUAGE_C */




#endif  /* __SYS_SN_SN1_SNACLBREGS_H__ */