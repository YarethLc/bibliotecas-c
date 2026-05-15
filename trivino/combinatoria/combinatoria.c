#include "combinatoria.h"
long factorial(long n) {
    if (n <= 1) return 1;
    long r = 1;
    for (long i = 2; i <= n; i++) r *= i;
    return r;
}
long permutacion(long n, long r) {
    if (r > n) return 0;
    return factorial(n) / factorial(n - r);
}
long combinacion(long n, long r) {
    if (r > n) return 0;
    return factorial(n) / (factorial(r) * factorial(n - r));
}
long combinacion_repeticion(long n, long r) {
    return combinacion(n + r - 1, r);
}
long permutacion_repeticion(long n, long r) {
    long res = 1;
    for (long i = 0; i < r; i++) res *= n;
    return res;
}
