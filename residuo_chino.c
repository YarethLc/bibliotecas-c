#include "residuo_chino.h"

// Calcula el inverso de a mod m usando Euclides Extendido
//  mcd + combinación lineal
int inverso(int a, int m) {

    int r0 = m, r1 = a;
    int t0 = 0, t1 = 1;

    while (r1 != 0) {
        int q = r0 / r1;

        int r2 = r0 - q * r1;
        r0 = r1;
        r1 = r2;

        int t2 = t0 - q * t1;
        t0 = t1;
        t1 = t2;
    }

    // Si el mcd no es 1, no existe inverso
    if (r0 != 1)
        return -1;

    // Ajustar el inverso al módulo
    if (t0 < 0)
        t0 += m;

    return t0;
}

// Teorema del Residuo Chino para 3 congruencias
int trc3(int a1, int m1, int a2, int m2, int a3, int m3) {

    // Paso 1: m = m1*m2*m3
    int m = m1 * m2 * m3;

    // Paso 2: M1, M2, M3
    int M1 = m / m1;
    int M2 = m / m2;
    int M3 = m / m3;

    // Paso 3: inversos Y1, Y2, Y3
    int Y1 = inverso(M1 % m1, m1);
    int Y2 = inverso(M2 % m2, m2);
    int Y3 = inverso(M3 % m3, m3);

    // Paso 4: fórmula
    int x = a1 * M1 * Y1 +
            a2 * M2 * Y2 +
            a3 * M3 * Y3;

    // Resultado final mod m
    x = x % m;
    if (x < 0) x += m;

    return x;
}
