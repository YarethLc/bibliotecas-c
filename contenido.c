#include "contenido.h"

#include <stdio.h>

static const ContenidoItem CONTENIDOS[] = {
    {1, "Logica proposicional", "Proposiciones, conectores y equivalencias logicas."},
    {2, "Predicados", "Cuantificadores y evaluacion en dominios finitos."},
    {3, "Induccion matematica", "Base, hipotesis y paso inductivo."},
    {4, "Sucesiones y sumatorias", "Patrones, formulas cerradas y propiedades."},
    {5, "Teoria de numeros", "Divisibilidad, congruencias y algoritmos."},
    {6, "Residuo chino", "Sistema de congruencias con modulos coprimos."}
};

size_t contenido_total(void) {
    return sizeof(CONTENIDOS) / sizeof(CONTENIDOS[0]);
}

const ContenidoItem *contenido_obtener(size_t indice) {
    if (indice >= contenido_total()) {
        return NULL;
    }
    return &CONTENIDOS[indice];
}

void contenido_imprimir_todos(void) {
    size_t i;
    for (i = 0; i < contenido_total(); ++i) {
        printf("[%d] %s\n", CONTENIDOS[i].id, CONTENIDOS[i].titulo);
        printf("    %s\n", CONTENIDOS[i].texto);
    }
}

void contenido_imprimir_por_id(int id) {
    size_t i;
    for (i = 0; i < contenido_total(); ++i) {
        if (CONTENIDOS[i].id == id) {
            printf("[%d] %s\n", CONTENIDOS[i].id, CONTENIDOS[i].titulo);
            printf("%s\n", CONTENIDOS[i].texto);
            return;
        }
    }
    printf("Contenido no encontrado para id=%d\n", id);
}
