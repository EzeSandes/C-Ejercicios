#define ES_MINUSCULA(x)     ((x) >= 'a' && (x) <= 'z')
#define ES_MAYUSCULA(x)     ((x) >= 'A' && (x) <= 'Z')
#define ES_LETRA(x)         (ES_MINUSCULA(x) || ES_MAYUSCULA(x))
#define ES_ESPACIO(x)       ((x) == ' ' || (x) == '\t')
#define ES_DIGITO(x)        ((x) >= '0' && (x) <= '9')
#define DIGITO_A_NUMERO(x)         ((x) - '0')

double atof_mio(const char *numPtr)
{
    int signo = 1;

    double numero = 0,
           multiplo;

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

    if(*numPtr != '.')
        return numero * signo;

    numPtr++;

    multiplo = (double)1 / 10;
    while(ES_DIGITO(*numPtr))
    {
        numero += DIGITO_A_NUMERO(*numPtr) * multiplo;
        multiplo /= 10;

        numPtr++;
    }

    return numero * signo;
}
