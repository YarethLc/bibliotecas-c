#ifndef PREGUNTAS_H
#define PREGUNTAS_H

#include <stddef.h>

#define PREGUNTAS_MAX_OPCIONES 4

typedef struct {
    int id;
    char enunciado[160];
    char opciones[PREGUNTAS_MAX_OPCIONES][80];
    int opcion_correcta;
} Pregunta;

size_t preguntas_cargar_basicas(Pregunta *buffer, size_t capacidad);
const Pregunta *preguntas_buscar(const Pregunta *banco, size_t total, int id);

#endif
