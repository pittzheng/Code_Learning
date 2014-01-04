/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  a
 *
 *        Version:  1.0
 *        Created:  12/20/13 04:09:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

// ====== includes ======


// ====== defines ======


// ====== enums ======


// ====== typedefs ======


// ====== globals ======


// ====== statics ======


// ====== prototypes ======

#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/klog.h>

#define LOG_BUF 131072
int main(int argc, char *argv[])
{
    char *buf = NULL;
    int size;
    int cmd = atoi(argv[1]);
    
    buf = malloc(LOG_BUF);

    if(buf == NULL)
    {
        printf("malloc failed\n");
        return 0;
    }

    memset(buf, '\0', LOG_BUF);

    
    if((size =klogctl(cmd, buf, LOG_BUF)) < 0)
    {
        free(buf);
        printf("klogctl failed\n");
        return 0;
    }
    
    printf("%d, %d\n%s", size, strlen(buf), buf);

    free(buf);

    return 0;
}
