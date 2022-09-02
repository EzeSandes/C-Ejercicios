#define ERROR 0
#define TODO_OK 1

int esMatrizDiagonal(int mat[][COL], int filas, int columnas)
{
    int i, j;

    for(i = 0; i < filas; i++)
    {
        for(j = i + 1; j < columnas; j++)
            if(mat[i][j] || mat[j][i])
                return ERROR;
    }

    return TODO_OK;
}
