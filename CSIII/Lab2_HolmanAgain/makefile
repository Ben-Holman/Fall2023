CFLAGS = -g -std=c++20 -Wall


main: main.o wordlist.o Wordoccurrence.o
	g++ $(CFLAGS) main.o wordlist.o Wordoccurrence.o -o main

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

wordlist.o: wordlist.cpp wordlist.h
	g++ $(CFLAGS) -c wordlist.cpp

Wordoccurrence.o: Wordoccurrence.cpp Wordoccurrence.h
	g++ $(CFLAGS) -c Wordoccurrence.cpp

clean:
	rm *.o main
