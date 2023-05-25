#include "pila.h"
#define TODO_OK    1
#define ERROR      0

#define MIN(x, y)   ((x) < (y)? (x) : (y))

///////////////////////////

void crearPila(tPila *p)
{
    *p = NULL;
}

///////////////////////////

int apilar(tPila *p, const void *d,
           unsigned cantBytes)
{
      // 1ero Reservo mem para el Nodo nuevo
      tNodo *nuevo = (tNodo *)malloc(sizeof(tNodo));
      // Si todo sale mal salir
      if(!nuevo)
        return ERROR;

      nuevo->info = malloc(cantBytes);
      if(!nuevo->info)
      {
          free(nuevo);
          return ERROR;
      }

      // Copio Info
      memcpy(nuevo->info, d, cantBytes);

      // Copio cantBytes en este nodo
      nuevo->tamInfo = cantBytes;
      // Sig->nuevo = *p;
      nuevo->sig = *p;
      *p = nuevo;

      return TODO_OK;
}

///////////////////////////

int pilaVacia(const tPila *p)
{
    return *p == NULL;
}

///////////////////////////

int pilaLlena(const tPila *p, unsigned cantBytes)
{
    tNodo   *elim = (tNodo *)malloc(sizeof(tNodo));
    void    *info = malloc(cantBytes);

    free(elim);
    free(info);

    return elim == NULL || info == NULL;
}

///////////////////////////

void vaciarPila(tPila *p)
{
    tNodo    *elim;

    while(*p)
    {
        elim = *p;
        *p = elim->sig;

        free(elim->info);
        free(elim);
    }
}

///////////////////////////

int desapilar(tPila *p, void *d, unsigned cantBytes)
{
    tNodo   *elim = *p;

    if(!*p) // == if(!elim)
        return ERROR;

    memcpy(d, elim->info, MIN(cantBytes, elim->tamInfo));
    *p = elim->sig;

    free(elim->info);
    free(elim);

    return TODO_OK;
}

///////////////////////////

int verTope(const tPila *p, void *d, unsigned cantBytes)
{
    if(!*p)
        return ERROR;

    memcpy(d, (*p)->info, MIN(cantBytes, (*p)->tamInfo));

    return TODO_OK;
}

///////////////////////////
