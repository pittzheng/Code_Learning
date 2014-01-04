# Do not edit this makefile. It was generated automatically 
# with commands like
#
#     $ AUPSRC=/aup # (for example)
#     $ export AUPSRC
#     $ awk -f $AUPSRC/makebuild.awk $AUPSRC/c1/makebuild.spec >$AUPSRC/c1/Makefile
#
# It is incomplete in the sense that there are no header-file
# dependencies.
#
# Use the shell-procedure makebuild to run awk. Then compile
# with a shell-procedure like this one for Linux:
#
# 	AUPSRC=/aup # (for example)
# 	OS=LINUX
# 	LIBS="-lncurses -lutil"
# 	TLIBS=-pthread
# 	export OS LIBS TLIBS
# 	make $2 -f $AUPSRC/$1/Makefile $3
#

defaulttarget: all
# Following must be defined in the environment before you run make:
#
#	OS = SOLARIS or LINUX or FREEBSD or HPUX
#	LIBS = regular (non-thread) libraries (eg, "-lncurses -lutil")
#	TLIBS = thread libraries (eg, "-llthread -llgcc_r")
#	PTHREADSTUB = stub for thread functions (eg, pthreadstub.o), if needed
#	INCLUDES = additional include directory (eg, "-I/usr/local/include/pthread/linuxthreads")
#	Don't forget:
#		export OS LIBS TLIBS PTHREADSTUB INCLUDES
#	Suggestions:
#		Solaris:
#			OS=SOLARIS
#			LIBS="-lrt -lcurses -lsocket -lnsl"
#			TLIBS="-lpthread"
#
#		FreeBSD:
#			OS=FREEBSD
#			LIBS="-lncurses -lutil"
#			TLIBS="-llthread -llgcc_r"
#			PTHREADSTUB=pthreadstub.o
#			INCLUDES="-I/usr/local/include/pthread/linuxthreads"
#
#		Linux:
#			OS=LINUX
#			LIBS="-lncurses -lutil"
#			TLIBS="-pthread"
#
#		HPUX:
#			OS=HPUX
#			LIBS="-lcurses"
#			TLIBS="-lpthread" (not yet checked out)
# Options below (e.g., -Wimplicit) are for gcc mostly. You will have to modify them for a non-gcc compiler.
CFLAGS = $(INCLUDES) -I$(AUPSRC) -I$(AUPSRC)/include -I$(AUPSRC)/common -I$(AUPSRC)/c6 -Wimplicit -Wstrict-prototypes -Wall -D$(OS) -D_REENTRANT -D_THREAD_SAFE -std=c99
CC = gcc
CCPP = g++
CCLINK = gcc
# Same objects are used all the time, sometimes linking in unnecessary files.
AUPOBJS = syserr.o time.o extio.o getblksize.o setblock.o ec.o logf.o options.o macrostr.o

mms: mkmacrostr.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o mms mkmacrostr.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)
#############################################
# Utility to build macro-string program
#############################################
macrostr.o: $(AUPSRC)/common/macrostr.c $(AUPSRC)/common/macrostr.incl
	$(CC) $(CFLAGS) -c  -o macrostr.o $(AUPSRC)/common/macrostr.c

setblock.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/setblock.c
	$(CC) $(CFLAGS)  -c -o setblock.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/setblock.c

logf.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/common/logf.c
	$(CC) $(CFLAGS)  -c -o logf.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/common/logf.c

extio.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c2/extio.c
	$(CC) $(CFLAGS)  -c -o extio.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c2/extio.c

getblksize.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c2/getblksize.c
	$(CC) $(CFLAGS)  -c -o getblksize.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c2/getblksize.c

ec.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/common/ec.c
	$(CC) $(CFLAGS)  -c -o ec.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/common/ec.c

mkmacrostr.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/common/mkmacrostr.c
	$(CC) $(CFLAGS)  -c -o mkmacrostr.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/common/mkmacrostr.c

syserr.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/syserr.c
	$(CC) $(CFLAGS)  -c -o syserr.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/syserr.c

time.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/time.c
	$(CC) $(CFLAGS)  -c -o time.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/time.c

pthreadstub.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/common/pthreadstub.c
	$(CC) $(CFLAGS)  -c -o pthreadstub.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/common/pthreadstub.c

options.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/common/options.c
	$(CC) $(CFLAGS)  -c -o options.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/common/options.c

aupnice: nice.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o aupnice nice.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

fpe: fpe.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o fpe fpe.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

lim: limit.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o lim limit.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sh0: sh0.o builtin.o statuspr.o setenv.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sh0 sh0.o builtin.o statuspr.o setenv.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

t0: t0.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o t0 t0.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

t1: t1.o $(AUPOBJS) 
	$(CCLINK) -o t1 t1.o $(AUPOBJS) $(LIBS) $(TLIBS) 

t2: t2.o $(AUPOBJS) 
	$(CCLINK) -o t2 t2.o $(AUPOBJS) $(LIBS) $(TLIBS) 

t2-mtx: t2-mtx.o $(AUPOBJS) 
	$(CCLINK) -o t2-mtx t2-mtx.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx1: tx1.o $(AUPOBJS) 
	$(CCLINK) -o tx1 tx1.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx2: tx2.o $(AUPOBJS) 
	$(CCLINK) -o tx2 tx2.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx3: tx3.o $(AUPOBJS) 
	$(CCLINK) -o tx3 tx3.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx4: tx4.o $(AUPOBJS) 
	$(CCLINK) -o tx4 tx4.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx5: tx5.o $(AUPOBJS) 
	$(CCLINK) -o tx5 tx5.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx6: tx6.o $(AUPOBJS) 
	$(CCLINK) -o tx6 tx6.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx7: tx7.o $(AUPOBJS) 
	$(CCLINK) -o tx7 tx7.o $(AUPOBJS) $(LIBS) $(TLIBS) 

uidgrp: uidgrp.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o uidgrp uidgrp.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

waitid: waitid.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o waitid waitid.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

waitpid: waitpid.o statuspr.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o waitpid waitpid.o statuspr.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

x5: x5.o setenv.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o x5 x5.o setenv.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

x5a: x5a.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o x5a x5a.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

tx6.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx6.c
	$(CC) $(CFLAGS)  -c -o tx6.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx6.c

tx7.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx7.c
	$(CC) $(CFLAGS)  -c -o tx7.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx7.c

sh0.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/sh0.c
	$(CC) $(CFLAGS)  -c -o sh0.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/sh0.c

setenv.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/setenv.c
	$(CC) $(CFLAGS)  -c -o setenv.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/setenv.c

nice.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/nice.c
	$(CC) $(CFLAGS)  -c -o nice.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/nice.c

t0.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/t0.c
	$(CC) $(CFLAGS)  -c -o t0.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/t0.c

t1.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/t1.c
	$(CC) $(CFLAGS)  -c -o t1.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/t1.c

statuspr.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/statuspr.c
	$(CC) $(CFLAGS)  -c -o statuspr.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/statuspr.c

waitid.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/waitid.c
	$(CC) $(CFLAGS)  -c -o waitid.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/waitid.c

tx1.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx1.c
	$(CC) $(CFLAGS)  -c -o tx1.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx1.c

t2.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/t2.c
	$(CC) $(CFLAGS)  -c -o t2.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/t2.c

fpe.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/fpe.c
	$(CC) $(CFLAGS)  -c -o fpe.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/fpe.c

limit.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/limit.c
	$(CC) $(CFLAGS)  -c -o limit.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/limit.c

t2-mtx.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/t2-mtx.c
	$(CC) $(CFLAGS)  -c -o t2-mtx.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/t2-mtx.c

uidgrp.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/uidgrp.c
	$(CC) $(CFLAGS)  -c -o uidgrp.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/uidgrp.c

tx2.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx2.c
	$(CC) $(CFLAGS)  -c -o tx2.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx2.c

tx3.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx3.c
	$(CC) $(CFLAGS)  -c -o tx3.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx3.c

waitpid.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/waitpid.c
	$(CC) $(CFLAGS)  -c -o waitpid.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/waitpid.c

x5.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/x5.c
	$(CC) $(CFLAGS)  -c -o x5.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/x5.c

tx4.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx4.c
	$(CC) $(CFLAGS)  -c -o tx4.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx4.c

builtin.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/builtin.c
	$(CC) $(CFLAGS)  -c -o builtin.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/builtin.c

tx5.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx5.c
	$(CC) $(CFLAGS)  -c -o tx5.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/tx5.c

x5a.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/x5a.c
	$(CC) $(CFLAGS)  -c -o x5a.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c5/x5a.c

all:  t2-mtx lim aupnice waitpid t0 t1 t2 x5 fpe uidgrp tx1 tx2 waitid tx3 x5a tx4 tx5 tx6 tx7 sh0
clean:
	rm  t2-mtx lim aupnice waitpid t0 t1 t2 x5 fpe uidgrp tx1 tx2 waitid tx3 x5a tx4 tx5 tx6 tx7 sh0 *.o
