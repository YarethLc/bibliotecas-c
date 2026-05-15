#include <stdio.h>
#include "combinatoria.h"
int main(void) {
    int op; long n, r, res;
    printf("\n=== CALCULADORA DE COMBINATORIA ===\n");
    printf("1. Factorial(n)\n");
    printf("2. Permutacion P(n,r)\n");
    printf("3. Combinacion C(n,r)\n");
    printf("4. Combinacion con repeticion CR(n,r)\n");
    printf("5. Permutacion con repeticion n^r\n");
    printf("Elige una opcion: "); scanf("%d", &op);
    switch (op) {
        case 1: printf("n = "); scanf("%ld", &n); res = factorial(n);
                printf("Resultado: %ld! = %ld\n", n, res); break;
        case 2: printf("n = "); scanf("%ld", &n); printf("r = "); scanf("%ld", &r);
                res = permutacion(n, r); printf("P(%ld,%ld) = %ld\n", n, r, res); break;
        case 3: printf("n = "); scanf("%ld", &n); printf("r = "); scanf("%ld", &r);
                res = combinacion(n, r); printf("C(%ld,%ld) = %ld\n", n, r, res); break;
        case 4: printf("n = "); scanf("%ld", &n); printf("r = "); scanf("%ld", &r);
                res = combinacion_repeticion(n, r); printf("CR(%ld,%ld) = %ld\n", n, r, res); break;
        case 5: printf("n = "); scanf("%ld", &n); printf("r = "); scanf("%ld", &r);
                res = permutacion_repeticion(n, r); printf("%ld^%ld = %ld\n", n, r, res); break;
        default: printf("Opcion invalida.\n");
    }
    return 0;
}
