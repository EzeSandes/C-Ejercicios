#define ES_DIGITO(x)        ((x) >= '0' && (x) <= '9')
#define DIGITO_A_NUMERO(x)         ((x) - '0')




char* invertirCadSegunDigitos(char *cad)
{
    char    *pInicio = cad,
             *pRango,
             *pEscritura;

    int rango,
        cantDigitosEncontrados = 0; // Sirve para saber cuantos espacios menos tendra la cadena

    ///////////
    // Si no posee digitos la cadena, no tiene sentido todo lo de abajo => verifico primero

    while(!ES_DIGITO(*cad) && *cad)
        cad++;

    if(!*cad)
        return pInicio;

    ///////////

    // Si llega aca => cad == Algun Digito => Debo ir Copiando y corriendo la cadena.
    pEscritura = cad;
    while(*cad)
    {
        rango = DIGITO_A_NUMERO(*cad);
        pRango = cad;

        // Necesito esto para saber si no se pasa del fin de cadena el numero
        while(*pRango && rango) // == while(*pRango && rango--) pRango++;
        {
            pRango++;
            rango--;
        }

        if(!*pRango)
            pRango--;

        intercambiarLetras(cad + 1, pRango);
        str_cpy_mio(pEscritura, cad + 1, pRango);

        pEscritura = pRango - cantDigitosEncontrados;
        cad = pRango + 1;
        cantDigitosEncontrados++;

        while(!ES_DIGITO(*cad) && *cad)
        {
            *pEscritura = *cad;
            cad++;
            pEscritura++;
        }
    }

    *pEscritura = '\0';

    return pInicio;
}

///////////////////

char* str_cpy_mio(char *donde, char *desde, char *hasta){
    char *pIni = donde;

    while(desde != hasta && *desde){
        *donde = *desde;
        desde++;
        donde++;
    }

    return pIni;
}

void intercambiarLetras(char *c1, char *c2){
    char aux;

    aux = *c1;
    *c1 = *c2;
    *c2 = aux;
}
