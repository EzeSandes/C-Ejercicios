#define COL 100

void cargarMatriz(int mat[][COL], int filas, int columnas)
{
    int i,
        j;

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
            mat[i][j] = (i * 10) + j;
    }
}

// Yo elegi que muestren los indices que contiene cada posicion para luego verificar rapidamente que paso por los indices que se buscaban.
