#include "calificar.h"

#include <stdio.h>

ResultadoEvaluacion calificar_respuestas(
    const Pregunta *banco,
    size_t total,
    const int *respuestas,
    size_t respuestasTotal
) {
    ResultadoEvaluacion resultado;
    size_t i;

    resultado.correctas = 0;
    resultado.incorrectas = 0;
    resultado.nota100 = 0.0;

    if (banco == NULL || respuestas == NULL || total == 0 || respuestasTotal == 0) {
        return resultado;
    }

    for (i = 0; i < total && i < respuestasTotal; ++i) {
        if (respuestas[i] == banco[i].opcion_correcta) {
            resultado.correctas++;
        } else {
            resultado.incorrectas++;
        }
    }

    resultado.nota100 = (resultado.correctas * 100.0) / (double)(resultado.correctas + resultado.incorrectas);
    return resultado;
}

void calificar_imprimir(ResultadoEvaluacion resultado) {
    printf("Correctas: %d\n", resultado.correctas);
    printf("Incorrectas: %d\n", resultado.incorrectas);
    printf("Nota: %.2f/100\n", resultado.nota100);
}
