#ifndef LOGICA_PROPOSICIONAL_H
#define LOGICA_PROPOSICIONAL_H

#include <stdbool.h>

bool AND(bool p, bool q);
bool OR(bool p, bool q);
bool NOT(bool p);
bool XOR(bool p, bool q);
bool NAND(bool p, bool q);
bool NOR(bool p, bool q);
bool IMPLICACION(bool p, bool q);
bool BICONDICIONAL(bool p, bool q);

void imprimir_tabla_verdad(const char *nombre, bool (*operacion)(bool, bool));
void imprimir_tabla_verdad_unaria(const char *nombre, bool (*operacion)(bool));

#endif
