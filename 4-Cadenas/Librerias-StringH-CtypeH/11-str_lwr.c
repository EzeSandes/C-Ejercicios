#define ES_MINUSCULA(x)     ((x) >= 'a' && (x) <= 'z')
#define ES_MAYUSCULA(x)     ((x) >= 'A' && (x) <= 'Z')
#define ES_LETRA(x)         (ES_MINUSCULA(x) || ES_MAYUSCULA(x))

#define A_MINUSC(x)    ((x) >= 'a' && (x) <= 'z' ? (x) : ((x) + ('a' - 'A')))

char* str_lwr(char *cad)
{
    char *pInicio = cad;

    while(*cad)
    {
        if(ES_LETRA(*cad))
            *cad = A_MINUSC(*cad);

        cad++;
    }

    return pInicio;
}
