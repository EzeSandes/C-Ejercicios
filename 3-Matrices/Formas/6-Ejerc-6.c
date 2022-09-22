#define MIN(x, y)   ((x) < (y)? (x) : (y))

void mostrarT1(int mat[][COL], int filas, int columnas)
{
    int i, j;
    int menor = MIN(filas, columnas);

    for(i = 0; i < menor; i++)
    {
        printf("%*s", ESPACIOS * i, "");
        for(j = i; j < columnas - i; j++)
            printf("%*.02d", ESPACIOS, mat[i][j]);

        printf("\n");
    }
}
