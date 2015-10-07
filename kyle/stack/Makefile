CFLAGS= -c -W -Wall -Werror -ansi
CC=gcc
NAME=main

all: rpn.o stack.o main.o
	$(CC) rpn.o stack.o main.o -o $(NAME)

rpn_calc.o: rpn.c
	$(CC) $(CFLAGS) rpn.c

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm *.o $(NAME)

