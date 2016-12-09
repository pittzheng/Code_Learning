OPT_GCC = -std=c99 -Wall -Wextra

OPT = -D_XOPEN_SOURCE=700
LIB = -lrt

all: cons prod

cons: consumer.c
	gcc $(OPT_GCC) $(OPT) -o cons consumer.c $(LIB)

prod: producer.c
	gcc $(OPT_GCC) $(OPT) -o prod producer.c $(LIB)

run: cons prod
	./prod
	./cons

clean:
	rm -f cons prod

