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

auptty: auptty.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o auptty auptty.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

pginfo: pginfo.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o pginfo pginfo.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

record: record.o ptutil.o tc_setraw.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o record record.o ptutil.o tc_setraw.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

scrapp: scrapp.o tc_setraw.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o scrapp scrapp.o tc_setraw.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

scrappc: scrappc.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o scrappc scrappc.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

streamlist: streamlist.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o streamlist streamlist.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

x4: x4.o bufio.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o x4 x4.o bufio.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

x4a: x4a.o tc_setraw.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o x4a x4a.o tc_setraw.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

pginfo.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/pginfo.c
	$(CC) $(CFLAGS)  -c -o pginfo.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/pginfo.c

scrapp.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/scrapp.c
	$(CC) $(CFLAGS)  -c -o scrapp.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/scrapp.c

tc_setraw.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/tc_setraw.c
	$(CC) $(CFLAGS)  -c -o tc_setraw.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/tc_setraw.c

record.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/record.c
	$(CC) $(CFLAGS)  -c -o record.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/record.c

auptty.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/auptty.c
	$(CC) $(CFLAGS)  -c -o auptty.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/auptty.c

scrappc.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/scrappc.c
	$(CC) $(CFLAGS)  -c -o scrappc.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/scrappc.c

bufio.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c2/bufio.c
	$(CC) $(CFLAGS)  -c -o bufio.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c2/bufio.c

streamlist.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/streamlist.c
	$(CC) $(CFLAGS)  -c -o streamlist.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/streamlist.c

x4.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/x4.c
	$(CC) $(CFLAGS)  -c -o x4.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/x4.c

x4a.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/x4a.c
	$(CC) $(CFLAGS)  -c -o x4a.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/x4a.c

ptutil.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/ptutil.c
	$(CC) $(CFLAGS)  -c -o ptutil.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c4/ptutil.c

all:  streamlist pginfo record auptty scrapp scrappc x4 x4a
clean:
	rm  streamlist pginfo record auptty scrapp scrappc x4 x4a *.o
