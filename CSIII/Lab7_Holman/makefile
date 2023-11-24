CFLAGS = -g -Wall

main: testHashmap-2.o
	g++ $(CFLAGS) testHashmap-2.o -o main

testHashmap-2.o: testHashmap-2.cpp
	g++ $(CFLAGS) -c testHashmap-2.cpp

clean:
	rm *.o main
