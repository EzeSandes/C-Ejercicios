#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

typedef struct
{
    tNodo       *pri,
                *ult;
}tCola;

////////////////////////////////

void crearCola(tCola *c);
int colaVacia(const tCola *c);
int colaLlena(const tCola *c, unsigned cantBytes);
void vaciarCola(tCola *c);
int ponerEnCola(tCola *c, const void *d, unsigned cantBytes);
int sacarDeCola(tCola *c, void *d, unsigned cantBytes);
int verPrimeroDeCola(const tCola *c, void *d, unsigned cantBytes);

////////////////////////////////
////////////////////////////////

#endif // COLA_H_INCLUDED
