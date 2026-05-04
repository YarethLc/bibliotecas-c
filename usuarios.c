
#include "usuarios.h"
#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------
 * usuarios_registrar
 * Agrega un nuevo usuario al archivo binario.
 * Retorna  0 si se guardó correctamente.
 * Retorna -1 si hubo error al abrir el archivo.
 * ------------------------------------------------------- */
int usuarios_registrar(const char *rutaArchivo, const Usuario *usuario) {
    FILE *f = fopen(rutaArchivo, "ab");
    if (!f) return -1;

    fwrite(usuario, sizeof(Usuario), 1, f);
    fclose(f);
    return 0;
}

/* -------------------------------------------------------
 * usuarios_existe_correo
 * Recorre el archivo buscando si ya existe ese correo.
 * Retorna  1 si existe.
 * Retorna  0 si no existe.
 * Retorna -1 si hubo error al abrir el archivo.
 * ------------------------------------------------------- */
int usuarios_existe_correo(const char *rutaArchivo, const char *correo) {
    FILE *f = fopen(rutaArchivo, "rb");
    if (!f) return 0;   /* si no existe el archivo aún, nadie está registrado */

    Usuario temp;
    while (fread(&temp, sizeof(Usuario), 1, f) == 1) {
        if (strcmp(temp.correo, correo) == 0) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

/* -------------------------------------------------------
 * usuarios_validar_datos
 * Valida que los campos del usuario no estén vacíos.
 * Retorna  1 si los datos son válidos.
 * Retorna  0 si algún campo está vacío.
 * ------------------------------------------------------- */
int usuarios_validar_datos(const Usuario *usuario) {
    if (strlen(usuario->nombre)     == 0) return 0;
    if (strlen(usuario->correo)     == 0) return 0;
    if (strlen(usuario->clave_hash) == 0) return 0;
    return 1;
}

/* -------------------------------------------------------
 * usuarios_cargar_por_correo
 * Busca en el archivo el usuario con ese correo y lo
 * copia en *salida.
 * Retorna  1 si lo encontró.
 * Retorna  0 si no lo encontró.
 * Retorna -1 si hubo error al abrir el archivo.
 * ------------------------------------------------------- */
int usuarios_cargar_por_correo(const char *rutaArchivo,
                               const char *correo,
                               Usuario    *salida) {
    FILE *f = fopen(rutaArchivo, "rb");
    if (!f) return -1;

    Usuario temp;
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
