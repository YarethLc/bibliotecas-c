#include <stdio.h>
#include "conjuntos.h"
void leer(int A[], int *n, char nom) {
    printf("Cuantos elementos tiene %c? ", nom); scanf("%d", n);
    printf("Ingresa los %d elementos: ", *n);
    for (int i = 0; i < *n; i++) scanf("%d", &A[i]);
}
void imprimir(int A[], int n) {
    printf("{ "); for (int i = 0; i < n; i++) printf("%d ", A[i]); printf("}\n");
}
int main(void) {
    int A[MAX], B[MAX], R[MAX], nA, nB, nr, op;
    printf("\n=== CALCULADORA DE CONJUNTOS ===\n");
    printf("1. Union\n2. Interseccion\n3. Diferencia A-B\n");
    printf("4. Diferencia simetrica\n5. Es A subconjunto de B?\n");
    printf("Elige una opcion: "); scanf("%d", &op);
    leer(A, &nA, 'A'); leer(B, &nB, 'B');
    switch (op) {
        case 1: nr = union_conjuntos(A,nA,B,nB,R); printf("A U B = "); imprimir(R,nr); break;
        case 2: nr = interseccion(A,nA,B,nB,R); printf("A n B = "); imprimir(R,nr); break;
        case 3: nr = diferencia(A,nA,B,nB,R); printf("A - B = "); imprimir(R,nr); break;
        case 4: nr = diferencia_simetrica(A,nA,B,nB,R); printf("A  B = "); imprimir(R,nr); break;
        case 5: printf(es_subconjunto(A,nA,B,nB)?"Si, A es subconjunto de B\n":"No, A NO es subconjunto de B\n"); break;
        default: printf("Opcion invalida.\n");
    }
    return 0;
}
