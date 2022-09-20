#define MIN(x, y)   ((x) < (y)? (x) : (y))
#define ESPACIOS 5
/*
*
*
*
*   SOLUCION - Sin Diagonal Principal
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*/

void mostrarTrianguloInferiorDP_sDP(int mat[][COL], int filas, int columnas)
{
    int i, j;

    int menor = MIN(filas, columnas);

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < i && j < menor; j++)
            printf("%*.02d", ESPACIOS, mat[i][j]);

        printf("\n");
    }
}
/*
*
*
*
*   SOLUCION - Con Diagonal Principal
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*/

void mostrarTrianguloInferiorDP_cDP(int mat[][COL], int filas, int columnas)
{
    int i, j;

    int menor = MIN(filas, columnas);

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j <= i && j < menor; j++)
            printf("%*.02d", ESPACIOS, mat[i][j]);

        printf("\n");
    }
}
