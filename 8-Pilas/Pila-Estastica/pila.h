#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PILA 200

/////////// PILA ESTATICA

typedef struct
{
    char        pila[TAM_PILA];
    unsigned    tope;
}tPila;

///////////

void crearPila(tPila *p);
int apilar(tPila *p, const void *d, unsigned cantBytes);
int desapilar(tPila *p, void *d, unsigned cantBytes);
int pilaVacia(const tPila *p);
int pilaLlena(const tPila *p, unsigned cantBytes); // En implementacion con Memoria Dinamica no es posible esta funcion ya que
// en un microSeg otro proceso me toma la mem q tome anteriormente. Se debe quedar
// para que sea compatible con la implementacion Estatica de Pila.
// Sirve para mantener la compatibilidad con pila estatica.
void vaciarPila(tPila *p);
int verTope(const tPila *p, void *d, unsigned cantBytes);

#endif // PILA_H_INCLUDED
