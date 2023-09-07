CFLAGS = -g -Wall

main: main.o WordList.o
	g++ $(CFLAGS) main.o WordList.o -o main

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

WordList.o: WordList.cpp WordList.h
	g++ $(CFLAGS) -c WordList.cpp
clean:
	rm *.o main
