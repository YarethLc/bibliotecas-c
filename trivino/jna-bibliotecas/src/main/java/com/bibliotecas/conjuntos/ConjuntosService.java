package com.bibliotecas.conjuntos;

import java.util.Arrays;

/**
 * Servicio Java que envuelve la biblioteca C de conjuntos.
 *
 * Simplifica el manejo de arrays: internamente trabaja con int[],
 * y los resultados se recortan al tamaño real devuelto por la C library.
 */
public class ConjuntosService {

    /** Tamaño máximo de cualquier conjunto (igual que MAX en conjuntos.h). */
    public static final int MAX = 100;

    private final ConjuntosLibrary lib;

    public ConjuntosService() {
        this.lib = ConjuntosLibrary.INSTANCE;
    }

    public ConjuntosService(ConjuntosLibrary lib) {
        this.lib = lib;
    }

    // ── Operaciones ───────────────────────────────────────────────────────

    /**
     * Verifica si {@code elemento} pertenece al conjunto {@code conjunto}.
     */
    public boolean pertenece(int[] conjunto, int elemento) {
        validarConjunto(conjunto, "conjunto");
        return lib.pertenece(conjunto, conjunto.length, elemento) == 1;
    }

    /**
     * Retorna la unión de A ∪ B.
     */
    public int[] union(int[] a, int[] b) {
        validarConjunto(a, "A");
        validarConjunto(b, "B");
        int[] resultado = new int[MAX];
        int tam = lib.union_conjuntos(a, a.length, b, b.length, resultado);
        return Arrays.copyOf(resultado, tam);
    }

    /**
     * Retorna la intersección A ∩ B.
     */
    public int[] interseccion(int[] a, int[] b) {
        validarConjunto(a, "A");
        validarConjunto(b, "B");
        int[] resultado = new int[MAX];
        int tam = lib.interseccion(a, a.length, b, b.length, resultado);
        return Arrays.copyOf(resultado, tam);
    }

    /**
     * Retorna la diferencia A - B.
     */
    public int[] diferencia(int[] a, int[] b) {
        validarConjunto(a, "A");
        validarConjunto(b, "B");
        int[] resultado = new int[MAX];
        int tam = lib.diferencia(a, a.length, b, b.length, resultado);
        return Arrays.copyOf(resultado, tam);
    }

    /**
     * Retorna la diferencia simétrica (A - B) ∪ (B - A).
     */
    public int[] diferenciaSimetrica(int[] a, int[] b) {
        validarConjunto(a, "A");
        validarConjunto(b, "B");
        int[] resultado = new int[MAX];
        int tam = lib.diferencia_simetrica(a, a.length, b, b.length, resultado);
        return Arrays.copyOf(resultado, tam);
    }

    /**
     * Retorna {@code true} si A ⊆ B.
     */
    public boolean esSubconjunto(int[] a, int[] b) {
        validarConjunto(a, "A");
        validarConjunto(b, "B");
        return lib.es_subconjunto(a, a.length, b, b.length) == 1;
    }

    // ── Validaciones ──────────────────────────────────────────────────────

    private void validarConjunto(int[] conjunto, String nombre) {
        if (conjunto == null)
            throw new IllegalArgumentException("El conjunto " + nombre + " no puede ser null.");
        if (conjunto.length > MAX)
            throw new IllegalArgumentException(
                    "El conjunto " + nombre + " supera MAX=" + MAX + ". Tamaño: " + conjunto.length);
    }
}
