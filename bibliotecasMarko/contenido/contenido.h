#ifndef CONTENIDO_H
#define CONTENIDO_H

#include <stddef.h>

typedef struct {
    int id;
    const char *titulo;
    const char *texto;
} ContenidoItem;

size_t contenido_total(void);
const ContenidoItem *contenido_obtener(size_t indice);
const ContenidoItem *contenido_buscar_por_id(int id);
const char *contenido_obtener_titulo(int id);
const char *contenido_obtener_descripcion(int id);
void contenido_imprimir_todos(void);
void contenido_imprimir_por_id(int id);

#endif
