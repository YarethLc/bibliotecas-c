package com.denkitronik.booleanaservice.bridge;

import com.sun.jna.Library;
import com.sun.jna.Native;

public interface BooleanaLibrary extends Library {

    BooleanaLibrary INSTANCE = Native.load("booleana", BooleanaLibrary.class);

    int booleana_validar_bit(int valor);

    int booleana_and(int a, int b);
    int booleana_or(int a, int b);
    int booleana_not(int a);

    int booleana_xor(int a, int b);
    int booleana_nand(int a, int b);
    int booleana_nor(int a, int b);
    int booleana_xnor(int a, int b);

    int booleana_implica(int a, int b);
    int booleana_equivale(int a, int b);

    int booleana_tabla_verdad();
}