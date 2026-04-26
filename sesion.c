#include "sesion.h"

#include <stdio.h>
#include <string.h>

void sesion_iniciar(Sesion *sesion) {
    if (sesion == NULL) {
        return;
    }
    sesion->activa = 0;
    sesion->correo[0] = '\0';
    sesion->intentos_fallidos = 0;
}

const char *sesion_hash_simple(const char *entrada, char *bufferHex, size_t capacidad) {
    unsigned long hash = 5381;
    int c;

    if (entrada == NULL || bufferHex == NULL || capacidad < 17) {
        return NULL;
    }

    while ((c = *entrada++) != 0) {
        hash = ((hash << 5) + hash) + (unsigned long)c;
    }

    snprintf(bufferHex, capacidad, "%016lx", hash);
    return bufferHex;
}

int sesion_login(Sesion *sesion, const char *rutaUsuarios, const char *correo, const char *clavePlano) {
    Usuario usuario;
    char hash[USUARIOS_MAX_CAMPO];

    if (sesion == NULL || rutaUsuarios == NULL || correo == NULL || clavePlano == NULL) {
        return 0;
    }

    if (sesion->intentos_fallidos >= 3) {
        return -1;
    }

    if (!usuarios_cargar_por_correo(rutaUsuarios, correo, &usuario)) {
        sesion->intentos_fallidos++;
        return 0;
    }

    if (sesion_hash_simple(clavePlano, hash, sizeof(hash)) == NULL) {
        return 0;
    }

    if (strcmp(hash, usuario.clave_hash) == 0) {
        sesion->activa = 1;
        strncpy(sesion->correo, correo, sizeof(sesion->correo) - 1);
        sesion->correo[sizeof(sesion->correo) - 1] = '\0';
        sesion->intentos_fallidos = 0;
        return 1;
    }

    sesion->intentos_fallidos++;
    return 0;
}

void sesion_logout(Sesion *sesion) {
    if (sesion == NULL) {
        return;
    }
    sesion->activa = 0;
    sesion->correo[0] = '\0';
}
