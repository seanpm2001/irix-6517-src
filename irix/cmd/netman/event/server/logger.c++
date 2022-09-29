/*
 * logger.c++ -- implementation of event daemon class that manages
 *		 logging and the event log.
 * 
 * $Revision: 1.5 $
 */
 
/*
 * Copyright 1992 Silicon Graphics, Inc.  All rights reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics, Inc.;
 * the contents of this file may not be disclosed to third parties, copied or
 * duplicated in any form, in whole or in part, without the prior written
 * permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to restrictions
 * as set forth in subdivision (c)(1)(ii) of the Rights in Technical Data
 * and Computer Software clause at DFARS 252.227-7013, and/or in similar or
 * successor clauses in the FAR, DOD or NASA FAR Supplement. Unpublished -
 * rights reserved under the Copyright Laws of the United States.
 */
 
extern "C" { 
#include <unistd.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <syslog.h>
#include <time.h>
};
#include <osfcn.h>
#include "event.h"
#include "daemonName.h"
#include "server.h"
#include "logger.h"
#include "cfg.h"

extern "C" {
#include "eventStrings.h"
void syslog (int p, const char *m, ...);   
};

extern EV_cfg *cfg;

/*
 * EV_logger::EV_logger - instantiate the event logger function of the server
 * 
 * Arguments are the maximum size a log can grow to, the number of logs there
 * can be, and the logfilename to use.
 * 
 * WARNING if EV_MAX_NUM_LOGS ever goes beyond 10, this will need to be 
 * changed. SUFFIX_LEN and the routine for generating names must change to
 * reflect double digit suffixes.
 */
EV_logger::EV_logger(int logSize, int numLogs, const char *logfilename) {

#define SUFFIX_LEN 2

    char suffix [SUFFIX_LEN + 1];

    
    suffix[0] = '.';			        /* the separator */
    suffix[2] = '\0';			        /* NULL terminate */
    
    log = 0;				        /* init FILE * */
    currsize = 0;			        /* init size of log */
    
    /*
     * flushcnt is used to determine how often to force the log buffer to
     * disk. The value 1 flushes each record. Buffering would be more
     * efficient,  but I don't know a good value yet.
     */
       
    flushcnt = 1;   // XXXX This will be a parameter in the future

    /*
     * sanity check the arguments
     */
    if (logSize > 0 && logSize <= EV_MAX_LOG_SIZE) {
	logsize = logSize;
    }
    else {
	logsize = EV_LOG_SIZE;
    }
    
    if (numLogs > 0 && numLogs < EV_MAX_NUM_LOGS) {
	numlogs = numLogs;
    }
    else {
	numlogs = EV_NUM_LOGS;
    }
    
    if (!logfilename || (strlen (logfilename) > (MAXPATHLEN - SUFFIX_LEN))) {
	logFileNames[0] = new char [strlen(EV_LOGFILE_NAME) + 1];
    }
    else { 
	logFileNames[0] =   new char [strlen(logfilename) + 1];
	strcpy(logFileNames[0], logfilename);
    }
    
    /*
     * Logfile names are generated by adding suffixes of .<n> to the name
     * passed in. 
     * Note that if we go to double digit suffixes, this will
     * break.
     */
    for (int i = 1; i < numlogs; i++) {
	logFileNames[i] = new char [strlen(logfilename) + 
				    SUFFIX_LEN + 1];
	strcpy (logFileNames[i], logfilename);
	suffix[1] = i + '0';
	strcat (logFileNames[i], suffix);
    }
    
}

EV_logger::~EV_logger(void) {
    syslog(LOG_INFO, "EV_logger::~EV_logger");
}

/*
 * EV_logger::openLog -- open the eventlog file
 * 
 * returns EV_OK if successful,  -1 otherwise. Note that the FILE *log
 * is NULL if the open fails.
 * 
 * This function only opens THE eventlog file. It handles existing files, 
 * full files,  empty files,  and non-existent files.
 */
EV_stat
EV_logger::openLog(void) {

    struct stat fstats;

    if (stat(logFileNames[0], &fstats) == 0) {  /* does it exist */
    
	// log exists. See if its full
	
	/*
	 * the test is a guess since the st_size is in bytes.
	 * My idea of size is number of records. This is a conservative
	 * test since there will be few records of maximum size.
	 */
	if (fstats.st_size >= (EV_MAX_LOG_REC_SIZE * logsize)) {	    
	    cycleLogs();
	}	
	else {
	    currsize = (int) (fstats.st_size / EV_MAX_LOG_REC_SIZE);
	}
    }
    
    // Using stream I/O, append only access.
    if (! (log = fopen(logFileNames[0], FILE_OPEN_TYPE_APPEND))) {
	syslog(LOG_ERR, "EV_logger::EV_logger cannot open log file: %m");
	return (-1);	
    }
    else {
	EV_event *ep = new EV_event(NV_LOG_START);
	ep->srcApp = strdup (eventDaemon);
	ep->pid = getpid();
	ep->timeSent = (time ((time_t *)NULL));
	ep->setOtherData("**********");
	logit(ep);
	delete (ep);
	return(EV_OK);
    }
}

/*
 * EV_logger::cycleLogs -- called to move event logs to an older ones
 * 
 * Treats the list of log files as a list of pointers in a circular
 * buffer. It removes the oldest file and then renames all the other ones, 
 * "aging" them in the process. The rename function will delete an existing
 * file. This is why it works.
 */
void
EV_logger::cycleLogs(void) {

    for (int i = numlogs - 2 ; i >= 0; i--) {
	if (rename(logFileNames[i], logFileNames[i+1])) {
	     // can't make the logfile logfile.old; simply truncate
	     syslog(LOG_ERR, 
		"EV_logger::EV_logger cannot move old to new: %s, %s:%m", 
		 logFileNames[i], logFileNames[i+1]);
	}
    }
    
}

/*
 * EV_logger::logit - put an event in the event log
 */
void
EV_logger::logit (EV_event *ep) {
    char logbuf [EV_MAX_LOG_REC_SIZE + 1];
  
    if (! ep) {
	return;
    }
    
    if (currsize >= logsize) {		        /* test if log is full */
	currsize = 0;			        /* size for new log file */
	cycleLogs();			        /* get the next log file */
	if (openLog() == -1) {		        
	    syslog (LOG_ERR, "EV_logger::logit cannot open log file.");
	    return;
	}
    }
    if (log != NULL) {	    /* always test here for valid FILE for the log*/
	logrec.format (ep, logbuf);	        /* format the event */
	if (fputs(logbuf, log) != EOF) {        /* put it the stream */
	    currsize++;			        /* new logsize */
	    fputc('\n', log);		        /* add newline */
	    if (! (currsize % flushcnt) ) {     /* to disk if time */
		fflush(log);
	    }
	}
	else {				        /* unexpected error */
	    syslog(LOG_ERR, "EV_logger::logit: fputs: %m");
	}
	
	
    }
}

/*
 * EV_logrec::format --  formats an eventlog record into a buffer from the
 *			 event passed to it.
 * 
 */
void
EV_logrec::format (EV_event *ep, char *logbuf) {
    /*
     * XXXX
     * In its final incarnation this function will use the EV_cfg info about the
     * event format. Right now I'll do it manually.
     */
	   
    int buflen = 0;			        /* total length */
    char *bufptr;			        /* where in buffer */
    char itembuf[EV_MAX_LOG_REC_SIZE];	        /* tmp buf for formatting */
    int itemlen;			        /* length of this item */
    char tbuf[28];			        /* buffer for time string */
    EV_timeStamp ts;			        /* the timestamp in event */
    eventID etype;			        /* the even type in event */
    
/*
 * This define adds an "item" to the eventlog record buffer.
 * It first checks to see if a string format item is NULL.
 * If it is it does not add it to the record. This keeps the log 
 * record smaller and keeps the string '(null)' from appearing which 
 * is what the sprintf function sticks in for a string that is a
 * NULL pointer. Each item is first formatted into the item buffer to
 * make sure that it will fit into the event log buffer. If it does not
 * the item is not added to the buffer
 */
#define ADD_ITEM(item, format)				    \
	    if (!(item == NULL && format[1] == 's')) {	    \
		itemlen = sprintf(itembuf, format, item);   \
		buflen += itemlen;			    \
		if (buflen <= EV_MAX_LOG_REC_SIZE) {	    \
		    strcpy(bufptr, itembuf);		    \
		    bufptr += itemlen; }		    \
		    else {				    \
			buflen -= itemlen;}}		    
			 

	    						
    bufptr = logbuf;			        /* init pos in buffer */
    
    etype = ep->getType();		        /* get the event type */
    
    // format the timestamp into a time buffer
    ts = ep->getTimeStamp();
    cftime (tbuf, "%b %e %X", &ts);
 
    // Now put in the generic info for all events.
    
    ADD_ITEM (tbuf, "%s ");
    ADD_ITEM (eventTypeStrings[etype], "%s ");  /* string for the type */
    ADD_ITEM (ep->getSrcApp(), "%s");
    ADD_ITEM('[', "%c");
    ADD_ITEM(ep->getPID(), "%d");
    ADD_ITEM (']', "%c ");
    
    ADD_ITEM (ep->getUserName(), "%s");
    ADD_ITEM ('(', "%c");
    ADD_ITEM (ep->getUID(),  "%d");
    ADD_ITEM (')',  "%c ");
    
    
    /*
     * Don't put in the source host and its address for this release.
     * Everything is local. Also it is not really that important where the
     * application is running.
     *
     * ADD_ITEM (ep->getSrcHostName(), "%s ");
     * ADD_ITEM (ep->getSrcHostAddr(), "%s ");
     */
     
    ADD_ITEM (alarmStrings[cfg->getAlarmLevel(etype)], "%s ");
    ADD_ITEM (ep->getInterfaceName(), "%s");
    ADD_ITEM('(', "%c");
    ADD_ITEM (ep->getInterfaceAddr(), "%s");
    ADD_ITEM (')', "%c ");
    ADD_ITEM (ep->getFilter(), "%s ");
    
    /*
     * The previous stuff is common to all events, and for the set of events
     * in the if statement below there is no other data except for the 
     * "otherData if supplied. Therefore this test determines whether I need
     * to add a newline and tab to separate the event specific data from the
     * generic information.
     * 
     */
    if (!(etype == NV_OTHER    || etype == NV_STARTUP     ||
	etype == NV_SHUTDOWN   || etype == NV_START_SNOOP ||
	etype == NV_STOP_SNOOP || etype == NV_LOG_START   ||
	etype == NV_LOG_END))	
	ADD_ITEM("\n\t", "%s");
    
    /*
     * Now for the event specific stuff. Note that for items that are 
     * EV_objIDs, that is those that have a name, network address, and 
     * MAC address, I only put in the MAC address if the address (and name)
     * are missing. This is just to keep the record smaller and easier to
     * read.
     */
    
    switch (etype) {
    case NV_NEW_NODE:
	ADD_ITEM (ep->getNodeName(), "%s");
	ADD_ITEM('(', "%c");
	ADD_ITEM (ep->getNodeAddr(), "%s");
	ADD_ITEM (')', "%c ");
	if (! ep->getNodeAddr())
	    ADD_ITEM (ep->getNodeMACAddr(), "%s ");
    break;
    case NV_NEW_NET:
	ADD_ITEM (ep->getNetName(), "%s");
	ADD_ITEM('(', "%c");
	ADD_ITEM (ep->getNetAddr(),  "%s");
	ADD_ITEM(')', "%c ");
    break;
    case NV_CONVERSE_START:
	ADD_ITEM (ep->getEndPt1Name(), "%s");
	ADD_ITEM('(', "%c");
	ADD_ITEM (ep->getEndPt1Addr(), "%s");
	ADD_ITEM (')', "%c ");
	if (!ep->getEndPt1Addr())
	    ADD_ITEM (ep->getEndPt1MACAddr(), "%s ");
	ADD_ITEM (ep->getEndPt2Name(), "%s");
	ADD_ITEM('(', "%c");
	ADD_ITEM (ep->getEndPt2Addr(), "%s");
	ADD_ITEM(')', "%c ");
	if (! ep->getEndPt2Addr())
	    ADD_ITEM (ep->getEndPt2MACAddr(), "%s ");
    break;
    case NV_CONVERSE_STOP:
	ADD_ITEM (ep->getEndPt1Name(), "%s");
	ADD_ITEM('(', "%c");
	ADD_ITEM (ep->getEndPt1Addr(), "%s");
	ADD_ITEM (')', "%c ");
	if (!ep->getEndPt1Addr())
	    ADD_ITEM (ep->getEndPt1MACAddr(), "%s ");
	ADD_ITEM (ep->getEndPt2Name(), "%s");
	ADD_ITEM('(', "%c");
	ADD_ITEM (ep->getEndPt2Addr(), "%s");
	ADD_ITEM(')', "%c ");
	if (! ep->getEndPt2Addr())
	    ADD_ITEM (ep->getEndPt2MACAddr(), "%s ");
	ADD_ITEM (ep->getBytes(), "%d bytes ");
	ADD_ITEM (ep->getPkts(), "%d packets ");
    break;
    case NV_NEW_PROTO:
	ADD_ITEM(ep->getProto(), "%s ");
    break;
    case NV_RATE_THRESH_HI_MET:
    case NV_RATE_THRESH_HI_UN_MET:
    case NV_RATE_THRESH_LO_MET:
    case NV_RATE_THRESH_LO_UN_MET:
	{
	    ADD_ITEM(ep->getRate(), "%.0f ");
	    rateBase base = ep->getRateBase();
	    switch (base) {
		case BYTE_BASED:
		case PACKET_BASED:
		    ADD_ITEM(rateStrings[base], "%s/sec ");
		break;
		case PERCENT_UTIL:
		case PERCENT_BYTES:
		case PERCENT_PKTS:
		case PERCENT_N_BYTES:
		case PERCENT_N_PKTS:
		    ADD_ITEM (rateStrings[base], "%s ");
		    if (base == PERCENT_N_BYTES) {
			ADD_ITEM(ep->getRateOfBase(), "%.0f bytes. ");
		    } else if (base == PERCENT_N_PKTS) {
			ADD_ITEM(ep->getRateOfBase(), "%.0f packets. ");
		    }
		break;
	    }
	    ADD_ITEM(ep->getThreshRate(),  "threshold: %.0f ");
	}
    break;
    case NV_NEW_TOPN:
	{
	    int i = 0;
	    objectList *topN = ep->getTopNodes();
	    while (topN[i]) {
		ADD_ITEM(topN[i], "%s ");
		i++;
	    }
	}
    break;
    }
    
    /*
     * The "otherData" is treated specially, put on a line by itself 
     * indented like event specific data. The test is made so as not to add
     * a line consisting of only a TAB.
     */
    
    if (ep->getOtherData()) {
	ADD_ITEM("\n\t", "%s");
	ADD_ITEM(ep->getOtherData(),  "%s");
    }
    
}