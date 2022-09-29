/*
 * os/numa/plac_policy_default.h
 *
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 *
 * UNPUBLISHED -- Rights reserved under the copyright laws of the United
 * States.   Use of a copyright notice is precautionary only and does not
 * imply publication or disclosure.
 *
 * U.S. GOVERNMENT RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to restrictions
 * as set forth in FAR 52.227.19(c)(2) or subparagraph (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS 252.227-7013 and/or
 * in similar or successor clauses in the FAR, or the DOD or NASA FAR
 * Supplement.  Contractor/manufacturer is Silicon Graphics, Inc.,
 * 2011 N. Shoreline Blvd. Mountain View, CA 94039-7311.
 *
 * THE CONTENT OF THIS WORK CONTAINS CONFIDENTIAL AND PROPRIETARY
 * INFORMATION OF SILICON GRAPHICS, INC. ANY DUPLICATION, MODIFICATION,
 * DISTRIBUTION, OR DISCLOSURE IN ANY FORM, IN WHOLE, OR IN PART, IS STRICTLY
 * PROHIBITED WITHOUT THE PRIOR EXPRESS WRITTEN PERMISSION OF SILICON
 * GRAPHICS, INC.
 */

#ifndef __NUMA_PLAC_POLICY_DEFAULT_H__
#define __NUMA_PLAC_POLICY_DEFAULT_H__

extern int plac_policy_default_create(pm_t* pm, void* args, pmo_ns_t* pmo_ns);
extern void plac_policy_default_destroy(pm_t* pm);
extern void plac_policy_default_afflink(struct pm* pm,
                                        aff_caller_t aff_caller,
                                        kthread_t* ckt,
                                        kthread_t* pkt)
#endif /* __NUMA_PLAC_POLICY_DEFAULT_H__ */