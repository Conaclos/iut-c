
CC = gcc
CFLAGS = -c -ansi -Wall -pedantic


all: test-streq test-strreplace

clear:
	rm *.o test-streq test-strreplace


test-streq: test-streq.o str.o
	$(CC) -o test-streq test-streq.o str.o

test-strreplace: test-strreplace.o str.o
	$(CC) -o test-strreplace test-strreplace.o str.o

str.o: str.c str.h
	$(CC) $(CFLAGS) str.c

test-streq.o: test-streq.c str.h
	$(CC) $(CFLAGS) test-streq.c

test-strreplace.o: test-strreplace.c str.h
	$(CC) $(CFLAGS) test-strreplace.c

