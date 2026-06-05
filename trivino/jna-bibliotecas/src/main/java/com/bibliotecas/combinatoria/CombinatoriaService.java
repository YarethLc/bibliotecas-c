package com.bibliotecas.combinatoria;

/**
 * Servicio Java que envuelve la biblioteca C de combinatoria.
 * Agrega validaciones, mensajes de error claros y una API idiomática.
 */
public class CombinatoriaService {

    private final CombinatoriaLibrary lib;

    public CombinatoriaService() {
        this.lib = CombinatoriaLibrary.INSTANCE;
    }

    /** Constructor para inyección (tests/mocks). */
    public CombinatoriaService(CombinatoriaLibrary lib) {
        this.lib = lib;
    }

    // ── Factorial ─────────────────────────────────────────────────────────

    /**
     * Calcula n! (factorial de n).
     * @param n número no negativo
     * @return n!
     * @throws IllegalArgumentException si n < 0 o n > 20 (desbordamiento long)
     */
    public long factorial(long n) {
        validarNoNegativo(n, "n");
        if (n > 20) throw new IllegalArgumentException(
                "n=" + n + " produce desbordamiento en long. Use BigInteger para valores > 20.");
        return lib.factorial(n);
    }

    // ── Permutaciones ─────────────────────────────────────────────────────

    /**
     * Permutación sin repetición P(n, r).
     * Número de formas de ordenar r elementos de un conjunto de n.
     */
    public long permutacion(long n, long r) {
        validarNoNegativo(n, "n");
        validarNoNegativo(r, "r");
        if (r > n) throw new IllegalArgumentException(
                "r=" + r + " no puede ser mayor que n=" + n);
        return lib.permutacion(n, r);
    }

    /**
     * Permutación con repetición PR(n, r) = n^r.
     * Número de secuencias de longitud r tomadas de n elementos con repetición.
     */
    public long permutacionRepeticion(long n, long r) {
        validarNoNegativo(n, "n");
        validarNoNegativo(r, "r");
        return lib.permutacion_repeticion(n, r);
    }

    // ── Combinaciones ─────────────────────────────────────────────────────

    /**
     * Combinación sin repetición C(n, r).
     * Número de subconjuntos de tamaño r de un conjunto de n elementos.
     */
    public long combinacion(long n, long r) {
        validarNoNegativo(n, "n");
        validarNoNegativo(r, "r");
        if (r > n) throw new IllegalArgumentException(
                "r=" + r + " no puede ser mayor que n=" + n);
        return lib.combinacion(n, r);
    }

    /**
     * Combinación con repetición CR(n, r) = C(n+r-1, r).
     * Número de multiconjuntos de tamaño r formados con n tipos de elementos.
     */
    public long combinacionRepeticion(long n, long r) {
        validarNoNegativo(n, "n");
        validarNoNegativo(r, "r");
        return lib.combinacion_repeticion(n, r);
    }

    // ── Validaciones ──────────────────────────────────────────────────────

    private void validarNoNegativo(long valor, String nombre) {
        if (valor < 0) throw new IllegalArgumentException(
                nombre + " no puede ser negativo. Recibido: " + valor);
    }
}
