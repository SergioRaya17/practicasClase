CC=gcc
CFLAGS=-I.

centros: centros.o utils.o
	$(CC) -o centros centros.o utils.o $(CFLAGS)

centros.o: centros.c estructuras.h utils.h
	$(CC) -c centros.c $(CFLAGS)

utils.o: utils.c utils.h
	$(CC) -c utils.c $(CFLAGS)

clean:
	rm -f *.o centros
