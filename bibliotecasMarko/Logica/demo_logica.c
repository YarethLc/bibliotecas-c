#include <stdio.h>
#include "logica.h"

/**
 * demo_logica.c — Programa de demostración de la biblioteca logica.
 *
 * Integrante: ARCILA ZAPATA MARKO ANDRES
 * Equipo 1 — Arquitectura de Computadores — UCEVA
 */
int main(void) {
    int op;
    int p, q;

    printf("\n=== CALCULADORA DE LOGICA PROPOSICIONAL ===\n");
    printf("1. AND (Conjuncion)\n");
    printf("2. OR  (Disyuncion)\n");
    printf("3. NOT (Negacion)\n");
    printf("4. XOR (Disyuncion exclusiva)\n");
    printf("5. NAND\n");
    printf("6. NOR\n");
    printf("7. IMPLICACION\n");
    printf("8. BICONDICIONAL\n");
    printf("9. Mostrar todas las tablas de verdad\n");
    printf("Elige una opcion: ");
    scanf("%d", &op);

    if (op == 3) {
        printf("Ingresa p (0 o 1): ");
        scanf("%d", &p);
        printf("Resultado: NOT(%d) = %d\n", p, logica_not(p));
        logica_tabla_unaria("NOT (~p)", logica_not);
    } else if (op == 9) {
        logica_tabla_verdad();
    } else if (op >= 1 && op <= 8) {
        printf("Ingresa p (0 o 1): ");
        scanf("%d", &p);
        printf("Ingresa q (0 o 1): ");
        scanf("%d", &q);

        int resultado;
        const char *nombre;
        int (*operacion)(int, int);

        switch (op) {
            case 1: resultado = logica_and(p, q);          nombre = "AND";          operacion = logica_and;          break;
            case 2: resultado = logica_or(p, q);           nombre = "OR";           operacion = logica_or;           break;
            case 4: resultado = logica_xor(p, q);          nombre = "XOR";          operacion = logica_xor;          break;
            case 5: resultado = logica_nand(p, q);         nombre = "NAND";         operacion = logica_nand;         break;
            case 6: resultado = logica_nor(p, q);          nombre = "NOR";          operacion = logica_nor;          break;
            case 7: resultado = logica_implicacion(p, q);  nombre = "IMPLICACION";  operacion = logica_implicacion;  break;
            case 8: resultado = logica_bicondicional(p, q);nombre = "BICONDICIONAL";operacion = logica_bicondicional;break;
            default: printf("Opcion invalida.\n"); return 1;
        }

        printf("Resultado: %d %s %d = %d\n", p, nombre, q, resultado);
        logica_tabla_binaria(nombre, operacion);
    } else {
        printf("Opcion invalida.\n");
    }

    return 0;
}
