CFLAGS = -g -Wall
all: main main2 main3
main: main.o
	gcc $(CFLAGS) main.o -o main

main.o: main.c
	gcc $(CFLAGS) -c main.c

main2: main2.o
	gcc $(CFLAGS) main2.o -o main2

main2.o: main2.c
	gcc $(CFLAGS) -c main2.c

main3: main3.o
	gcc $(CFLAGS) main3.o -o main3

main3.o: main3.c
	gcc $(CFLAGS) -c main3.c

clean:
	rm *.o main main2 main3
