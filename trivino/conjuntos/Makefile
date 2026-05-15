CC = gcc
CFLAGS = -Wall

all: libconjuntos.a libconjuntos.so demo_conjuntos

conjuntos.o:
	$(CC) $(CFLAGS) -c -o conjuntos.o conjuntos.c

libconjuntos.a: conjuntos.o
	ar rcs libconjuntos.a conjuntos.o

libconjuntos.so: conjuntos.c
	$(CC) $(CFLAGS) -fPIC -c -o conjuntos_pic.o conjuntos.c
	$(CC) -shared -o libconjuntos.so conjuntos_pic.o

demo_conjuntos: demo_conjuntos.c libconjuntos.a
	$(CC) $(CFLAGS) -o demo_conjuntos demo_conjuntos.c -L. -lconjuntos

clean:
	rm -f *.o *.a *.so demo_conjuntos
