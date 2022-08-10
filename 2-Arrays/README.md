# Consignas

No se puede utilizar indireccion, ej:

`
vec[i] == *(vec + i); // ESTAN PROHIBIDOS
`

Lo unico que se puede utilizar es aritmetica de punteros.

Tener en cuenta que un array puede ser de 100 posiciones por ejemplo pero solo 10 elementos son validos(usted elija los numeros que quiera). Cómo se que posiciones consecutivas son validas? Se sabe porque se tiene que pasar otra variable en las 
funciones que me indica la cantidad de elementos(CE) validos que tiene el array con el que estoy trabajando(en este caso 10). 

Una posible solucion capaz que piense para no utilizar la variable CE es colocarle a los elementos int del array un 0(cero), -1 o cualquier otro valor negativo para saber que esa posicion del array ya no hay 
elementos validos. ERROR.
El valor 0(Cero) no puede indicarme si esa posicion es valida porque el cero puede ser un elemento valido tambien si estoy por ejemplo
trabajando con un array de cuentas de bancos, tener saldo 0 es posible e incluso en negativo tambien. Es por eso que el 0(cero) no puedo utilizarlo para indicar que esa posicion
en donde se encuentra no es valido.

Por esta misma razon es posible que tal vez deba de alguna manera cambiar en el main la cantidad de elementos validos que posee el array ya sea si se le inserto o elimino algun valor
en la funcion.

__NOTA:__ Si no quiere ver la solucion completa de una, puede ver minimamente el archivo "vector.h" con las declaraciones de las funciones y las variables que reciben.

__ES ALTAMENTE RECOMENDABLE ENTENDER EL PROBLEMA, EN LAPIZ Y PAPEL PRIMERAMENTE JUNTO CON LOS CASOS LIMITES Y LUEGO PASAR A CODIGO.__
## 1 - Insertar Elemento en array int dada una posicion
Desarrollar una función que inserte un elemento en un arreglo de enteros, dada la posición de inserción.

## 2 - Insertar Elemento en array int ordenado
Desarrollar una función que inserte un elemento en un arreglo de enteros, ordenado en forma ascendente, de forma de no alterar el orden.

## 3 - Eliminar Elemento en array int dada una pocicion
Desarrollar una función que elimine el elemento que ocupa una determinada posición de un arreglo de enteros.

Tenga en cuenta que solo colocando 0(cero) en la posicion indicada esta mal, ya que el cero o cualquier otro numero incluso los negativos, pueden ser numeros validos
en mi array de enteros. Lo mismo aplica para los demas ejercicios que siguen.

## 4 - Eliminar primera aparicion de un elemento dado en array int
Desarrollar una función que elimine la primera aparición de un elemento determinado de un arreglo de enteros.

## 5 - Eliminar todos los Elemento en array int daddo un elemento
Desarrollar una función que elimine todas las apariciones de un determinado elemento de un arreglo de enteros.
