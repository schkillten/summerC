CFLAGS= -c -W -Wall -Werror -ansi
CC=gcc
NAME=rpn_calc

all: rpn_calc.o stack.o main.o
	$(CC) rpn_calc.o stack.o main.o -o $(NAME)

rpn_calc.o: rpn_calc.c
	$(CC) $(CFLAGS) rpn_calc.c

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm *.o $(NAME)

