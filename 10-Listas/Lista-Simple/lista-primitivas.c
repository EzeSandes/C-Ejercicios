#include <string.h>
#include "lista.h"

#define TODO_OK 1
#define SIN_MEM 0
#define OVERFLOW_INDEX 0
#define NO_HAY_LISTA 0

#define MIN(x, y)   ((x) < (y) ? (x) : (y))

///////////////////////////////////

void crearLista(tLista *l)
{
    *l = NULL;
}

///////////////////////////////////

void mostrarLista(tLista *l, void(*mostrar)(const void *))
{
    while(*l)
    {
        mostrar((*l)->info);
        l = &(*l)->sig;
    }
}

///////////////////////////////////

void vaciarLista(tLista *l)
{
    tNodo *elim;

    while(*l)
    {
        elim = *l;
        *l = elim->sig;

        free(elim->info);
        free(elim);
    }
}

///////////////////////////////////

int sacarPrimeroLista(tLista *l, void *d, unsigned cantBytes)
{
    tNodo   *elim = *l;
    if(!elim)
        return NO_HAY_LISTA;

    memcpy(d, elim->info, MIN(cantBytes, elim->tamInfo));

    *l = elim->sig;

    free(elim->info);
    free(elim);

    return TODO_OK;
}

///////////////////////////////////

int sacarUltimoLista(tLista *l, void *d, unsigned cantBytes)
{
    tNodo *elim;

    if(!*l)
        return NO_HAY_LISTA;

    while((*l)->sig)
        l = &(*l)->sig;

    elim = *l;
    *l = NULL;

    memcpy(d, elim->info, MIN(cantBytes, elim->tamInfo));

    free(elim->info);
    free(elim);

    return TODO_OK;
}

///////////////////////////////////

///////////////////////////////////

///////////////////////////////////

///////////////////////////////////
