.PHONY: run

CFLAGS=-Wall -Werror -O2 -g -ggdb

run: main
	./main

main: main.c Makefile
	clang $(CFLAGS) main.c -o main
