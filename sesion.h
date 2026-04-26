#ifndef SESION_H
#define SESION_H

#include <stddef.h>

#include "usuarios.h"

typedef struct {
    int activa;
    char correo[USUARIOS_MAX_CAMPO];
    int intentos_fallidos;
} Sesion;

void sesion_iniciar(Sesion *sesion);
int sesion_login(Sesion *sesion, const char *rutaUsuarios, const char *correo, const char *clavePlano);
void sesion_logout(Sesion *sesion);
const char *sesion_hash_simple(const char *entrada, char *bufferHex, size_t capacidad);

#endif
