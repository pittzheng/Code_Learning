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

ckstdvers: ckstdvers.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o ckstdvers ckstdvers.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

ckvers: ckvers.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o ckvers ckvers.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

err: errorhandling.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o err errorhandling.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

opttest: opttest.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o opttest opttest.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

suvreq: suvreq.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o suvreq suvreq.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sysconf: sysconf.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sysconf sysconf.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

timetst: timetst.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o timetst timetst.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

version: version.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o version version.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

errorhandling.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/errorhandling.c
	$(CC) $(CFLAGS)  -c -o errorhandling.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/errorhandling.c

opttest.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/opttest.c
	$(CC) $(CFLAGS)  -c -o opttest.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/opttest.c

sysconf.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/sysconf.c
	$(CC) $(CFLAGS)  -c -o sysconf.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/sysconf.c

suvreq.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/suvreq.c
	$(CC) $(CFLAGS) -DCKVERS_UNIX98x -c -o suvreq.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/suvreq.c

version.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/version.c
	$(CC) $(CFLAGS)  -c -o version.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/version.c

timetst.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/timetst.c
	$(CC) $(CFLAGS)  -c -o timetst.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/timetst.c

ckvers.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/ckvers.c
	$(CC) $(CFLAGS) -DCKVERS_UNIX98 -c -o ckvers.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/ckvers.c

ckstdvers.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/ckstdvers.c
	$(CC) $(CFLAGS)  -c -o ckstdvers.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c1/ckstdvers.c

all:  sysconf opttest ckvers version ckstdvers suvreq timetst err
clean:
	rm  sysconf opttest ckvers version ckstdvers suvreq timetst err *.o
