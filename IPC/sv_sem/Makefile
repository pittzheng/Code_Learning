RM = @rm -f

CC = gcc

LIBSEM_COMMON = libsem_common.so
SEM_CLIENT_TARGET = sem_client
SEM_SERVER_TARGET = sem_server

LIBSEM_COMMON_SOURCEFILE := sem_common.c
SEM_CLIENT_SOURCEFILE := sem_client.c
SEM_SERVER_SOURCEFILE := sem_server.c

LIBSEM_COMMON_OBJS := $(addsuffix .o, $(basename $(LIBSEM_COMMON_SOURCEFILE)))
SEM_CLIENT_OBJS := $(addsuffix .o, $(basename $(SEM_CLIENT_SOURCEFILE)))
SEM_SERVER_OBJS := $(addsuffix .o, $(basename $(SEM_SERVER_SOURCEFILE)))

LIBSEM_COMMON_CFLAGS := -fPIC -I.
SEM_CLIENT_CFLAGS := -I.
SEM_SERVER_CFLAGS := -I.

LIBSEM_COMMON_LDFLAGS := -shared 
SEM_CLIENT_LDFLAGS := -L. -lsem_common
SEM_SERVER_LDFLAGS := -L. -lsem_common

all: ${LIBSEM_COMMON} ${SEM_CLIENT_TARGET} ${SEM_SERVER_TARGET} 

${LIBSEM_COMMON}: ${LIBSEM_COMMON_OBJS}
	@echo "linking $@ ..."
	${CC} $(LIBSEM_COMMON_OBJS) $(LIBSEM_COMMON_LDFLAGS) -o $(LIBSEM_COMMON)

${SEM_CLIENT_TARGET}: ${SEM_CLIENT_OBJS}
	@echo "linking $@ ..."
	${CC} $(SEM_CLIENT_OBJS)  $(SEM_CLIENT_LDFLAGS) -o ${SEM_CLIENT_TARGET}

${SEM_SERVER_TARGET}: ${SEM_SERVER_OBJS}
	@echo "linking $@ ..."
	${CC} $(SEM_SERVER_OBJS)  $(SEM_SERVER_LDFLAGS) -o ${SEM_SERVER_TARGET}


# %.o: %.c
#     @echo "compiling $(notdir $<)"
#     @echo $(LIBSEM_COMMON_SOURCEFILE)
#     $(CC) $(LIBSEM_COMMON_CFLAGS) -c -o $@ $<

${LIBSEM_COMMON_OBJS}: ${LIBSEM_COMMON_SOURCEFILE}
	@echo "compiling $(notdir $<)"
	@echo $(LIBSEM_COMMON_SOURCEFILE)
	$(CC) $(LIBSEM_COMMON_CFLAGS) -c -o $@ $<

${SEM_CLIENT_OBJS}: ${SEM_CLIENT_SOURCEFILE}
	@echo "compiling $(notdir $<)"
	@echo $(SEM_CLIENT_SOURCEFILE)
	$(CC) $(SEM_CLIENT_CFLAGS) -c -o $@ $<

${SEM_SERVER_OBJS}: ${SEM_SERVER_SOURCEFILE}
	@echo "compiling $(notdir $<)"
	@echo $(SEM_SERVER_SOURCEFILE)
	$(CC) $(SEM_SERVER_CFLAGS) -c -o $@ $<


clean:
	@$(RM) *.o
	@$(RM) ${LIBSEM_COMMON} ${SEM_CLIENT_TARGET} ${SEM_SERVER_TARGET}  
