/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/20/2014 06:35:24 PM
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

#pragma pack(1)
typedef struct
{
    int aa; //第一个成员，放在[0,3]偏移的位置，
    char a; //第二个成员，自身长为1，#pragma pack(4),取小值，也就是1，所以这个成员按一字节对齐，放在偏移[4]的位置。
    short b; //第三个成员，自身长2，#pragma pack(4)，取2，按2字节对齐，所以放在偏移[6,7]的位置。
    char c; //第四个，自身长为1，放在[8]的位置。
} st_a;
#pragma pack()

#if 1
/*#pragma pack(2)*/
typedef struct
{
    int aa; //第一个成员，放在[0,3]偏移的位置.
    char a; //第二个成员，自身长为1，#pragma pack(4),取小值，也就是1，所以这个成员按一字节对齐，放在偏移[4]的位置。
    short b; //第三个成员，自身长2，#pragma pack(4)，取2，按2字节对齐，所以放在偏移[6,7]的位置。
    char c; //第四个，自身长为1，放在[8]的位置。
} st_b __attribute__((aligned(1)));
/*__attribute__(((packed)))*/
#else
#pragma pack(2)
typedef struct
{
    int aa; //第一个成员，放在[0,3]偏移的位置.
    char a; //第二个成员，自身长为1，#pragma pack(4),取小值，也就是1，所以这个成员按一字节对齐，放在偏移[4]的位置。
    short b; //第三个成员，自身长2，#pragma pack(4)，取2，按2字节对齐，所以放在偏移[6,7]的位置。
    char c; //第四个，自身长为1，放在[8]的位置。
} st_b;
/*__attribute__(((packed)))*/
#pragma pack()
#endif

#pragma pack(4)
typedef struct
{
    char a; //第一个成员，放在[0]偏移的位置，
    short b; //第二个成员，自身长2，#pragma pack(4)，取2，按2字节对齐，所以放在偏移[2,3]的位置。
    char c; //第三个，自身长为1，放在[4]的位置。
} st_c;

typedef struct
{
    char x1; //第一个成员，放在[0]位置，
    short x2; //第二个成员，自身长度为2，按2字节对齐，所以放在偏移[2,3]的位置，
    float x3; //第三个成员，自身长度为4，按4字节对齐，所以放在偏移[4,7]的位置，
    char x4; //第四个陈冠，自身长度为1，按1字节对齐，所以放在偏移[8]的位置，
} st_d;
#pragma pack()

#pragma pack(16)
typedef struct
{
    short a; //第一个，放在[0,1]位置，
    long b; //第二个，自身长度为4，按min(4, 8) = 4对齐，所以放在[4,7]位置
} st_e;
#pragma pack()
#pragma pack(8)
typedef struct
{
    char c; //第一个，放在[0]位置，
/*    st_e d; //第二个，根据规则四，对齐是min( 4, pack_value ) = 4字节，所以放在[4,11]位置,*/
    long long e; //第三个，自身长度为8字节，所以按8字节对齐，所以放在[16,23]位置，
    long long f; //第三个，自身长度为8字节，所以按8字节对齐，所以放在[16,23]位置，
} st_f;
#pragma pack()

int main(int argc, char *argv[])
{
    printf("sizeof(st_a)=[%d]\n", sizeof(st_a));
    printf("sizeof(st_b)=[%d]\n", sizeof(st_b));
    printf("sizeof(st_c)=[%d]\n", sizeof(st_c));
    printf("sizeof(st_d)=[%d]\n", sizeof(st_d));
    printf("sizeof(st_e)=[%d]\n", sizeof(st_e));
    printf("sizeof(st_f)=[%d][%d]\n", sizeof(st_f), sizeof(long long));

    return 0;
}
