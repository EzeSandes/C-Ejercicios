///////////////////////

int trazaDeMatrizDP(int mat[][COL], int filas, int columnas)
{
    int i;
    int sum = 0;

    for(i = 0; i < filas; i++)
        sum += mat[i][i];

    return sum;
}

///////////////////////

int trazaDeMatrizDS(int mat[][COL], int filas, int columnas)
{
    int i;
    int sum = 0;

    for(i = 0; i < filas; i++)
        sum += mat[i][filas - i - 1];

    return sum;
}

///////////////////////
