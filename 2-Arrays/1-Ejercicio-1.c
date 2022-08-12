/*
El usuario ve siempre POS == index + 1 => (POS = 1) == (vector[0])
*/
int insertarEnVector_INT(int *vec, int dato, int pos, int *cantElem, int tam)
{
    int *pVec;

    // Si no hay lugar, continua pero el ultimo valor lo perdere.
    if(pos <= 0 || pos > *cantElem + 1)
        return ERROR;

    if(pos == tam && pos == *cantElem)
    {
        vec += pos - 1;
        *vec = dato;
        return TODO_OK;
    }

    pVec = vec + *cantElem;
    while(vec + pos - 1 < pVec)
    {
        *pVec = *(pVec - 1);
        pVec--;
    }

    *pVec = dato;
    (*cantElem)++;

    return TODO_OK;
}
