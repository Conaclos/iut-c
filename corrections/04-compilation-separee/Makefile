
CC = gcc
CFLAGs = -c -Wall -pedantic
PGM = main


$(PGM): main.o fighter-bet-pointers.o random_name.o
	$(CC) -o $(PGM) *.o

random_name.o: random_name.c random_name.h
	$(CC) $(CFLAGs) random_name.c

fighter-bet-pointers.o: fighter-bet-pointers.c fighter-bet-pointers.h random_name.h
	$(CC) $(CFLAGs) fighter-bet-pointers.c

main.o: main.c fighter-bet-pointers.h
	$(CC) $(CFLAGs) main.c


clear:
	rm $(PGM) *.o

