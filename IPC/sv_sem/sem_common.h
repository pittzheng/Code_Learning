#ifndef __SEM_COMMON_H__
#define __SEM_COMMON_H__
// ====== includes ======

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <linux/sem.h>
#include <sys/types.h>

// ====== defines ======

#define CAPI_IPCKEY 'l'
#define CAPI_FTOK_FILENAME  "/tmp/m_data"
#define DEBUG_PRINTF(format, args...)       \
    do                                      \
    {                                       \
        printf("[%s]:[%s]:[%s]:[%d]" format,strerror(errno),__FILE__,__func__,__LINE__,##args);    \
    } while (0)

// ====== enums ======

typedef enum _capi_lock_type_e
{
    CAPI_LOCK_CONF_RETRIEVE = 0,
    CAPI_LOCK_CONF_STORE,
    CAPI_LOCK_CALL_LOG,
    CAPI_LOCK_GUI_FW_UPGRADE,
/*    CAPI_LOCK_GUI_PNG_UPLOAD,*/
/*    CAPI_LOCK_GUI_WEB_BIN_TOKEN,*/
/*    CAPI_LOCK_CDM,*/
/*    CAPI_LOCK_TR69_CONFIG,*/
    CAPI_LOCK_MAX
}CAPI_LOCK_TYPE_E;

// ====== typedefs ======


// ====== globals ======


// ====== statics ======


// ====== prototypes ======
extern int init_sem( void );
extern int get_semid( void );
extern int lock_sem(CAPI_LOCK_TYPE_E type);
extern int unlock_sem(CAPI_LOCK_TYPE_E type);
extern int ipc_stat_sem(int semid);
extern int ipc_info_sem(int semid);
extern int ipc_rmid_sem(int semid);
extern int sem_info_sem( void );
extern int sem_stat_sem( void );
extern int get_num_of_sem(int semid);
extern int getall_sem(int semid);
extern int getncnt_sem(int semid, int index);
extern int getpid_sem(int semid, int index);
extern int getval_sem(int semid, int index);
extern int getzcnt_sem(int semid, int index);
extern int setall_sem(int semid, int value);
extern int setval_sem(int semid, int index, int value);
#endif
