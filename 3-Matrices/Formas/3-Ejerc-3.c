void mostrarTrianguloSuperiorDP(int mat[][COL], int filas, int columnas)
{
    int i, j;
//   Siempre es el menor - 1 en caso de no se cuadrada
//   Si filas resulto ser el menor => necesito mostrar una fila mas, de lo contrario no.

    int menor = filas < columnas? filas + 1 : columnas;
    menor = menor == filas && menor == columnas? menor : menor - 1;

    for(i = 0; i < menor; i++)
    {
        printf("%*s", ESPACIOS * (i + 1), "");
        for(j = i + 1; j < columnas; j++)
            printf("%*.02d", ESPACIOS, mat[i][j]);

        printf("\n");
    }
}
