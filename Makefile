CC = gcc
FLAGS=-Wextra -Wall -Werror -pedantic -std=c99

all: run

run:  queue.o main.o
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -f run *.o

lib: queue.o
	ar rc lib/libqueue.a queue.o
	ranlib lib/libqueue.a