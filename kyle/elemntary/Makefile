CFLAGS= -c -W -Wall -Werror -std=gnu99
CC=gcc
NAME=main

all: helpers.o elem.o main.o
	$(CC) helpers.o elem.o main.o -o $(NAME)

helpers.o: helpers.c
	$(CC) $(CFLAGS) helpers.c

elem.o: elem.c
	$(CC) $(CFLAGS) elem.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm *.o $(NAME)
