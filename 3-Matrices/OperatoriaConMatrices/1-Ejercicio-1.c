/*
SIEMPRE SERA CUADRADA

    ******
      ****
       ***
         *
*/
int sumatoriaTrianguloSuperiorSinDP(int mat[][COL], int filas, int columnas)
{
    int i, j;
    int sum = 0;

    for(i = 0; i < filas; i++)
    {
        for(j = i + 1; j < columnas; j++)
            sum += mat[i][j];
    }

    return sum;
}

///////////////////////
// DP incluida
int sumatoriaTrianguloSuperiorConDP(int mat[][COL], int filas, int columnas)
{
    int i, j;
    int sum = 0;

    for(i = 0; i < filas; i++)
    {
        for(j = i; j < columnas; j++)
            sum += mat[i][j];
    }

    return sum;
}
