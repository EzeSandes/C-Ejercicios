// Esta funcion es sencible a Mayusc y Min y solo es posible verificar una palabra, no una oracion.
int esPalindromo_palabra(const char *cad)
{
    char *pFin = (char *)cad;

    while(*pFin)
        pFin++;

    pFin--;

    while(*cad == *pFin && cad < pFin)
    {
        cad++;
        pFin--;
    }

    return *cad == *pFin;
}
