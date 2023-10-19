CC = g++
CFLAGS = -std=c++17

all: matrix

matrix: matrix.o
	$(CC) $(CFLAGS) -o matrix matrix.o

matrix.o: matrix.cpp
	$(CC) $(CFLAGS) -c matrix.cpp

clean:
	rm -rf *.o matrix
