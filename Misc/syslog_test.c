/*
 * =====================================================================================
 *
 *       Filename:  syslog_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/25/13 00:02:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

// ====== includes ======

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

// ====== defines ======


// ====== enums ======


// ====== typedefs ======


// ====== globals ======


// ====== statics ======


// ====== prototypes ======

int main(int argc, char *argv[])
{
/*    setlogmask (LOG_UPTO (LOG_NOTICE)); */
    setlogmask (~(LOG_MASK(LOG_NOTICE))); 
    openlog ("exampleprog", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);           
    syslog (LOG_NOTICE, "Program started by User %d", getuid ());      
    syslog (LOG_INFO, "A tree falls in a forest %d", LOG_LOCAL1);           
    syslog (LOG_WARNING, "Warning %d", LOG_LOCAL2);           
    closelog (); 
    return EXIT_SUCCESS;
}
