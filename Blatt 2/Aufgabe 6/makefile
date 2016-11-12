CC=gcc
CFLAGS=-std=c99 -g -Wall
DEPS = list.h ownstring.h
OBJ = main.o list.o ownstring.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


sort.out: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
