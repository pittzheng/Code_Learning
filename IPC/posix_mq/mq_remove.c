#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "mq_common.h"

int main(int argc, char *argv[])
{
    mq_remove();
    return EXIT_SUCCESS;
}
