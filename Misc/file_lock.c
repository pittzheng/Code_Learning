/*
 * =====================================================================================
 *
 *       Filename:  file_lock.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/27/2014 07:05:07 PM
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

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define LOCK_FILE "/home/peiqzhen/test.lock"

int main(int argc, char *argv[])
{
    int fd = -1;
    int ret;

    fd = open(LOCK_FILE, O_RDWR);


    if(fd == -1)
    {
        printf("open failed\n");
        return 0;
    }

    lseek(fd, 0, SEEK_SET);

    printf("debug line =%d\n", __LINE__);
    ret = lockf(fd, F_LOCK, 0);
    printf("debug line =%d\n", __LINE__);

    if(ret != 0)
    {
        printf("lockf failed\n");
        close(fd);
        return 0;
    }

/*    ret = write(fd, "123", 2);*/

/*    printf("ret = %d\n", ret);*/

/*    sleep(10);*/

/*    ret = lockf(fd, F_ULOCK, 0);*/

/*    if(ret != 0)*/
/*    {*/
/*        printf("l2ockf failed\n");*/
/*        close(fd);*/
/*        return 0;*/
/*    }*/
/*    return 0;*/
}
