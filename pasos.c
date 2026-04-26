#include "pasos.h"

#include <stdio.h>

size_t pasos_proposicion_equivalente(const char *expresion, Paso *buffer, size_t capacidad) {
    static const char *PLANTILLA[] = {
        "1) Identificar conectores principales de la expresion.",
        "2) Aplicar equivalencias logicas (De Morgan, doble negacion, etc.).",
        "3) Simplificar terminos repetidos o tautologicos.",
        "4) Verificar equivalencia con una tabla de verdad parcial."
    };
    size_t total = sizeof(PLANTILLA) / sizeof(PLANTILLA[0]);
    size_t i;

    (void)expresion;
    if (buffer == NULL || capacidad == 0) {
        return total;
    }

    for (i = 0; i < total && i < capacidad; ++i) {
        buffer[i].texto = PLANTILLA[i];
    }
    return total;
}

size_t pasos_induccion_basica(const char *enunciado, Paso *buffer, size_t capacidad) {
    static const char *PLANTILLA[] = {
        "1) Probar el caso base n=1 (o el inicial indicado).",
        "2) Suponer verdadera la proposicion para n=k.",
        "3) Demostrar el caso n=k+1 usando la hipotesis inductiva.",
        "4) Concluir por induccion que vale para todo n natural."
    };
    size_t total = sizeof(PLANTILLA) / sizeof(PLANTILLA[0]);
    size_t i;

    (void)enunciado;
    if (buffer == NULL || capacidad == 0) {
        return total;
    }

    for (i = 0; i < total && i < capacidad; ++i) {
        buffer[i].texto = PLANTILLA[i];
    }
    return total;
}

void pasos_imprimir(const Paso *pasos, size_t total) {
    size_t i;
    if (pasos == NULL) {
        return;
    }
    for (i = 0; i < total; ++i) {
        if (pasos[i].texto != NULL) {
            printf("%s\n", pasos[i].texto);
        }
    }
}
