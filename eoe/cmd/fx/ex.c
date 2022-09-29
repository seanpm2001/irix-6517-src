#include "fx.h"
#include <math.h>	/* for random() */

int             exercising;	/* for callsub() and gread() */

static          stop_on_err, showdiffs;

unchar *extrack;
unchar *chktrack;

struct err {
	uint             hits[4];
	uint             drive;
	daddr_t         bn;
};

#define MAX_ERRBLOCKS 100	/* max errors we keep in log */
#define TOOMANYCONSEC 10	/* max consecutive errors before complaining */

static struct exercise {
	char            modifier;
	char            aflag;
	char            iflag, lflag;
	daddr_t         firstbn, lastbn;
	void             (*stepper)(void);
	int             passes;

	int             rsize;
	unchar           *buf;
	int             bufsize;
	daddr_t         curbn;
	int             phase;

	struct err      eb[MAX_ERRBLOCKS];
	uint             neb;
}               E;

static void showdiff(unchar *dbuf, unchar *cmpbuf, uint cnt);
static scanchunk(daddr_t bn, int sectors);
static errcompar(const void *a, const void *b);
static int exrun(void);

extern int nomenus;	/* see fx.c, -c option */

# define MXR	001	/* read */
# define MXW	002	/* write */
# define MXS	004	/* seek */
# define MXC	010	/* compare */
# define MAX_TESTPAT	MAX_BSIZE
static
int             TestPhase = 0, TestCycle = 3;

/* a prime # is best, with a non-repeating pattern within the prime. Ideally,
 * the pattern should be > than one sector in length, so that if the drive
 * or controller returns the wrong sector sometimes, the error is likely
 * to be detected; otherwise every sector contains the same pattern!
 * We use 1031, since we may go to 1024 byte sectors; some drives already
 * support that for raw accesses.  This pattern was generated by a
 * program using random(), with the first 3 bytes replaced by the old
 * pattern.
*/
unchar   defpat[1031] = {
	0xdb, 0x6d, 0xb6, 0xbe, 0x7f, 0x51, 0x96, 0x0b, 0xcf, 0x9e, 0xdb, 0x2b,
	0x61, 0xf0, 0x6f, 0x0f, 0xeb, 0x5a, 0x38, 0xb6, 0x48, 0x01, 0x02, 0xa4,
	0xbf, 0x89, 0xa9, 0x9b, 0xa6, 0xbb, 0x5c, 0x63, 0xbd, 0xf8, 0x22, 0x3d,
	0x49, 0xb8, 0x48, 0x18, 0x56, 0x23, 0x43, 0xb7, 0x13, 0xb2, 0xc7, 0xff,
	0x0c, 0xff, 0xb5, 0x54, 0x00, 0xb8, 0xf8, 0xbf, 0x41, 0xa2, 0x5b, 0xe7,
	0x5d, 0xb7, 0x4b, 0x1b, 0xaf, 0x6d, 0x58, 0xf8, 0x25, 0xa0, 0x11, 0x7c,
	0xc4, 0x54, 0x33, 0xd7, 0x07, 0xfa, 0xd6, 0x13, 0xf9, 0x8c, 0x68, 0xfa,
	0x44, 0x60, 0xb9, 0x85, 0x02, 0x14, 0x6d, 0x60, 0xcc, 0xb8, 0x7b, 0x7b,
	0x25, 0xd3, 0x74, 0x4a, 0x73, 0x85, 0xc6, 0x37, 0xd9, 0xfa, 0x0f, 0xe0,
	0xf4, 0xe5, 0xf4, 0xee, 0x71, 0x5c, 0xe8, 0xb5, 0xbc, 0xa1, 0x3b, 0xbf,
	0xb6, 0xa8, 0x1f, 0x82, 0x60, 0x9a, 0xfd, 0x85, 0x6d, 0x71, 0xcf, 0xe0,
	0xf6, 0x96, 0x18, 0xd0, 0x90, 0x27, 0xb0, 0x84, 0x0c, 0xa4, 0x72, 0x7e,
	0x00, 0x5a, 0x33, 0xbd, 0xfc, 0x6e, 0x7c, 0xb2, 0x16, 0x9b, 0x34, 0x76,
	0x35, 0x31, 0xfb, 0xa2, 0xa3, 0xcb, 0x82, 0x99, 0x61, 0x9a, 0x69, 0xf1,
	0xc1, 0x1a, 0x75, 0xce, 0xbe, 0xe8, 0x4c, 0xbf, 0x42, 0x7f, 0x7c, 0x3e,
	0xee, 0xf8, 0xf0, 0x04, 0x93, 0x24, 0x7b, 0xc8, 0x56, 0x76, 0x6a, 0xf9,
	0x41, 0xec, 0x92, 0xa2, 0x87, 0xfc, 0x93, 0x48, 0x16, 0x09, 0x16, 0xd4,
	0xf1, 0x62, 0x93, 0x33, 0xe2, 0x0f, 0x72, 0xd0, 0x07, 0x62, 0xd4, 0x9a,
	0x87, 0x4f, 0x62, 0xdd, 0xc6, 0xcc, 0xd6, 0x07, 0xb9, 0x68, 0xaa, 0x40,
	0x64, 0x3d, 0x88, 0x7a, 0x46, 0x9f, 0x4f, 0x37, 0x01, 0xe2, 0x6b, 0xe3,
	0xf2, 0xdd, 0xb3, 0xf9, 0x3f, 0x88, 0x94, 0xc6, 0xd7, 0xf6, 0xa3, 0x9d,
	0xc3, 0x79, 0xa5, 0x7c, 0xe2, 0x4f, 0xbc, 0x46, 0x8c, 0x44, 0xc1, 0xd3,
	0xe3, 0x10, 0x0a, 0xe5, 0xf2, 0x75, 0xc8, 0xe4, 0x52, 0x7c, 0xde, 0x92,
	0x04, 0x72, 0x58, 0xdb, 0x68, 0xfc, 0x79, 0x2b, 0x75, 0x1e, 0xa7, 0x57,
	0x6d, 0x63, 0x9e, 0xf9, 0xa8, 0x5f, 0xcc, 0x8b, 0x6f, 0xd7, 0x70, 0x61,
	0x4c, 0x39, 0x46, 0x9f, 0xb5, 0x24, 0x31, 0xb9, 0x96, 0x89, 0x94, 0xfe,
	0x85, 0x0d, 0x2a, 0xfb, 0x2b, 0xd1, 0x52, 0x98, 0x35, 0xf0, 0x92, 0xdd,
	0x4f, 0x5e, 0x68, 0xbe, 0x35, 0xd9, 0x20, 0x82, 0x12, 0x66, 0x21, 0xc7,
	0x8a, 0x52, 0x80, 0x20, 0xdb, 0x14, 0x1e, 0x61, 0x22, 0x48, 0x5c, 0x4d,
	0x1a, 0xae, 0xe6, 0x4f, 0x9f, 0x78, 0x2c, 0xee, 0xd6, 0x94, 0xad, 0x0c,
	0x6d, 0xcd, 0x8e, 0x7f, 0x33, 0xaf, 0x46, 0xbd, 0x01, 0xc6, 0xdd, 0xdc,
	0xdb, 0xfb, 0x3d, 0xfd, 0x44, 0x99, 0x4a, 0x5e, 0x48, 0x30, 0xad, 0xe7,
	0xa8, 0xd9, 0xd5, 0x7f, 0x6d, 0x82, 0x8b, 0xdb, 0x4f, 0x19, 0x5a, 0x82,
	0xc8, 0xa1, 0x3f, 0xc9, 0x67, 0x1c, 0xa5, 0x42, 0x18, 0xe3, 0x3f, 0x5c,
	0x7c, 0x8a, 0xba, 0xc4, 0xba, 0x67, 0xab, 0x63, 0x40, 0x81, 0xe2, 0xad,
	0x03, 0x6d, 0x88, 0x53, 0x86, 0xe3, 0xd5, 0x4e, 0x84, 0x15, 0x17, 0xeb,
	0x31, 0xbc, 0x2e, 0x49, 0x9f, 0x6d, 0xa5, 0x1c, 0xf7, 0x5f, 0xe0, 0xb2,
	0xc6, 0x8c, 0x15, 0x06, 0x0d, 0xf7, 0xb4, 0x10, 0x64, 0x3c, 0x63, 0xea,
	0x1f, 0x39, 0x38, 0xa3, 0x4e, 0x4f, 0x8f, 0x7f, 0x0b, 0xbd, 0xc9, 0xab,
	0x2a, 0x6e, 0xc7, 0x22, 0xce, 0xa7, 0xd4, 0x94, 0x33, 0xe9, 0x9b, 0x40,
	0xe0, 0x4f, 0x51, 0x44, 0x8b, 0xb4, 0x2e, 0xab, 0xed, 0x66, 0x4e, 0x3b,
	0xb5, 0xdd, 0xbb, 0xc0, 0x9a, 0x84, 0x6b, 0xc5, 0xf2, 0x32, 0xe7, 0xc0,
	0xda, 0xbb, 0x55, 0x0d, 0xa4, 0xf0, 0x4e, 0x84, 0x3f, 0x9f, 0xc8, 0xca,
	0x53, 0xf6, 0x75, 0x41, 0x5c, 0xc4, 0x7c, 0x11, 0xa1, 0x37, 0xd1, 0x3c,
	0xbb, 0x3d, 0x01, 0xae, 0x6f, 0xe8, 0x6e, 0x49, 0xa3, 0xc3, 0x57, 0x47,
	0xb3, 0xa5, 0xcb, 0xf2, 0x44, 0x93, 0xbd, 0x97, 0x89, 0x32, 0xd8, 0xe5,
	0xf6, 0x55, 0xf6, 0x98, 0x8c, 0xc7, 0xd4, 0x48, 0x04, 0xd5, 0xf6, 0x74,
	0xbd, 0x64, 0xbd, 0x60, 0x28, 0x14, 0xa7, 0xdb, 0xb9, 0x72, 0xce, 0xfd,
	0x05, 0x8b, 0x95, 0x8e, 0xbd, 0x6d, 0x73, 0xb4, 0xc2, 0x69, 0x4c, 0x4f,
	0x30, 0x20, 0x97, 0x35, 0xf5, 0x8d, 0xa9, 0xb2, 0xf1, 0x66, 0x12, 0x19,
	0x7b, 0xb9, 0xf5, 0x34, 0x2b, 0xc3, 0x32, 0x30, 0x4e, 0xc7, 0xbe, 0x0b,
	0x34, 0x31, 0xbf, 0xf7, 0x9a, 0x0b, 0x46, 0xca, 0x2b, 0xdd, 0xff, 0x20,
	0x6a, 0xa8, 0xd2, 0x5b, 0x0f, 0xe4, 0x75, 0x8a, 0x9d, 0x6a, 0xbe, 0xc8,
	0x2d, 0xf0, 0xf8, 0x7b, 0xb7, 0xb6, 0x86, 0xec, 0xe7, 0x46, 0xe3, 0x81,
	0x51, 0x29, 0x4c, 0x7d, 0x06, 0x4b, 0x9d, 0x70, 0xf4, 0x70, 0xcb, 0x03,
	0x54, 0x40, 0x8d, 0xf2, 0xaa, 0x4b, 0xba, 0xd7, 0x3c, 0xb3, 0x52, 0xf3,
	0x69, 0xd9, 0xdf, 0x51, 0x1f, 0xc2, 0xd2, 0x70, 0xeb, 0x1e, 0xed, 0xf1,
	0x6a, 0x8b, 0x61, 0x5e, 0xfb, 0x2d, 0x61, 0x4f, 0x6d, 0xee, 0x41, 0x18,
	0x39, 0xfc, 0xef, 0x75, 0xaf, 0x42, 0x69, 0x18, 0x1b, 0x48, 0x69, 0x3a,
	0x0b, 0x3c, 0xaa, 0xf6, 0x5a, 0x98, 0xe8, 0xc4, 0x23, 0x49, 0x22, 0x1e,
	0x76, 0x83, 0x6d, 0xe4, 0x71, 0xaf, 0xfc, 0xab, 0xab, 0xeb, 0x20, 0x5a,
	0x2d, 0x89, 0x72, 0x48, 0xd2, 0xdc, 0x82, 0xdd, 0x18, 0x2d, 0xd3, 0x72,
	0xc5, 0xbb, 0x37, 0xe8, 0x05, 0x59, 0x06, 0x7b, 0xdd, 0x73, 0x5f, 0x4e,
	0x22, 0x5b, 0xf9, 0xcd, 0x47, 0x1a, 0x27, 0x74, 0xa3, 0x9a, 0xbd, 0x75,
	0x76, 0x3f, 0x52, 0x8e, 0x6c, 0x26, 0x00, 0x31, 0xe1, 0x37, 0x19, 0xe6,
	0x91, 0x1f, 0x62, 0x6e, 0x93, 0xc1, 0xbc, 0xb5, 0x1d, 0xb6, 0x83, 0x64,
	0xd0, 0xaa, 0xd8, 0x73, 0x44, 0x95, 0xe9, 0xba, 0xd5, 0x3b, 0x48, 0x41,
	0x61, 0x49, 0x73, 0x43, 0x80, 0x8c, 0x29, 0x11, 0xac, 0x8b, 0x7f, 0x3f,
	0x4d, 0x3c, 0xf4, 0x6a, 0xf2, 0x77, 0xce, 0xc2, 0x22, 0xa6, 0x35, 0x66,
	0x3c, 0x1e, 0x21, 0x11, 0x5a, 0x69, 0x52, 0xbb, 0xb2, 0xc5, 0xfe, 0x33,
	0x52, 0x28, 0x44, 0xfe, 0xb3, 0xc4, 0x3d, 0x00, 0x00, 0x31, 0x6a, 0xf2,
	0xa9, 0x38, 0xb4, 0xcb, 0xdf, 0xe9, 0x31, 0x1b, 0x08, 0x52, 0x2c, 0x62,
	0xbc, 0x7e, 0x1d, 0x6e, 0x44, 0x1c, 0xa1, 0x96, 0x44, 0xe6, 0x94, 0xf7,
	0xaa, 0xd1, 0xf8, 0xaa, 0x02, 0x62, 0x9c, 0xab, 0x9b, 0x50, 0x76, 0x7a,
	0x39, 0xa8, 0x95, 0x41, 0xfa, 0xc1, 0xa3, 0xb6, 0x3f, 0xc1, 0x25, 0x83,
	0xdd, 0xc6, 0x19, 0x21, 0xac, 0xad, 0x18, 0x56, 0x7e, 0x10, 0x00, 0x81,
	0x73, 0x9c, 0x2c, 0x0e, 0xec, 0xa3, 0x88, 0x26, 0x4b, 0x1d, 0x67, 0x45,
	0xde, 0x0b, 0xfc, 0x1d, 0xcc, 0x21, 0xa1, 0xa9, 0xe7, 0xba, 0xca, 0x94,
	0x68, 0xe2, 0xea, 0xe6, 0xf3, 0xeb, 0x67, 0x66, 0x87, 0x94, 0x74, 0x74,
	0x37, 0xfc, 0x9a, 0x82, 0x19, 0x01, 0xc7, 0xf7, 0x0c, 0xc3, 0x14, 0xd8,
	0xe4, 0xb5, 0x81, 0xcc, 0x70, 0x4b, 0x60, 0xd8, 0x2e, 0x4a, 0xbe, 0x21,
	0x35, 0x26, 0x87, 0xbd, 0xba, 0xfb, 0x31, 0xf1, 0xf7, 0xcb, 0x73, 0x10,
	0xcc, 0x3a, 0x07, 0xd9, 0xfe, 0x1b, 0xb1, 0xe2, 0xd1, 0x33, 0xae, 0x41,
	0x7e, 0x0e, 0x19, 0xac, 0x59, 0xd7, 0xcd, 0x8e, 0xfd, 0x54, 0x4b, 0xb7,
	0x4f, 0x7c, 0xa8, 0x46, 0x47, 0x1b, 0x56, 0x14, 0x56, 0x5d, 0xed, 0x54,
	0x79, 0x9e, 0x36, 0x4a, 0xd1, 0xe5, 0x8b, 0x50, 0xf3, 0xa4, 0xfc
};

size_t defpatsz = sizeof(defpat);

/* TestPat is set to deftest during fx startup */
unsigned char   DefTestPat[MAX_TESTPAT];
unsigned char   *TestPat;

/*
 * compute next block number for sequential exercise 
 */
void
seqstepper(void)
{
	E.curbn += E.rsize;
}

/*
 * sequential exercise 
 */
void
sequential_func(void)
{
	exargs();
	E.stepper = seqstepper;
	(void)exrun();
}

/*
 * compute next block number for butterfly exercise 
 */
void
bflystepper(void)
{
	E.curbn = E.lastbn - (E.curbn - E.firstbn);
	if (E.curbn >= (E.lastbn + E.firstbn) / 2)
		E.curbn -= E.rsize;
}

/*
 * butterfly exercise 
 */
void
butterfly_func(void)
{
	exargs();
	E.stepper = bflystepper;
	(void)exrun();
}

/*
 * random number generator 
 * The old one was *very* non-random with some values (a range of 500000
 * passed to genrand 100000 times generated 38 unique numbers!)
 * Now we use the random() function from BSD, with the defaults
 */
static int
genrand(long range)
{
	if (range <= 0)
		return 0;
	return random() % range;
}

/*
 * compute next block number for random exercise 
 */
void
randstepper(void)
{
	E.curbn = E.firstbn + genrand(E.lastbn - E.firstbn);
}

/*
 * random exercise 
 */
void
random_func(void)
{
	exargs();
	E.stepper = randstepper;
	(void)exrun();
}

/*
 * complete exercise 
 */
void
complete_func(void)
{
	completeargs();
	E.stepper = seqstepper;
	if(exrun()) {
		E.stepper = bflystepper;
		E.aflag = 1;
		exrun();
	}
	/* else aborted */
}

/*
 * get arguments for complete exercise 
 */
void
completeargs(void)
{
	E.modifier = MXC | MXW;
	if(nomenus)
	    E.aflag = 1;
	else
	    checkflags("a", &E.aflag);
	E.firstbn = 0;
	E.lastbn = E.firstbn + exarea(E.firstbn);
	E.passes = 1;

	switch (drivernum) {
#ifdef SMFD_NUMBER
	case SMFD_NUMBER:
		E.rsize = 16;	/* arbitrary, but "small"; some "floppies"
			aren't, but that's OK, they are still small */
		break;
#endif /* SMFD_NUMBER */
	case SCSI_NUMBER:
		E.rsize = 256;	/* arbitrary, but "large" */
		break;

	default:
		printf("Don't know how to exercise disk for driver type %u\n",
			drivernum);
		return;
	}
	argcheck();
}

uint ebwidth = 35;

/* ix not used, but colprint passes it */
/*ARGSUSED*/
static void
ebsub(int ix, struct err *t, char *tgt)
{
	{
		sprintf(tgt, "%llu r%u(%u) w%u(%u)",
			t->bn,
			t->hits[0], t->hits[1],
			t->hits[2], t->hits[3]);
	}
}

/* print the error log */
void
printerr(void)
{
	fxsort((char *) E.eb, E.neb, sizeof *E.eb, errcompar);
	setoff("error summary");
		printf("(bn) ");
	printf(" rretries(rfail) wretries/wfail\n");
	colprint(E.eb, E.neb, sizeof *E.eb, ebwidth, ebsub);
}


/*
 * sort the error log 
 */
static
errcompar(const void *a, const void *b)
{
	return ((struct err *)a)->bn - ((struct err *)b)->bn;
}
/*
 * menu item to manage the error log 
 */
void
errlog_func(void)
{
	checkflags("il", &E.iflag);
	if (E.lflag)
		printerr();
	errlog_summary();
	if (E.iflag)
		E.neb = 0;
}


/*
 * toggle between stopping on errors, or doing the 'normal'/old
 * behavior of sparing and continuing. 
 */
void
stop_on_error_func(void)
{
	stop_on_err = !stop_on_err;
	printf("Will %sstop on errors\n", stop_on_err ? "" : "not ");
}


/*
 * toggle between showing diffs on miscompares, or just reporting it
 * and retrying.
 */
void
miscompares_func(void)
{
	showdiffs = !showdiffs;
	printf("Will %sshow differences on miscompares\n", showdiffs ? "" : "not ");
}


/* ----- */
/* ----- testpat subroutines ----- */
/*
 * menu item to interactively change the test pattern 
 */
void
settestpat_func(void)
{
	uint val;
	register i;
	printf("Enter .. to finish; CR keeps current value\n");
	for(i = 0; i < MAX_TESTPAT;) {
		argnum(&val, (uint)DefTestPat[i], 0x100, "value");
		DefTestPat[i++] = val;
		/* has to be inside loop, because loop is exitted via .. */
		SetTestPat(DefTestPat, i);
	}
}
/*
 * menu item to print the current test pattern 
 */
void
showtestpat_func(void)
{
	register int    n;
	argcheck();
	printf("test pattern:");
	for (n = 0; n < TestCycle; n++) {
		if((n%0x18) == 0)
			printf("\n%3x: ", n);
		printf(" %02x", TestPat[n]);
	}
	newline();
}


/*
 * initialize exercise globals 
 */
void
init_ex(void)
{
	bzero((char *) &E, sizeof E);
	SetTestPat(defpat, defpatsz);
	bcopy(defpat, DefTestPat, sizeof defpat);
}

/*
 * get arguments for sequential, random, and butterfly exercises 
 */
ITEM            exmod_items[] =
{
 {"rd-only", 0, 0},
 {"ro-cmp", 1, 0},
 {"seek", 2, 0},
 {"wr-only", 3, 1},
 {"wr-cmp", 4, 1},
 {0}
};


MENU            exmod_menu = {
			      exmod_items, "exercise modifiers"};
char            exmod_bits[] = {
			   MXR, MXC | MXR, MXS | MXR, MXW, MXC | MXW};
void
exargs(void)
{
	daddr_t         startbn, nblocks, lastbn;
	uint             nscans, defscans;
	int             n;

	checkflags("a", &E.aflag);
	argchoice(&n, 0, &exmod_menu, "modifier");
	E.modifier = exmod_bits[n];
	defscans = 1;

	switch (drivernum) {

#ifdef SMFD_NUMBER
	case SMFD_NUMBER:
		E.rsize = 16;	/* arbitrary, but "small"; some "floppies"
			aren't, but that's OK, they are still small */
		break;
#endif /* SMFD_NUMBER */
	case SCSI_NUMBER:
		E.rsize = 256;	/* arbitrary, but "large" */
		break;

	default:
		printf("Don't know how to exercise disk for driver type %u\n",
			drivernum);
		return;
	}

	/* used to calculate lastbn here, but that could be larger than
	 * what exarea returns, leading to case where we accept a larger
	 * max value for starting block than number of blocks.  So just
	 * use exarea to get lastbn.  Also, start block has to be at least
	 * 1 less than lastblock for there to be anything to do...
	*/
	lastbn = exarea(0);
	argbn(&startbn, (daddr_t) 0, lastbn-1, "starting block#");
	nblocks = lastbn - startbn;
	argbn(&nblocks, nblocks, nblocks + 1, "nblocks");
	argnum(&nscans, defscans, 1000000, "nscans");
	argcheck();
	E.firstbn = startbn;
	E.lastbn = startbn + nblocks;
	E.passes = nscans;
	if (!(E.modifier & (MXR | MXW | MXS)))
		E.modifier = MXR | MXW;
	if (E.modifier & MXS)
		E.modifier = (MXR | MXS), E.rsize = 1;
}

/*
 * run an exercise, called from main exercise routines. 
 * return 1 if all OK, 0 if it was aborted.
 */
static int
exrun(void)
{
	int passno;

	(void) setintr(1);
	if ((E.modifier & MXW) && !E.aflag)
		lastchance();

	/* allow for an interrupted exercise pass */
	if(extrack) free(extrack);
	if(chktrack) free(chktrack);

	E.bufsize = E.rsize * DP(&vh)->dp_secbytes;
	E.buf = extrack = malloc(E.bufsize);
	if(!extrack) {
		printf("Can't allocate memory for i/o buffer\n");
		return 0;
	}
	if(E.modifier & MXC) {
		chktrack = malloc(E.bufsize);
		if(!chktrack) {
			printf("Can't allocate memory for comparison buffer\n");
			return 0;
		}
	}
	exercising = 1;

	for (passno = 0; passno < E.passes; passno++) {
		printf("%s ", (E.stepper == seqstepper ? "sequential" :
		(E.stepper == bflystepper ? "butterfly" : "random")));
		/* casts necessary because 32 bit standalone has 32 bit
		 * daddr_t; See bug #524200. */
		printf("pass %d: scanning [%llu, %llu]",
			passno+1, (long long)E.firstbn, (long long)E.lastbn);
		if(drivernum == SCSI_NUMBER)
			printf(" (%lld blocks)", (long long)(E.lastbn-E.firstbn));
		printf("\n");
		SetTestPhase(passno);
		TestPatFill(E.buf, E.bufsize);
		E.phase = passno;
		E.curbn = E.firstbn;
		if (scanpass())
			break;	/* user abort, etc.  */
		if (E.neb > 0)
			errlog_summary();
	}
	exercising = 0;
	if(chktrack) free(chktrack);
	free(extrack);
	extrack = chktrack = 0;
	return passno == E.passes;	/* if not equal, we aborted */
}


/* progress report, for exercising.  print a numeric value for every
 * dotnumfreq dots, and a dot for every percent.
 *
 * For some i/o size vs total combos, we may be doing more than 1% / call
 * (currently this happens for floppies, and disks of less than 12.8MB (yeah,
 * right...), and also if only a small section of the disk is being exercised.
 * For these cases, we simply print fewer than 100 dots, and possibly not
 * all the 10% numerics.  The "last10" hack helps this a bit.
 *
 * totsectors is only used on initialization call.
*/

static void 
dot(uint sectors, uint totsectors)
{
    static uint ncols, curcol, pctintvl, lastpct, runtotal;
	uint last10;

    if(!sectors) { /* initialize */
	runtotal = lastpct = 0;
	pctintvl = (99+totsectors)/100;
	/* -1 because some terminals wrap at last column
	 * don't worry about it changing during the run. */
	ncols = getscreenwidth() - 1;
	printf("0%%");
	flushoutp();
	curcol = 2;
	return;
    }
    else if( sectors == (uint)-1) {	/* end of pass */
	if(lastpct != 100) {
		if((curcol+5) >= ncols)
			newline();
		printf(" 100%%");
	}
	newline();
	return;
    }

    runtotal += sectors;

    last10 = lastpct/10;
    if((runtotal/pctintvl) > lastpct) {
    	lastpct = (runtotal/pctintvl);
	if(++curcol >= ncols) {
	    newline();
	    curcol = 0;
	}
	printf(".");
	if(last10 != (lastpct/10)) {
	    char nbuf[5];
	    size_t slen;

	    sprintf(nbuf, "%u%%", lastpct);
	    slen = strlen(nbuf);
	    curcol += slen;
	    /* if window is really small, don't do extra newline */
	    if(curcol >= ncols && slen < ncols) {
		newline();
		curcol = slen-1;
	    }
	    printf("%s", nbuf);
	}
	flushoutp();
    }
}

/*
 * do one pass of an exercise Keep track of consecutive errors; if we
 * see a number of sequential errors it's likely that there's a drive
 * hardware problem.  Used to check for more than a cyls worth, but that
 * doesn't work well on SCSI where we do a cyl at a time, or on drives
 * with a small number of heads.
 * Warn the user & give a chance to abort. To that end, return 0
 * normally, 1 if aborting. 
 */
scanpass(void)
{
	int steps, sectors, userabort;
	int consec_errs=0;

	dot(0, E.lastbn - E.firstbn);
	sectors = E.rsize;
	for (steps = (E.lastbn - E.firstbn + E.rsize - 1) / E.rsize; --steps >= 0;) {
		dot(sectors,0);
		if(drivernum == SCSI_NUMBER && E.stepper == randstepper) {
			/* SCSI does cyl at a time i/o; which means it doesn't
			 * do as many random seeks as non-SCSI.  To enhance the
			 * randomness, we therefore do a random number of
			 * sectors, and select a new base block each time.
			 * May not due quite as many blocks of i/o if many
			 * errors, but doesn't much matter in that case.
			 * Done here so instead of change E.rsize so that
			 * we still get one '.' per "cylinder" of i/o. */
			 int rsecs, secs;
			 for(rsecs=sectors; rsecs>0; rsecs-=secs) {
				secs = genrand(sectors);
				if(secs == 0)
					secs = 1;
				if(secs > rsecs)
					secs = rsecs;
				if((E.curbn+secs) > E.lastbn)
					secs = E.lastbn-E.curbn;
				if(secs && (userabort = scanchunk(E.curbn, secs)))
					break;
				consec_errs = 0;
				randstepper();
			}
		}
		else {
			int secs = sectors;
			/* can't change 'sectors', or dot() gets wrong arg
			 * when doing random i/o (or perhaps butterfly in some
			 * cases); that mess up the cylno we print */
			if((E.curbn+secs) > E.lastbn)
				secs = E.lastbn-E.curbn;
			userabort = scanchunk(E.curbn, secs);
		}
		if(userabort) {
			if (userabort == -1)
				return 1;
			if((E.modifier & MXW) && errno == EROFS)
				return 1;	/* don't retry! */
			if(++consec_errs >= TOOMANYCONSEC) {
				printf("\nNotice: %d consecutive errors detected.\n",
					consec_errs);
				printf("Suspect hardware problems with the drive.\n");
				if (no("Continue exercising"))
					return 1;
				consec_errs = 0;	/* restart count */
			}
		}
		else
			consec_errs = 0;
		(*E.stepper) ();
	}
	dot(-1, 0);
	return 0;
}

/*
 * do one chunk of an exercise, and find bad sectors if any.
 * Return 0 if no error, 1 if any error.  If sparing, retry
 * the chunk to be sure it worked; return failure even if it
 * worked on the retry for the consecutive error checks in scanpass().
 */
static
scanchunk(daddr_t bn, int sectors)
{
	int i, gotone=0, savesectors, savebn;
	int cmperr;

retry:
	if((cmperr=rwcheck(bn, sectors)) == 0)
		return gotone;

	if((E.modifier & MXW) && errno == EROFS)
		return 1;	/* don't try to find error or spare */

	/*
	 * If we got an error on the track, try up to ioretries
	 * times to find the bad sector.  We do this because some
	 * errors are so 'soft', that we can get track errors, but not
	 * find an error on the individual sector with only one
	 * attempt.  Don't stop after first one, in case multiple sectors
	 * are bad.
	 */
	savesectors = sectors;
	savebn = bn;
	scerrwarn("%s in chunk starting at block %d,\n"
		"	looking for failing block(s) sector by sector",
		cmperr==1?"miscompare":"read error", bn);

	for(i=0; i < ioretries; i++) {
		for(sectors=savesectors, bn=savebn; --sectors >= 0; bn++) {
			if (rwcheck(bn, 1) < 0) {
#ifdef SMFD_NUMBER	/* don't even try on floppy */
				if (drivernum != SMFD_NUMBER)
#endif /* SMFD_NUMBER */
				{
					if (stop_on_err) {
				/* casts necessary because 32 bit standalone has 32 bit
				 * daddr_t; See bug #524200. */
						printf("Error at block %lld, ",
							(long long)bn);
						if (no("Continue exercising"))
							return -1;
						if (no("Add to badblock list"))
							return 1;
					}
					if(addibb(bn))
						return -1;	/* abort */
					if(++gotone < TOOMANYCONSEC) {
						bn = savebn;
						goto retry;	/* re-check after sparing */
					}
					return 1;
				}
			}
		}
	}

	if (!gotone)
		scerrwarn("Couldn't find bad block after %d tries,\n%s\n", i,
			cmperr==1?"soft error or possibly a live filesystem" :
			"probable soft error");
	return gotone;
}

/*
 * one chunk of an exercise, unadorned 
 */
int
rwcheck(daddr_t bn, uint sectors)
{
	if (E.modifier & MXW) {
		if (gwrite(bn, E.buf, sectors) < 0)
			return -1;
	} else if (E.modifier & MXR) {
		if (gread(bn, E.buf, sectors) < 0)
			return -1;
	}
	if (E.modifier & MXC) {
		if (gread(bn, chktrack, sectors) < 0)
			return -1;

		if (bcmp(chktrack, E.buf, stob(sectors)) != 0) {
			errno = 0;	/* make sure no bogus message printed */
			errwarn("data mismatch, start block %d", bn);
			if(showdiffs)
				showdiff(E.buf, chktrack, sectors);
			else
				printf("\n");
			logmsg("data mismatch, start block %d, %d sectors read\n",
				bn, sectors);
			return 1;	/* so can tell difference from error */
		}
	}
	return 0;
}

static void
showdiff(unchar *dbuf, unchar *cmpbuf, uint cnt)
{
	int errs = 0, maxerrs=stob(1);
	register        i;

	printf("\ncompared 0x%x sectors, differences are (in hex, as:  byteoffset: expected, got):\n", cnt);
	cnt = stob(cnt);
	for (i = 0; i < cnt && errs < maxerrs; i++) {
		/* print only first few lines of diffs */
		if (*dbuf != *cmpbuf) {
			printf("%x: %02x - %02x  ", i, *dbuf, *cmpbuf);
			if ((++errs % 5) == 0)
				printf("\n");
		}
		dbuf++, cmpbuf++;
	}
	if (errs % 5)
		printf("\n");
	if(errs == maxerrs)
		printf("only first %d errs were shown\n", maxerrs);
	else
		printf("%d bytes were different\n", errs);
}

/* ----- error logging routines ----- */
/* error flags */
# define EH	01	/* hard error (as opp to recovered error) */
# define EW	02	/* write error (as opp to read error) */
/*
 * add to the error log 
 */
void
adderr(int drive, daddr_t bn, char *s)
{
	register int    i;
	register struct err *ep;
	for (ep = E.eb, i = E.neb; --i >= 0; ep++)
		if (ep->bn == bn && ep->drive == drive)
			break;
	if (i < 0) {
		if (E.neb >= MAX_ERRBLOCKS)
			return;
		ep = E.eb + E.neb++;
		ep->bn = bn;
		ep->drive = drive;
		ep->hits[0] = ep->hits[1]
			= ep->hits[2] = ep->hits[3] = 0;
	}
	i = 0;
	if (s[0] == 'h')
		i |= EH;
	if (s[1] == 'w')
		i |= EW;
	ep->hits[i]++;
}

void
errlog_summary(void)
{
	register int    i;
	register struct err *ep;
	struct err      e;
	bzero((char *) &e, sizeof e);
	ep = E.eb;
	for (i = E.neb; --i >= 0;) {
		if (ep->hits[0])
			e.hits[0]++;
		if (ep->hits[1])
			e.hits[1]++;
		if (ep->hits[2])
			e.hits[2]++;
		if (ep->hits[3])
			e.hits[3]++;
		ep++;
	}
	printf("TOTAL ERR BLOCKS r%u(%u hard) w%u(%u hard)\n",
		e.hits[0], e.hits[1],
		e.hits[2], e.hits[3]);
}

void
SetTestPat(unchar *s, int n)
{
	TestPat = s;
	TestCycle = n;
}

int
SetTestPhase(int x)
{
	return TestPhase = x;
}


# define BumpTestPat()	((TestPhase>=TestCycle?(TestPhase=0):0) \
	, TestPat[TestPhase++])

void
TestPatFill(unchar *buf, int len)
{
	while (--len >= 0)
		*buf++ = BumpTestPat();
}
