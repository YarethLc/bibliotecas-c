#ifndef USUARIOS_H
#define USUARIOS_H

#define USUARIOS_MAX_CAMPO 64

typedef struct {
    char nombre[USUARIOS_MAX_CAMPO];
    char correo[USUARIOS_MAX_CAMPO];
    char clave_hash[USUARIOS_MAX_CAMPO];
} Usuario;

int usuarios_registrar(const char *rutaArchivo, const Usuario *usuario);
int usuarios_existe_correo(const char *rutaArchivo, const char *correo);
int usuarios_validar_datos(const Usuario *usuario);
int usuarios_cargar_por_correo(const char *rutaArchivo, const char *correo, Usuario *salida);

#endif
