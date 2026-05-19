#ifndef BOOLEANA_H
#define BOOLEANA_H

#define BOOLEANA_OK 0
#define BOOLEANA_ERROR_INVALIDO 1

#define BOOLEANA_FALSO 0
#define BOOLEANA_VERDADERO 1

int booleana_validar_bit(int valor);

int booleana_and(int a, int b);
int booleana_or(int a, int b);
int booleana_not(int a);

int booleana_xor(int a, int b);
int booleana_nand(int a, int b);
int booleana_nor(int a, int b);
int booleana_xnor(int a, int b);

int booleana_implica(int a, int b);
int booleana_equivale(int a, int b);

int booleana_tabla_verdad(void);

#endif