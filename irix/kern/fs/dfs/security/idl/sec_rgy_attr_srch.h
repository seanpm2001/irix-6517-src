/*
 * @OSF_COPYRIGHT@
 * COPYRIGHT NOTICE
 * Copyright (c) 1990, 1991, 1992, 1993, 1994, 1996 Open Software Foundation, Inc.
 * ALL RIGHTS RESERVED (DCE).  See the file named COPYRIGHT.DCE for
 * the full copyright text.
 */
/*
 * HISTORY
 * $Log: sec_rgy_attr_srch.h,v $
 * Revision 65.2  1999/02/03 22:44:24  mek
 * Convert from IDL to C style include format.
 *
 * Revision 65.1  1997/10/20 19:46:42  jdoak
 * *** empty log message ***
 *
 * Revision 1.1.6.1  1996/10/03  14:54:50  arvind
 * 	Correct types to match the actual type for the name used over the wire.
 * 	[1996/09/17  00:21 UTC  sommerfeld  /main/sommerfeld_pk_kdc_1/1]
 *
 * Revision 1.1.4.2  1996/03/09  23:29:22  marty
 * 	Update OSF copyright year
 * 	[1996/03/09  22:44:44  marty]
 * 
 * Revision 1.1.4.1  1995/12/08  17:38:19  root
 * 	Submit OSF/DCE 1.2.1
 * 	[1995/12/08  16:56:15  root]
 * 
 * Revision 1.1.2.2  1994/06/17  18:42:37  devsrc
 * 	cr10872 - fix copyright
 * 	[1994/06/17  18:10:42  devsrc]
 * 
 * Revision 1.1.2.1  1994/03/02  17:55:34  hanfei
 * 	Initial ERA drop
 * 	[1994/02/18  19:20:01  hanfei]
 * 
 * $EndLog$
 */
/* Generated by IDL compiler version OSF DCE T1.2.0-09 */
#ifndef sec_rgy_attr_srch_v0_0_included
#define sec_rgy_attr_srch_v0_0_included
#ifndef IDLBASE_H
#include <dce/idlbase.h>
#endif

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef nbase_v0_0_included
#include <dce/nbase.h>
#endif
#ifndef rgybase_v0_0_included
#include <dce/rgybase.h>
#endif
#ifndef sec_attr_base_v0_0_included
#include <dce/sec_attr_base.h>
#endif
extern void sec_rgy_attr_srch_cursor_init(
#ifdef IDL_PROTOTYPES
    /* [in] */ sec_rgy_handle_t context,
    /* [in] */ sec_rgy_domain_t name_domain,
    /* [in] */ unsigned32 num_search_attrs,
    /* [in] */ sec_attr_t search_attrs[],
    /* [out] */ sec_attr_srch_cursor_t *cursor,
    /* [out] */ error_status_t *st
#endif
);
extern void sec_rgy_attr_srch_cursor_rel(
#ifdef IDL_PROTOTYPES
    /* [in] */ sec_rgy_handle_t context,
    /* [in, out] */ sec_attr_srch_cursor_t *cursor,
    /* [out] */ error_status_t *st
#endif
);
extern void sec_rgy_attr_srch_names(
#ifdef IDL_PROTOTYPES
    /* [in] */ sec_rgy_handle_t context,
    /* [in, out] */ sec_attr_srch_cursor_t *cursor,
    /* [in] */ unsigned32 num_names_avail,
    /* [out] */ unsigned32 *num_names_returned,
    /* [out] */ sec_attr_component_name_t names[],
    /* [out] */ unsigned32 total_component_attrs[],
    /* [out] */ error_status_t *st
#endif
);
extern void sec_rgy_attr_srch_names_attrs(
#ifdef IDL_PROTOTYPES
    /* [in] */ sec_rgy_handle_t context,
    /* [in, out] */ sec_attr_srch_cursor_t *cursor,
    /* [in] */ unsigned32 num_desired_attrs,
    /* [in] */ uuid_t desired_attrs[],
    /* [in] */ unsigned32 num_names_avail,
    /* [in] */ unsigned32 num_attrs_avail,
    /* [out] */ unsigned32 *num_names_returned,
    /* [out] */ sec_attr_component_name_t names[],
    /* [out] */ unsigned32 component_attr_num[],
    /* [out] */ unsigned32 *num_attrs_returned,
    /* [out] */ sec_attr_t attrs[],
    /* [out] */ error_status_t *st
#endif
);

#ifdef __cplusplus
    }

#endif
#endif