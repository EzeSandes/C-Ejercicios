#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

int main()
{
    void **matDin;

    matDin = crearMatDinamica(2, 3, sizeof(char));

    cargarMatrizDin(matDin, 2, 3, cargarVecChar);
    mostrarMatrizDin(matDin, 2, 3, mostrarVecChar);

    liberarMatDin(matDin, 2);

    return 0;
}
