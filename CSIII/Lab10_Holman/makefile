CFLAGS = -g -Wall

main: bridgeFigures.o
	g++ $(CFLAGS) bridgeFigures.o -o main

bridgeFigures.o: bridgeFigures.cpp
	g++ $(CFLAGS) -c bridgeFigures.cpp

clean:
	rm *.o main
