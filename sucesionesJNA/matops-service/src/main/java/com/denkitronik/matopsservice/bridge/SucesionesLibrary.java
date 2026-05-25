package com.denkitronik.matopsservice.bridge;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.DoubleByReference;
import com.sun.jna.ptr.LongByReference;

public interface SucesionesLibrary extends Library {
    // carga la librería (puedes usar NativeLibrary.addSearchPath antes si necesitas indicar carpeta)
    SucesionesLibrary INSTANCE = Native.load("sucesiones", SucesionesLibrary.class);

    int sucesion_aritmetica_termino(double a1, double d, int n, DoubleByReference out_termino);
    int sucesion_geometrica_termino(double a1, double r, int n, DoubleByReference out_termino);
    int sucesion_fibonacci_termino(int n, LongByReference out_termino);

    int sucesion_aritmetica_generar(double a1, double d, int cantidad, double[] out_vector, int out_len);
    int sucesion_geometrica_generar(double a1, double r, int cantidad, double[] out_vector, int out_len);
    int sucesion_fibonacci_generar(int cantidad, long[] out_vector, int out_len);

    int sucesion_aritmetica_suma(double a1, double d, int n, DoubleByReference out_suma);
    int sucesion_geometrica_suma(double a1, double r, int n, DoubleByReference out_suma);
    int sumatoria_naturales(int n, LongByReference out_suma);
    int sumatoria_cuadrados(int n, LongByReference out_suma);

    Pointer sucesiones_error_texto(int error_code);
}