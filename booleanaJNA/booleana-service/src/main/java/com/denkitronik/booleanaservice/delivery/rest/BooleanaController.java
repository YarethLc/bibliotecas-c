package com.denkitronik.booleanaservice.delivery.rest;

import com.denkitronik.booleanaservice.service.BooleanaService;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.Map;

@RestController
@RequestMapping("/api/v1/booleana")
public class BooleanaController {

    private final BooleanaService service;

    public BooleanaController(BooleanaService service) {
        this.service = service;
    }

    @GetMapping("/and")
    public Map<String, Object> and(@RequestParam int a, @RequestParam int b) {
        return Map.of(
                "operacion", "booleana_and",
                "a", a,
                "b", b,
                "resultado", service.and(a, b)
        );
    }

    @GetMapping("/or")
    public Map<String, Object> or(@RequestParam int a, @RequestParam int b) {
        return Map.of(
                "operacion", "booleana_or",
                "a", a,
                "b", b,
                "resultado", service.or(a, b)
        );
    }

    @GetMapping("/not")
    public Map<String, Object> not(@RequestParam int a) {
        return Map.of(
                "operacion", "booleana_not",
                "a", a,
                "resultado", service.not(a)
        );
    }

    @GetMapping("/xor")
    public Map<String, Object> xor(@RequestParam int a, @RequestParam int b) {
        return Map.of(
                "operacion", "booleana_xor",
                "a", a,
                "b", b,
                "resultado", service.xor(a, b)
        );
    }

    @GetMapping("/nand")
    public Map<String, Object> nand(@RequestParam int a, @RequestParam int b) {
        return Map.of(
                "operacion", "booleana_nand",
                "a", a,
                "b", b,
                "resultado", service.nand(a, b)
        );
    }

    @GetMapping("/nor")
    public Map<String, Object> nor(@RequestParam int a, @RequestParam int b) {
        return Map.of(
                "operacion", "booleana_nor",
                "a", a,
                "b", b,
                "resultado", service.nor(a, b)
        );
    }

    @GetMapping("/xnor")
    public Map<String, Object> xnor(@RequestParam int a, @RequestParam int b) {
        return Map.of(
                "operacion", "booleana_xnor",
                "a", a,
                "b", b,
                "resultado", service.xnor(a, b)
        );
    }

    @GetMapping("/implica")
    public Map<String, Object> implica(@RequestParam int a, @RequestParam int b) {
        return Map.of(
                "operacion", "booleana_implica",
                "a", a,
                "b", b,
                "resultado", service.implica(a, b)
        );
    }

    @GetMapping("/equivale")
    public Map<String, Object> equivale(@RequestParam int a, @RequestParam int b) {
        return Map.of(
                "operacion", "booleana_equivale",
                "a", a,
                "b", b,
                "resultado", service.equivale(a, b)
        );
    }

    @GetMapping("/tabla")
    public Map<String, Object> tabla() {
        return Map.of(
                "operacion", "booleana_tabla_verdad",
                "resultado", service.tablaVerdad()
        );
    }
}