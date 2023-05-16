# Ejercicio Matriz Dinamica

Crear la funcion "crearMatDinamica()" que dado los siguientes parametros que se le pasen, cree una matriz con memoria dinamica(no memoria estatica), es decir, utilizando el area de "heap" del proceso en memoria.

Parametros:

- fil< int >: Determina la cantidad de filas de la matriz
- col< int >: Determina la cantidad de columnas de la matriz
- tamElem< size_t >: Determina la cantidad de bytes a reservar para el tipo de dato de la matriz.
- return < void** >: Devuelve un puntero al comienzo de la matriz ya creada.
  
Ej: crearMatDinamica(2, 3, sizeof(char)) // Crea una matriz 2x3 para una matriz del tipo char.
  
Nota: Tenga en cuenta que si no puede reservar mas memoria, se debe regresar todo el proceso hacia atras y liberar la memoria previamente reservada. Ej: Reservo para
  1.000.000 de filas y columnas y a las 500.000 no puedo reservar mas, no puedo abortar hasta que libere las 500.000 filas y columnas que previamente reserve.
