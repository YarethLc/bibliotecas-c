#include "logica_proposicional.h"
#include <stdio.h>

bool AND(bool p, bool q) {
    return p && q;
}

bool OR(bool p, bool q) {
    return p || q;
}

bool NOT(bool p) {
    return !p;
}

bool XOR(bool p, bool q) {
    return (p && !q) || (!p && q);
}

bool NAND(bool p, bool q) {
    return !(p && q);
}

bool NOR(bool p, bool q) {
    return !(p || q);
}

bool IMPLICACION(bool p, bool q) {
    return (!p) || q;
}

bool BICONDICIONAL(bool p, bool q) {
    return IMPLICACION(p, q) && IMPLICACION(q, p);
}

void imprimir_tabla_verdad(const char *nombre, bool (*operacion)(bool, bool)) {
    printf("\n%s:\n", nombre);
    printf("p | q | %s\n", nombre);
    printf("---------\n");
    
    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            bool resultado = operacion((bool)p, (bool)q);
            printf("%d | %d | %d\n", p, q, resultado ? 1 : 0);
        }
    }
}

void imprimir_tabla_verdad_unaria(const char *nombre, bool (*operacion)(bool)) {
    printf("\n%s:\n", nombre);
    printf("p | %s\n", nombre);
    printf("-----\n");
    
    for (int p = 0; p <= 1; p++) {
        bool resultado = operacion((bool)p);
        printf("%d | %d\n", p, resultado ? 1 : 0);
    }
}
