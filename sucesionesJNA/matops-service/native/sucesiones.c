#include <math.h>
#include <stddef.h>
#include <stdint.h>

#ifdef _WIN32
#define SUCESIONES_API __declspec(dllexport)
#else
#define SUCESIONES_API
#endif

#define SUCESIONES_OK 0
#define SUCESIONES_ERROR_NULL 1
#define SUCESIONES_ERROR_INVALID_ARG 2
#define SUCESIONES_ERROR_SIZE 3
#define SUCESIONES_ERROR_OVERFLOW 4

/*
 * Convencion de indices:
 * - Sucesiones/progresiones aritmetica y geometrica: n inicia en 1.
 * - Fibonacci: n inicia en 0 (F0 = 0, F1 = 1).
 */

SUCESIONES_API int sucesion_aritmetica_termino(double a1, double d, uint32_t n, double* out_termino) {
    if (out_termino == NULL) {
        return SUCESIONES_ERROR_NULL;
    }
    if (n == 0u) {
        return SUCESIONES_ERROR_INVALID_ARG;
    }

    *out_termino = a1 + (double)(n - 1u) * d;
    return SUCESIONES_OK;
}

SUCESIONES_API int sucesion_geometrica_termino(double a1, double r, uint32_t n, double* out_termino) {
    if (out_termino == NULL) {
        return SUCESIONES_ERROR_NULL;
    }
    if (n == 0u) {
        return SUCESIONES_ERROR_INVALID_ARG;
    }

    *out_termino = a1 * pow(r, (double)(n - 1u));
    return SUCESIONES_OK;
}

SUCESIONES_API int sucesion_fibonacci_termino(uint32_t n, uint64_t* out_termino) {
    uint32_t i;
    uint64_t prev;
    uint64_t curr;
    uint64_t next;

    if (out_termino == NULL) {
        return SUCESIONES_ERROR_NULL;
    }

    if (n == 0u) {
        *out_termino = 0u;
        return SUCESIONES_OK;
    }
    if (n == 1u) {
        *out_termino = 1u;
        return SUCESIONES_OK;
    }

    prev = 0u;
    curr = 1u;
    for (i = 2u; i <= n; ++i) {
        if (UINT64_MAX - curr < prev) {
            return SUCESIONES_ERROR_OVERFLOW;
        }
        next = prev + curr;
        prev = curr;
        curr = next;
    }

    *out_termino = curr;
    return SUCESIONES_OK;
}

SUCESIONES_API int sucesion_aritmetica_generar(double a1, double d, uint32_t cantidad, double* out_vector, uint32_t out_len) {
    uint32_t i;

    if (out_vector == NULL) {
        return SUCESIONES_ERROR_NULL;
    }
    if (cantidad == 0u) {
        return SUCESIONES_ERROR_INVALID_ARG;
    }
    if (out_len < cantidad) {
        return SUCESIONES_ERROR_SIZE;
    }

    for (i = 0u; i < cantidad; ++i) {
        out_vector[i] = a1 + (double)i * d;
    }

    return SUCESIONES_OK;
}

SUCESIONES_API int sucesion_geometrica_generar(double a1, double r, uint32_t cantidad, double* out_vector, uint32_t out_len) {
    uint32_t i;
    double actual;

    if (out_vector == NULL) {
        return SUCESIONES_ERROR_NULL;
    }
    if (cantidad == 0u) {
        return SUCESIONES_ERROR_INVALID_ARG;
    }
    if (out_len < cantidad) {
        return SUCESIONES_ERROR_SIZE;
    }

    actual = a1;
    for (i = 0u; i < cantidad; ++i) {
        out_vector[i] = actual;
        actual *= r;
    }

    return SUCESIONES_OK;
}

SUCESIONES_API int sucesion_fibonacci_generar(uint32_t cantidad, uint64_t* out_vector, uint32_t out_len) {
    uint32_t i;

    if (out_vector == NULL) {
        return SUCESIONES_ERROR_NULL;
    }
    if (cantidad == 0u) {
        return SUCESIONES_ERROR_INVALID_ARG;
    }
    if (out_len < cantidad) {
        return SUCESIONES_ERROR_SIZE;
    }

    out_vector[0] = 0u;
    if (cantidad == 1u) {
        return SUCESIONES_OK;
    }

    out_vector[1] = 1u;
    for (i = 2u; i < cantidad; ++i) {
        if (UINT64_MAX - out_vector[i - 1u] < out_vector[i - 2u]) {
            return SUCESIONES_ERROR_OVERFLOW;
        }
        out_vector[i] = out_vector[i - 1u] + out_vector[i - 2u];
    }

    return SUCESIONES_OK;
}

SUCESIONES_API int sucesion_aritmetica_suma(double a1, double d, uint32_t n, double* out_suma) {
    if (out_suma == NULL) {
        return SUCESIONES_ERROR_NULL;
    }
    if (n == 0u) {
        return SUCESIONES_ERROR_INVALID_ARG;
    }

    *out_suma = ((double)n / 2.0) * (2.0 * a1 + (double)(n - 1u) * d);
    return SUCESIONES_OK;
}

SUCESIONES_API int sucesion_geometrica_suma(double a1, double r, uint32_t n, double* out_suma) {
    if (out_suma == NULL) {
        return SUCESIONES_ERROR_NULL;
    }
    if (n == 0u) {
        return SUCESIONES_ERROR_INVALID_ARG;
    }

    if (r == 1.0) {
        *out_suma = a1 * (double)n;
        return SUCESIONES_OK;
    }

    *out_suma = a1 * (1.0 - pow(r, (double)n)) / (1.0 - r);
    return SUCESIONES_OK;
}

SUCESIONES_API int sumatoria_naturales(uint32_t n, uint64_t* out_suma) {
    if (out_suma == NULL) {
        return SUCESIONES_ERROR_NULL;
    }

    if (n == 0u) {
        *out_suma = 0u;
        return SUCESIONES_OK;
    }

    /* Formula: n(n + 1)/2 */
    if ((uint64_t)n > (UINT64_MAX / ((uint64_t)n + 1u))) {
        return SUCESIONES_ERROR_OVERFLOW;
    }

    *out_suma = ((uint64_t)n * ((uint64_t)n + 1u)) / 2u;
    return SUCESIONES_OK;
}

SUCESIONES_API int sumatoria_cuadrados(uint32_t n, uint64_t* out_suma) {
    uint64_t a;
    uint64_t b;
    uint64_t c;

    if (out_suma == NULL) {
        return SUCESIONES_ERROR_NULL;
    }

    if (n == 0u) {
        *out_suma = 0u;
        return SUCESIONES_OK;
    }

    /* Formula: n(n + 1)(2n + 1)/6 */
    a = (uint64_t)n;
    b = (uint64_t)n + 1u;
    c = 2u * (uint64_t)n + 1u;

    if (a > UINT64_MAX / b) {
        return SUCESIONES_ERROR_OVERFLOW;
    }
    a *= b;

    if (a > UINT64_MAX / c) {
        return SUCESIONES_ERROR_OVERFLOW;
    }
    a *= c;

    *out_suma = a / 6u;
    return SUCESIONES_OK;
}

SUCESIONES_API const char* sucesiones_error_texto(int error_code) {
    switch (error_code) {
        case SUCESIONES_OK:
            return "OK";
        case SUCESIONES_ERROR_NULL:
            return "Puntero nulo";
        case SUCESIONES_ERROR_INVALID_ARG:
            return "Argumento invalido";
        case SUCESIONES_ERROR_SIZE:
            return "Tamano de buffer insuficiente";
        case SUCESIONES_ERROR_OVERFLOW:
            return "Overflow numerico";
        default:
            return "Codigo de error desconocido";
    }
}
