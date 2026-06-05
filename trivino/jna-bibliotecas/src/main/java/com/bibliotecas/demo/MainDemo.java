package com.bibliotecas.demo;

import com.bibliotecas.combinatoria.CombinatoriaService;
import com.bibliotecas.conjuntos.ConjuntosService;

import java.util.Arrays;

/**
 * Demo completo de las bibliotecas C cargadas vía JNA.
 *
 * Para ejecutar:
 *   mvn exec:java
 *
 * Si los .so no están en java.library.path, especifica la ruta:
 *   mvn exec:java -Dcombinatorio.lib=/ruta/libcombinatorio.so
 *                 -Dconjuntos.lib=/ruta/libconjuntos.so
 */
public class MainDemo {

    public static void main(String[] args) {
        System.out.println("╔══════════════════════════════════════════════════╗");
        System.out.println("║        BIBLIOTECAS C → JAVA vía JNA              ║");
        System.out.println("╚══════════════════════════════════════════════════╝\n");

        demoCombinatoría();
        System.out.println();
        demoConjuntos();
    }

    // ── Demo Combinatoria ─────────────────────────────────────────────────

    private static void demoCombinatoría() {
        System.out.println("━━━━━━━━━━━━━━━━  COMBINATORIA  ━━━━━━━━━━━━━━━━");

        CombinatoriaService comb = new CombinatoriaService();

        // Factorial
        System.out.println("\n[ Factorial ]");
        for (long n : new long[]{0, 1, 5, 10, 20}) {
            System.out.printf("  %2d! = %,d%n", n, comb.factorial(n));
        }

        // Permutaciones sin repetición
        System.out.println("\n[ Permutación sin repetición P(n, r) ]");
        System.out.printf("  P(5, 2) = %d   (ordenar 2 de 5 elementos)%n",  comb.permutacion(5, 2));
        System.out.printf("  P(10, 3) = %d  (ordenar 3 de 10 elementos)%n", comb.permutacion(10, 3));

        // Permutaciones con repetición
        System.out.println("\n[ Permutación con repetición PR(n, r) = n^r ]");
        System.out.printf("  PR(3, 4) = %d   (secuencias de 4 con 3 opciones)%n",
                comb.permutacionRepeticion(3, 4));
        System.out.printf("  PR(10, 3) = %d  (todos los números de 3 dígitos)%n",
                comb.permutacionRepeticion(10, 3));

        // Combinaciones sin repetición
        System.out.println("\n[ Combinación sin repetición C(n, r) ]");
        System.out.printf("  C(5, 2) = %d   (subconjuntos de 2 de 5)%n",  comb.combinacion(5, 2));
        System.out.printf("  C(10, 3) = %d  (subconjuntos de 3 de 10)%n", comb.combinacion(10, 3));

        // Combinaciones con repetición
        System.out.println("\n[ Combinación con repetición CR(n, r) ]");
        System.out.printf("  CR(3, 2) = %d   (elegir 2 de 3 tipos con repetición)%n",
                comb.combinacionRepeticion(3, 2));
        System.out.printf("  CR(5, 3) = %d  (elegir 3 de 5 tipos con repetición)%n",
                comb.combinacionRepeticion(5, 3));
    }

    // ── Demo Conjuntos ────────────────────────────────────────────────────

    private static void demoConjuntos() {
        System.out.println("━━━━━━━━━━━━━━━━━  CONJUNTOS  ━━━━━━━━━━━━━━━━━");

        ConjuntosService conj = new ConjuntosService();

        int[] A = {1, 2, 3, 4, 5};
        int[] B = {3, 4, 5, 6, 7};
        int[] C = {3, 4};         // subconjunto de A

        System.out.printf("%nA = %s%n", Arrays.toString(A));
        System.out.printf("B = %s%n", Arrays.toString(B));
        System.out.printf("C = %s (subconjunto de A)%n", Arrays.toString(C));

        System.out.println("\n[ Pertenencia ]");
        System.out.printf("  ¿3 ∈ A? %s%n", conj.pertenece(A, 3));
        System.out.printf("  ¿9 ∈ A? %s%n", conj.pertenece(A, 9));

        System.out.println("\n[ Unión  A ∪ B ]");
        System.out.printf("  %s%n", Arrays.toString(conj.union(A, B)));

        System.out.println("\n[ Intersección  A ∩ B ]");
        System.out.printf("  %s%n", Arrays.toString(conj.interseccion(A, B)));

        System.out.println("\n[ Diferencia  A - B ]");
        System.out.printf("  %s%n", Arrays.toString(conj.diferencia(A, B)));

        System.out.println("\n[ Diferencia  B - A ]");
        System.out.printf("  %s%n", Arrays.toString(conj.diferencia(B, A)));

        System.out.println("\n[ Diferencia simétrica  (A - B) ∪ (B - A) ]");
        System.out.printf("  %s%n", Arrays.toString(conj.diferenciaSimetrica(A, B)));

        System.out.println("\n[ Subconjunto ]");
        System.out.printf("  ¿C ⊆ A? %s%n", conj.esSubconjunto(C, A));
        System.out.printf("  ¿A ⊆ B? %s%n", conj.esSubconjunto(A, B));
    }
}
