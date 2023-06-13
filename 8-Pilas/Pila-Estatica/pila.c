#include "pila.h"

#define TODO_OK    1
#define ERROR      0

#define MIN(x, y)   ((x) < (y)? (x) : (y))

/// PILA ESTATICA

void crearPila(tPila *p)
{
    p->tope = TAM_PILA;
}

int apilar(tPila *p, const void *d, unsigned cantBytes)
{
    if(p->tope < sizeof(unsigned) + cantBytes)
        return ERROR;

    // Copio la Info primero
    p->tope -= cantBytes;
    memcpy(p->pila + p->tope, d, cantBytes);

    // Copio la cantBytes luego
    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));
//    *(unsigned *)(p->pila + p->tope) = cantBytes;

    return TODO_OK;
}

int desapilar(tPila *p, void *d, unsigned cantBytes)
{
    unsigned tamInfoPila;

    if(p->tope == TAM_PILA)
        return ERROR;

    memcpy(&tamInfoPila, p->pila + p->tope, sizeof(unsigned));

    p->tope += sizeof(unsigned);
    memcpy(d, p->pila + p->tope, MIN(tamInfoPila, cantBytes));

    p->tope += tamInfoPila; // Muevo el que diga la pila

    return TODO_OK;
}

int pilaVacia(const tPila *p)
{
    return TAM_PILA == p->tope; // Para no equivocarse y colocar UN SOLO "="
}

int pilaLlena(const tPila *p, unsigned cantBytes)
{
    // tope indica la cant de espacio disponible
    // tope == 19 y cantBytes == 20 NO ENTRA
    return p->tope < cantBytes + sizeof(unsigned);
}

void vaciarPila(tPila *p)
{
    p->tope = TAM_PILA;
}

int verTope(const tPila *p, void *d, unsigned cantBytes)
{
    unsigned tamInfoPila;

    if(p->tope == TAM_PILA)
        return ERROR;

    // El MIN xq solo tomo hasta lo MAX que pueda soportar
    // mi variable "d" con "cantBytes". Si no puedo mas de X bytes
    // tomo solo X bytes, que es hasta donde pueda.
    // tamInfoPila = *(unsigned *)(p->pila + p->tope);
    memcpy(&tamInfoPila, p->pila + p->tope, sizeof(unsigned));

    memcpy(d, p->pila + p->tope + sizeof(unsigned), MIN(tamInfoPila, cantBytes));
    return TODO_OK;
}


