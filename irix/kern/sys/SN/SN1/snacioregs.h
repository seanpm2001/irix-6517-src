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



#ifndef __SYS_SN_SN1_SNACIOREGS_H__
#define __SYS_SN_SN1_SNACIOREGS_H__



#define    II_WID                    0x400000    /* Widget Identification   */
#define    II_WSTAT                  0x400008    /*
                                                  * This register is also
                                                  * accessible from
                                                  * Crosstalk at address
                                                  * 0x0.
                                                  */
#define    II_WCR                    0x400020    /* Widget Status           */
#define    II_ILAPR                  0x400100    /* Widget Control          */
#define    II_ILAPO                  0x400108    /*
                                                  * IO Local Access
                                                  * Protection
                                                  */
#define    II_IOWA                   0x400110    /*
                                                  * IO Local Access
                                                  * Protection Override.
                                                  */
#define    II_IIWA                   0x400118    /*
                                                  * IO Outbound Widget
                                                  * Access
                                                  */
#define    II_IIDEM                  0x400120    /*
                                                  * IO Inbound Widget
                                                  * Access
                                                  */
#define    II_ILCSR                  0x400128    /*
                                                  * IO Inbound Device Error
                                                  * Mask
                                                  */
#define    II_ILLR                   0x400130    /*
                                                  * IO LLP Control and
                                                  * Status
                                                  */
#define    II_IIDSR                  0x400138    /* IO LLP Log              */
#define    II_IGFX0                  0x400140    /*
                                                  * IO Interrupt
                                                  * Destination
                                                  */
#define    II_IGFX1                  0x400148    /*
                                                  * IO Graphics Node-Widget
                                                  * Map 0
                                                  */
#define    II_ISCR0                  0x400150    /*
                                                  * IO Graphics Node-Widget
                                                  * Map 1
                                                  */
#define    II_ISCR1                  0x400158    /* IO Scratch register 0   */
#define    II_ITTE1                  0x400160    /* IO Scratch register 1   */
#define    II_ITTE2                  0x400168    /*
                                                  * IO Translation Table
                                                  * Entry 1
                                                  */
#define    II_ITTE3                  0x400170    /*
                                                  * IO Translation Table
                                                  * Entry 2
                                                  */
#define    II_ITTE4                  0x400178    /*
                                                  * IO Translation Table
                                                  * Entry 3
                                                  */
#define    II_ITTE5                  0x400180    /*
                                                  * IO Translation Table
                                                  * Entry 4
                                                  */
#define    II_ITTE6                  0x400188    /*
                                                  * IO Translation Table
                                                  * Entry 5
                                                  */
#define    II_ITTE7                  0x400190    /*
                                                  * IO Translation Table
                                                  * Entry 6
                                                  */
#define    II_IPRB0                  0x400198    /*
                                                  * IO Translation Table
                                                  * Entry 7
                                                  */
#define    II_IPRB8                  0x4001A0    /* IO PRB Entry 0          */
#define    II_IPRB9                  0x4001A8    /* IO PRB Entry 8          */
#define    II_IPRBA                  0x4001B0    /* IO PRB Entry 9          */
#define    II_IPRBB                  0x4001B8    /* IO PRB Entry A          */
#define    II_IPRBC                  0x4001C0    /* IO PRB Entry B          */
#define    II_IPRBD                  0x4001C8    /* IO PRB Entry C          */
#define    II_IPRBE                  0x4001D0    /* IO PRB Entry D          */
#define    II_IPRBF                  0x4001D8    /* IO PRB Entry E          */
#define    II_IXCC                   0x4001E0    /* IO PRB Entry F          */
#define    II_IMEM                   0x4001E8    /*
                                                  * IO Crosstalk Credit
                                                  * Count Time out
                                                  */
#define    II_IXTT                   0x4001F0    /*
                                                  * IO Miscellaneous Enable
                                                  * Mask
                                                  */
#define    II_IECLR                  0x4001F8    /*
                                                  * IO Crosstalk Tail Time
                                                  * out
                                                  */
#define    II_IPCA                   0x400300    /* IO Error Clear          */
#define    II_IPRTE0                 0x400308    /* IO PRB Counter Adjust   */
#define    II_IPRTE1                 0x400310    /*
                                                  * IO PIO Read Address
                                                  * Table Entry 0
                                                  */
#define    II_IPRTE2                 0x400318    /*
                                                  * IO PIO Read Address
                                                  * Table Entry 1
                                                  */
#define    II_IPRTE3                 0x400320    /*
                                                  * IO PIO Read Address
                                                  * Table Entry 2
                                                  */
#define    II_IPRTE4                 0x400328    /*
                                                  * IO PIO Read Address
                                                  * Table Entry 3
                                                  */
#define    II_IPRTE5                 0x400330    /*
                                                  * IO PIO Read Address
                                                  * Table Entry 4
                                                  */
#define    II_IPRTE6                 0x400338    /*
                                                  * IO PIO Read Address
                                                  * Table Entry 5
                                                  */
#define    II_IPRTE7                 0x400340    /*
                                                  * IO PIO Read Address
                                                  * Table Entry 6
                                                  */
#define    II_IPDR                   0x400388    /*
                                                  * IO PIO Read Address
                                                  * Table Entry 7
                                                  */
#define    II_ICDR                   0x400390    /*
                                                  * IO PIO Table Entry
                                                  * Deallocation
                                                  */
#define    II_IFDR                   0x400398    /*
                                                  * IO CRB Entry
                                                  * Deallocation
                                                  */
#define    II_IIAP                   0x4003A0    /*
                                                  * IO IOQ FIFO Depth
                                                  * Register
                                                  */
#define    II_ICMR                   0x4003A8    /*
                                                  * IO IIQ Arbitration
                                                  * Parameters Register
                                                  */
#define    II_ICCR                   0x4003B0    /*
                                                  * IO CRB Management
                                                  * Register
                                                  */
#define    II_ICTO                   0x4003B8    /* IO CRB Control Register */
#define    II_ICTP                   0x4003C0    /*
                                                  * IO CRB Time Out
                                                  * Register
                                                  */
#define    II_ICRB0_A                0x400400    /*
                                                  * IO CRB Time Out
                                                  * Prescalar
                                                  */
#define    II_ICRB0_B                0x400408    /* IO CRB Entry 0_A        */
#define    II_ICRB0_C                0x400410    /* IO CRB Entry 0_B        */
#define    II_ICRB0_D                0x400418    /* IO CRB Entry 0_C        */
#define    II_ICRB1_A                0x400420    /* IO CRB Entry 0_D        */
#define    II_ICRB1_B                0x400428    /* IO CRB Entry 1_A        */
#define    II_ICRB1_C                0x400430    /* IO CRB Entry 1_B        */
#define    II_ICRB1_D                0x400438    /* IO CRB Entry 1_C        */
#define    II_ICRB2_A                0x400440    /* IO CRB Entry 1_D        */
#define    II_ICRB2_B                0x400448    /* IO CRB Entry 2_A        */
#define    II_ICRB2_C                0x400450    /* IO CRB Entry 2_B        */
#define    II_ICRB2_D                0x400458    /* IO CRB Entry 2_C        */
#define    II_ICRB3_A                0x400460    /* IO CRB Entry 2_D        */
#define    II_ICRB3_B                0x400468    /* IO CRB Entry 3_A        */
#define    II_ICRB3_C                0x400470    /* IO CRB Entry 3_B        */
#define    II_ICRB3_D                0x400478    /* IO CRB Entry 3_C        */
#define    II_ICRB4_A                0x400480    /* IO CRB Entry 3_D        */
#define    II_ICRB4_B                0x400488    /* IO CRB Entry 4_A        */
#define    II_ICRB4_C                0x400490    /* IO CRB Entry 4_B        */
#define    II_ICRB4_D                0x400498    /* IO CRB Entry 4_C        */
#define    II_ICRB5_A                0x4004A0    /* IO CRB Entry 4_D        */
#define    II_ICRB5_B                0x4004A8    /* IO CRB Entry 5_A        */
#define    II_ICRB5_C                0x4004B0    /* IO CRB Entry 5_B        */
#define    II_ICRB5_D                0x4004B8    /* IO CRB Entry 5_C        */
#define    II_ICRB6_A                0x4004C0    /* IO CRB Entry 5_D        */
#define    II_ICRB6_B                0x4004C8    /* IO CRB Entry 6_A        */
#define    II_ICRB6_C                0x4004D0    /* IO CRB Entry 6_B        */
#define    II_ICRB6_D                0x4004D8    /* IO CRB Entry 6_C        */
#define    II_ICRB7_A                0x4004E0    /* IO CRB Entry 6_D        */
#define    II_ICRB7_B                0x4004E8    /* IO CRB Entry 7_A        */
#define    II_ICRB7_C                0x4004F0    /* IO CRB Entry 7_B        */
#define    II_ICRB7_D                0x4004F8    /* IO CRB Entry 7_C        */
#define    II_IPCR                   0x430000    /* IO CRB Entry 7_D        */
#define    II_IPPR                   0x430008    /* IO Performance Control  */


#ifdef _LANGUAGE_C

typedef union ii_wid_u {
	__uint64_t	wid_regval;
	struct  {
		__uint64_t	w_rsvd                    :	32;
		__uint64_t	w_rev_num                 :	 4;
		__uint64_t	w_part_num                :	16;
		__uint64_t	w_mfg_num                 :	11;
		__uint64_t	w_rsvd_3                  :	 1;
	} wid_fld_s;
} ii_wid_u_t;


typedef union ii_wstat_u {
	__uint64_t	wstat_regval;
	struct  {
		__uint64_t	w_rsvd                    :	31;
		__uint64_t	w_crazy                   :	 1;
		__uint64_t	w_rsvd_1                  :	 8;
		__uint64_t	w_llp_tx_cnt              :	 8;
		__uint64_t	w_rsvd_3                  :	 6;
		__uint64_t	w_tx_mx_rty               :	 1;
		__uint64_t	w_rsvd_5                  :	 2;
		__uint64_t	w_xt_tail_to              :	 1;
		__uint64_t	w_xt_crd_to               :	 1;
		__uint64_t	w_rsvd_0                  :	 1;
		__uint64_t	w_pending                 :	 4;
	} wstat_fld_s;
} ii_wstat_u_t;


typedef union ii_wcr_u {
	__uint64_t	wcr_regval;
	struct  {
		__uint64_t	w_rsvd                    :	41;
		__uint64_t	w_e_thresh                :	 5;
		__uint64_t	w_dir_con                 :	 1;
		__uint64_t	w_f_bad_pkt               :	 1;
		__uint64_t	w_dst_crd                 :	 3;
		__uint64_t	w_rsvd_4                  :	 8;
		__uint64_t	w_tag                     :	 1;
		__uint64_t	w_wid                     :	 4;
	} wcr_fld_s;
} ii_wcr_u_t;


typedef union ii_ilapr_u {
	__uint64_t	ilapr_regval;
	struct  {
		__uint64_t	i_region                  :	64;
	} ilapr_fld_s;
} ii_ilapr_u_t;


typedef union ii_ilapo_u {
	__uint64_t	ilapo_regval;
	struct  {
		__uint64_t	i_rsvd_0                  :	55;
		__uint64_t	i_io_ovrride              :	 9;
	} ilapo_fld_s;
} ii_ilapo_u_t;


typedef union ii_iowa_u {
	__uint64_t	iowa_regval;
	struct  {
		__uint64_t	i_rsvd                    :	48;
		__uint64_t	i_wx_oac                  :	 8;
		__uint64_t	i_rsvd_1                  :	 7;
		__uint64_t	i_w0_oac                  :	 1;
	} iowa_fld_s;
} ii_iowa_u_t;


typedef union ii_iiwa_u {
	__uint64_t	iiwa_regval;
	struct  {
		__uint64_t	i_rsvd                    :	48;
		__uint64_t	i_wx_iac                  :	 8;
		__uint64_t	i_rsvd_1                  :	 7;
		__uint64_t	i_w0_iac                  :	 1;
	} iiwa_fld_s;
} ii_iiwa_u_t;


typedef union ii_iidem_u {
	__uint64_t	iidem_regval;
	struct  {
		__uint64_t	i_wf_dxs                  :	 8;
		__uint64_t	i_we_dxs                  :	 8;
		__uint64_t	i_wd_dxs                  :	 8;
		__uint64_t	i_wc_dxs                  :	 8;
		__uint64_t	i_wb_dxs                  :	 8;
		__uint64_t	i_wa_dxs                  :	 8;
		__uint64_t	i_w9_dxs                  :	 8;
		__uint64_t	i_w8_dxs                  :	 8;
	} iidem_fld_s;
} ii_iidem_u_t;


typedef union ii_ilcsr_u {
	__uint64_t	ilcsr_regval;
	struct  {
		__uint64_t	i_rsvd                    :	22;
		__uint64_t	i_maxbrst                 :	10;
		__uint64_t	i_rsvd_1                  :	 6;
		__uint64_t	i_maxrtry                 :	10;
		__uint64_t	i_rsvd_3                  :	 2;
		__uint64_t	i_llp_stat                :	 2;
		__uint64_t	i_bm8                     :	 1;
		__uint64_t	i_llp_en                  :	 1;
		__uint64_t	i_rsvd_7                  :	 1;
		__uint64_t	i_wrmrst                  :	 1;
		__uint64_t	i_rsvd_9                  :	 2;
		__uint64_t	i_nullto                  :	 6;
	} ilcsr_fld_s;
} ii_ilcsr_u_t;


typedef union ii_illr_u {
	__uint64_t	illr_regval;
	struct  {
		__uint64_t	i_rsvd                    :	32;
		__uint64_t	i_cb_cnt                  :	16;
		__uint64_t	i_sn_cnt                  :	16;
	} illr_fld_s;
} ii_illr_u_t;


typedef union ii_idsr_u {
	__uint64_t	idsr_regval;
	struct  {
		__uint64_t	i_rsvd                    :	35;
		__uint64_t	i_int_sent                :	 1;
		__uint64_t	i_rsvd_1                  :	 3;
		__uint64_t	i_enable                  :	 1;
		__uint64_t	i_rsvd_3                  :	 7;
		__uint64_t	i_node                    :	 9;
		__uint64_t	i_rsvd_5                  :	 1;
		__uint64_t	i_level                   :	 7;
	} idsr_fld_s;
} ii_idsr_u_t;


typedef union ii_igfx0_u {
	__uint64_t	igfx0_regval;
	struct  {
		__uint64_t	i_rsvd                    :	47;
		__uint64_t	i_p_num                   :	 1;
		__uint64_t	i_rsvd_1                  :	 3;
		__uint64_t	i_n_num                   :	 9;
		__uint64_t	i_w_num                   :	 4;
	} igfx0_fld_s;
} ii_igfx0_u_t;


typedef union ii_iptp0_u {
	__uint64_t	iptp0_regval;
	struct  {
		__uint64_t	i_rsvd_0                  :	28;
		__uint64_t	i_scr_2                   :	 4;
		__uint64_t	i_rsvd                    :	 8;
		__uint64_t	i_scr_1                   :	 4;
		__uint64_t	i_rsvd_3                  :	 7;
		__uint64_t	i_scr_0                   :	13;
	} iptp0_fld_s;
} ii_iptp0_u_t;


typedef union ii_itte1_u {
	__uint64_t	itte1_regval;
	struct  {
		__uint64_t	i_rsvd                    :	51;
		__uint64_t	i_iosp                    :	 1;
		__uint64_t	i_w_num                   :	 4;
		__uint64_t	i_rsvd_2                  :	 3;
		__uint64_t	i_offset                  :	 5;
	} itte1_fld_s;
} ii_itte1_u_t;


typedef union ii_iprb0_u {
	__uint64_t	iprb0_regval;
	struct  {
		__uint64_t	i_rsvd                    :	15;
		__uint64_t	i_error                   :	 1;
		__uint64_t	i_of_cnt                  :	 5;
		__uint64_t	i_f                       :	 1;
		__uint64_t	i_m                       :	 2;
		__uint64_t	i_rsvd_4                  :	 2;
		__uint64_t	i_nb                      :	14;
		__uint64_t	i_rsvd_6                  :	 2;
		__uint64_t	i_na                      :	14;
		__uint64_t	i_c                       :	 8;
	} iprb0_fld_s;
} ii_iprb0_u_t;


typedef union ii_ixcc_u {
	__uint64_t	ixcc_regval;
	struct  {
		__uint64_t	i_rsvd                    :	38;
		__uint64_t	i_time_out                :	26;
	} ixcc_fld_s;
} ii_ixcc_u_t;


typedef union ii_imem_u {
	__uint64_t	imem_regval;
	struct  {
		__uint64_t	i_rsvd                    :	51;
		__uint64_t	i_clr_precise             :	 1;
		__uint64_t	i_rsvd_1                  :	11;
		__uint64_t	i_w0_esd                  :	 1;
	} imem_fld_s;
} ii_imem_u_t;


typedef union ii_ixtt_u {
	__uint64_t	ixtt_regval;
	struct  {
		__uint64_t	i_rsvd                    :	38;
		__uint64_t	i_time_out                :	26;
	} ixtt_fld_s;
} ii_ixtt_u_t;


typedef union ii_ieclr_u {
	__uint64_t	ieclr_regval;
	struct  {
		__uint64_t	i_rsvd                    :	47;
		__uint64_t	i_e_crazy                 :	 1;
		__uint64_t	i_e_prb_f                 :	 1;
		__uint64_t	i_e_prb_e                 :	 1;
		__uint64_t	i_e_prb_d                 :	 1;
		__uint64_t	i_e_prb_c                 :	 1;
		__uint64_t	i_e_prb_b                 :	 1;
		__uint64_t	i_e_prb_a                 :	 1;
		__uint64_t	i_e_prb_9                 :	 1;
		__uint64_t	i_e_prb_8                 :	 1;
		__uint64_t	i_rsvd_9                  :	 7;
		__uint64_t	i_e_prb_0                 :	 1;
	} ieclr_fld_s;
} ii_ieclr_u_t;


typedef union ii_ipca_u {
	__uint64_t	ipca_regval;
	struct  {
		__uint64_t	i_rsvd                    :	54;
		__uint64_t	i_field                   :	 2;
		__uint64_t	i_rsvd_1                  :	 3;
		__uint64_t	i_adjust                  :	 1;
		__uint64_t	i_wid                     :	 4;
	} ipca_fld_s;
} ii_ipca_u_t;


typedef union ii_iprte0_u {
	__uint64_t	iprte0_regval;
	struct  {
		__uint64_t	i_rsvd                    :	 7;
		__uint64_t	i_vld                     :	 1;
		__uint64_t	i_rsvd_1                  :	 1;
		__uint64_t	i_source                  :	 9;
		__uint64_t	i_init                    :	 2;
		__uint64_t	i_rsvd_4                  :	 3;
		__uint64_t	i_addr                    :	38;
		__uint64_t	i_rsvd_6                  :	 3;
	} iprte0_fld_s;
} ii_iprte0_u_t;


typedef union ii_ipdr_u {
	__uint64_t	ipdr_regval;
	struct  {
		__uint64_t	i_rsvd                    :	58;
		__uint64_t	i_init_rpcnt              :	 1;
		__uint64_t	i_pnd                     :	 1;
		__uint64_t	i_rsvd_2                  :	 1;
		__uint64_t	i_te                      :	 3;
	} ipdr_fld_s;
} ii_ipdr_u_t;


typedef union ii_icdr_u {
	__uint64_t	icdr_regval;
	struct  {
		__uint64_t	i_rsvd                    :	59;
		__uint64_t	i_pnd                     :	 1;
		__uint64_t	i_rsvd_1                  :	 1;
		__uint64_t	i_crb_num                 :	 3;
	} icdr_fld_s;
} ii_icdr_u_t;


typedef union ii_ifdr_u {
	__uint64_t	ifdr_regval;
	struct  {
		__uint64_t	i_rsvd                    :	49;
		__uint64_t	i_max_rp                  :	 7;
		__uint64_t	i_rsvd_1                  :	 1;
		__uint64_t	i_max_rq                  :	 7;
	} ifdr_fld_s;
} ii_ifdr_u_t;


typedef union ii_iiap_u {
	__uint64_t	iiap_regval;
	struct  {
		__uint64_t	i_rsvd                    :	50;
		__uint64_t	i_rp_mls                  :	 6;
		__uint64_t	i_rsvd_1                  :	 2;
		__uint64_t	i_rq_mls                  :	 6;
	} iiap_fld_s;
} ii_iiap_u_t;


typedef union ii_icmr_u {
	__uint64_t	icmr_regval;
	struct  {
		__uint64_t	i_rsvd                    :	11;
		__uint64_t	i_precise                 :	 1;
		__uint64_t	i_rsvd_1                  :	 1;
		__uint64_t	i_pc_vld                  :	15;
		__uint64_t	i_rsvd_3                  :	 1;
		__uint64_t	i_crb_vld                 :	15;
		__uint64_t	i_fc_cnt                  :	 4;
		__uint64_t	i_rsvd_6                  :	 2;
		__uint64_t	i_clr_rppd                :	 1;
		__uint64_t	i_clr_rqpd                :	 1;
		__uint64_t	i_rsvd_9                  :	 4;
		__uint64_t	i_c_cnt                   :	 4;
		__uint64_t	i_p_cnt                   :	 4;
	} icmr_fld_s;
} ii_icmr_u_t;


typedef union ii_iccr_u {
	__uint64_t	iccr_regval;
	struct  {
		__uint64_t	i_rsvd                    :	47;
		__uint64_t	i_pending                 :	 1;
		__uint64_t	i_cmd                     :	 8;
		__uint64_t	i_rsvd_2                  :	 4;
		__uint64_t	i_crb_num                 :	 4;
	} iccr_fld_s;
} ii_iccr_u_t;


typedef union ii_icto_u {
	__uint64_t	icto_regval;
	struct  {
		__uint64_t	i_rsvd                    :	56;
		__uint64_t	i_timeout                 :	 8;
	} icto_fld_s;
} ii_icto_u_t;


typedef union ii_ictp_u {
	__uint64_t	ictp_regval;
	struct  {
		__uint64_t	i_rsvd                    :	40;
		__uint64_t	i_prescale                :	24;
	} ictp_fld_s;
} ii_ictp_u_t;


typedef union ii_icrb0_d_u {
	__uint64_t	icrb0_d_regval;
	struct  {
		__uint64_t	id_rsvd                   :	38;
		__uint64_t	id_tvld                   :	 1;
		__uint64_t	id_cvld                   :	 1;
		__uint64_t	id_rsvd_2                 :	 1;
		__uint64_t	id_context                :	15;
		__uint64_t	id_timeout                :	 8;
	} icrb0_d_fld_s;
} ii_icrb0_d_u_t;


typedef union ii_icrb0_c_u {
	__uint64_t	icrb0_c_regval;
	struct  {
		__uint64_t	ic_rsvd                   :	 6;
		__uint64_t	ic_sleep                  :	 1;
		__uint64_t	ic_pr_cnt                 :	 4;
		__uint64_t	ic_pr_psc                 :	 4;
		__uint64_t	ic_rsvd_3                 :	 1;
		__uint64_t	ic_pa_be                  :	34;
		__uint64_t	ic_suppl                  :	11;
		__uint64_t	ic_bo                     :	 1;
		__uint64_t	ic_resprqd                :	 1;
		__uint64_t	ic_gbr                    :	 1;
	} icrb0_c_fld_s;
} ii_icrb0_c_u_t;


typedef union ii_icrb0_b_u {
	__uint64_t	icrb0_b_regval;
	struct  {
		__uint64_t	ib_rsvd                   :	 6;
		__uint64_t	ib_ct                     :	 1;
		__uint64_t	ib_size                   :	 2;
		__uint64_t	ib_source                 :	11;
		__uint64_t	ib_use_old                :	 1;
		__uint64_t	ib_imsgtype               :	 2;
		__uint64_t	ib_imsg                   :	 8;
		__uint64_t	ib_init                   :	 3;
		__uint64_t	ib_exc                    :	 5;
		__uint64_t	ib_rsvd_8                 :	 7;
		__uint64_t	ib_ack_cnt                :	11;
		__uint64_t	ib_resp                   :	 1;
		__uint64_t	ib_ack                    :	 1;
		__uint64_t	ib_hold                   :	 1;
		__uint64_t	ib_wb                     :	 1;
		__uint64_t	ib_intvn                  :	 1;
		__uint64_t	ib_stall_ib               :	 1;
		__uint64_t	ib_stall_intr             :	 1;
	} icrb0_b_fld_s;
} ii_icrb0_b_u_t;


typedef union ii_icrb0_a_u {
	__uint64_t	icrb0_a_regval;
	struct  {
		__uint64_t	ia_rsvd                   :	 8;
		__uint64_t	ia_error                  :	 1;
		__uint64_t	ia_errcode                :	 3;
		__uint64_t	ia_ln_uce                 :	 1;
		__uint64_t	ia_mark                   :	 1;
		__uint64_t	ia_xt_err                 :	 1;
		__uint64_t	ia_sidn                   :	 4;
		__uint64_t	ia_tnum                   :	 5;
		__uint64_t	ia_addr                   :	38;
		__uint64_t	ia_vld                    :	 1;
		__uint64_t	ia_iow                    :	 1;
	} icrb0_a_fld_s;
} ii_icrb0_a_u_t;


typedef union ii_ipcr_u {
	__uint64_t	ipcr_regval;
	struct  {
		__uint64_t	i_rsvd                    :	48;
		__uint64_t	i_icct                    :	 8;
		__uint64_t	i_ippr1_c                 :	 4;
		__uint64_t	i_ippr0_c                 :	 4;
	} ipcr_fld_s;
} ii_ipcr_u_t;


typedef union ii_ippr_u {
	__uint64_t	ippr_regval;
	struct  {
		__uint64_t	i_ippr1                   :	32;
		__uint64_t	i_ippr0                   :	32;
	} ippr_fld_s;
} ii_ippr_u_t;




#endif /* _LANGUAGE_C */




#endif  /* __SYS_SN_SN1_SNACIOREGS_H__ */