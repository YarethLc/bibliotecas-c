CC = gcc
CFLAGS = -Wall

all: libcontenido.a libcontenido.so demo_contenido

contenido.o:
	$(CC) $(CFLAGS) -c -o contenido.o contenido.c

libcontenido.a: contenido.o
	ar rcs libcontenido.a contenido.o

libcontenido.so: contenido.c
	$(CC) $(CFLAGS) -fPIC -c -o contenido_pic.o contenido.c
	$(CC) -shared -o libcontenido.so contenido_pic.o

demo_contenido: demo_contenido.c libcontenido.a
	$(CC) $(CFLAGS) -o demo_contenido demo_contenido.c -L. -lcontenido

clean:
	rm -f *.o *.a *.so demo_contenido
