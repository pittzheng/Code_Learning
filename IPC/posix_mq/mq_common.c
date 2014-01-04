#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "mq_common.h"


static MQ_OBJ_S mq_objs[MODULE_MAX] =
{
    {CONF_MGR_STORE_MQ_OBJ_NAME, 0, (O_NONBLOCK | O_RDWR | O_CREAT) },
    {CONF_MGR_RETRIEVE_OBJ_NAME, 0, (O_NONBLOCK | O_RDWR | O_CREAT)},
    {CAPI_STORE_MQ_OBJ_NAME, 0, (O_RDWR | O_CREAT)},
    {CAPI_RETRIEVE_MQ_OBJ_NAME, 0, (O_RDWR | O_CREAT)},
    {TR69_MGR_OBJ_NAME, 0, (O_RDWR | O_CREAT | O_NONBLOCK)},
    {TR69_AGENT_OBJ_NAME, 0, (O_RDWR | O_CREAT | O_NONBLOCK)},
};

int mq_init(void)
{
    int i, ret = 0;
    
    struct mq_attr defattr = { 0, 9, 4096, 0};

    for (i = 0; i < MODULE_MAX; i++)
    {
        mq_objs[i].id = mq_open(mq_objs[i].obj_name, mq_objs[i].flag, 0600 , &defattr);
        if (((mqd_t) - 1) == mq_objs[i].id)
        {
            DEBUG_PRINTF("init module %d message queue failure!\n", i);

            ret = -1;
        }
    }

    return ret;
}

int mq_remove(void)
{
    int i, ret = 0;

    for (i = 0; i < MODULE_MAX; i++)
    {
        ret = mq_unlink(mq_objs[i].obj_name);
        if (ret)
        {
            DEBUG_PRINTF( "Unlink module %d message queue failure!\n", i);
        }
    }

    return ret;

}

int mq_unload(void)
{
    int i, ret = 0;

    for (i = 0; i < MODULE_MAX; i++)
    {
        ret = mq_close(mq_objs[i].id);
        if (ret)
        {
            DEBUG_PRINTF( "Unload module %d message queue failure!\n", i);
        }
    }

    return ret;
}

int mq_send_msg(MQ_MODULE_E src, MQ_MODULE_E dest, void *data, ssize_t size, unsigned priority)
{
    MQ_BUF msg;

    memset(&msg, 0, sizeof(msg));
    msg.type = src;

    if (size > MQBUF_SIZE)
    {
        size = MQBUF_SIZE;
    }

    memcpy(msg.data, data, size);

    return mq_send(mq_objs[dest].id, (char *)&msg, sizeof(msg), priority);
}

ssize_t mq_recv_msg(MQ_MODULE_E *src, MQ_MODULE_E dest, void *data, ssize_t size)
{
    ssize_t nread;
    MQ_BUF msg;
    struct mq_attr attr;
    unsigned int msg_prio;
    memset(&msg, 0, sizeof(msg));
    memset(&attr, 0, sizeof(attr));

    mq_getattr(mq_objs[dest].id, &attr);

    nread = mq_receive(mq_objs[dest].id, (char *) & msg, attr.mq_msgsize, &msg_prio);

    if (nread >= 0)
    {
        if (nread > size)
        {
            nread = size;
        }

        memcpy(data, msg.data, nread);

        *src = msg.type;
    }

    return nread;
}

mqd_t mq_get_id(MQ_MODULE_E module)
{
    mqd_t ret = -1;

    if (0 <= module && module < MODULE_MAX)
    {
        ret = mq_objs[module].id;
    }

    return ret;
}
