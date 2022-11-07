char* str_rchr(const char *cad, int c)
{
    char *pTemp = NULL;

    while(*cad)
    {
        if(*cad == c)
            pTemp = (char *)cad;

        cad++;
    }

    if(!*cad && *cad == c)
        pTemp = (char *)cad;

    return pTemp;
}
