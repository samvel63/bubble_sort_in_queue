CC = gcc
CFLAGS = -g -std=c99

all: run

run:  queue.o main.o
	$(CC) $^ -o $@

clean:
	rm -f run *.o