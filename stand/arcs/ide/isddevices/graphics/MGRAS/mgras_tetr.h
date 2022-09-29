/**************************************************************************
 *                                                                        *
 *               Copyright (C) 1990, Silicon Graphics, Inc.               *
 *                                                                        *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *                                                                        *
 **************************************************************************/

/* defines for te-tram level 2 tests */

#define ldrsmpl_checksum 	0x7fffffff80ull
#define ldrsmpl_1tram_checksum 	0x7fbfffffc0ull

__uint32_t ldrsmpl_array[256] = {
0x55555555, 0x55550000, 0x55555555, 0x55550044, 0xaaaaaaaa, 0xaaaa0000, 0xaaaaaaaa, 0xaaaa0044, 0xcccccccc, 0xcccc0088, 0xcccccccc, 0xcccc00cc, 0xffffffff, 0xffff0088, 0xffffffff, 0xffff00cc, 0x44004411, 0x44221100, 0x44004411, 0x44221144,
0x44884499, 0x44aa1100, 0x44884499, 0x44aa1144, 0x55555555, 0x55550000, 0x55555555, 0x55550044, 0xaaaaaaaa, 0xaaaa0000, 0xaaaaaaaa, 0xaaaa0044, 0xcccccccc, 0xcccc0088, 0xcccccccc, 0xcccc00cc, 0xffffffff, 0xffff0088, 0xffffffff, 0xffff00cc,
0x44004411, 0x44221100, 0x44004411, 0x44221144, 0x44884499, 0x44aa1100, 0x44884499, 0x44aa1144, 0x55555555, 0x55550000, 0x55555555, 0x55550044, 0xaaaaaaaa, 0xaaaa0000, 0xaaaaaaaa, 0xaaaa0044, 0xcccccccc, 0xcccc0088, 0xcccccccc, 0xcccc00cc,
0xffffffff, 0xffff0088, 0xffffffff, 0xffff00cc,
0xaaaaaaaa, 0xaaaaffff, 0xaaaaaaaa, 0xaaaaffbb, 0x55555555, 0x5555ffff, 0x55555555, 0x5555ffbb, 0x33333333, 0x3333ff77, 0x33333333, 0x3333ff33, 0x0, 0xff77, 0x0, 0xff33, 0xbbffbbee, 0xbbddeeff, 0xbbffbbee, 0xbbddeebb, 0xbb77bb66, 0xbb55eeff, 0xbb77bb66, 0xbb55eebb, 0xaaaaaaaa, 0xaaaaffff, 0xaaaaaaaa, 0xaaaaffbb, 0x55555555, 0x5555ffff, 0x55555555, 0x5555ffbb, 0x33333333, 0x3333ff77, 0x33333333, 0x3333ff33, 0x0, 0xff77, 0x0, 0xff33, 0xbbffbbee, 0xbbddeeff, 0xbbffbbee, 0xbbddeebb, 0xbb77bb66, 0xbb55eeff, 0xbb77bb66, 0xbb55eebb, 0xaaaaaaaa, 0xaaaaffff, 0xaaaaaaaa, 0xaaaaffbb, 0x55555555, 0x5555ffff, 0x55555555, 0x5555ffbb, 0x33333333,
0x3333ff77, 0x33333333, 0x3333ff33, 0x0, 0xff77, 0x0, 0xff33,
0x55555555, 0x55550000, 0x55555555, 0x55550044, 0xaaaaaaaa, 0xaaaa0000, 0xaaaaaaaa, 0xaaaa0044, 0xcccccccc, 0xcccc0088, 0xcccccccc, 0xcccc00cc, 0xffffffff, 0xffff0088, 0xffffffff, 0xffff00cc, 0x44004411, 0x44221100, 0x44004411, 0x44221144,
0x44884499, 0x44aa1100, 0x44884499, 0x44aa1144, 0x55555555, 0x55550000, 0x55555555, 0x55550044, 0xaaaaaaaa, 0xaaaa0000, 0xaaaaaaaa, 0xaaaa0044, 0xcccccccc, 0xcccc0088, 0xcccccccc, 0xcccc00cc, 0xffffffff, 0xffff0088, 0xffffffff, 0xffff00cc,
0x44004411, 0x44221100, 0x44004411, 0x44221144, 0x44884499, 0x44aa1100, 0x44884499, 0x44aa1144, 0x55555555, 0x55550000, 0x55555555, 0x55550044, 0xaaaaaaaa, 0xaaaa0000, 0xaaaaaaaa, 0xaaaa0044, 0xcccccccc, 0xcccc0088, 0xcccccccc, 0xcccc00cc,
0xffffffff, 0xffff0088, 0xffffffff, 0xffff00cc,
0xaaaaaaaa, 0xaaaaffff, 0xaaaaaaaa, 0xaaaaffbb, 0x55555555, 0x5555ffff, 0x55555555, 0x5555ffbb, 0x33333333, 0x3333ff77, 0x33333333, 0x3333ff33, 0x0, 0xff77, 0x0, 0xff33, 0xbbffbbee, 0xbbddeeff, 0xbbffbbee, 0xbbddeebb, 0xbb77bb66, 0xbb55eeff, 0xbb77bb66, 0xbb55eebb, 0xaaaaaaaa, 0xaaaaffff, 0xaaaaaaaa, 0xaaaaffbb, 0x55555555, 0x5555ffff, 0x55555555, 0x5555ffbb, 0x33333333, 0x3333ff77, 0x33333333, 0x3333ff33, 0x0, 0xff77, 0x0, 0xff33, 0xbbffbbee, 0xbbddeeff, 0xbbffbbee, 0xbbddeebb, 0xbb77bb66, 0xbb55eeff, 0xbb77bb66, 0xbb55eebb, 0xaaaaaaaa, 0xaaaaffff, 0xaaaaaaaa, 0xaaaaffbb, 0x55555555, 0x5555ffff, 0x55555555, 0x5555ffbb, 0x33333333,
0x3333ff77, 0x33333333, 0x3333ff33, 0x0, 0xff77, 0x0, 0xff33
};

__uint32_t ldrsmpl_1tram_array[128] = {
0xff555555, 0xff555555, 0xff555555, 0xff000000, 0xff555555, 0xff555555, 0xff555555, 0xff040404, 0xffaaaaaa, 0xffaaaaaa, 0xffaaaaaa, 0xff000000, 0xffaaaaaa, 0xffaaaaaa, 0xffaaaaaa, 0xff040404, 0xffcccccc, 0xffcccccc, 0xffcccccc, 0xff080808, 0xffcccccc, 0xffcccccc, 0xffcccccc, 0xff0c0c0c, 0xffffffff, 0xffffffff, 0xffffffff, 0xff080808, 0xffffffff, 0xffffffff, 0xffffffff, 0xff0c0c0c, 0xff404040, 0xff414141, 0xff424242, 0xff101010, 0xff404040, 0xff414141, 0xff424242, 0xff141414, 0xff484848, 0xff494949, 0xff4a4a4a, 0xff101010, 0xff484848, 0xff494949, 0xff4a4a4a, 0xff141414, 0xff555555, 0xff555555, 0xff555555, 0xff000000, 0xff555555, 0xff555555, 0xff555555, 0xff040404, 0xffaaaaaa, 0xffaaaaaa, 0xffaaaaaa, 0xff000000, 0xffaaaaaa, 0xffaaaaaa, 0xffaaaaaa, 0xff040404, 
0xffaaaaaa, 0xffaaaaaa, 0xffaaaaaa, 0xffffffff, 0xffaaaaaa, 0xffaaaaaa, 0xffaaaaaa, 0xfffbfbfb, 0xff555555, 0xff555555, 0xff555555, 0xffffffff, 0xff555555, 0xff555555, 0xff555555, 0xfffbfbfb, 0xff333333, 0xff333333, 0xff333333, 0xfff7f7f7, 0xff333333, 0xff333333, 0xff333333, 0xfff3f3f3, 0xff000000, 0xff000000, 0xff000000, 0xfff7f7f7, 0xff000000, 0xff000000, 0xff000000, 0xfff3f3f3, 0xffbfbfbf, 0xffbebebe, 0xffbdbdbd, 0xffefefef, 0xffbfbfbf, 0xffbebebe, 0xffbdbdbd, 0xffebebeb, 0xffb7b7b7, 0xffb6b6b6, 0xffb5b5b5, 0xffefefef, 0xffb7b7b7, 0xffb6b6b6, 0xffb5b5b5, 0xffebebeb, 0xffaaaaaa, 0xffaaaaaa, 0xffaaaaaa, 0xffffffff, 0xffaaaaaa, 0xffaaaaaa, 0xffaaaaaa, 0xfffbfbfb, 0xff555555, 0xff555555, 0xff555555, 0xffffffff, 0xff555555, 0xff555555, 0xff555555, 0xfffbfbfb
};