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


/////////////////////////// PROBADOR ATOI

#define COL_CHARS 50

   char pruebasAtoi[][50] = {
                           "    123  565 l",
                           "    -123L",
                           "    LABV123",
                           "    LABV-123",
                           "    LABV+123",
                           "    123ABC",
                           "    123 ABC",
                           "    ABC",
                           "    ",
                           "    ?//123",
                           "    ?//+123",
                           "    ?//-123",
                           "-1234",
                           "+1234",
                           "",
                           "    +12345",
                           "    -12345",
                           "    12345",
                           "    12345   ABC",
                           "    -12345   ABC",
                           "    +12345   ABC",
                           "    +1234567890",
                           "    -1234567890",
                           "    +12345678900", // Se pasan AMBOS del rango permitido
                           "    -12345678900", // Ya hay error en ambas funciones.
                           // Soportan numeros de hasta 10 Digitos.
                           "abc",
                           "a1b2c3",
                           "  000123",
                           "  -000123",
                           "  +000123",
                           "000123",
                           "-000123",
                           "+000123",
                       };

probadorAtoi(pruebasAtoi, sizeof(pruebasAtoi) / 50);

///////////////

void probadorAtoi(char pruebas[][COL_CHARS], int filas)
{
    int i;

    for(i = 0; i < filas; i++)
    {
        printf("Atoi <stdlib.h> ( %s ): %d", pruebas[i], atoi(pruebas[i]));
        printf("\nAtoi <MIO> ( %s ): %d", pruebas[i], atoi_mio(pruebas[i]));

        printf("\n\n");
    }
}

