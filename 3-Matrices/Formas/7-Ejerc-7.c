#define ESPACIOS 5
#define COL 100

void mostrarT3(int mat[][COL], int filas, int columnas)
{
    int i, j, k;

    for(i = 0, k = columnas - 1; i < filas; i++, k--)
    {
        printf("%*s", ESPACIOS * k, "");
        for(j = k; j >= k && j < columnas; j++)
            printf("%*.02d", ESPACIOS, mat[i][k]);

        printf("\n");
    }
}
