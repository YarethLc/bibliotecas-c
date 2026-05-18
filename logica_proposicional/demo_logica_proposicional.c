#include <stdio.h>
#include "logica_proposicional.h"

int main(void) {
    int op;
    int p, q, res;
    
    printf("\n=== CALCULADORA DE LOGICA PROPOSICIONAL ===\n");
    printf("1. AND (Conjuncion)\n");
    printf("2. OR (Disyuncion)\n");
    printf("3. NOT (Negacion)\n");
    printf("4. XOR (Disyuncion exclusiva)\n");
    printf("5. NAND\n");
    printf("6. NOR\n");
    printf("7. IMPLICACION\n");
    printf("8. BICONDICIONAL\n");
    printf("Elige una opcion: ");
    scanf("%d", &op);
    
    if (op == 3) {
        printf("Ingresa p (0 o 1): ");
        scanf("%d", &p);
        bool resultado = NOT((bool)p);
        printf("Resultado: NOT(%d) = %d\n", p, resultado ? 1 : 0);
        imprimir_tabla_verdad_unaria("NOT", NOT);
    } else if (op >= 1 && op <= 8) {
        printf("Ingresa p (0 o 1): ");
        scanf("%d", &p);
        printf("Ingresa q (0 o 1): ");
        scanf("%d", &q);
        
        bool resultado;
        const char *nombre;
        bool (*operacion)(bool, bool);
        
        switch (op) {
            case 1:
                resultado = AND((bool)p, (bool)q);
                nombre = "AND";
                operacion = AND;
                break;
            case 2:
                resultado = OR((bool)p, (bool)q);
                nombre = "OR";
                operacion = OR;
                break;
            case 4:
                resultado = XOR((bool)p, (bool)q);
                nombre = "XOR";
                operacion = XOR;
                break;
            case 5:
                resultado = NAND((bool)p, (bool)q);
                nombre = "NAND";
                operacion = NAND;
                break;
            case 6:
                resultado = NOR((bool)p, (bool)q);
                nombre = "NOR";
                operacion = NOR;
                break;
            case 7:
                resultado = IMPLICACION((bool)p, (bool)q);
                nombre = "IMPLICACION";
                operacion = IMPLICACION;
                break;
            case 8:
                resultado = BICONDICIONAL((bool)p, (bool)q);
                nombre = "BICONDICIONAL";
                operacion = BICONDICIONAL;
                break;
        }
        
        printf("Resultado: %d %s %d = %d\n", p, nombre, q, resultado ? 1 : 0);
        imprimir_tabla_verdad(nombre, operacion);
    } else {
        printf("Opcion invalida.\n");
    }
    
    return 0;
}
