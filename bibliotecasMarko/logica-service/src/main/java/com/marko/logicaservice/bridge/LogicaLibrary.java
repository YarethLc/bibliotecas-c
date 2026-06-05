package com.marko.logicaservice.bridge;

import com.sun.jna.Library;
import com.sun.jna.Native;

public interface LogicaLibrary extends Library {
    LogicaLibrary INSTANCE = (LogicaLibrary)
            Native.load("logica", LogicaLibrary.class);

    /* ── Conectivos unarios ─────────────────────────────────────────────── */
    int logica_not(int p);

    /* ── Conectivos binarios ────────────────────────────────────────────── */
    int logica_and(int p, int q);
    int logica_or(int p, int q);
    int logica_xor(int p, int q);
    int logica_nand(int p, int q);
    int logica_nor(int p, int q);
    int logica_implicacion(int p, int q);
    int logica_bicondicional(int p, int q);

    /* ── Clasificadores ─────────────────────────────────────────────────── */
    int logica_es_tautologia(int p);
    int logica_es_contradiccion(int p);

    /* ── Leyes de De Morgan ─────────────────────────────────────────────── */
    int logica_demorgan_and(int p, int q);
    int logica_demorgan_or(int p, int q);
}
