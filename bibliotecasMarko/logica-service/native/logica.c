#include <stdio.h>
#include "logica.h"

/**
 * logica.c — Implementación de conectivos y operaciones de lógica proposicional.
 *
 * Convención booleana: 0 = FALSO, 1 = VERDADERO.
 * Cualquier valor != 0 se normaliza a 1 internamente.
 *
 * Integrante: ARCILA ZAPATA MARKO ANDRES
 * Equipo 1 — Arquitectura de Computadores — UCEVA
 */

/* Normaliza cualquier entero a estrictamente 0 o 1 */
static int n(int v) { return (v != 0) ? 1 : 0; }

/* ── Conectivos unarios ──────────────────────────────────────────────────── */

/**
 * logica_not — ~p
 * Invierte el valor de verdad.
 * Tabla: 0->1, 1->0
 * Hardware: instrucción NOT de la ALU.
 */
int logica_not(int p) {
    return n(!n(p));
}

/* ── Conectivos binarios ─────────────────────────────────────────────────── */

/**
 * logica_and — p /\ q
 * Verdadero solo cuando AMBOS son verdaderos.
 * Hardware: instrucción AND de la ALU.
 */
int logica_and(int p, int q) {
    return n(n(p) & n(q));
}

/**
 * logica_or — p \/ q
 * Verdadero cuando AL MENOS UNO es verdadero.
 * Hardware: instrucción OR de la ALU.
 */
int logica_or(int p, int q) {
    return n(n(p) | n(q));
}

/**
 * logica_xor — p XOR q
 * Verdadero cuando EXACTAMENTE UNO es verdadero.
 * Hardware: instrucción XOR de la ALU.
 */
int logica_xor(int p, int q) {
    return n(n(p) ^ n(q));
}

/**
 * logica_nand — ~(p /\ q)
 * Falso solo cuando AMBOS son verdaderos.
 */
int logica_nand(int p, int q) {
    return logica_not(logica_and(p, q));
}

/**
 * logica_nor — ~(p \/ q)
 * Verdadero solo cuando AMBOS son falsos.
 */
int logica_nor(int p, int q) {
    return logica_not(logica_or(p, q));
}

/**
 * logica_implicacion — p -> q
 * Falso SOLO cuando p=V y q=F.
 * Equivalente: ~p \/ q
 */
int logica_implicacion(int p, int q) {
    return n(!n(p) || n(q));
}

/**
 * logica_bicondicional — p <-> q
 * Verdadero cuando p y q tienen el MISMO valor de verdad.
 * Equivalente: (p->q) /\ (q->p)
 */
int logica_bicondicional(int p, int q) {
    return n(n(p) == n(q));
}

/* ── Clasificadores ─────────────────────────────────────────────────────── */

/**
 * logica_es_tautologia — verifica p \/ ~p == 1 para todo p.
 * Retorna 1 si se cumple (siempre lo hace), 0 si hay error.
 */
int logica_es_tautologia(int p) {
    return logica_or(p, logica_not(p));
}

/**
 * logica_es_contradiccion — verifica p /\ ~p == 0 para todo p.
 * Retorna 0 siempre (es contradicción).
 */
int logica_es_contradiccion(int p) {
    return logica_and(p, logica_not(p));
}

/* ── Leyes de De Morgan ─────────────────────────────────────────────────── */

/**
 * logica_demorgan_and — verifica ~(p/\q) == ~p\/~q.
 * Retorna 1 si la equivalencia se cumple para estos valores.
 */
int logica_demorgan_and(int p, int q) {
    int izq = logica_not(logica_and(p, q));
    int der = logica_or(logica_not(p), logica_not(q));
    return n(izq == der);
}

/**
 * logica_demorgan_or — verifica ~(p\/q) == ~p/\~q.
 * Retorna 1 si la equivalencia se cumple para estos valores.
 */
int logica_demorgan_or(int p, int q) {
    int izq = logica_not(logica_or(p, q));
    int der = logica_and(logica_not(p), logica_not(q));
    return n(izq == der);
}

/* ── Tablas de verdad ────────────────────────────────────────────────────── */

void logica_tabla_unaria(const char *nombre, int (*fn)(int)) {
    printf("\n%s:\n", nombre);
    printf("p | %s\n", nombre);
    printf("---------\n");
    int p;
    for (p = 0; p <= 1; p++) {
        printf("%d | %d\n", p, fn(p));
    }
}

void logica_tabla_binaria(const char *nombre, int (*fn)(int, int)) {
    printf("\n%s:\n", nombre);
    printf("p | q | %s\n", nombre);
    printf("---------\n");
    int p, q;
    for (p = 0; p <= 1; p++) {
        for (q = 0; q <= 1; q++) {
            printf("%d | %d | %d\n", p, q, fn(p, q));
        }
    }
}

void logica_tabla_verdad(void) {
    int p, q;

    printf("\n=== TABLAS DE VERDAD — MODULO LOGICA ===\n");
    printf("Integrante: ARCILA ZAPATA MARKO ANDRES — UCEVA\n");

    logica_tabla_unaria("NOT (~p)", logica_not);
    logica_tabla_binaria("AND (p /\\ q)", logica_and);
    logica_tabla_binaria("OR  (p \\/ q)", logica_or);
    logica_tabla_binaria("XOR (p XOR q)", logica_xor);
    logica_tabla_binaria("NAND", logica_nand);
    logica_tabla_binaria("NOR", logica_nor);
    logica_tabla_binaria("IMPLICACION (p -> q)", logica_implicacion);
    logica_tabla_binaria("BICONDICIONAL (p <-> q)", logica_bicondicional);

    printf("\nClasificadores (para p=0 y p=1):\n");
    for (p = 0; p <= 1; p++) {
        printf("  p=%d: p\\/~p=%d (tautologia), p/\\~p=%d (contradiccion)\n",
               p, logica_es_tautologia(p), logica_es_contradiccion(p));
    }

    printf("\nVerificacion De Morgan (todos los casos):\n");
    printf("p | q | ~(p/\\q)==~p\\/~q | ~(p\\/q)==~p/\\~q\n");
    printf("--+---+-----------------+-----------------\n");
    for (p = 0; p <= 1; p++) {
        for (q = 0; q <= 1; q++) {
            printf("%d | %d |        %d        |        %d\n",
                   p, q,
                   logica_demorgan_and(p, q),
                   logica_demorgan_or(p, q));
        }
    }
}
