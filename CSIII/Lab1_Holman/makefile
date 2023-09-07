CFLAGS = -g -Wall
main: main.o 
	g++ $(CFLAGS) main.o -o main

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp


clean:
	rm *.o main
