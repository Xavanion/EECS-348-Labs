CC = gcc
CFLAGS = -Wall

all: sales

sales: sales.o
	$(CC) $(CFLAGS) -o sales sales.o

sales.o: sales.c
	$(CC) $(CFLAGS) -c sales.c

clean:
	rm -f sales *.o
