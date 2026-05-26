package com.denkitronik.booleanaservice.service;

import com.denkitronik.booleanaservice.bridge.BooleanaLibrary;
import org.springframework.stereotype.Service;

@Service
public class BooleanaService {

    private final BooleanaLibrary lib = BooleanaLibrary.INSTANCE;

    private void validarBit(int valor) {
        if (lib.booleana_validar_bit(valor) != 0) {
            throw new IllegalArgumentException("Valor booleano inválido: " + valor);
        }
    }

    public boolean and(int a, int b) {
        validarBit(a);
        validarBit(b);
        return lib.booleana_and(a, b) == 1;
    }

    public boolean or(int a, int b) {
        validarBit(a);
        validarBit(b);
        return lib.booleana_or(a, b) == 1;
    }

    public boolean not(int a) {
        validarBit(a);
        return lib.booleana_not(a) == 1;
    }

    public boolean xor(int a, int b) {
        validarBit(a);
        validarBit(b);
        return lib.booleana_xor(a, b) == 1;
    }

    public boolean nand(int a, int b) {
        validarBit(a);
        validarBit(b);
        return lib.booleana_nand(a, b) == 1;
    }

    public boolean nor(int a, int b) {
        validarBit(a);
        validarBit(b);
        return lib.booleana_nor(a, b) == 1;
    }

    public boolean xnor(int a, int b) {
        validarBit(a);
        validarBit(b);
        return lib.booleana_xnor(a, b) == 1;
    }

    public boolean implica(int a, int b) {
        validarBit(a);
        validarBit(b);
        return lib.booleana_implica(a, b) == 1;
    }

    public boolean equivale(int a, int b) {
        validarBit(a);
        validarBit(b);
        return lib.booleana_equivale(a, b) == 1;
    }

    public int tablaVerdad() {
        return lib.booleana_tabla_verdad();
    }
}