CFLAGS = -g -Wall

main: main.o
	gcc $(CFLAGS) main.o -o main

main.o: main.c functions.hpp
	gcc $(CFLAGS) -c main.c functions.hpp

clean:
	rm *.o main
