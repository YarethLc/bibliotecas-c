
#include "sesion.h"
#include "usuarios.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define MAX_INTENTOS 3

/* -------------------------------------------------------
 * sesion_hash_simple
 * Hash muy sencillo (djb2) que convierte cualquier cadena
 * en una representación hexadecimal.
 * Retorna bufferHex (para poder usarla en expresiones).
 * ------------------------------------------------------- */
const char *sesion_hash_simple(const char *entrada,
                               char       *bufferHex,
                               size_t      capacidad) {
    unsigned long hash = 5381;
    int c;
    const char *p = entrada;

    while ((c = (unsigned char)*p++) != 0) {
        hash = ((hash << 5) + hash) + c;   /* hash * 33 + c */
    }

    snprintf(bufferHex, capacidad, "%016lx", hash);
    return bufferHex;
}

/* -------------------------------------------------------
 * sesion_iniciar
 * Deja la sesión en estado "sin autenticar".
 * ------------------------------------------------------- */
void sesion_iniciar(Sesion *sesion) {
    sesion->activa           = 0;
    sesion->intentos_fallidos = 0;
    sesion->correo[0]        = '\0';
}

/* -------------------------------------------------------
 * sesion_login
 * Intenta autenticar al usuario.
 *   Retorna  1  → login exitoso.
 *   Retorna  0  → credenciales incorrectas.
 *   Retorna -1  → usuario no encontrado en el archivo.
 *   Retorna -2  → demasiados intentos fallidos (bloqueado).
 * ------------------------------------------------------- */
int sesion_login(Sesion     *sesion,
                 const char *rutaUsuarios,
                 const char *correo,
                 const char *clavePlano) {

    /* Bloqueo por intentos */
    if (sesion->intentos_fallidos >= MAX_INTENTOS) {
        printf("Cuenta bloqueada por demasiados intentos fallidos.\n");
        return -2;
    }

    /* Buscar usuario */
    Usuario encontrado;
    int resultado = usuarios_cargar_por_correo(rutaUsuarios, correo, &encontrado);
    if (resultado != 1) {
        sesion->intentos_fallidos++;
        return -1;
    }

    /* Hashear la clave ingresada y comparar */
    char hashIngresado[USUARIOS_MAX_CAMPO];
    sesion_hash_simple(clavePlano, hashIngresado, sizeof(hashIngresado));

    if (strcmp(hashIngresado, encontrado.clave_hash) != 0) {
        sesion->intentos_fallidos++;
        printf("Contraseña incorrecta. Intento %d de %d.\n",
               sesion->intentos_fallidos, MAX_INTENTOS);
        return 0;
    }

    /* Login exitoso */
    sesion->activa            = 1;
    sesion->intentos_fallidos = 0;
    strncpy(sesion->correo, correo, USUARIOS_MAX_CAMPO - 1);
    sesion->correo[USUARIOS_MAX_CAMPO - 1] = '\0';

    printf("Sesión iniciada: %s\n", sesion->correo);
    return 1;
}

/* -------------------------------------------------------
 * sesion_logout
 * Cierra la sesión activa.
 * ------------------------------------------------------- */
void sesion_logout(Sesion *sesion) {
    sesion->activa            = 0;
    sesion->intentos_fallidos = 0;
    sesion->correo[0]         = '\0';
    printf("Sesión cerrada.\n");
}
