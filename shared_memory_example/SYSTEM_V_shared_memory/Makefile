OPT_GCC = -std=c99 -Wall -Wextra

OPT = -D_XOPEN_SOURCE=700

all: testread testwrite

testread: testread.c
	gcc $(OPT_GCC) $(OPT) -o testread testread.c

testwrite: testwrite.c
	gcc $(OPT_GCC) $(OPT) -o testwrite testwrite.c

clean:
	rm -f testread testwrite shmseg

