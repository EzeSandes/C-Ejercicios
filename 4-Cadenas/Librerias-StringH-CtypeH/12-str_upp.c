#define ES_MINUSCULA(x)     ((x) >= 'a' && (x) <= 'z')
#define ES_MAYUSCULA(x)     ((x) >= 'A' && (x) <= 'Z')
#define ES_LETRA(x)         (ES_MINUSCULA(x) || ES_MAYUSCULA(x))

#define A_MAYUSC(x)    ((x) >= 'A' && (x) <= 'Z' ? (x) : ((x) - ('a' - 'A')))

char* str_upr(char *cad)
{
    char *pInicio = cad;

    while(*cad)
    {
        if(ES_LETRA(*cad))
            *cad = A_MAYUSC(*cad);

        cad++;
    }

    return pInicio;
}
