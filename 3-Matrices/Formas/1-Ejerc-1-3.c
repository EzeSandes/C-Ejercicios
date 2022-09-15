#define COL 100

void mostrarMatriz(int mat[][COL], int filas, int columnas)
{
    int i;
    for(i = 0; i < filas; i++)
    {
        // Se utiliza la funcion del item anterior.
        mostrarVec(mat[i], columnas);
        printf("\n");
    }
}
