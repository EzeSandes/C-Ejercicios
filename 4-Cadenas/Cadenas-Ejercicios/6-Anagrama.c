#include <stdio.h>
#include <stdlib.h>

#define NRO_CHAR_PERMITIDO 26

#define CHAR_A_INDEX(x)     (int)((x) - 'a')

int sonAnagramas(const char *cad1, const char *cad2);

int main()
{
    printf("Hello world!\n");

    printf("%d", sonAnagramas("Roma", "Amor"));

    return 0;
}


//////////////////////////////

int sonAnagramas(const char *cad1, const char *cad2)
{
    int i;
    int caracteresPermitidos1[NRO_CHAR_PERMITIDO] = {0};
    int caracteresPermitidos2[NRO_CHAR_PERMITIDO] = {0};

    int *pCaracteresPermitidos1 = caracteresPermitidos1;
    int *pCaracteresPermitidos2 = caracteresPermitidos2;

    while(*cad1 && *cad2)
    {
        (*(caracteresPermitidos1 + CHAR_A_INDEX(*cad1)))++;
        (*(caracteresPermitidos2 + CHAR_A_INDEX(*cad2)))++;

        cad1++;
        cad2++;
    }

    if(*cad1 || *cad2)
        return 0;

    for(i = 0; i < NRO_CHAR_PERMITIDO; i++)
    {
        if(*pCaracteresPermitidos1 != *pCaracteresPermitidos2)
            return 0;

        pCaracteresPermitidos1++;
        pCaracteresPermitidos2++;
    }

    return 1;
}

//////////////////////////////
