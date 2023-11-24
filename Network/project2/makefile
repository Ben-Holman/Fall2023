CFLAGS = -g -Wall

all: sender rec

sender: sender.o
	gcc $(CFLAGS) sender.o -o sender

sender.o: sender.c
	gcc $(CFLAGS) -c sender.c

rec: rec.o
	gcc $(CFLAGS) rec.o -o rec

rec.o: rec.c
	gcc $(CFLAGS) -c rec.c

clean:
	rm *.o sender rec
