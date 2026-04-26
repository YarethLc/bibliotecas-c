#ifndef MODULOS_H
#define MODULOS_H

#include <stddef.h>

typedef struct {
    int id;
    const char *nombre;
    int prerequisito_id;
} Modulo;

size_t modulos_total(void);
const Modulo *modulos_obtener(size_t indice);
const Modulo *modulos_buscar_por_id(int id);
void modulos_imprimir_ruta(void);

#endif
