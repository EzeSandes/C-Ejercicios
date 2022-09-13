# Formas y recorridos desde una matriz

En esta seccion se espera que al pasarle una matriz a una funcion, la funcion imprima por consola/pantalla la forma que especifica la funcion si es posible.

Ej:
    Triangulo Inferior(mat, filas, col)
    
                    
                      00000
                      
                       0000
                       
                        000
                        
                         00
                         
                          0
                   
La funcion debe imprimir los elementos de la matriz en su respectiva forma.

Nota: 
  - Recuerde que no es necesario utilizar aritmetica de punteros. Puede utilizar indireccion para trabajar matrices.
  - Los elementos de la matriz en este caso las coloque con "0" pero pueden ser "*" o lo que usted prefiera.
  - Se recomienda pensar la resolucion en lapiz y papel primeramente: Realice dibujos de la matriz con los subindices de cada posicion y busque el patron comun que tienen para mostrar unicamente los elementos que se piden

A continuacion se detallan las consignas.

## 1 - Funciones Basicas para ayudarlo.

- Realice la funcion "``void cargarMatriz(int mat[][COL], int filas, int columnas)``" para cargar una matriz de N elementos, siendo N la cantidad de elementos en total
que tiene la matriz

- Realice la funcion "``void mostrarVec(int *vec, int cantElem)``" que dado un VECTOR, muestre los elementos del mismo de manera prolija. Elija uste la cantidad de espacios 
de separador entre elementos a la hora de mostrar.

- Realice la funcion "``void mostrarMatriz(int mat[][COL], int filas, int columnas)``" que muestre una matriz impelementando la funcion de "mostrarVector"
