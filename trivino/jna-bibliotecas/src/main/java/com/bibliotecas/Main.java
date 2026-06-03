package com.bibliotecas;

import java.util.Arrays;

/**
 * Clase principal que demuestra el uso de ambas bibliotecas C
 * a través de JNA (Java Native Access).
 *
 * Ejecución:
 *   mvn compile exec:java
 */
public class Main {

    public static void main(String[] args) {

        demoCombinaria();
        System.out.println();
        demoConjuntos();
    }

    // ------------------------------------------------------------------
    // Demo Combinatoria
    // ------------------------------------------------------------------
    private static void demoCombinaria() {
        CombinatoriaLib lib = CombinatoriaLib.cargar();

        System.out.println("========== COMBINATORIA (via JNA) ==========");

        System.out.printf("factorial(5)                  = %d%n", lib.factorial(5));
        System.out.printf("factorial(10)                 = %d%n", lib.factorial(10));

        System.out.printf("permutacion(5, 3)             = %d%n", lib.permutacion(5, 3));
        System.out.printf("permutacion(10, 2)            = %d%n", lib.permutacion(10, 2));

        System.out.printf("combinacion(5, 3)             = %d%n", lib.combinacion(5, 3));
        System.out.printf("combinacion(10, 4)            = %d%n", lib.combinacion(10, 4));

        System.out.printf("combinacion_repeticion(5, 3)  = %d%n", lib.combinacion_repeticion(5, 3));
        System.out.printf("combinacion_repeticion(4, 2)  = %d%n", lib.combinacion_repeticion(4, 2));

        System.out.printf("permutacion_repeticion(3, 4)  = %d%n", lib.permutacion_repeticion(3, 4));
        System.out.printf("permutacion_repeticion(2, 8)  = %d%n", lib.permutacion_repeticion(2, 8));
    }

    // ------------------------------------------------------------------
    // Demo Conjuntos
    // ------------------------------------------------------------------
    private static void demoConjuntos() {
        ConjuntosLib lib = ConjuntosLib.cargar();

        System.out.println("========== CONJUNTOS (via JNA) ==========");

        int[] A = {1, 2, 3, 4, 5};
        int[] B = {3, 4, 5, 6, 7};
        int nA  = A.length;
        int nB  = B.length;

        System.out.println("A = " + Arrays.toString(A));
        System.out.println("B = " + Arrays.toString(B));
        System.out.println();

        // pertenece
        System.out.printf("pertenece(A, 3) = %d  (1=sí, 0=no)%n", lib.pertenece(A, nA, 3));
        System.out.printf("pertenece(A, 9) = %d  (1=sí, 0=no)%n", lib.pertenece(A, nA, 9));

        // unión
        int[] R = new int[100];
        int nr = lib.union_conjuntos(A, nA, B, nB, R);
        System.out.printf("A ∪ B = %s%n", Arrays.toString(Arrays.copyOf(R, nr)));

        // intersección
        nr = lib.interseccion(A, nA, B, nB, R);
        System.out.printf("A ∩ B = %s%n", Arrays.toString(Arrays.copyOf(R, nr)));

        // diferencia A - B
        nr = lib.diferencia(A, nA, B, nB, R);
        System.out.printf("A - B = %s%n", Arrays.toString(Arrays.copyOf(R, nr)));

        // diferencia B - A
        nr = lib.diferencia(B, nB, A, nA, R);
        System.out.printf("B - A = %s%n", Arrays.toString(Arrays.copyOf(R, nr)));

        // diferencia simétrica
        nr = lib.diferencia_simetrica(A, nA, B, nB, R);
        System.out.printf("A △ B = %s%n", Arrays.toString(Arrays.copyOf(R, nr)));

        // subconjunto
        int[] C = {1, 2, 3};
        System.out.printf("%nC = %s%n", Arrays.toString(C));
        System.out.printf("C ⊆ A = %d  (1=sí, 0=no)%n", lib.es_subconjunto(C, C.length, A, nA));
        System.out.printf("A ⊆ C = %d  (1=sí, 0=no)%n", lib.es_subconjunto(A, nA, C, C.length));
    }
}
