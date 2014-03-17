/*
 * =====================================================================================
 *
 *       Filename:  sizeof.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/27/2014 02:53:28 PM
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

typedef struct _sys_msg_s {
    unsigned int  magic;      // 0x524A3131

    unsigned int  msg_type;    // command/event
    unsigned int  version;    // reserved
    unsigned int  sender_id;   // sender module id
    unsigned int  receiver_id; // receiver module id

    unsigned int  need_ack;    // reqest ACK from receiver
    unsigned int  need_result; // reqest ACK from receiver
    unsigned int  ack;        // response of needAck from receiver
    unsigned int  result;     // result of command/event

    unsigned int length;     // length of data[]
    unsigned int seq_no;      // Seq Number - no use now

    unsigned char data[0];    // SYS_MSG_EVENT_INFO_U
} SYS_MSG_S;

typedef union _sys_msg_event_info_u
{
    char a;
    int b;
    short c;

} SYS_MSG_EVENT_INFO_U;

typedef struct _sys_msg_event_info_s
{
    SYS_MSG_S hdr;
    SYS_MSG_EVENT_INFO_U info_u;
} SYS_MSG_EVENT_INFO_S;

typedef struct _sys_msg_array_s {
    unsigned int count;       // msg count
    SYS_MSG_EVENT_INFO_S info[0];
} SYS_MSG_ARRAY_S;


int main(int argc, char *argv[])
{
    printf("%d, %d, %d, %d\n",
            sizeof(SYS_MSG_ARRAY_S),
            sizeof(SYS_MSG_EVENT_INFO_S),
            sizeof(SYS_MSG_S),
            sizeof(SYS_MSG_EVENT_INFO_U)
            );
    return 0;
}






