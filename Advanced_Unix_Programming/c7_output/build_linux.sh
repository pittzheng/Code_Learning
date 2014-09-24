#!/bin/sh
AUPSRC=$(cd ..&&/bin/pwd)
OS=LINUX
LIBS="-lncurses -lutil -lrt -lpthread"
TLIBS="-pthread"

export AUPSRC OS LIBS TLIBS
make $2 -f $AUPSRC/$1/Makefile $3
