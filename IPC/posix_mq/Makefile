RM = @rm -f

CC = gcc

SEND_TARGET = mq_send
RECV_TARGET = mq_recv
REMOVE_TARGET = mq_remove

SEND_SOURCE := mq_common.c mq_send.c
RECV_SOURCE := mq_common.c mq_recv.c
REMOVE_SOURCE := mq_common.c mq_remove.c

SEND_OBJS := $(addsuffix .o, $(basename $(SEND_SOURCE)))
RECV_OBJS := $(addsuffix .o, $(basename $(RECV_SOURCE)))
REMOVE_OBJS := $(addsuffix .o, $(basename $(REMOVE_SOURCE)))

MQ_CFLAGS := -I.

MQ_LDFLAGS := -lrt

all: ${SEND_TARGET} ${RECV_TARGET} ${REMOVE_TARGET}

${SEND_TARGET}: ${SEND_OBJS}
	@echo "linking $@ ..."
	${CC} $(SEND_OBJS) $(MQ_LDFLAGS) -o $(SEND_TARGET)

${RECV_TARGET}: ${RECV_OBJS}
	@echo "linking $@ ..."
	${CC} $(RECV_OBJS) $(MQ_LDFLAGS) -o $(RECV_TARGET)

${REMOVE_TARGET}: ${REMOVE_OBJS}
	@echo "linking $@ ..."
	${CC} $(REMOVE_OBJS) $(MQ_LDFLAGS) -o $(REMOVE_TARGET)

%.o: %.c
	@echo "compiling $(notdir $<)"
	@echo $(SEND_SOURCE) ${RECV_SOURCE} ${REMOVE_SOURCE}
	$(CC) $(MQ_CFLAGS) -c -o $@ $<

clean:
	@$(RM) *.o
	@$(RM) ${SEND_TARGET} ${RECV_TARGET} ${REMOVE_TARGET}
