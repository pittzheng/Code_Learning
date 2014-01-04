#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "mq_common.h"

int main ( int argc, char *argv[] )
{
    MQ_MODULE_E src, dest;
    char send_data[64];
    char recv_data[64];

    memset(send_data, '\0', sizeof(send_data));
    memset(recv_data, '\0', sizeof(recv_data));

    src = MODULE_CAPI_RETRIEVE;
    dest = MODULE_CONF_MGR_RETRIEVE;

    strcpy(send_data, "send1");

    if ( mq_init() == -1 ) 
    {
        DEBUG_PRINTF("mq_init failed\n");
        return EXIT_FAILURE;
    }

    if ( mq_send_msg(src, dest, send_data, sizeof(send_data), MQ_PRIO_1) < 0) 
    {
        DEBUG_PRINTF("mq_send_msg failed\n");
        return EXIT_FAILURE;
    }

    strcpy(send_data, "send2");

    if ( mq_send_msg(src, dest, send_data, sizeof(send_data), MQ_PRIO_2) < 0) 
    {
        DEBUG_PRINTF("mq_send_msg failed\n");
        return EXIT_FAILURE;
    }


    mq_unload();
    return EXIT_SUCCESS;
}
