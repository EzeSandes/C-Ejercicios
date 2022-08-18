#define     TODO_OK 1
#define     ERROR   0;

int eliminarDeVectorPorPos_INT(int *vec, int pos, int *cantElem)
{
    int *pVec;

    if(pos < 0 || pos > *cantElem)
        return ERROR;

    pVec = vec + *cantElem - 1;
    vec += pos - 1;

    while(vec < pVec)
    {
        *vec = *(vec + 1);
        vec++;
    }

    (*cantElem)--;
    return TODO_OK;
}
