#ifndef TORRECARTONI_H
#define TORRECARTONI_H

#include <stdlib.h>

typedef struct {
    unsigned int p; // Peso
    unsigned int a; // Altezza
    unsigned int l; // Limite
} Cartone;

extern void TorreCartoni(const Cartone* c, size_t n);

#endif