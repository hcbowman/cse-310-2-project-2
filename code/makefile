CC=g++
CPPFLAGS=--std=c++11 -pedantic -Wall

all: storm

storm: main.cpp heap.o defn.o prime.o
	$(CC) $(CPPFLAGS) main.cpp heap.o defn.o prime.o -o storm

heap.o: heap.cpp
	$(CC) $(CPPFLAGS) -c heap.cpp

prime.o: prime.cpp
	$(CC) $(CPPFLAGS) -c prime.cpp

clean:
	rm -f *.o *.out *.exe *.stackdump storm