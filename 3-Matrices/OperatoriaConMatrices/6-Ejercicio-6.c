#define ERROR 0
#define TODO_OK 1

int multiplicarMatriz(int mat1[][COL], int mat2[][COL], int matResultado[][COL],
                      int filasMat1, int columnasMat1, int filasMat2, int columnasMat2)
{
    int i, j, k;

    // k: Fija la columna de mat2
    // i: Mueve la fila de mat1
    // j: Mueve la fila de mat2 para multiplicar

    // Como no tengo que mostrarla en el momento puedo
    // ir en cualquier orden llenando la matResultado.

    if(columnasMat1 != filasMat2)
        return ERROR;

    for(k = 0; k < columnasMat2; k++)
    {
        for(i = 0; i < filasMat1; i++)
        {
            matResultado[i][k] = 0;
            for(j = 0; j < filasMat2; j++)
                matResultado[i][k] += (mat1[i][j] * mat2[j][k]);
        }
    }

    return TODO_OK;
}

///////////////////////
