#include "preguntas.h"

#include <string.h>

size_t preguntas_cargar_basicas(Pregunta *buffer, size_t capacidad) {
    size_t total = 3;

    if (buffer == NULL || capacidad == 0) {
        return total;
    }

    if (capacidad >= 1) {
        buffer[0].id = 1;
        strncpy(buffer[0].enunciado, "Si p->q y p son verdaderas, q es:", sizeof(buffer[0].enunciado) - 1);
        buffer[0].enunciado[sizeof(buffer[0].enunciado) - 1] = '\0';
        strncpy(buffer[0].opciones[0], "Verdadera", sizeof(buffer[0].opciones[0]) - 1);
        buffer[0].opciones[0][sizeof(buffer[0].opciones[0]) - 1] = '\0';
        strncpy(buffer[0].opciones[1], "Falsa", sizeof(buffer[0].opciones[1]) - 1);
        buffer[0].opciones[1][sizeof(buffer[0].opciones[1]) - 1] = '\0';
        strncpy(buffer[0].opciones[2], "Indeterminada", sizeof(buffer[0].opciones[2]) - 1);
        buffer[0].opciones[2][sizeof(buffer[0].opciones[2]) - 1] = '\0';
        strncpy(buffer[0].opciones[3], "Ninguna", sizeof(buffer[0].opciones[3]) - 1);
        buffer[0].opciones[3][sizeof(buffer[0].opciones[3]) - 1] = '\0';
        buffer[0].opcion_correcta = 0;
    }

    if (capacidad >= 2) {
        buffer[1].id = 2;
        strncpy(buffer[1].enunciado, "Formula de suma 1+2+...+n:", sizeof(buffer[1].enunciado) - 1);
        buffer[1].enunciado[sizeof(buffer[1].enunciado) - 1] = '\0';
        strncpy(buffer[1].opciones[0], "n(n+1)/2", sizeof(buffer[1].opciones[0]) - 1);
        buffer[1].opciones[0][sizeof(buffer[1].opciones[0]) - 1] = '\0';
        strncpy(buffer[1].opciones[1], "n^2", sizeof(buffer[1].opciones[1]) - 1);
        buffer[1].opciones[1][sizeof(buffer[1].opciones[1]) - 1] = '\0';
        strncpy(buffer[1].opciones[2], "2n+1", sizeof(buffer[1].opciones[2]) - 1);
        buffer[1].opciones[2][sizeof(buffer[1].opciones[2]) - 1] = '\0';
        strncpy(buffer[1].opciones[3], "n!", sizeof(buffer[1].opciones[3]) - 1);
        buffer[1].opciones[3][sizeof(buffer[1].opciones[3]) - 1] = '\0';
        buffer[1].opcion_correcta = 0;
    }

    if (capacidad >= 3) {
        buffer[2].id = 3;
        strncpy(buffer[2].enunciado, "Si x congruente 2 (mod 3) y 2 (mod 5), una solucion es:", sizeof(buffer[2].enunciado) - 1);
        buffer[2].enunciado[sizeof(buffer[2].enunciado) - 1] = '\0';
        strncpy(buffer[2].opciones[0], "2", sizeof(buffer[2].opciones[0]) - 1);
        buffer[2].opciones[0][sizeof(buffer[2].opciones[0]) - 1] = '\0';
        strncpy(buffer[2].opciones[1], "3", sizeof(buffer[2].opciones[1]) - 1);
        buffer[2].opciones[1][sizeof(buffer[2].opciones[1]) - 1] = '\0';
        strncpy(buffer[2].opciones[2], "5", sizeof(buffer[2].opciones[2]) - 1);
        buffer[2].opciones[2][sizeof(buffer[2].opciones[2]) - 1] = '\0';
        strncpy(buffer[2].opciones[3], "7", sizeof(buffer[2].opciones[3]) - 1);
        buffer[2].opciones[3][sizeof(buffer[2].opciones[3]) - 1] = '\0';
        buffer[2].opcion_correcta = 0;
    }

    return total;
}

const Pregunta *preguntas_buscar(const Pregunta *banco, size_t total, int id) {
    size_t i;
    if (banco == NULL) {
        return NULL;
    }
    for (i = 0; i < total; ++i) {
        if (banco[i].id == id) {
            return &banco[i];
        }
    }
    return NULL;
}
