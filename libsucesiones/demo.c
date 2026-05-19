#include <stdio.h>
#include <stdint.h>

#include "sucesiones.h"

int main(void) {
    int err;
    double t;
    double suma;
    uint64_t fib;
    double arit[5];
    uint64_t fibs[10];
    uint32_t i;

    err = sucesion_aritmetica_termino(2.0, 3.0, 4u, &t);
    if (err != SUCESIONES_OK) {
        printf("Error: %s\n", sucesiones_error_texto(err));
        return 1;
    }
    printf("Termino aritmetico n=4: %.2f\n", t);

    err = sucesion_geometrica_suma(1.0, 2.0, 6u, &suma);
    if (err != SUCESIONES_OK) {
        printf("Error: %s\n", sucesiones_error_texto(err));
        return 1;
    }
    printf("Suma geometrica n=6: %.2f\n", suma);

    err = sucesion_fibonacci_termino(20u, &fib);
    if (err != SUCESIONES_OK) {
        printf("Error: %s\n", sucesiones_error_texto(err));
        return 1;
    }
    printf("Fibonacci n=20: %llu\n", (unsigned long long)fib);

    err = sucesion_aritmetica_generar(5.0, -1.0, 5u, arit, 5u);
    if (err != SUCESIONES_OK) {
        printf("Error: %s\n", sucesiones_error_texto(err));
        return 1;
    }

    printf("Aritmetica: ");
    for (i = 0u; i < 5u; ++i) {
        printf("%.2f ", arit[i]);
    }
    printf("\n");

    err = sucesion_fibonacci_generar(10u, fibs, 10u);
    if (err != SUCESIONES_OK) {
        printf("Error: %s\n", sucesiones_error_texto(err));
        return 1;
    }

    printf("Fibonacci: ");
    for (i = 0u; i < 10u; ++i) {
        printf("%llu ", (unsigned long long)fibs[i]);
    }
    printf("\n");

    return 0;
}
