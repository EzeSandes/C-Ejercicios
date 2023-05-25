#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////// PILA DINAMICA

typedef struct sNodo
{
    void            *info;
    unsigned        tamInfo;
    struct sNodo    *sig; // ptr al sig Nodo
}tNodo;

typedef tNodo* tPila; // tPila es un PUNTERO A NODO(El primer nodo de la pila)

///////////

void crearPila(tPila *p);
int apilar(tPila *p, const void *d, unsigned tamInfo);
int desapilar(tPila *p, void *d, unsigned tamInfo);
int pilaVacia(const tPila *p);
int pilaLlena(const tPila *p, unsigned tamInfo);
void vaciarPila(tPila *p);
int verTope(const tPila *p, void *d, unsigned tamInfo);

///////////

#endif // PILA_H_INCLUDED
