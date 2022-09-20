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
  - DP: Diagonal Principal
  - DS: Diagonal Secundaria

A continuacion se detallan las consignas.

## 1 - Funciones Basicas para ayudarlo.

- Realice la funcion "``void cargarMatriz(int mat[][COL], int filas, int columnas)``" para cargar una matriz de N elementos, siendo N la cantidad de elementos en total
que tiene la matriz

- Realice la funcion "``void mostrarVec(int *vec, int cantElem)``" que dado un VECTOR, muestre los elementos del mismo de manera prolija. Elija uste la cantidad de espacios 
de separador entre elementos a la hora de mostrar.

- Realice la funcion "``void mostrarMatriz(int mat[][COL], int filas, int columnas)``" que muestre una matriz impelementando la funcion de "mostrarVector"

## 2 - Mostrar Diagonal Secundaria

Realice la funcion que dada una matriz cuadrada N, muestre por pantalla los elementos de la diagonal secundaria.

Nota: Hay dos opciones, que las muestre en una fila los elementos(opcion 1), o que muestren los elementos de la DS manteniendo sus respectivas posiciones(opcion2)

Ej: Dada una matriz 5x5

```
00  01  02  03  04

10  11  12  13  14

20  21  22  23  24

30  31  32  33  34

40  41  42  43  44
```
Solucion
```
Opcion 1 => [fila][col] = 04 13 22 31 40

Opcion 2 = >

                04

            13

        22

    31 

40 
            
```
A su vez, el ejercicio tiene variantes pero primeramente puede pensarlo como lo haria con la opcion 1, luego con la opcion 2 y por ultimo como adaptarlo a matrices rectangulares(5x6, 6x7, 3x7, ...)

## 3 - Mostrar Triangulo Superior DP

Realice una funcion que dada una matriz de orden N, muestre por pantalla los elementos por encima de la DP.

Nota: Hay dos opciones, que las muestre en una fila los elementos(opcion 1), o que muestren los elementos manteniendo sus respectivas posiciones(opcion2)


Ej: Dada una matriz 5x5

```
00  01  02  03  04

10  11  12  13  14

20  21  22  23  24

30  31  32  33  34

40  41  42  43  44
```
Solucion
```
Opcion 1 => [fila][col] = 00  01  02  03  04 10  11  12  13  20  21  22  30  31  40

Opcion 2 = >

                00  01  02  03  04

                10  11  12  13

                20  21  22

                30  31 

                40
            
```
## 4 - Mostrar Triangulo Inferior DP

Realice una funcion que dada una matriz de orden N, muestre por pantalla los elementos por debajo de la DP manteniendo sus respectivas posiciones.

Nota: Tambien puede hacer una variante del ejercicio, sin incluir la diagonal y que admita matrices rectangulares.

Ej: Dada una matriz 5x5

```
*  *  *  *  *

*  *  *  *  *

*  *  *  *  *

*  *  *  *  *

*  *  *  *  *
```
Solucion
```
*  

*  *  

*  *  *  

*  *  *  *  

*  *  *  *  *
            
```
