#include <string.h>
#include "cola.h"

#define SIN_LUGAR   0
#define COLA_VACIA   0
#define TODO_OK     1

#define MIN(x, y) ((x) < (y)? (x):(y))

/////////////////////////////////////////

void crearCola(tCola *c)
{
    c->pri = 0; // Cualquier pos < TAM_COLA y debe ser igual a ult
    c->ult = 0;
    c->tamDisp = TAM_COLA;
}

/////////////////////////////////////////

int colaLlena(const tCola *c, unsigned cantBytes)
{
    return c->tamDisp < cantBytes + sizeof(unsigned);
}

/////////////////////////////////////////

void vaciarCola(tCola *c)
{
    c->pri = c->ult; // o a los 2 los pongo en 0
    c->tamDisp = TAM_COLA;
}

/////////////////////////////////////////

int colaVacia(const tCola *c)
{
    return c->tamDisp == TAM_COLA;
}

/////////////////////////////////////////

int ponerEnCola(tCola *c, const void *d, unsigned cantBytes)
{
    unsigned    ini, // Lo que va en el final de la cola
                fin;// lo que va en el segundo memcpy

    if(c->tamDisp < sizeof(unsigned) + cantBytes)
        return SIN_LUGAR;

    c->tamDisp -= sizeof(unsigned) + cantBytes;

    /// COLOCAMOS EL TAM DE DATO PRIMERO
    // ini = cuantos bytes van a entrar al final
    // Puede ser el valor del unsigned xq entra entero o menor, lo que puedo colocar
    // de lo que me queda al final de la cola.
    // c->ult xq ESTAMOS COLOCANDO INFO
    ini = MIN(TAM_COLA - c->ult, sizeof(unsigned));
    if(ini) // Si es 0 es xq esta justamente lleno hasta tope y no hay ni siquiera 1 bytes
        memcpy(c->cola + c->ult, &cantBytes, ini);

    fin = sizeof(unsigned) - ini; /// Si se partio el dato => fin != 0
    if(fin) // (char*)&cantBytes = Lo casteo a char para sumar de a uno.
        memcpy(c->cola, ((char *)&cantBytes) + ini, fin);

    //////////

    /// Si fin tiene un valor => estoy al principio de la cola
    c->ult = fin ? : c->ult + ini;

    //////////

    /// COLOCAMOS EL DATO EN SI AHORA

    ini = MIN(TAM_COLA - c->ult, cantBytes);
    if(ini)
        memcpy(c->cola + c->ult, d, ini);

    fin = cantBytes - ini;
    if(fin)
        memcpy(c->cola, ((char*)d) + ini, fin);

    c->ult = fin ? fin : c->ult + ini;

    return TODO_OK;
}

/////////////////////////////////////////

int sacarDeCola(tCola *c, void *d, unsigned cantBytes)
{
    unsigned    ini,
                fin,
                tamInfo,
                tamASacar; // Es la cant real que hay de info en la cola.

    if(c->tamDisp == TAM_COLA)
        return COLA_VACIA;

    /// Sacar el TAM_INFO
    ini = MIN(TAM_COLA - c->pri, sizeof(unsigned));
    if(ini)
        memcpy(&tamInfo, c->cola + c->pri, ini);

    fin = sizeof(unsigned) - ini;
    if(fin)
        memcpy(((char *)&tamInfo) + ini, c->cola, fin);

    c->pri = fin ? fin : c->pri + ini;
    ////////////////

    tamASacar = tamInfo;
    tamInfo = MIN(tamInfo, cantBytes);
    c->tamDisp += sizeof(unsigned) + tamASacar;

    ////////////////
    /// Sacar el DATO
    ini = MIN(TAM_COLA - c->pri, tamInfo);
    if(ini)
        memcpy(d, c->cola + c->pri, ini);

    fin = tamInfo - ini;
    if(fin)
        memcpy(((char *)d) + ini, c->cola, fin);

    c->pri = (c->pri + tamASacar) % TAM_COLA;
    return TODO_OK;
}

/////////////////////////////////////////

int verPrimeroDeCola(const tCola *c, void *d, unsigned cantBytes)
{
    unsigned    ini,
                fin,
                tamInfo,
                pos = c->pri;

    if(c->tamDisp == TAM_COLA)
        return COLA_VACIA;

    ///
    ini = MIN(TAM_COLA - pos, sizeof(unsigned));
    if(ini)
        memcpy(&tamInfo, c->cola + pos, ini);

    fin = sizeof(unsigned) - ini;
    if(fin)
        memcpy(((char *)&tamInfo) + ini, c->cola, fin);

    pos = fin ? fin : pos + ini;

    ///////////////

    // Como no voy a sacarlo al dato, no me importa si el usuario toma menos
    // lo que si me importa, es que no tome DE MAS. Que unicamente tome
    // o lo maximo del dato que guarda cola(q lo tengo ahora en tamInfo)
    // o menor a ese dato, que me lo puede pasar por cantBytes.
    // Si coloca un dato mayor de bytes para sacar, sacara como mucho "tamInfo"
    tamInfo = MIN(tamInfo, cantBytes);

    ///////////////

    ini = MIN(TAM_COLA - pos, tamInfo);
    if(ini)
        memcpy(d, c->cola + pos, ini);

    fin = tamInfo - ini;
    if(fin)
        memcpy(((char *)d) + ini, c->cola, fin);

    return TODO_OK;
}

/////////////////////////////////////////
