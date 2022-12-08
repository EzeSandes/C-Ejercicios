unsigned cantDeVocales(const char *cad)
{
    unsigned cant = 0;
    while(*cad)
    {
        if(ES_LETRA(*cad) && ES_VOCAL(*cad))
            cant++;

        cad++;
    }

    return cant;
}
