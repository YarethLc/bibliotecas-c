CC = gcc
CFLAGS = -Wall

all: libcombinatorio.a libcombinatorio.so demo_combinatoria

combinatoria.o:
	$(CC) $(CFLAGS) -c -o combinatoria.o combinatoria.c

libcombinatorio.a: combinatoria.o
	ar rcs libcombinatorio.a combinatoria.o

libcombinatorio.so: combinatoria.c
	$(CC) $(CFLAGS) -fPIC -c -o combinatoria_pic.o combinatoria.c
	$(CC) -shared -o libcombinatorio.so combinatoria_pic.o

demo_combinatoria: demo_combinatoria.c libcombinatorio.a
	$(CC) $(CFLAGS) -o demo_combinatoria demo_combinatoria.c -L. -lcombinatorio

clean:
	rm -f *.o *.a *.so demo_combinatoria
