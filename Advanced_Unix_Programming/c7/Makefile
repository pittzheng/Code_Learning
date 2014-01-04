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

f1: f1.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o f1 f1.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

f2: f2.o SimpleSemSysV.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o f2 f2.o SimpleSemSysV.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

f3: f3.o SimpleSemSysV.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o f3 f3.o SimpleSemSysV.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

ipcobjs: ipcobjs.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o ipcobjs ipcobjs.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

lockftest: lockftest.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o lockftest lockftest.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

mt: msg_time.o pcsync_sig.o smi_fifo.o smi_mq.o smi_msg.o smi_skt.o ssi.o smi_shm.o smi_pshm.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o mt msg_time.o pcsync_sig.o smi_fifo.o smi_mq.o smi_msg.o smi_skt.o ssi.o smi_shm.o smi_pshm.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

shmex: shmex.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o shmex shmex.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

shmex2: shmex2.o SimpleSemSysV.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o shmex2 shmex2.o SimpleSemSysV.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

shmex3: shmex3.o SimpleSemSysV.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o shmex3 shmex3.o SimpleSemSysV.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_client: smsg_client.o smsg_makefifoname.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_client smsg_client.o smsg_makefifoname.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_client_smi_fifo: smsg_client_smi_a.o smi_fifo.o smi_fifo_wrap.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_client_smi_fifo smsg_client_smi_a.o smi_fifo.o smi_fifo_wrap.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_client_smi_mq: smsg_client_smi_a.o smi_mq.o smi_mq_wrap.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_client_smi_mq smsg_client_smi_a.o smi_mq.o smi_mq_wrap.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_client_smi_msg: smsg_client_smi_a.o smi_msg.o smi_msg_wrap.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_client_smi_msg smsg_client_smi_a.o smi_msg.o smi_msg_wrap.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_client_smi_pshm: smsg_client_smi_a.o smi_pshm.o smi_pshm_wrap.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_client_smi_pshm smsg_client_smi_a.o smi_pshm.o smi_pshm_wrap.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_client_smi_shm: smsg_client_smi_a.o smi_shm.o smi_shm_wrap.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_client_smi_shm smsg_client_smi_a.o smi_shm.o smi_shm_wrap.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_client_smi_skt: smsg_client_smi_a.o smi_skt.o smi_skt_wrap.o ssi.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_client_smi_skt smsg_client_smi_a.o smi_skt.o smi_skt_wrap.o ssi.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_server: smsg_server.o smsg_makefifoname.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_server smsg_server.o smsg_makefifoname.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_server_smi_fifo: smsg_server_smi_a.o smi_fifo.o smi_fifo_wrap.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_server_smi_fifo smsg_server_smi_a.o smi_fifo.o smi_fifo_wrap.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_server_smi_mq: smsg_server_smi_a.o smi_mq.o smi_mq_wrap.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_server_smi_mq smsg_server_smi_a.o smi_mq.o smi_mq_wrap.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_server_smi_msg: smsg_server_smi_a.o smi_msg.o smi_msg_wrap.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_server_smi_msg smsg_server_smi_a.o smi_msg.o smi_msg_wrap.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_server_smi_pshm: smsg_server_smi_a.o smi_pshm.o smi_pshm_wrap.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_server_smi_pshm smsg_server_smi_a.o smi_pshm.o smi_pshm_wrap.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_server_smi_shm: smsg_server_smi_a.o smi_shm.o smi_shm_wrap.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_server_smi_shm smsg_server_smi_a.o smi_shm.o smi_shm_wrap.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

smsg_server_smi_skt: smsg_server_smi_a.o smi_skt.o smi_skt_wrap.o ssi.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o smsg_server_smi_skt smsg_server_smi_a.o smi_skt.o smi_skt_wrap.o ssi.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

ssp: sstest.o SimpleSemPOSIX.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o ssp sstest.o SimpleSemPOSIX.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

ssv: sstest.o SimpleSemSysV.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o ssv sstest.o SimpleSemSysV.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

uemtst: uemtst.o uem.o $(AUPOBJS) 
	$(CCLINK) -o uemtst uemtst.o uem.o $(AUPOBJS) $(LIBS) $(TLIBS) 

semtest: semtest.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o semtest semtest.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

uem.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/uem.c
	$(CC) $(CFLAGS)  -c -o uem.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/uem.c

f1.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/f1.c
	$(CC) $(CFLAGS)  -c -o f1.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/f1.c

SimpleSemSysV.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/SimpleSemSysV.c
	$(CC) $(CFLAGS)  -c -o SimpleSemSysV.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/SimpleSemSysV.c

smi_shm.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_shm.c
	$(CC) $(CFLAGS)  -c -o smi_shm.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_shm.c

smi_msg.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_msg.c
	$(CC) $(CFLAGS)  -c -o smi_msg.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_msg.c

shmex2.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/shmex2.c
	$(CC) $(CFLAGS)  -c -o shmex2.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/shmex2.c

smi_msg_wrap.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_msg_wrap.c
	$(CC) $(CFLAGS)  -c -o smi_msg_wrap.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_msg_wrap.c

f2.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/f2.c
	$(CC) $(CFLAGS)  -c -o f2.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/f2.c

smi_mq_wrap.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_mq_wrap.c
	$(CC) $(CFLAGS)  -c -o smi_mq_wrap.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_mq_wrap.c

shmex3.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/shmex3.c
	$(CC) $(CFLAGS)  -c -o shmex3.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/shmex3.c

f3.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/f3.c
	$(CC) $(CFLAGS)  -c -o f3.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/f3.c

smi_pshm_wrap.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_pshm_wrap.c
	$(CC) $(CFLAGS)  -c -o smi_pshm_wrap.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_pshm_wrap.c

smi_pshm.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_pshm.c
	$(CC) $(CFLAGS)  -c -o smi_pshm.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_pshm.c

semtest.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/semtest.c
	$(CC) $(CFLAGS)  -c -o semtest.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/semtest.c

smi_fifo.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_fifo.c
	$(CC) $(CFLAGS)  -c -o smi_fifo.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_fifo.c

smsg_client.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smsg_client.c
	$(CC) $(CFLAGS)  -c -o smsg_client.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smsg_client.c

uemtst.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/uemtst.c
	$(CC) $(CFLAGS)  -c -o uemtst.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/uemtst.c

smi_skt_wrap.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_skt_wrap.c
	$(CC) $(CFLAGS)  -c -o smi_skt_wrap.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_skt_wrap.c

smi_shm_wrap.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_shm_wrap.c
	$(CC) $(CFLAGS)  -c -o smi_shm_wrap.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_shm_wrap.c

smi_mq.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_mq.c
	$(CC) $(CFLAGS)  -c -o smi_mq.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_mq.c

smsg_server_smi_a.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smsg_server_smi_a.c
	$(CC) $(CFLAGS)  -c -o smsg_server_smi_a.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smsg_server_smi_a.c

smsg_client_smi_a.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smsg_client_smi_a.c
	$(CC) $(CFLAGS)  -c -o smsg_client_smi_a.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smsg_client_smi_a.c

smi_skt.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_skt.c
	$(CC) $(CFLAGS)  -c -o smi_skt.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_skt.c

lockftest.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/lockftest.c
	$(CC) $(CFLAGS)  -c -o lockftest.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/lockftest.c

smsg_server.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smsg_server.c
	$(CC) $(CFLAGS)  -c -o smsg_server.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smsg_server.c

msg_time.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/msg_time.c
	$(CC) $(CFLAGS)  -c -o msg_time.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/msg_time.c

smi_fifo_wrap.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_fifo_wrap.c
	$(CC) $(CFLAGS)  -c -o smi_fifo_wrap.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smi_fifo_wrap.c

SimpleSemPOSIX.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/SimpleSemPOSIX.c
	$(CC) $(CFLAGS)  -c -o SimpleSemPOSIX.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/SimpleSemPOSIX.c

smsg_makefifoname.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smsg_makefifoname.c
	$(CC) $(CFLAGS)  -c -o smsg_makefifoname.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/smsg_makefifoname.c

sstest.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/sstest.c
	$(CC) $(CFLAGS)  -c -o sstest.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/sstest.c

ssi.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/ssi.c
	$(CC) $(CFLAGS)  -c -o ssi.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c8/ssi.c

shmex.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/shmex.c
	$(CC) $(CFLAGS)  -c -o shmex.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/shmex.c

pcsync_sig.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c6/pcsync_sig.c
	$(CC) $(CFLAGS)  -c -o pcsync_sig.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c6/pcsync_sig.c

ipcobjs.o: /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/ipcobjs.c
	$(CC) $(CFLAGS)  -c -o ipcobjs.o /home/peiqzhen/github/Code_Learning/Advanced_Unix_Programming/c7/ipcobjs.c

all:  lockftest smsg_server_smi_pshm smsg_client_smi_pshm mt smsg_server_smi_fifo smsg_client_smi_fifo smsg_server_smi_skt smsg_client_smi_skt smsg_server_smi_shm smsg_client_smi_shm ssp smsg_server_smi_msg smsg_client_smi_msg uemtst shmex2 shmex3 ssv shmex smsg_client semtest smsg_server_smi_mq smsg_client_smi_mq f1 f2 f3 ipcobjs smsg_server
clean:
	rm  lockftest smsg_server_smi_pshm smsg_client_smi_pshm mt smsg_server_smi_fifo smsg_client_smi_fifo smsg_server_smi_skt smsg_client_smi_skt smsg_server_smi_shm smsg_client_smi_shm ssp smsg_server_smi_msg smsg_client_smi_msg uemtst shmex2 shmex3 ssv shmex smsg_client semtest smsg_server_smi_mq smsg_client_smi_mq f1 f2 f3 ipcobjs smsg_server *.o
