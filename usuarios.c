#include "usuarios.h"

#include <stdio.h>
#include <string.h>

static int campo_valido(const char *texto) {
    if (texto == NULL || texto[0] == '\0') {
        return 0;
    }
    if (strchr(texto, ';') != NULL || strchr(texto, '\n') != NULL || strchr(texto, '\r') != NULL) {
        return 0;
    }
    return 1;
}

int usuarios_validar_datos(const Usuario *usuario) {
    const char *arroba;
    const char *punto;

    if (usuario == NULL) {
        return 0;
    }

    if (!campo_valido(usuario->nombre) || !campo_valido(usuario->correo) || !campo_valido(usuario->clave_hash)) {
        return 0;
    }

    arroba = strchr(usuario->correo, '@');
    punto = strrchr(usuario->correo, '.');
    if (arroba == NULL || punto == NULL || arroba > punto) {
        return 0;
    }

    return 1;
}

int usuarios_existe_correo(const char *rutaArchivo, const char *correo) {
    FILE *archivo;
    char linea[256];
    char nombreLeido[USUARIOS_MAX_CAMPO];
    char correoLeido[USUARIOS_MAX_CAMPO];
    char hashLeido[USUARIOS_MAX_CAMPO];

    if (rutaArchivo == NULL || correo == NULL) {
        return 0;
    }

    archivo = fopen(rutaArchivo, "r");
    if (archivo == NULL) {
        return 0;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if (sscanf(linea, "%63[^;];%63[^;];%63[^\n]", nombreLeido, correoLeido, hashLeido) == 3) {
            if (strcmp(correoLeido, correo) == 0) {
                fclose(archivo);
                return 1;
            }
        }
    }

    fclose(archivo);
    return 0;
}

int usuarios_registrar(const char *rutaArchivo, const Usuario *usuario) {
    FILE *archivo;

    if (rutaArchivo == NULL || !usuarios_validar_datos(usuario)) {
        return 0;
    }

    if (usuarios_existe_correo(rutaArchivo, usuario->correo)) {
        return 0;
    }

    archivo = fopen(rutaArchivo, "a");
    if (archivo == NULL) {
        return 0;
    }

    fprintf(archivo, "%s;%s;%s\n", usuario->nombre, usuario->correo, usuario->clave_hash);
    fclose(archivo);
    return 1;
}

int usuarios_cargar_por_correo(const char *rutaArchivo, const char *correo, Usuario *salida) {
    FILE *archivo;
    char linea[256];

    if (rutaArchivo == NULL || correo == NULL || salida == NULL) {
        return 0;
    }

    archivo = fopen(rutaArchivo, "r");
    if (archivo == NULL) {
        return 0;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if (sscanf(linea, "%63[^;];%63[^;];%63[^\n]", salida->nombre, salida->correo, salida->clave_hash) == 3) {
            if (strcmp(salida->correo, correo) == 0) {
                fclose(archivo);
                return 1;
            }
        }
    }

    fclose(archivo);
    return 0;
}
