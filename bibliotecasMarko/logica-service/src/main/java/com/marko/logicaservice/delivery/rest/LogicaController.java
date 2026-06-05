package com.marko.logicaservice.delivery.rest;

import com.marko.logicaservice.service.LogicaService;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/logica")
public class LogicaController {

    private final LogicaService service;

    public LogicaController(LogicaService service) {
        this.service = service;
    }

    /* ── Conectivos unarios ─────────────────────────────────────────────── */

    @GetMapping("/not/{p}")
    public int not(@PathVariable int p) {
        return service.not(p);
    }

    /* ── Conectivos binarios ────────────────────────────────────────────── */

    @GetMapping("/and/{p}/{q}")
    public int and(@PathVariable int p, @PathVariable int q) {
        return service.and(p, q);
    }

    @GetMapping("/or/{p}/{q}")
    public int or(@PathVariable int p, @PathVariable int q) {
        return service.or(p, q);
    }

    @GetMapping("/xor/{p}/{q}")
    public int xor(@PathVariable int p, @PathVariable int q) {
        return service.xor(p, q);
    }

    @GetMapping("/nand/{p}/{q}")
    public int nand(@PathVariable int p, @PathVariable int q) {
        return service.nand(p, q);
    }

    @GetMapping("/nor/{p}/{q}")
    public int nor(@PathVariable int p, @PathVariable int q) {
        return service.nor(p, q);
    }

    @GetMapping("/implicacion/{p}/{q}")
    public int implicacion(@PathVariable int p, @PathVariable int q) {
        return service.implicacion(p, q);
    }

    @GetMapping("/bicondicional/{p}/{q}")
    public int bicondicional(@PathVariable int p, @PathVariable int q) {
        return service.bicondicional(p, q);
    }

    /* ── Clasificadores ─────────────────────────────────────────────────── */

    @GetMapping("/tautologia/{p}")
    public int esTautologia(@PathVariable int p) {
        return service.esTautologia(p);
    }

    @GetMapping("/contradiccion/{p}")
    public int esContradiccion(@PathVariable int p) {
        return service.esContradiccion(p);
    }

    /* ── Leyes de De Morgan ─────────────────────────────────────────────── */

    @GetMapping("/demorgan/and/{p}/{q}")
    public int demorganAnd(@PathVariable int p, @PathVariable int q) {
        return service.demorganAnd(p, q);
    }

    @GetMapping("/demorgan/or/{p}/{q}")
    public int demorganOr(@PathVariable int p, @PathVariable int q) {
        return service.demorganOr(p, q);
    }
}
