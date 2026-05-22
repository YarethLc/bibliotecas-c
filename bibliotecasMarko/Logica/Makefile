CC = gcc
CFLAGS = -Wall

all: liblogica.a liblogica.so demo_logica

logica.o:
	$(CC) $(CFLAGS) -c -o logica.o logica.c

liblogica.a: logica.o
	ar rcs liblogica.a logica.o

liblogica.so: logica.c
	$(CC) $(CFLAGS) -fPIC -c -o logica_pic.o logica.c
	$(CC) -shared -o liblogica.so logica_pic.o

demo_logica: demo_logica.c liblogica.a
	$(CC) $(CFLAGS) -o demo_logica demo_logica.c -L. -llogica

clean:
	rm -f *.o *.a *.so demo_logica
