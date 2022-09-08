#define FIL     100
#define COL     100

/*
Se define en el main.c una matriz de longitud maxima de 100 x 100 en este caso pero en las funciones con las que opero 
la matriz, unicamente le paso las dimenciones con las que voy a trajabar realmente, ej: 5x5, 8x10

La ventaja de hacerlo asi es no tener que estar cambiando constantemente las dimenciones de la matriz con la que se trabaja
y poder tener "varias matrices" en una sola(en realidad es la misma matriz solo que se trabaja con diferentes partes) y poder
hacer varias pruebas en simultaneo.

Ej: 

  int mat[FIL][COL] = {{...}, {....}, ...};
  
  // sumarDP(matriz, cant filas, cant columnas)
  sumarDP(mat, 5, 5);
  sumarDP(mat, 10, 10);
  sumarDP(mat, 22, 22);
  
  Asi la ventaja es que puedo ejecutar varias pruebas en simultaneo sin tener que cambiar las dimenciones constantemente o tener varias
  matrices de diferentes dimenciones.
*/


int sumatoriaTrianguloSuperiorDP(int mat[][COL], int filas, int columnas);
int sumatoriaTrianguloSuperiorDP_DP(int mat[][COL], int filas, int columnas);

int trazaDeMatrizDP(int mat[][COL], int filas, int columnas);
int trazaDeMatrizDS(int mat[][COL], int filas, int columnas);

int esMatrizDiagonal(int mat[][COL], int filas, int columnas);
int esMatrizSimetrica(int mat[][COL], int filas, int columnas);
int trasponerMatriz(int mat[][COL], int filas, int columnas);
int multiplicarMatriz(int mat1[][COL], int mat2[][COL], int matResultado[][COL],
                      int filasMat1, int columnasMat1, int filasMat2, int columnasMat2);
