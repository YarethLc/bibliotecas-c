#ifndef CONJUNTOS_H
#define CONJUNTOS_H

#define MAX 100

int pertenece(int A[], int n, int e);
int union_conjuntos(int A[], int nA, int B[], int nB, int R[]);
int interseccion(int A[], int nA, int B[], int nB, int R[]);
int diferencia(int A[], int nA, int B[], int nB, int R[]);
int diferencia_simetrica(int A[], int nA, int B[], int nB, int R[]);
int es_subconjunto(int A[], int nA, int B[], int nB);

#endif
