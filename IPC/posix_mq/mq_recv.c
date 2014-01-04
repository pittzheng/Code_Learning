#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "mq_common.h"

static void mq_recv_msg_noblock( MQ_MODULE_E dest)
{
    mqd_t id;
    fd_set rfds;
    unsigned long max_fd;
    int ret;
    MQ_MODULE_E from;
    char recv_data[64];

    memset(recv_data, '\0', sizeof(recv_data));

    id =  mq_get_id (dest);

    if(id < 0)
    {
        DEBUG_PRINTF("mq_get_id failed\n");
        return;
    }
    
    max_fd = id + 1;
    
    while(1)
    {
        FD_ZERO(&rfds);
        FD_SET(id, &rfds);
    
        ret = select(max_fd, &rfds,  NULL, NULL, NULL);
        if (ret >= 0)
        {
            if (FD_ISSET(id, &rfds))
            {
                ret = mq_recv_msg(&from, dest, recv_data, sizeof(recv_data));
                if(ret<0)
                {
                    DEBUG_PRINTF("recv_error, ret =%d\n", ret);
                }
                else
                {
                    DEBUG_PRINTF("recv_data=%s, from=%d\n", recv_data, from);
                }
            }
        }
    }
    return;
}

int main ( int argc, char *argv[] )
{
    int i       ;
    
    if ( mq_init() == -1 ) 
    {
        DEBUG_PRINTF("mq_init failed %s\n", "hello");
        return EXIT_FAILURE;
    }

    mq_recv_msg_noblock( MODULE_CONF_MGR_RETRIEVE);

/*    for(i=0; i< MODULE_MAX; i++)*/
/*    {*/
/*        DEBUG_PRINTF("id[i]=%d\n", mq_get_id(MODULE_CONF_MGR_STORE + i));*/
/*    }*/

    mq_unload();
    return EXIT_SUCCESS;
}
