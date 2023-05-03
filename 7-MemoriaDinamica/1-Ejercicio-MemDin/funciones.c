#include "funciones.h"

void mi_memcpy(void *destino, const void *origen, size_t cant)
{
    int i;
    // DESCOMENTAR LO COMENTADO Y COMENTAR LO DEMAS ES LO MISMO
//    destino = (char *)destino + cant;
//    origen = (char *)origen + cant;

    destino = (char *)destino + (cant - 1);
    origen = (char *)origen + (cant - 1);

//    for(i = 0; i <= cant; i++)
    for(i = 0; i < cant; i++)
    {
        *(char *)destino = *(char *)origen;

        (char *)destino--;
        (char *)origen--;
    }
}

/////////////////////////////

void* mi_memmove(void *destino, const void *origen, size_t cant)
{
    int i;
    void    *pAux,
            *pInicioAux,
            *pDestino = destino;

    pAux = malloc(cant); // Reservo primero memoria para un duplicado
    if(!pAux)
        return NULL;

    pInicioAux = pAux;

    /// Duplico el origen
    for(i = 0; i < cant; i++)
    {
        *(char *)pAux = *(char *)origen;

        (char *)pAux++;
        (char *)origen++;
    }

    /// Copio en el destino
    pAux = pInicioAux;
    for(i = 0; i < cant; i++)
    {
        // Es mas rapido y puedo hacerlo asi.
        // *(char *)(pAux + i) = *(char *)(destino + i)
        *(char *)destino = *(char *)pAux;

        (char *)destino++;
        (char *)pAux++;
    }

    free(pInicioAux); // Ptr a mem dinamica.
    return pDestino;
}
