#include "modulos.h"

#include <stdio.h>

static const Modulo MODULOS[] = {
    {1, "Logica proposicional", 0},
    {2, "Predicados y demostracion", 1},
    {3, "Induccion matematica", 2},
    {4, "Sucesiones y sumatorias", 3},
    {5, "Teoria de numeros", 4},
    {6, "Teorema del residuo chino", 5}
};

size_t modulos_total(void) {
    return sizeof(MODULOS) / sizeof(MODULOS[0]);
}

const Modulo *modulos_obtener(size_t indice) {
    if (indice >= modulos_total()) {
        return NULL;
    }
    return &MODULOS[indice];
}

const Modulo *modulos_buscar_por_id(int id) {
    size_t i;
    for (i = 0; i < modulos_total(); ++i) {
        if (MODULOS[i].id == id) {
            return &MODULOS[i];
        }
    }
    return NULL;
}

void modulos_imprimir_ruta(void) {
    size_t i;
    for (i = 0; i < modulos_total(); ++i) {
        printf("Modulo %d: %s", MODULOS[i].id, MODULOS[i].nombre);
        if (MODULOS[i].prerequisito_id > 0) {
            printf(" (requiere modulo %d)", MODULOS[i].prerequisito_id);
        }
        printf("\n");
    }
}
