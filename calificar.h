#ifndef CALIFICAR_H
#define CALIFICAR_H

#include <stddef.h>

#include "preguntas.h"

typedef struct {
    int correctas;
    int incorrectas;
    double nota100;
} ResultadoEvaluacion;

ResultadoEvaluacion calificar_respuestas(
    const Pregunta *banco,
    size_t total,
    const int *respuestas,
    size_t respuestasTotal
);

void calificar_imprimir(ResultadoEvaluacion resultado);

#endif
