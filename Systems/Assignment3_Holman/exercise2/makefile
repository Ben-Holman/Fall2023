CFLAGS = -g -Wall

splitname: splitname.o
	gcc $(CFLAGS) splitname.o -o main

splitname.o: splitname.c
	gcc $(CFLAGS) -c splitname.c

clean:
	rm *.o splitname
