CC = gcc

CFLAGS = -Wall -g -std=c99

solution: main.o
	$(CC) main.o -lm -o solution

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm *.o solution
	clear
