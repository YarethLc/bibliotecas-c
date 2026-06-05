package com.bibliotecas;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.NativeLibrary;

/**
 * Interfaz JNA que mapea las funciones de libconjuntos.so
 *
 * Las funciones C que trabajan con arreglos int[] se mapean
 * directamente: JNA convierte int[] de Java en int* de C.
 *
 * Funciones disponibles:
 *   int pertenece(int A[], int n, int e)
 *   int union_conjuntos(int A[], int nA, int B[], int nB, int R[])
 *   int interseccion(int A[], int nA, int B[], int nB, int R[])
 *   int diferencia(int A[], int nA, int B[], int nB, int R[])
 *   int diferencia_simetrica(int A[], int nA, int B[], int nB, int R[])
 *   int es_subconjunto(int A[], int nA, int B[], int nB)
 */
public interface ConjuntosLib extends Library {

    /**
     * Carga la librería nativa desde el classpath (resources/native/)
     * o desde java.library.path si está instalada en el sistema.
     */
    static ConjuntosLib cargar() {
        String rutaNativa = ConjuntosLib.class
                .getResource("/native/libconjuntos.so")
                .getPath()
                .replace("libconjuntos.so", "");

        NativeLibrary.addSearchPath("conjuntos", rutaNativa);
        return Native.load("conjuntos", ConjuntosLib.class);
    }

    // ---------------------------------------------------------------
    // Funciones exportadas por conjuntos.c
    // ---------------------------------------------------------------

    /**
     * Verifica si el elemento {@code e} pertenece al conjunto {@code A} de tamaño {@code n}.
     * @return 1 si pertenece, 0 si no.
     */
    int pertenece(int[] A, int n, int e);

    /**
     * Calcula A ∪ B y guarda el resultado en {@code R}.
     * @return tamaño del conjunto resultado.
     */
    int union_conjuntos(int[] A, int nA, int[] B, int nB, int[] R);

    /**
     * Calcula A ∩ B y guarda el resultado en {@code R}.
     * @return tamaño del conjunto resultado.
     */
    int interseccion(int[] A, int nA, int[] B, int nB, int[] R);

    /**
     * Calcula A - B y guarda el resultado en {@code R}.
     * @return tamaño del conjunto resultado.
     */
    int diferencia(int[] A, int nA, int[] B, int nB, int[] R);

    /**
     * Calcula (A - B) ∪ (B - A) y guarda el resultado en {@code R}.
     * @return tamaño del conjunto resultado.
     */
    int diferencia_simetrica(int[] A, int nA, int[] B, int nB, int[] R);

    /**
     * Verifica si A ⊆ B.
     * @return 1 si A es subconjunto de B, 0 si no.
     */
    int es_subconjunto(int[] A, int nA, int[] B, int nB);
}
