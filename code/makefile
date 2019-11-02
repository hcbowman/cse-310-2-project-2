CC=g++
CPPFLAGS=--std=c++11 -pedantic -Wall

all: storm

storm: main.cpp file_handler.o hash_table.o
	$(CC) $(CPPFLAGS) main.cpp file_handler.o hash_table.o -o storm

file_handler.o: file_handler.cpp
	$(CC) $(CPPFLAGS) -c file_handler.cpp

hash_table.o: hash_table.cpp
	$(CC) $(CPPFLAGS) -c hash_table.cpp

clean:
	rm -f *.o *.out *.exe *.stackdump storm