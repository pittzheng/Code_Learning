/*
 * =====================================================================================
 *
 *       Filename:  sem_common.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/25/2013 10:13:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

// ====== includes ======
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include "sem_common.h"

// ====== defines ======


// ====== enums ======


// ====== typedefs ======


// ====== globals ======


// ====== statics ======
static char CAPI_LOCK_NAME_MAP[CAPI_LOCK_MAX][32] =
{
    "CAPI_LOCK_CONF_RETRIEVE",
    "CAPI_LOCK_CONF_STORE",
    "CAPI_LOCK_CALL_LOG",
    "CAPI_LOCK_GUI_FW_UPGRADE"
/*    "CAPI_LOCK_GUI_PNG_UPLOAD",*/
/*    "CAPI_LOCK_GUI_WEB_BIN_TOKEN",*/
/*    "CAPI_LOCK_TR69_CONFIG"*/
};


// ====== prototypes ======

int init_sem( void )
{
    key_t mykey;
    int semid, ret;
    union semun options;
    CAPI_LOCK_TYPE_E typeindex;

    mykey = ftok(CAPI_FTOK_FILENAME, CAPI_IPCKEY);

    if (mykey == -1)
    {
        DEBUG_PRINTF("ftok failed\n");
        return -1;
    }

    semid = semget(mykey, CAPI_LOCK_MAX, IPC_EXCL | IPC_CREAT | 0777);
    //semid = semget(mykey, CAPI_LOCK_MAX, IPC_EXCL | IPC_CREAT | 0666);
    if (semid == -1)
    {
        DEBUG_PRINTF("semget failed\n");
        return -1;
    }

    options.val = 2;
    for (typeindex = CAPI_LOCK_CONF_RETRIEVE; typeindex < CAPI_LOCK_MAX; typeindex ++)
    {
        ret = semctl(semid, typeindex, SETVAL, options);
        if (ret == -1)
        {
            DEBUG_PRINTF("semctl failed at lock_type[%s]\n", CAPI_LOCK_NAME_MAP[typeindex]);
            return -1;
        }
    }
    
    return semid;
}

int get_semid( void )
{
    key_t mykey;
    int semid;

    mykey = ftok(CAPI_FTOK_FILENAME, CAPI_IPCKEY);
    if (mykey == -1)
    {
        DEBUG_PRINTF("ftok failed\n");
        return -1;
    }

    semid = semget(mykey, CAPI_LOCK_MAX, IPC_CREAT | 0666);
    if (semid == -1)
    {
        DEBUG_PRINTF("semget failed\n");
        return -1;
    }

    return semid;
}

int lock_sem(CAPI_LOCK_TYPE_E type)
{
    int semid, value;
    struct sembuf op[2];

    memset(&op[0], '\0', sizeof(struct sembuf));
    memset(&op[1], '\0', sizeof(struct sembuf));

    semid = get_semid();

    if(semid == -1)
    {
        DEBUG_PRINTF("get_semid failed\n");
        return -1;
    }

    op[0].sem_num = type;
    op[0].sem_op = -2;
    op[0].sem_flg = SEM_UNDO;

    op[1].sem_num = type + 1;
    op[1].sem_op = -2;
    op[1].sem_flg = SEM_UNDO;

    if(semop(semid, &op, 2) == -1)
    {
        DEBUG_PRINTF("semop failed\n");
        return -1;
    }

    value = semctl(semid, type, GETVAL, 0);

    if(value != 0)
    {
        DEBUG_PRINTF("value is not zero[%d]\n", value);
    }

    return 0;
}

int unlock_sem(CAPI_LOCK_TYPE_E type)
{
    int semid, value;
    struct sembuf op;

    memset(&op, '\0', sizeof(struct sembuf));

    semid = get_semid();

    if(semid == -1)
    {
        DEBUG_PRINTF("get_semid failed\n");
        return -1;
    }

    value = semctl(semid, type, GETVAL, 0);
    if (value != 0)
    {
        DEBUG_PRINTF("unlock failed, lock_type = [%s], bad/current sem value = [%d]\n", CAPI_LOCK_NAME_MAP[type], value);
        return -1;
    }

    op.sem_num = type;
    op.sem_op = 2;
/*    op.sem_flg = SEM_UNDO;*/
    op.sem_flg = 0;

    if(semop(semid, &op, 1) == -1)
    {
        DEBUG_PRINTF("semop failed\n");
        return -1;
    }

    return 0;
}

/* semctl cmds */
int ipc_stat_sem(int semid)
{
    struct semid_ds semds;
	struct ipc_perm *ipcp = &semds.sem_perm;
    union semun arg;

    memset(&semds, '\0', sizeof(struct semid_ds));

    arg.buf = &semds;
    
    if(semctl(semid, 0, IPC_STAT, arg))
    {
        DEBUG_PRINTF("semctl failed\n");
        return -1;
    }
    

    DEBUG_PRINTF("Semaphore Array semid=%d\n\n"
              "uid=%d\t gid=%d\t cuid=%d\t cgid=%d\n"
              "mode=%#o, access_perms=%#o\n"
              "nsems = %ld\n"
              "otime = %-26.24s\n",
              semid,
              semds.sem_perm.uid, semds.sem_perm.gid, semds.sem_perm.cuid, semds.sem_perm.cgid,
              semds.sem_perm.mode, semds.sem_perm.mode & 0777,
              (long) semds.sem_nsems,
              semds.sem_otime ? ctime(&semds.sem_otime) : "Not set");

	DEBUG_PRINTF("ctime = %-26.24s\n"
			  "%-10s %-10s %-10s %-10s %-10s\n",
			  ctime(&semds.sem_ctime),
			  "semnum", "value", "ncount", "zcount", "pid");

    return 0;
}

int ipc_info_sem(int semid)
{
	struct seminfo seminfo;
	union semun arg;

    memset(&seminfo, '\0', sizeof(struct seminfo));

	arg.array = (unsigned short *) (void *) &seminfo;

    if ((semctl(0, 0, IPC_INFO, arg)) < 0)
    {
        DEBUG_PRINTF("semctl failed\n");
        return -1;
    }

    DEBUG_PRINTF( "number of entries in semaphore map = %d\n"
                  "max number of semaphore sets = %d\n"
                  "max number of semaphores in all semaphore sets = %d\n"
                  "max number of undo structures = %d\n"
				  "max semaphores per set = %d\n"
                  "max number of operations for semop = %d\n"
                  "max number of undo entries per process = %d\n"
                  "size of struct sem_undo = %d\n"
				  "semaphore max value = %d\n"
				  "max value that can be recorded for semaphore adjustment %d\n",
                  seminfo.semmap,
				  seminfo.semmni,
				  seminfo.semmns,
                  seminfo.semmnu,
				  seminfo.semmsl,
                  seminfo.semopm,
                  seminfo.semume,
                  seminfo.semusz,
                  seminfo.semvmx,
                  seminfo.semaem);

    return 0;
}

int ipc_rmid_sem(int semid)
{
    if ((semctl(semid, 0, IPC_RMID)))
    {
        DEBUG_PRINTF("semctl failed\n");
        return -1;
    }

    return 0;
}

int sem_info_sem( void )
{
	struct seminfo seminfo;
	union semun arg;

    memset(&seminfo, '\0', sizeof(struct seminfo));

	arg.array = (unsigned short *) (void *) &seminfo;

    if ((semctl(0, 0, SEM_INFO, arg)) < 0)
    {
        DEBUG_PRINTF("semctl failed\n");
        return -1;
    }

    DEBUG_PRINTF( "number of entries in semaphore map = %d\n"
                  "max number of semaphore sets = %d\n"
                  "max number of semaphores in all semaphore sets = %d\n"
                  "max number of undo structures = %d\n"
				  "max semaphores per set = %d\n"
                  "max number of operations for semop = %d\n"
                  "max number of undo entries per process = %d\n"
                  "number of semaphore sets that currently exist on the system = %d\n"
				  "semaphore max value = %d\n"
				  "total number of semaphores in all semaphore sets on the system %d\n",
                  seminfo.semmap,
				  seminfo.semmni,
				  seminfo.semmns,
                  seminfo.semmnu,
				  seminfo.semmsl,
                  seminfo.semopm,
                  seminfo.semume,
                  seminfo.semusz,
                  seminfo.semvmx,
                  seminfo.semaem);

    return 0;

}

static void print_perms(int id, struct ipc_perm *ipcp)
{
	struct passwd *pw;
	struct group *gr;

	printf("%-10d %-10o", id, ipcp->mode & 0777);

	pw = getpwuid(ipcp->cuid);
	if (pw)	printf(" %-10s", pw->pw_name);
	else	printf(" %-10d", ipcp->cuid);
	gr = getgrgid(ipcp->cgid);
	if (gr)	printf(" %-10s", gr->gr_name);
	else	printf(" %-10d", ipcp->cgid);

	pw = getpwuid(ipcp->uid);
	if (pw)	printf(" %-10s", pw->pw_name);
	else	printf(" %-10d", ipcp->uid);
	gr = getgrgid(ipcp->gid);
	if (gr)	printf(" %-10s\n", gr->gr_name);
	else	printf(" %-10d\n", ipcp->gid);
}

int sem_stat_sem( void )
{
    int maxid, semid, id;
	struct semid_ds semary;
	struct seminfo seminfo;
	struct ipc_perm *ipcp = &semary.sem_perm;
	struct passwd *pw = NULL;
	union semun arg;

	arg.array = (unsigned short *) (void *) &seminfo;
	maxid = semctl(0, 0, SEM_INFO, arg);

	if (maxid < 0) 
    {
		DEBUG_PRINTF("kernel not configured for %s\n", "semaphores");
		return -1;
	}

    for(id = 0; id <= maxid; id++)
    {
        arg.buf = (struct semid_ds *) &semary;
		semid = semctl(id, 0, SEM_STAT, arg);
		if (semid < 0)
			continue;

	    ipcp = &semary.sem_perm;
        if(1)
        {
            print_perms(semid, ipcp);
        }

		pw = getpwuid(ipcp->uid);
        if (pw)
            printf("%-8d %-10.10s", semid, pw->pw_name);
        else
            printf("%-8d %-10d", semid, ipcp->uid);
        /* ctime uses static buffer: use separate calls */
        printf("  %-26.24s", semary.sem_otime
                ? ctime(&semary.sem_otime) : "Not set");
        printf(" %-26.24s\n", semary.sem_ctime
                ? ctime(&semary.sem_ctime) : "Not set");

        printf("0x%08x ", ipcp->key);
        if (pw)
            printf("%-10d %-10.9s", semid, pw->pw_name);
        else
            printf("%-10d %-9d", semid, ipcp->uid);
        printf(" %-10o %-10ld\n", ipcp->mode & 0777,
                /*
                 * glibc-2.1.3 and earlier has unsigned short;
                 * glibc-2.1.91 has variation between
                 * unsigned short and unsigned long
                 * Austin prescribes unsigned short.
                 */
                (long) semary.sem_nsems);
    }

    return 0;
}

int get_num_of_sem(int semid)
{
	struct seminfo seminfo;
	union semun arg;

    memset(&seminfo, '\0', sizeof(struct seminfo));

	arg.array = (unsigned short *) (void *) &seminfo;

    if ((semctl(0, 0, SEM_INFO, arg)) < 0)
    {
        DEBUG_PRINTF("semctl failed\n");
        return -1;
    }

    return   seminfo.semaem;
    
}

int getall_sem(int semid)
{
	union semun arg;
    unsigned short *array = NULL;
    int i = 0;
    int num = 0;

    num = get_num_of_sem(semid);

    array = malloc(sizeof(unsigned short) * num);
    
    memset(array, '\0', sizeof(unsigned short) * num);

	arg.array = array;

    if(semctl(semid, 0, GETALL, arg))
    {
        DEBUG_PRINTF("semctl failed\n");
        return -1;
    }
    
    for(i=0; i< num; i++)
    {
        DEBUG_PRINTF("the value of sem[%d] = %d\n", i, array[i]);
    }

    free(array);
    return 0;
}

int getncnt_sem(int semid, int index)
{
    union semun arg;
    int ncnt;
    arg.val = 0;

    ncnt = semctl(semid, index, GETNCNT, arg);

    if (ncnt < 0)
    {
        DEBUG_PRINTF("semctl failed\n");
        return -1;
    }
    return ncnt;
}

int getpid_sem(int semid, int index)
{
    union semun arg;
    int pid;
    arg.val = 0;

    pid = semctl(semid, index, GETPID, arg);

    if (pid < 0)
    {
        DEBUG_PRINTF("semctl failed\n");
        return -1;
    }
    return pid;
}

int getval_sem(int semid, int index)
{
    union semun arg;
    int val;
    arg.val = 0;

    val = semctl(semid, index, GETVAL, arg);

    if (val < 0)
    {
        DEBUG_PRINTF("semctl failed\n");
        return -1;
    }
    return val;
}

int getzcnt_sem(int semid, int index)
{
    union semun arg;
    int zcnt;
    arg.val = 0;

    zcnt = semctl(semid, index, GETZCNT, arg);

    if (zcnt < 0)
    {
        DEBUG_PRINTF("semctl failed\n");
        return -1;
    }
    return zcnt;
}

int setall_sem(int semid, int value)
{
	union semun arg;
    unsigned short *array = NULL;
    int i = 0;
    int num;

    num = get_num_of_sem(semid);

    array = malloc(sizeof(unsigned short) * num);
    
    memset(array, '\0', sizeof(unsigned short) * num);

    for(i=0; i< num; i++)
    {
        array[i] = value;
    }

	arg.array = array;

    if(semctl(semid, 0, SETALL, arg))
    {
        DEBUG_PRINTF("semctl failed\n");
        return -1;
    }
    
    return 0;
}

int setval_sem(int semid, int index, int value)
{
	union semun arg;
    int val;

	arg.val = value;

    val = semctl(semid, index, SETVAL, arg);
    if (val < 0 )
    {
        DEBUG_PRINTF("semctl failed\n");
        return -1;
    }

    return 0;
}
