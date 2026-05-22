#include "contenido.h"

#include <stdio.h>

static const ContenidoItem CONTENIDOS[] = {
    {1, "Logica proposicional", "Proposiciones, conectores y equivalencias logicas."},
    {2, "Predicados", "Cuantificadores y evaluacion en dominios finitos."},
    {3, "Induccion matematica", "Base, hipotesis y paso inductivo."},
    {4, "Sucesiones y sumatorias", "Patrones, formulas cerradas y propiedades."},
    {5, "Teoria de numeros", "Divisibilidad, congruencias y algoritmos."},
    {6, "Residuo chino", "Sistema de congruencias con modulos coprimos."},
    {7, "Combinatoria", "Permutaciones, combinaciones y principios de conteo."},
    {8, "Teoria de grafos", "Vertices, aristas, caminos y conectividad."},
    {9, "Algebra booleana", "Operaciones, leyes y simplificacion de expresiones."},
    {10, "Recursion", "Definiciones recursivas, relaciones de recurrencia y demostraciones."},
    {11, "Analisis de complejidad", "Notacion O, omega y theta para algoritmos."},
    {12, "Funciones de crecimiento", "Comportamiento asintotico y comparacion de algoritmos."}
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

const ContenidoItem *contenido_buscar_por_id(int id) {
    size_t i;
    for (i = 0; i < contenido_total(); ++i) {
        if (CONTENIDOS[i].id == id) {
            return &CONTENIDOS[i];
        }
    }
    return NULL;
}

const char *contenido_obtener_titulo(int id) {
    const ContenidoItem *item = contenido_buscar_por_id(id);
    if (item == NULL) {
        return NULL;
    }
    return item->titulo;
}

const char *contenido_obtener_descripcion(int id) {
    const ContenidoItem *item = contenido_buscar_por_id(id);
    if (item == NULL) {
        return NULL;
    }
    return item->texto;
}
