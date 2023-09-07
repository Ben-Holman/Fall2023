CFLAGS = -g -Wall

main: main.o list.o
	g++ $(CFLAGS) main.o list.o -o main

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

list.o: list.cpp list.h
	g++ $(CFLAGS) -c list.cpp

clean:
	rm *.o main
