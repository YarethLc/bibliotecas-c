#include "conjuntos.h"

int pertenece(int A[], int n, int e) {
    for (int i = 0; i < n; i++) if (A[i] == e) return 1;
    return 0;
}

int union_conjuntos(int A[], int nA, int B[], int nB, int R[]) {
    int nr = 0;
    for (int i = 0; i < nA; i++) R[nr++] = A[i];
    for (int i = 0; i < nB; i++) if (!pertenece(A, nA, B[i])) R[nr++] = B[i];
    return nr;
}

int interseccion(int A[], int nA, int B[], int nB, int R[]) {
    int nr = 0;
    for (int i = 0; i < nA; i++) if (pertenece(B, nB, A[i])) R[nr++] = A[i];
    return nr;
}

int diferencia(int A[], int nA, int B[], int nB, int R[]) {
    int nr = 0;
    for (int i = 0; i < nA; i++) if (!pertenece(B, nB, A[i])) R[nr++] = A[i];
    return nr;
}

int diferencia_simetrica(int A[], int nA, int B[], int nB, int R[]) {
    int t1[MAX], t2[MAX];
    int n1 = diferencia(A, nA, B, nB, t1);
    int n2 = diferencia(B, nB, A, nA, t2);
    int nr = 0;
    for (int i = 0; i < n1; i++) R[nr++] = t1[i];
    for (int i = 0; i < n2; i++) R[nr++] = t2[i];
    return nr;
}

int es_subconjunto(int A[], int nA, int B[], int nB) {
    for (int i = 0; i < nA; i++) if (!pertenece(B, nB, A[i])) return 0;
    return 1;
}
