#ifndef SUCESIONES_H
#define SUCESIONES_H

#include <stdint.h>

#define SUCESIONES_OK 0
#define SUCESIONES_ERROR_NULL 1
#define SUCESIONES_ERROR_INVALID_ARG 2
#define SUCESIONES_ERROR_SIZE 3
#define SUCESIONES_ERROR_OVERFLOW 4

int sucesion_aritmetica_termino(double a1, double d, uint32_t n, double* out_termino);
int sucesion_geometrica_termino(double a1, double r, uint32_t n, double* out_termino);
int sucesion_fibonacci_termino(uint32_t n, uint64_t* out_termino);

int sucesion_aritmetica_generar(double a1, double d, uint32_t cantidad, double* out_vector, uint32_t out_len);
int sucesion_geometrica_generar(double a1, double r, uint32_t cantidad, double* out_vector, uint32_t out_len);
int sucesion_fibonacci_generar(uint32_t cantidad, uint64_t* out_vector, uint32_t out_len);

int sucesion_aritmetica_suma(double a1, double d, uint32_t n, double* out_suma);
int sucesion_geometrica_suma(double a1, double r, uint32_t n, double* out_suma);
int sumatoria_naturales(uint32_t n, uint64_t* out_suma);
int sumatoria_cuadrados(uint32_t n, uint64_t* out_suma);

const char* sucesiones_error_texto(int error_code);

#endif /* SUCESIONES_H */
