#define MIN(x, y)   ((x) < (y)? (x) : (y))
#define ESPACIOS  5

void mostrarTrianguloInferiorDS_cDS(int mat[][COL], int filas, int columnas)
{
    int i, j;

    int menor = MIN(filas, columnas);

    // Primero los espacios
    for(i = 0; i < menor; i++)
    {
        printf("%*s", ESPACIOS * (columnas - i - 1), "");
        for(j = columnas - i - 1; j < columnas; j++)
            printf("%*.02d", ESPACIOS, mat[i][j]);

        printf("\n");
    }

    // Segundo los elementos
    for(; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
            printf("%*.02d", ESPACIOS, mat[i][j]);

        printf("\n");
    }
}
