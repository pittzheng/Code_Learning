#!/bin/sh
AUPSRC=/home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming
OS=LINUX
LIBS="-lncurses -lutil"
TLIBS="-pthread"

export AUPSRC OS LIBS TLIBS
make $2 -f $AUPSRC/$1/Makefile $3
