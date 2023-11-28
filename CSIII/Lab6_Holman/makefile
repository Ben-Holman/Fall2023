CFLAGS = -g -Wall

main: zoo.o
	g++ $(CFLAGS) zoo.o -o main

zoo.o: zoo.cpp
	g++ $(CFLAGS) -c zoo.cpp

clean:
	rm *.o main
