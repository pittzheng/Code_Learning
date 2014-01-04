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

adi: adi.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o adi adi.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

br: br.o ssi.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o br br.o ssi.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

byteorder: byteorder.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o byteorder byteorder.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

minibr: minibr.o ssi.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o minibr minibr.o ssi.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

miniws: miniws.o ssi.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o miniws miniws.o ssi.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

ndb: ndb.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o ndb ndb.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

protoent: protoent.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o protoent protoent.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sktcl: sktcl.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sktcl sktcl.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sktex: sktex.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sktex sktex.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sktexdg: sktexdg.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sktexdg sktexdg.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sktexdgmult: sktexdgmult.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sktexdgmult sktexdgmult.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sktexdgmultmsg: sktexdgmultmsg.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sktexdgmultmsg sktexdgmultmsg.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sktexm: sktexm.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sktexm sktexm.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sktopt: sktopt.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sktopt sktopt.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

aupuname: uname.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o aupuname uname.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

ws: ws.o ssi.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o ws ws.o ssi.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

minibr.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/minibr.c
	$(CC) $(CFLAGS)  -c -o minibr.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/minibr.c

miniws.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/miniws.c
	$(CC) $(CFLAGS)  -c -o miniws.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/miniws.c

sktopt.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktopt.c
	$(CC) $(CFLAGS)  -c -o sktopt.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktopt.c

sktexdgmult.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktexdgmult.c
	$(CC) $(CFLAGS)  -c -o sktexdgmult.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktexdgmult.c

ndb.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/ndb.c
	$(CC) $(CFLAGS)  -c -o ndb.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/ndb.c

br.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/br.c
	$(CC) $(CFLAGS)  -c -o br.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/br.c

ws.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/ws.c
	$(CC) $(CFLAGS)  -c -o ws.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/ws.c

sktex.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktex.c
	$(CC) $(CFLAGS)  -c -o sktex.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktex.c

protoent.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/protoent.c
	$(CC) $(CFLAGS)  -c -o protoent.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/protoent.c

sktexm.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktexm.c
	$(CC) $(CFLAGS)  -c -o sktexm.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktexm.c

sktexdgmultmsg.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktexdgmultmsg.c
	$(CC) $(CFLAGS)  -c -o sktexdgmultmsg.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktexdgmultmsg.c

sktcl.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktcl.c
	$(CC) $(CFLAGS)  -c -o sktcl.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktcl.c

sktexdg.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktexdg.c
	$(CC) $(CFLAGS)  -c -o sktexdg.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/sktexdg.c

adi.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/adi.c
	$(CC) $(CFLAGS)  -c -o adi.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/adi.c

uname.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/uname.c
	$(CC) $(CFLAGS)  -c -o uname.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/uname.c

byteorder.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/byteorder.c
	$(CC) $(CFLAGS)  -c -o byteorder.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/byteorder.c

ssi.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/ssi.c
	$(CC) $(CFLAGS)  -c -o ssi.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/ssi.c

all:  sktex sktopt sktexm aupuname sktexdgmult sktexdgmultmsg ws br adi sktexdg miniws minibr sktcl protoent ndb byteorder
clean:
	rm  sktex sktopt sktexm aupuname sktexdgmult sktexdgmultmsg ws br adi sktexdg miniws minibr sktcl protoent ndb byteorder *.o
