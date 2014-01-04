#ifndef __MQ_COMMON_H__
#define __MQ_COMMON_H__
// ====== includes ======

#include <mqueue.h>

// ====== defines ======
#if 0
#define TMP "/home/peiqzhen"
#else
#define TMP
#endif

#define DEBUG_PRINTF(format, args...)       \
    do                                      \
    {                                       \
        printf("[%s]:[%s]:[%d]:[%s] "format,__FILE__,__FUNCTION__,__LINE__,strerror(errno),##args);    \
    } while (0)


#define MAX_PATH_LEN 128

#define MQBUF_SIZE (4092-16)
#define CAPI_MSG_SIZE (4092-32)
#define MAX_CAPI_DATA_SIZE (32*1024)

#define MQ_PRIO_1 (1)
#define MQ_PRIO_2 (2)
#define MQ_PRIO_999 (1000-1)

#define CONF_MGR_STORE_MQ_OBJ_NAME TMP"/conf_mgr_store_msg"
#define CONF_MGR_RETRIEVE_OBJ_NAME TMP"/conf_mgr_retrieve_msg"
#define CAPI_STORE_MQ_OBJ_NAME TMP"/capi_store_msg"
#define CAPI_RETRIEVE_MQ_OBJ_NAME TMP"/capi_retrieve_msg"
#define TR69_MGR_OBJ_NAME TMP"/tr69_mgr_msg"
#define TR69_AGENT_OBJ_NAME TMP"/tr69_agent_msg"

// ====== enums ======

typedef enum _mq_module_e
{
    MODULE_CONF_MGR_STORE = 0,
    MODULE_CONF_MGR_RETRIEVE,
    MODULE_CAPI_STORE,
    MODULE_CAPI_RETRIEVE,
    MODULE_TR69_MGR,
    MODULE_TR69_AGENT,
    MODULE_MAX,
} MQ_MODULE_E;

// ====== typedefs ======

typedef struct _mq_obj_s
{
    char obj_name[MAX_PATH_LEN];
    mqd_t id;
    int flag;
} MQ_OBJ_S;

typedef struct
{
    long int type;
    char data[MQBUF_SIZE];
} MQ_BUF;
// ====== globals ======


// ====== statics ======


// ====== prototypes ======

extern int mq_init(void);
extern int mq_remove(void);
extern int mq_unload(void);
extern int mq_send_msg(MQ_MODULE_E src, MQ_MODULE_E dest, void *data, ssize_t size, unsigned priority);
extern ssize_t mq_recv_msg(MQ_MODULE_E *src, MQ_MODULE_E dest, void *data, ssize_t size);
extern mqd_t mq_get_id(MQ_MODULE_E module);
#endif
