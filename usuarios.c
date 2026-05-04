
/* usuarios.c
 * Plataforma Matemáticas Discretas 1 — UCEVA
 */

#include "usuarios.h"
#include <stdio.h>
#include <string.h>

int usuarios_registrar(const char *rutaArchivo, const Usuario *usuario) {
    FILE *f;
    if (rutaArchivo == NULL || usuario == NULL) return -1;
    f = fopen(rutaArchivo, "ab");
    if (!f) return -1;
    fwrite(usuario, sizeof(Usuario), 1, f);
    fclose(f);
    return 0;
}

int usuarios_existe_correo(const char *rutaArchivo, const char *correo) {
    FILE *f;
    Usuario temp;
    if (rutaArchivo == NULL || correo == NULL) return -1;
    f = fopen(rutaArchivo, "rb");
    if (!f) return 0;
    while (fread(&temp, sizeof(Usuario), 1, f) == 1) {
        if (strcmp(temp.correo, correo) == 0) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int usuarios_validar_datos(const Usuario *usuario) {
    if (usuario == NULL)                  return 0;
    if (strlen(usuario->nombre)     == 0) return 0;
    if (strlen(usuario->correo)     == 0) return 0;
    if (strlen(usuario->clave_hash) == 0) return 0;
    return 1;
}

int usuarios_cargar_por_correo(const char *rutaArchivo,
                               const char *correo,
                               Usuario    *salida) {
    FILE *f;
    Usuario temp;
    if (rutaArchivo == NULL || correo == NULL || salida == NULL) return -1;
    f = fopen(rutaArchivo, "rb");
    if (!f) return -1;
    while (fread(&temp, sizeof(Usuario), 1, f) == 1) {
        if (strcmp(temp.correo, correo) == 0) {
            *salida = temp;
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}
