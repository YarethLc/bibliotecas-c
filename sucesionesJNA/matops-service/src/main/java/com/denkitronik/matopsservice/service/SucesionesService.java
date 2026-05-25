package com.denkitronik.matopsservice.service;

import com.denkitronik.matopsservice.bridge.SucesionesLibrary;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.DoubleByReference;
import com.sun.jna.ptr.LongByReference;
import org.springframework.stereotype.Service;

@Service
public class SucesionesService {

    private final SucesionesLibrary lib = SucesionesLibrary.INSTANCE;

    public double terminoAritmetico(double a1, double d, int n) {
        DoubleByReference out = new DoubleByReference();
        int status = lib.sucesion_aritmetica_termino(a1, d, n, out);
        validar(status);
        return out.getValue();
    }

    public double terminoGeometrico(double a1, double r, int n) {
        DoubleByReference out = new DoubleByReference();
        int status = lib.sucesion_geometrica_termino(a1, r, n, out);
        validar(status);
        return out.getValue();
    }

    public double sumaAritmetica(double a1, double d, int n) {
        DoubleByReference out = new DoubleByReference();
        int status = lib.sucesion_aritmetica_suma(a1, d, n, out);
        validar(status);
        return out.getValue();
    }

    public double sumaGeometrica(double a1, double r, int n) {
        DoubleByReference out = new DoubleByReference();
        int status = lib.sucesion_geometrica_suma(a1, r, n, out);
        validar(status);
        return out.getValue();
    }

    public long terminoFibonacci(int n) {
        LongByReference out = new LongByReference();
        int status = lib.sucesion_fibonacci_termino(n, out);
        validar(status);
        return out.getValue();
    }

    public long sumatoriaNaturales(int n) {
        LongByReference out = new LongByReference();
        int status = lib.sumatoria_naturales(n, out);
        validar(status);
        return out.getValue();
    }

    public long sumatoriaCuadrados(int n) {
        LongByReference out = new LongByReference();
        int status = lib.sumatoria_cuadrados(n, out);
        validar(status);
        return out.getValue();
    }

    public String errorTexto(int code) {
        Pointer p = lib.sucesiones_error_texto(code);
        return p.getString(0);
    }

    private void validar(int status) {
        if (status != 0) {
            throw new IllegalStateException(
                    "Error nativo " + status + ": " + errorTexto(status)
            );
        }
    }
}