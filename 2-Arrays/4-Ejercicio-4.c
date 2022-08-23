#define     TODO_OK 1
#define     ERROR   -1;
#define     NO_ENCONTRADO   -2

int eliminarPrimeraAparicionEnVector_INT(int *vec, int dato, int *cantElem)
{
    int index = 0,
        cantElemTemp = *cantElem,
        *pVec = vec;

    while(*pVec != dato && cantElemTemp)
    {
        pVec++;
        cantElemTemp--;
        index++;
    }

    return cantElemTemp ?   eliminarDeVectorPorPos_INT(vec, index + 1, cantElem) : NO_ENCONTRADO;
}
