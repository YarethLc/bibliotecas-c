#ifndef LOGICA_H
#define LOGICA_H

/**
 * logica.h — Biblioteca de operaciones de lógica proposicional.
 * Convención: 0 = falso, 1 = verdadero (igual que booleana.h del equipo).
 *
 * Integrante: ARCILA ZAPATA MARKO ANDRES
 * Equipo 1 — Arquitectura de Computadores — UCEVA
 */

#define LOGICA_FALSO    0
#define LOGICA_VERDADERO 1

/* ── Conectivos unarios ─────────────────────────────────────────────────── */
int logica_not(int p);

/* ── Conectivos binarios ────────────────────────────────────────────────── */
int logica_and(int p, int q);
int logica_or(int p, int q);
int logica_xor(int p, int q);
int logica_nand(int p, int q);
int logica_nor(int p, int q);
int logica_implicacion(int p, int q);
int logica_bicondicional(int p, int q);

/* ── Clasificadores ─────────────────────────────────────────────────────── */
int logica_es_tautologia(int p);       /* verifica p \/ ~p */
int logica_es_contradiccion(int p);    /* verifica p /\ ~p */

/* ── Leyes de De Morgan ─────────────────────────────────────────────────── */
int logica_demorgan_and(int p, int q); /* ~(p/\q) == ~p\/~q */
int logica_demorgan_or(int p, int q);  /* ~(p\/q) == ~p/\~q */

/* ── Tablas de verdad ───────────────────────────────────────────────────── */
void logica_tabla_unaria(const char *nombre, int (*fn)(int));
void logica_tabla_binaria(const char *nombre, int (*fn)(int, int));
void logica_tabla_verdad(void);

#endif /* LOGICA_H */
