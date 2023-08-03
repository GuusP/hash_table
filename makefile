CC = gcc
CFLAGS = -Wall -lm

objects = main.o hash.o

all: myht

myht: $(objects)
	$(CC) -o myht $(objects) -lm

hash.o: hash.c
	$(CC) -c $(CFLAGS) hash.c

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f $(objects)

purge: clean
	rm -f myht

