#include <string.h>
#include "cola.h"

#define ERROR   0
#define TODO_OK 1

#define MIN(x, y) ((x) < (y) ? (x) : (y))
/////////////////////////////////

void crearCola(tCola *c)
{
    c->pri = NULL;
    c->ult = NULL;
}

/////////////////////////////////
// Puedo preguntar por cualquiera, tanto pri como ult
int colaVacia(const tCola *c)
{
    return c->pri == NULL;
}

int colaLlena(const tCola *c, unsigned cantBytes)
{
    return 0; // LA MANERA MAS FACIL.
}

/////////////////////////////////

void vaciarCola(tCola *c)
{
    tNodo   *elim;

    while(c->pri)
    {
        elim = c->pri;
        c->pri = elim->sig;

        free(elim->sig);
        free(elim);
    }

    c->ult = NULL; // Igual que al sacar, no es necesario si lo consideramos como basura
}

/////////////////////////////////

int ponerEnCola(tCola *c, const void *d, unsigned cantBytes)
{
    tNodo   *nuevo = (tNodo *)malloc(sizeof(tNodo));

    if(!nuevo)
        return ERROR;

    nuevo->info = malloc(cantBytes);
    if(!nuevo->info)
    {
        free(nuevo);
        return ERROR;
    }

    memcpy(nuevo->info, d, cantBytes);
    nuevo->tamInfo = cantBytes;
    nuevo->sig = NULL;

//    if(c->pri == NULL)
    if(c->ult)
        c->ult->sig = nuevo; // Del ultimo nodo, me paro en sig y le asigno nuevo
    else
        c->pri = nuevo;

    c->ult = nuevo;

    return TODO_OK;
}

/////////////////////////////////

int sacarDeCola(tCola *c, void *d, unsigned cantBytes)
{
    tNodo   *elim;

    if(!c->pri)
        return ERROR;

    elim = c->pri; // elim apunta directo al primero

    memcpy(d, elim->info, MIN(elim->tamInfo, cantBytes));

    c->pri = elim->sig;

    if(c->pri == NULL)
        c->ult = NULL;
    // Podria no hacer esto y tomarlo como basura lo que
    // tenga en ult. Por una cuestion de prolijidad, se le coloca el NULL.

    free(elim->info);
    free(elim);
    return TODO_OK;
}

/////////////////////////////////

int verPrimeroDeCola(const tCola *c, void *d, unsigned cantBytes)
{
    if(c->pri == NULL)
        return ERROR;

    memcpy(d, c->pri->info, MIN(c->pri->tamInfo, cantBytes));

    return TODO_OK;
}

/////////////////////////////////
