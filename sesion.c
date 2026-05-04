/* sesion.c
 * Plataforma Matemáticas Discretas 1 — UCEVA
 */

#include "sesion.h"
#include "usuarios.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define MAX_INTENTOS 3

const char *sesion_hash_simple(const char *entrada,
                               char       *bufferHex,
                               size_t      capacidad) {
    unsigned long hash = 5381;
    int c;
    const char *p = entrada;
    while ((c = (unsigned char)*p++) != 0) {
        hash = ((hash << 5) + hash) + c;
    }
    snprintf(bufferHex, capacidad, "%016lx", hash);
    return bufferHex;
}

void sesion_iniciar(Sesion *sesion) {
    if (sesion == NULL) return;
    sesion->activa            = 0;
    sesion->intentos_fallidos = 0;
    sesion->correo[0]         = '\0';
}

int sesion_login(Sesion     *sesion,
                 const char *rutaUsuarios,
                 const char *correo,
                 const char *clavePlano) {
    Usuario encontrado;
    char hashIngresado[USUARIOS_MAX_CAMPO];
    int resultado;

    if (sesion == NULL || rutaUsuarios == NULL ||
        correo == NULL || clavePlano  == NULL) return -1;

    if (sesion->intentos_fallidos >= MAX_INTENTOS) {
        printf("Cuenta bloqueada. Demasiados intentos fallidos.\n");
        return -2;
    }

    resultado = usuarios_cargar_por_correo(rutaUsuarios, correo, &encontrado);
    if (resultado != 1) {
        sesion->intentos_fallidos++;
        printf("Usuario no encontrado.\n");
        return -1;
    }

    sesion_hash_simple(clavePlano, hashIngresado, sizeof(hashIngresado));

    if (strcmp(hashIngresado, encontrado.clave_hash) != 0) {
        sesion->intentos_fallidos++;
        printf("Contrasena incorrecta. Intento %d de %d.\n",
               sesion->intentos_fallidos, MAX_INTENTOS);
        return 0;
    }

    sesion->activa            = 1;
    sesion->intentos_fallidos = 0;
    strncpy(sesion->correo, correo, USUARIOS_MAX_CAMPO - 1);
    sesion->correo[USUARIOS_MAX_CAMPO - 1] = '\0';

    printf("Bienvenido, %s\n", encontrado.nombre);
    return 1;
}

void sesion_logout(Sesion *sesion) {
    if (sesion == NULL) return;
    sesion->activa            = 0;
    sesion->intentos_fallidos = 0;
    sesion->correo[0]         = '\0';
    printf("Sesion cerrada correctamente.\n");
}
