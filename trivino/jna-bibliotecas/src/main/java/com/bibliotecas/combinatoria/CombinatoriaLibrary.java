package com.bibliotecas.combinatoria;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Platform;

/**
 * Interfaz JNA que mapea las funciones de la biblioteca C libcombinatorio.so
 *
 * Equivalencias de tipos C → Java:
 *   long (C, 64-bit Linux) → long (Java)
 */
public interface CombinatoriaLibrary extends Library {

    /**
     * Carga la biblioteca nativa.
     * JNA busca primero en java.library.path, luego en el classpath
     * bajo natives/linux-x86-64/libcombinatorio.so
     */
    CombinatoriaLibrary INSTANCE = Native.load(
            resolverNombreLib(),
            CombinatoriaLibrary.class
    );

    // ── Funciones exportadas ──────────────────────────────────────────────

    /** Calcula el factorial de n. */
    long factorial(long n);

    /** Permutación sin repetición P(n, r) = n! / (n-r)! */
    long permutacion(long n, long r);

    /** Combinación sin repetición C(n, r) = n! / (r! * (n-r)!) */
    long combinacion(long n, long r);

    /** Combinación con repetición CR(n, r) = C(n+r-1, r) */
    long combinacion_repeticion(long n, long r);

    /** Permutación con repetición PR(n, r) = n^r */
    long permutacion_repeticion(long n, long r);

    // ── Utilidad de carga ─────────────────────────────────────────────────

    private static String resolverNombreLib() {
        // Permite sobreescribir la ruta con -Dcombinatorio.lib=/ruta/libcombinatorio.so
        String override = System.getProperty("combinatorio.lib");
        if (override != null) return override;
        return "combinatorio"; // JNA añade "lib" y ".so"/".dll" automáticamente
    }
}
