/*
 * =====================================================================================
 *
 *       Filename:  sem_client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/25/2013 09:56:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

// ====== includes ======

#include <stdlib.h>
#include <signal.h>
#include "sem_common.h"

// ====== defines ======


// ====== enums ======


// ====== typedefs ======


// ====== globals ======


// ====== statics ======

// ====== prototypes ======


void tr69_mgr_signal_handler(int signum)
{
    int semid = get_semid();

    if (semctl(semid, CAPI_LOCK_MAX, IPC_RMID) == -1)
    {
        DEBUG_PRINTF("semctl failed\n");
        return;
    }
}

int main ( int argc, char *argv[] )
{
    int  ret;
    
    signal(SIGUSR1, tr69_mgr_signal_handler);

    ret = lock_sem(CAPI_LOCK_CONF_RETRIEVE);

    if(ret == -1)
    {
        DEBUG_PRINTF("lock_sem failed\n");
        return -1;
    }
    else
    {
        DEBUG_PRINTF("lock_sem ok\n");
    }

    ret = lock_sem(CAPI_LOCK_CONF_STORE);
    if(ret == -1)
    {
        DEBUG_PRINTF("lock_sem failed\n");
        return -1;
    }
    else
    {
        DEBUG_PRINTF("lock_sem ok\n");
    }
    while(1);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
