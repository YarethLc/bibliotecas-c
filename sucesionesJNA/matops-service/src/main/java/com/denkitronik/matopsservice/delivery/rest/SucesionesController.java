package com.denkitronik.matopsservice.delivery.rest;

import com.denkitronik.matopsservice.service.SucesionesService;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.Map;

@RestController
@RequestMapping("/api/v1/sucesiones")
public class SucesionesController {

    private final SucesionesService service;

    public SucesionesController(SucesionesService service) {
        this.service = service;
    }

    @GetMapping("/aritmetica/termino")
    public Map<String, Object> terminoAritmetico(@RequestParam double a1,
                                                 @RequestParam double d,
                                                 @RequestParam int n) {
        return Map.of(
                "operacion", "sucesion_aritmetica_termino",
                "a1", a1,
                "d", d,
                "n", n,
                "resultado", service.terminoAritmetico(a1, d, n)
        );
    }

    @GetMapping("/geometrica/termino")
    public Map<String, Object> terminoGeometrico(@RequestParam double a1,
                                                 @RequestParam double r,
                                                 @RequestParam int n) {
        return Map.of(
                "operacion", "sucesion_geometrica_termino",
                "a1", a1,
                "r", r,
                "n", n,
                "resultado", service.terminoGeometrico(a1, r, n)
        );
    }

    @GetMapping("/fibonacci/termino")
    public Map<String, Object> terminoFibonacci(@RequestParam int n) {
        return Map.of(
                "operacion", "sucesion_fibonacci_termino",
                "n", n,
                "resultado", service.terminoFibonacci(n)
        );
    }

    @GetMapping("/aritmetica/suma")
    public Map<String, Object> sumaAritmetica(@RequestParam double a1,
                                              @RequestParam double d,
                                              @RequestParam int n) {
        return Map.of(
                "operacion", "sucesion_aritmetica_suma",
                "a1", a1,
                "d", d,
                "n", n,
                "resultado", service.sumaAritmetica(a1, d, n)
        );
    }

    @GetMapping("/geometrica/suma")
    public Map<String, Object> sumaGeometrica(@RequestParam double a1,
                                              @RequestParam double r,
                                              @RequestParam int n) {
        return Map.of(
                "operacion", "sucesion_geometrica_suma",
                "a1", a1,
                "r", r,
                "n", n,
                "resultado", service.sumaGeometrica(a1, r, n)
        );
    }

    @GetMapping("/naturales")
    public Map<String, Object> sumatoriaNaturales(@RequestParam int n) {
        return Map.of(
                "operacion", "sumatoria_naturales",
                "n", n,
                "resultado", service.sumatoriaNaturales(n)
        );
    }

    @GetMapping("/cuadrados")
    public Map<String, Object> sumatoriaCuadrados(@RequestParam int n) {
        return Map.of(
                "operacion", "sumatoria_cuadrados",
                "n", n,
                "resultado", service.sumatoriaCuadrados(n)
        );
    }
}