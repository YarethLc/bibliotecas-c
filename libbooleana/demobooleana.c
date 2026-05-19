#include <stdio.h>
#include "booleana.h"

int main(void) {
    int a;
    int b;

    a = 1;
    b = 0;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("AND: %d\n", booleana_and(a, b));
    printf("OR: %d\n", booleana_or(a, b));
    printf("NOT a: %d\n", booleana_not(a));
    printf("XOR: %d\n", booleana_xor(a, b));
    printf("NAND: %d\n", booleana_nand(a, b));
    printf("NOR: %d\n", booleana_nor(a, b));
    printf("XNOR: %d\n", booleana_xnor(a, b));
    printf("IMPLICA: %d\n", booleana_implica(a, b));
    printf("EQUIVALE: %d\n", booleana_equivale(a, b));

    booleana_tabla_verdad();

    return 0;
}