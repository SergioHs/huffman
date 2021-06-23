# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -O3

default: main

huffman.o: huffman.c huffman_interface.h huffman_privado.h
	$(CC) $(CFLAGS) -c huffman.c -o huffman.o

main: main.c huffman.o
	$(CC) $(CFLAGS) main.c huffman.o -o huffman

clean:
	rm -f main *.o core a.out *.*~ Makefile~

all: main
