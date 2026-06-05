package com.bibliotecas;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.NativeLibrary;

/**
 * Interfaz JNA que mapea las funciones de libcombinatorio.so
 *
 * Cada método Java corresponde exactamente a una función C:
 *   long factorial(long n)
 *   long permutacion(long n, long r)
 *   long combinacion(long n, long r)
 *   long combinacion_repeticion(long n, long r)
 *   long permutacion_repeticion(long n, long r)
 */
public interface CombinatoriaLib extends Library {

    /**
     * Carga la librería nativa desde el classpath (resources/native/)
     * o desde java.library.path si está instalada en el sistema.
     */
    static CombinatoriaLib cargar() {
        // Agrega la carpeta de recursos nativos al search path de JNA
        String rutaNativa = CombinatoriaLib.class
                .getResource("/native/libcombinatorio.so")
                .getPath()
                .replace("libcombinatorio.so", "");

        NativeLibrary.addSearchPath("combinatorio", rutaNativa);
        return Native.load("combinatorio", CombinatoriaLib.class);
    }

    // ---------------------------------------------------------------
    // Funciones exportadas por combinatoria.c
    // ---------------------------------------------------------------

    /** Calcula n! (factorial de n). */
    long factorial(long n);

    /** P(n, r) = n! / (n-r)!  — permutación sin repetición. */
    long permutacion(long n, long r);

    /** C(n, r) = n! / (r! * (n-r)!)  — combinación sin repetición. */
    long combinacion(long n, long r);

    /** CR(n, r) = C(n+r-1, r)  — combinación con repetición. */
    long combinacion_repeticion(long n, long r);

    /** PR(n, r) = n^r  — permutación con repetición. */
    long permutacion_repeticion(long n, long r);
}
