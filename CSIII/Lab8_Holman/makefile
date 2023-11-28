CFLAGS = -g -Wall

main: example.o
	g++ $(CFLAGS) example.o -o main

example.o: example.cpp
	g++ $(CFLAGS) -c example.cpp

clean:
	rm *.o main
