#include <stdio.h>
#include "booleana.h"

int booleana_validar_bit(int valor) {
    if (valor == BOOLEANA_FALSO || valor == BOOLEANA_VERDADERO) {
        return BOOLEANA_OK;
    }

    return BOOLEANA_ERROR_INVALIDO;
}

int booleana_and(int a, int b) {
    if (booleana_validar_bit(a) != BOOLEANA_OK) {
        return BOOLEANA_ERROR_INVALIDO;
    }
    if (booleana_validar_bit(b) != BOOLEANA_OK) {
        return BOOLEANA_ERROR_INVALIDO;
    }

    return a && b;
}

int booleana_or(int a, int b) {
    if (booleana_validar_bit(a) != BOOLEANA_OK) {
        return BOOLEANA_ERROR_INVALIDO;
    }
    if (booleana_validar_bit(b) != BOOLEANA_OK) {
        return BOOLEANA_ERROR_INVALIDO;
    }

    return a || b;
}

int booleana_not(int a) {
    if (booleana_validar_bit(a) != BOOLEANA_OK) {
        return BOOLEANA_ERROR_INVALIDO;
    }

    return !a;
}

int booleana_xor(int a, int b) {
    if (booleana_validar_bit(a) != BOOLEANA_OK) {
        return BOOLEANA_ERROR_INVALIDO;
    }
    if (booleana_validar_bit(b) != BOOLEANA_OK) {
        return BOOLEANA_ERROR_INVALIDO;
    }

    return (a && !b) || (!a && b);
}

int booleana_nand(int a, int b) {
    int resultado;

    resultado = booleana_and(a, b);
    if (resultado < 0) {
        return resultado;
    }

    return booleana_not(resultado);
}

int booleana_nor(int a, int b) {
    int resultado;

    resultado = booleana_or(a, b);
    if (resultado < 0) {
        return resultado;
    }

    return booleana_not(resultado);
}

int booleana_xnor(int a, int b) {
    int resultado;

    resultado = booleana_xor(a, b);
    if (resultado < 0) {
        return resultado;
    }

    return booleana_not(resultado);
}

int booleana_implica(int a, int b) {
    if (booleana_validar_bit(a) != BOOLEANA_OK) {
        return BOOLEANA_ERROR_INVALIDO;
    }
    if (booleana_validar_bit(b) != BOOLEANA_OK) {
        return BOOLEANA_ERROR_INVALIDO;
    }

    return (!a) || b;
}

int booleana_equivale(int a, int b) {
    return booleana_xnor(a, b);
}

int booleana_tabla_verdad(void) {
    int a;
    int b;

    printf("A B | AND OR NOT(A) XOR NAND NOR XNOR IMPLICA EQUIVALE\n");

    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            printf("%d %d |  %d   %d    %d     %d    %d    %d    %d      %d        %d\n",
                   a,
                   b,
                   booleana_and(a, b),
                   booleana_or(a, b),
                   booleana_not(a),
                   booleana_xor(a, b),
                   booleana_nand(a, b),
                   booleana_nor(a, b),
                   booleana_xnor(a, b),
                   booleana_implica(a, b),
                   booleana_equivale(a, b));
        }
    }

    return BOOLEANA_OK;
}