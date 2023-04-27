# Mas funciones utiles

Hay dos funciones muy utiles para el manejo de memoria dinamica aparte de las ya mencionadas. Una es __memcpy()__ y la otra __memmove()__. 

Ambas funciones permite copiar o mover bytes de memoria directamente desde una variable hacia otra, segun cuanto queramos. Esto da mucha flexibilidad
ya que podemos mover o copiar los bytes hasta donde quisieramos desde el principio de un array por ejemplo pero solo los primeros 3 bytes si nos permite.
Sin embargo tambien podemos caer en errores facilmente ya que estas funciones copiaran/moveran la cantidad indicada de bytes sin importar si hay espacio 
para hacerlo o no. Haran su trabajo sin importar si se sobrepasan del tamano de la variable.

Por ejemplo, si a una variable entera(llamada A) de 4bytes quiero copiarle un bloque de memoria de 6bytes, no habra restriccion de hacerlo con estas funciones,
pero seremos responsables de los errores que se tendran al sobreescribir los 2bytes siguientes a la variable "A" con informacion que no le corresponde, por lo que
tendremos perdida de informacion.

Estas funciones son muy importantes ya que cuando trabajamos con tipos de datos mas complejas como con los "struct", pueden variar de cantidad de bytes, no son variables
del tipo primitivas que siempre pesan X cantidad de bytes. Es por eso que estas funciones son importantes para manejar datos mas complejos.

Ambas funciones estan en libreria __<string.h>__

## Memmove
Copia los "cant" bytes de un origen hacia un destino, siempre la cantidad que se le indique. 

Duplica el origen para asegurar la salida que se quiere ya que si de un mismo bloque de memoria copio desde la mitad en su inicio de bloque, es decir, superponiendo
la copia de bytes, con memcpy da errores. Esta funcion duplica primeramente el origen para asegurar que obtenga un resultado si o si.
```C
void* memmove(void *destino, const void *origen, size_t cant);
```

##  Memcpy
Copia los "cant" bytes de un origen hacia un destino, siempre la cantidad que se le indique. 

A diferencia del anterior, no reserva memoria extra y copia sin restricciones la cantidad indicada de bytes. Para ser mas eficientes, esta es la funcion que se usara
por la razon indicada.
```C
void* memcpy(void *destino, const void *origen, size_t cant);
```

