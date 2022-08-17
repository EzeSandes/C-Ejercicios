#define     TODO_OK 1
#define     ERROR   0;

int insertarEnVectorEnOrden_INT(int *vec, int dato, int *cantElem, int tam)
{
    if(*cantElem == tam)
        return ERROR;

    vec += *cantElem;

    while(*(vec - 1) >= dato)
    {
        *vec = *(vec - 1);
        vec--;
    }

    *vec = dato;
    (*cantElem)++;

    return TODO_OK;
}
