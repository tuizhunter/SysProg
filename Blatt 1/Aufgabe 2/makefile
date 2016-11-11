CC=gcc
CFLAGS=-std=c99 -g -Wall
DEPS = ownstring.h list.h
OBJ = main.o list.o ownstring.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<


philosophensort: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
