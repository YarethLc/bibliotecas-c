package com.bibliotecas.conjuntos;

import com.sun.jna.Library;
import com.sun.jna.Native;

/**
 * Interfaz JNA que mapea las funciones de la biblioteca C libconjuntos.so
 *
 * Manejo de arrays:
 *   int[] en Java se pasa directamente como puntero int* en C.
 *   JNA copia automáticamente el contenido al pasar el array.
 *
 * Convención de las funciones de conjuntos:
 *   - A[], nA  → conjunto A y su tamaño
 *   - B[], nB  → conjunto B y su tamaño
 *   - R[]      → array resultado (debe tener espacio suficiente, MAX=100)
 *   - retorno  → tamaño del resultado
 */
public interface ConjuntosLibrary extends Library {

    ConjuntosLibrary INSTANCE = Native.load(
            resolverNombreLib(),
            ConjuntosLibrary.class
    );

    // ── Funciones exportadas ──────────────────────────────────────────────

    /**
     * Verifica si el elemento {@code e} pertenece al conjunto {@code A}.
     * @return 1 si pertenece, 0 si no.
     */
    int pertenece(int[] A, int n, int e);

    /**
     * Unión de A y B → R. Retorna el tamaño de R.
     */
    int union_conjuntos(int[] A, int nA, int[] B, int nB, int[] R);

    /**
     * Intersección de A y B → R. Retorna el tamaño de R.
     */
    int interseccion(int[] A, int nA, int[] B, int nB, int[] R);

    /**
     * Diferencia A - B → R. Retorna el tamaño de R.
     */
    int diferencia(int[] A, int nA, int[] B, int nB, int[] R);

    /**
     * Diferencia simétrica (A-B) ∪ (B-A) → R. Retorna el tamaño de R.
     */
    int diferencia_simetrica(int[] A, int nA, int[] B, int nB, int[] R);

    /**
     * Comprueba si A ⊆ B.
     * @return 1 si A es subconjunto de B, 0 si no.
     */
    int es_subconjunto(int[] A, int nA, int[] B, int nB);

    // ── Utilidad ──────────────────────────────────────────────────────────

    private static String resolverNombreLib() {
        String override = System.getProperty("conjuntos.lib");
        if (override != null) return override;
        return "conjuntos";
    }
}
