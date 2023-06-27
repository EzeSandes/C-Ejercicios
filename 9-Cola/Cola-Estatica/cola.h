#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM_COLA    100

typedef struct
{
    char        cola[TAM_COLA];
    unsigned    pri,
                ult,
                tamDisp;
}tCola;

void crearCola(tCola *c);
int colaLlena(const tCola *c, unsigned cantBytes);
void vaciarCola(tCola *c);
int colaVacia(const tCola *c);
int ponerEnCola(tCola *c, const void *d, unsigned cantBytes);


#endif // COLA_H_INCLUDED
