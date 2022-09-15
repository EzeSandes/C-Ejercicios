// FUNCION QUE ADMITE MATRICES RECTANGULARES

void mostrarDS(int mat[][COL], int filas, int columnas)
{
    int i;

    int minimo = filas < columnas ? filas : columnas;

    for(i = 0; i < minimo; i++, columnas--)
    {
//            printf("%*c%.2d ", (ESPACIOS * (columnas)) + (2 * (columnas - 1)), ' ', mat[i][columnas - 1]);
        printf("%*.02d\n", ESPACIOS * columnas, mat[i][columnas - 1]);
    }
}
