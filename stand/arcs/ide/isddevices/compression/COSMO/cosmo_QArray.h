/******************************************************************************/
/******  Compression Monitor for C-Cube Microsystems CL550 processor     ******/
/******  June 14 , 1991                                                  ******/
/******  Version 2.1                                                     ******/
/******************************************************************************/

/* 
 * Changed dim, 05. juin 1994 13:38:53 to reflect default 
 * qfactor of 75  -jd
 */

#ifndef __COSMO_QArray_H_
#define __COSMO_QArray_H

unsigned short DefaultDQ50Array1[] = {
0x6800, 0x50a5, 0x524a, 0x5076, 0x6900, 0x696d, 0x86c3, 0xa27b, 
0x50a5, 0x5716, 0x595f, 0x6ead, 0x6f42, 0x89cf, 0xa601, 0xa466, 
0x4d10, 0x595f, 0x6da8, 0x70e6, 0x8c69, 0x8e5f, 0xa6e5, 0xa453, 
0x6968, 0x704f, 0x726f, 0x74bd, 0x9076, 0xa764, 0xa700, 0xa3f9, 
0x6c00, 0x7208, 0x8d10, 0x8f49, 0xa880, 0xa80d, 0xa709, 0xa3dc, 
0x87db, 0x8fcd, 0x8ee2, 0xaa29, 0xaacd, 0xa806, 0xa67c, 0xa2b5, 
0x8709, 0x8b42, 0xa630, 0xa65d, 0xa709, 0xa60f, 0xa464, 0xa1f1, 
0x8446, 0x855b, 0x850c, 0x8507, 0xa2b0, 0xa27e, 0xa1e7, 0x0000, 

0x6900, 0x6c7b, 0x6fad, 0x8e1c, 0xac80, 0xa9d2, 0xa6c3, 0xa373, 
0x6c7b, 0x7529, 0x778f, 0xad74, 0xb156, 0xad9f, 0xa962, 0xa4c8, 
0x6fad, 0x778f, 0x97e6, 0xb334, 0xb055, 0xacd5, 0xa8d6, 0xa481, 
0x8e1c, 0xad74, 0xb334, 0xb148, 0xaeb2, 0xab8c, 0xa7f4, 0xa40e, 
0xac80, 0xb156, 0xb055, 0xaeb2, 0xac80, 0xa9d2, 0xa6c3, 0xa373, 
0xa9d2, 0xad9f, 0xacd5, 0xab8c, 0xa9d2, 0xa7b7, 0xa550, 0xa2b5, 
0xa6c3, 0xa962, 0xa8d6, 0xa7f4, 0xa6c3, 0xa550, 0xa3a9, 0xa1dd, 
0xa373, 0xa4c8, 0xa481, 0xa40e, 0xa373, 0xa2b5, 0xa1dd, 0x0000, 
};


unsigned short DefaultCQ50Array1[] = {
0x0080, 0x03b3, 0x017e, 0x02b0, 0x0072, 0x010c, 0x002c, 0x001f, 
0x03b3, 0x1485, 0x0849, 0x0b99, 0x0204, 0x03e0, 0x00c0, 0x0088, 
0x0217, 0x0849, 0x036a, 0x0478, 0x008d, 0x012c, 0x004a, 0x003e, 
0x025a, 0x0a70, 0x0419, 0x05e6, 0x00ac, 0x01d9, 0x0076, 0x006c, 
0x0055, 0x01b5, 0x0086, 0x00b9, 0x001e, 0x004e, 0x0015, 0x0014, 
0x00a1, 0x0268, 0x0122, 0x0158, 0x003b, 0x00c3, 0x0039, 0x0047, 
0x002b, 0x00cd, 0x0053, 0x0082, 0x0015, 0x003d, 0x0014, 0x0018, 
0x0024, 0x00e0, 0x0069, 0x00ab, 0x001d, 0x004d, 0x0018, 0x0000, 

0x0072, 0x0277, 0x00df, 0x00c9, 0x0014, 0x0040, 0x0016, 0x0017, 
0x0277, 0x0b32, 0x0476, 0x032a, 0x0072, 0x0165, 0x007b, 0x007d, 
0x00df, 0x0476, 0x00fa, 0x00fc, 0x0036, 0x00a8, 0x003a, 0x003b, 
0x00c9, 0x032a, 0x00fc, 0x01c5, 0x0060, 0x012f, 0x0068, 0x006a, 
0x0014, 0x0072, 0x0036, 0x0060, 0x0014, 0x0040, 0x0016, 0x0017, 
0x0040, 0x0165, 0x00a8, 0x012f, 0x0040, 0x00ca, 0x0046, 0x0047, 
0x0016, 0x007b, 0x003a, 0x0068, 0x0016, 0x0046, 0x0018, 0x0018, 
0x0017, 0x007d, 0x003b, 0x006a, 0x0017, 0x0047, 0x0018, 0x0000, 
};


#endif /* __COSMO_QArray_H_ */
