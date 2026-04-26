#include "avance.h"

#include <stdio.h>
#include <string.h>

int avance_guardar_estado(const char *rutaArchivo, const char *usuario, int moduloId, EstadoModulo estado) {
    FILE *archivo;

    if (rutaArchivo == NULL || usuario == NULL) {
        return 0;
    }

    archivo = fopen(rutaArchivo, "a");
    if (archivo == NULL) {
        return 0;
    }

    fprintf(archivo, "%s;%d;%d\n", usuario, moduloId, (int)estado);
    fclose(archivo);
    return 1;
}

EstadoModulo avance_cargar_estado(const char *rutaArchivo, const char *usuario, int moduloId) {
    FILE *archivo;
    char linea[256];
    char usuarioLeido[128];
    int moduloLeido;
    int estadoLeido;
    EstadoModulo ultimo = AVANCE_NO_VISTO;

    if (rutaArchivo == NULL || usuario == NULL) {
        return AVANCE_NO_VISTO;
    }

    archivo = fopen(rutaArchivo, "r");
    if (archivo == NULL) {
        return AVANCE_NO_VISTO;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if (sscanf(linea, "%127[^;];%d;%d", usuarioLeido, &moduloLeido, &estadoLeido) == 3) {
            if (strcmp(usuarioLeido, usuario) == 0 && moduloLeido == moduloId) {
                if (estadoLeido >= AVANCE_NO_VISTO && estadoLeido <= AVANCE_COMPLETADO) {
                    ultimo = (EstadoModulo)estadoLeido;
                }
            }
        }
    }

    fclose(archivo);
    return ultimo;
}

const char *avance_estado_texto(EstadoModulo estado) {
    switch (estado) {
        case AVANCE_NO_VISTO:
            return "No visto";
        case AVANCE_EN_CURSO:
            return "En curso";
        case AVANCE_COMPLETADO:
            return "Completado";
        default:
            return "Desconocido";
    }
}
