RM = rm -f
CC = gcc
CFLAGS = -g -Wall
default: all
all: serial
serial: main.o cellCount.o displayWorldGeneration.o initaliseWorld.o neighbourSearch.o
	$(CC) -o serial main.o cellCount.o displayWorldGeneration.o initaliseWorld.o neighbourSearch.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c
	
cellCount.o: cellCount.c
	$(CC) $(CFLAGS) -c cellCount.c
	
displayWorldGeneration.o: displayWorldGeneration.c
	$(CC) $(CFLAGS) -c displayWorldGeneration.c
	
initaliseWorld.o: initaliseWorld.c
	$(CC) $(CFLAGS) -c initaliseWorld.c
	
neighbourSearch.o: neighbourSearch.c
	$(CC) $(CFLAGS) -c neighbourSearch.c
	
clean:
	rm serial *.o *~ data/*
