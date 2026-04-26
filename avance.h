#ifndef AVANCE_H
#define AVANCE_H

typedef enum {
    AVANCE_NO_VISTO = 0,
    AVANCE_EN_CURSO = 1,
    AVANCE_COMPLETADO = 2
} EstadoModulo;

int avance_guardar_estado(const char *rutaArchivo, const char *usuario, int moduloId, EstadoModulo estado);
EstadoModulo avance_cargar_estado(const char *rutaArchivo, const char *usuario, int moduloId);
const char *avance_estado_texto(EstadoModulo estado);

#endif
