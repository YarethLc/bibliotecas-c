package com.marko.logicaservice.service;

import com.marko.logicaservice.bridge.LogicaLibrary;
import org.springframework.stereotype.Service;

@Service
public class LogicaService {

    /* ── Conectivos unarios ─────────────────────────────────────────────── */

    public int not(int p) {
        return LogicaLibrary.INSTANCE.logica_not(p);
    }

    /* ── Conectivos binarios ────────────────────────────────────────────── */

    public int and(int p, int q) {
        return LogicaLibrary.INSTANCE.logica_and(p, q);
    }

    public int or(int p, int q) {
        return LogicaLibrary.INSTANCE.logica_or(p, q);
    }

    public int xor(int p, int q) {
        return LogicaLibrary.INSTANCE.logica_xor(p, q);
    }

    public int nand(int p, int q) {
        return LogicaLibrary.INSTANCE.logica_nand(p, q);
    }

    public int nor(int p, int q) {
        return LogicaLibrary.INSTANCE.logica_nor(p, q);
    }

    public int implicacion(int p, int q) {
        return LogicaLibrary.INSTANCE.logica_implicacion(p, q);
    }

    public int bicondicional(int p, int q) {
        return LogicaLibrary.INSTANCE.logica_bicondicional(p, q);
    }

    /* ── Clasificadores ─────────────────────────────────────────────────── */

    public int esTautologia(int p) {
        return LogicaLibrary.INSTANCE.logica_es_tautologia(p);
    }

    public int esContradiccion(int p) {
        return LogicaLibrary.INSTANCE.logica_es_contradiccion(p);
    }

    /* ── Leyes de De Morgan ─────────────────────────────────────────────── */

    public int demorganAnd(int p, int q) {
        return LogicaLibrary.INSTANCE.logica_demorgan_and(p, q);
    }

    public int demorganOr(int p, int q) {
        return LogicaLibrary.INSTANCE.logica_demorgan_or(p, q);
    }
}
