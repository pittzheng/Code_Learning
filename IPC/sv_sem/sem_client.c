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
/*    int semid = get_semid();*/

/*    if (semctl(semid, CAPI_LOCK_MAX, IPC_RMID) == -1)*/
/*    {*/
/*        DEBUG_PRINTF("semctl failed\n");*/
/*        return;*/
/*    }*/
}


int main ( int argc, char *argv[] )
{
    int semid, ret;
    
    signal(SIGUSR1, tr69_mgr_signal_handler);

    semid = init_sem();
    
    if(semid == -1)
    {
        DEBUG_PRINTF("init_sem failed\n");
        return EXIT_FAILURE;
    }
    
/*    ret = lock_sem(CAPI_LOCK_CONF_RETRIEVE);*/
/*    */
/*    if(ret == -1)*/
/*    {*/
/*        DEBUG_PRINTF("lock_sem failed\n");*/
/*        return -1;*/
/*    }*/
/*    else*/
/*    {*/
/*        DEBUG_PRINTF("lock_sem ok\n");*/
/*    }*/

    int num ;

    printf("---------------------------------------------\n");
    ipc_stat_sem(semid);
    printf("---------------------------------------------\n");
    ipc_info_sem(semid);
    printf("---------------------------------------------\n");
    sem_info_sem();
    printf("---------------------------------------------\n");
    sem_stat_sem();
    printf("---------------------------------------------\n");
    getall_sem(semid);
    printf("---------------------------------------------\n");

/*    num = get_num_of_sem(semid);*/
/*    printf("ncnt = %d\n", getncnt_sem(semid, 0));*/
/*    printf("pid=%d\n",getpid_sem(semid, 1));*/
/*    printf("val =%d\n",getval_sem(semid, 2));*/
/*    printf("zcnd=%d\n",getzcnt_sem(semid, 3));*/

/*    setall_sem(semid, 8);*/
/*    setval_sem(semid, 1, 6);*/
/*    getall_sem(semid);*/
/*    ipc_rmid_sem(semid);*/

    while(1);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
