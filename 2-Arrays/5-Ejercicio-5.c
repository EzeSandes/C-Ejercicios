#define     TRUE    1
#define     FALSE   0

#define     TODO_OK 1
#define     ERROR   -1;
#define     NO_ENCONTRADO   -2

int eliminarTodasAparicionesDeVector_int(int *vec, int dato, int *cantElem)
{
    int     *pFin = vec + *cantElem,
             *pLectura,
             *pEscritura;

    while(vec < pFin)
    {
        while(*vec != dato && vec < pFin)
            vec++;

        if(vec == pFin)
            return ERROR; // Significa que se paso de rango permitido y no lo encontro

        (*cantElem)--;
        pLectura = vec + 1; // Si encontro  => apunto al siguiente.
        pEscritura = vec;

        // Tambien puedo usar a vec como pLectura y ahorrarme la variable y la asignacion del final
        // pEscritura = vec; vec++; y uso vec.

        while(pLectura < pFin)
        {
            if(*pLectura == dato)
            {
                (*cantElem)--;
            }
            else
            {
                *pEscritura = *pLectura;
                pEscritura++;
            }

            pLectura++;
        }

        vec = pLectura;
    }

    return TODO_OK;
}
