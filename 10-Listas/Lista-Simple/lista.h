#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo
{
    void            *info;
    unsigned        tamInfo;
    struct sNodo    *sig;
}tNodo;

typedef tNodo*  tLista; // Como en PILA DIN

///////////////////////////////////////

void crearLista(tLista *l);
void mostrarLista(tLista *l, void(*mostrar)(const void *));
void vaciarLista(tLista *l);

int sacarPrimeroLista(tLista *l, void *d, unsigned cantBytes);
int sacarUltimoLista(tLista *l, void *d, unsigned cantBytes);

int verPrimeroLista(const tLista *l, void *d, unsigned cantBytes);
int verUltimoLista(const tLista *l, void *d, unsigned cantBytes);
int verPorPosLista(const tLista *l, void *d, unsigned cantBytes, unsigned pos);
///////////////////////////////////////

#endif // LISTA_H_INCLUDED
