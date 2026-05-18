CC = gcc
CFLAGS = -Wall

all: demo_logica_proposicional

logica_proposicional.o:
	$(CC) $(CFLAGS) -c logica_proposicional.c

demo_logica_proposicional: logica_proposicional.o demo_logica_proposicional.c
	$(CC) $(CFLAGS) -o demo_logica_proposicional logica_proposicional.o demo_logica_proposicional.c

clean:
	rm -f *.o demo_logica_proposicional
