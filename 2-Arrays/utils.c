#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"

#define     TRUE    1
#define     FALSE   0

#define     TODO_OK 1
#define     ERROR   -1;
#define     NO_ENCONTRADO   -2

#define     ESPACIOS    4

void mostrarVec_int(int *vec, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%*d", ESPACIOS, *vec);
        vec++;
    }
}

////

int cargarVector(int *vec, int cantElem, int tam)
{
    int i;

    if(cantElem > tam)
        return ERROR;

    for(i = 0; i < cantElem; i++, vec++)
        *vec = i;

    return TODO_OK;
}
