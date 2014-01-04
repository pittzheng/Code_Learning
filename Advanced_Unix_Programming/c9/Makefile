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

alarm_test: alarm_test.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o alarm_test alarm_test.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

ctx: ctx.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o ctx ctx.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

intro: intro.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o intro intro.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

intro2: intro2.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o intro2 intro2.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

jmp: jmp.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o jmp jmp.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

prcssync: prcssync.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o prcssync prcssync.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sighandler: sighandler.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sighandler sighandler.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

siginfo: siginfo.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o siginfo siginfo.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sigmin: sigmin.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sigmin sigmin.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sigminthr: sigminthr.o $(AUPOBJS) 
	$(CCLINK) -o sigminthr sigminthr.o $(AUPOBJS) $(LIBS) $(TLIBS) 

slp: slp.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o slp slp.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

thrq: thrq.o $(AUPOBJS) 
	$(CCLINK) -o thrq thrq.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tmr: tmr.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o tmr tmr.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

tmr.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/tmr.c
	$(CC) $(CFLAGS)  -c -o tmr.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/tmr.c

slp.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/slp.c
	$(CC) $(CFLAGS)  -c -o slp.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/slp.c

ctx.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/ctx.c
	$(CC) $(CFLAGS)  -c -o ctx.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/ctx.c

sigmin.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/sigmin.c
	$(CC) $(CFLAGS)  -c -o sigmin.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/sigmin.c

sighandler.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/sighandler.c
	$(CC) $(CFLAGS)  -c -o sighandler.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/sighandler.c

sigminthr.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/sigminthr.c
	$(CC) $(CFLAGS)  -c -o sigminthr.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/sigminthr.c

prcssync.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/prcssync.c
	$(CC) $(CFLAGS)  -c -o prcssync.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/prcssync.c

intro2.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/intro2.c
	$(CC) $(CFLAGS)  -c -o intro2.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/intro2.c

siginfo.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/siginfo.c
	$(CC) $(CFLAGS)  -c -o siginfo.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/siginfo.c

thrq.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/thrq.c
	$(CC) $(CFLAGS)  -c -o thrq.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/thrq.c

intro.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/intro.c
	$(CC) $(CFLAGS)  -c -o intro.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/intro.c

slp-simple.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/slp-simplec9/slp-simple.c
	$(CC) $(CFLAGS)  -c -o slp-simple.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/slp-simplec9/slp-simple.c

alarm_test.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/alarm_test.c
	$(CC) $(CFLAGS)  -c -o alarm_test.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/alarm_test.c

jmp.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/jmp.c
	$(CC) $(CFLAGS)  -c -o jmp.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c9/jmp.c

all:  slp sigminthr alarm_test jmp intro2 tmr intro prcssync siginfo thrq sigmin sighandler ctx
clean:
	rm  slp sigminthr alarm_test jmp intro2 tmr intro prcssync siginfo thrq sigmin sighandler ctx *.o
