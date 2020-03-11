
CC = gcc
CFLAGS = -c -ansi -Wall -pedantic


all: test

clear:
	rm *.o test


test: test.o linked_list.o
	$(CC) -o test test.o linked_list.o

test.o: test.c linked_list.h
	$(CC) $(CFLAGS) test.c

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) linked_list.c

