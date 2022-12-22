#define ES_MINUSCULA(x)     ((x) >= 'a' && (x) <= 'z')
#define ES_MAYUSCULA(x)     ((x) >= 'A' && (x) <= 'Z')
#define ES_LETRA(x)         (ES_MINUSCULA(x) || ES_MAYUSCULA(x))
#define ES_ESPACIO(x)       ((x) == ' ' || (x) == '\t')
#define DIGITO_A_NUMERO(x)         ((x) - '0')
#define ES_DIGITO(x)        ((x) >= '0' && (x) <= '9')

int atoi_mio(const char *numPtr)
{
    int signo = 1,
        numero = 0;

    while(ES_ESPACIO(*numPtr))
        numPtr++;

    // Solo si es '-' o '+'
    if(ES_LETRA(*numPtr) || (*numPtr != '-' && *numPtr != '+' && !ES_DIGITO(*numPtr) ) || !*numPtr)
        return 0; // o coloco => return numero;

    // Puede ser que sea un signo
    if(*numPtr == '-')
    {
        signo *= -1;
        numPtr++;
    }

    if(*numPtr == '+')
        numPtr++;

    while(ES_DIGITO(*numPtr))
    {
        numero = numero * 10 + DIGITO_A_NUMERO(*numPtr);
        numPtr++;
    }

    return numero * signo;
}
