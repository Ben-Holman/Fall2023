CFLAGS = -g -Wall

main: main.o
	g++ $(CFLAGS) main.o -o main

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp node.h linkedlist.h

clean:
	rm *.o main
