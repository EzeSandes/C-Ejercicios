# Memoria Dinamica
Pra usar memoria dinamica es importante saber con que funciones contamos en el lenguaje para lograr esto.

## Malloc

__void* malloc(size_t tam)__

Reserva una cantidad de bytes. Si los tiene, devuelve la direccion inicial de ese bloque reservado. Si no, devuelve NULL.

Ej: Reservar memoria para 16 floats.
``` C
float *pFloat;
pFloat = (float *)malloc(16 * sizeof(float))

*(pFloat + 1) = 2.0; // Asigna
pFloat[1] = 2.0 // Asigna tambien
pFloat++; // Se mueve al sig float PERO pierdo la direccion del primero.
```
CUIDADO!: Al no ser un puntero const lo que devuelve => puedo perder la direccion 
de donde empieza el bloque. Por eso, se recomienda usar funciones
con ese puntero porque la funcion tendra una copia de ese puntero y si muevo
esa copia, no perdere donde apunta la variable original.

## Calloc

Reserva mem y la limpia(clear)(pone todo en 0 o valor nulo de cada tipo de lo q reservo).
Para vectores normalmente. Reserva una X cant de un Tipo de dato.

``` C
pFloat = (float *) calloc(16, sizeof(float));
```

## Realloc

Redimenciona una cantidad pedida de memoria dinamica a un nuevo tamano. Solo lo hace con memoria dinamica, no estatica.

``` C
// *ptr == Puntero a Mem Dinamica.
// tamanyo == Tam Nuevo
void* realloc(void *ptr, size_t tamanyo);
```

Ej: Ahora quiero el vector anterior de 16, con 8.
``` C
pFloat = (pFloat, 8 * sizeof(float));
```

__CUIDADO__: Copia TODO lo que tenia en una nueva pos(o no si ya tenia lugar). Si no hay lugar dara NULL => DEBO COLOCARLO EN UN PTR AUX primero 
para asegurarme que pierda nada. Si da error al relocalizar, me devolvera NULL, es por eso que no puedo sobreescribir en la misma linea de asignacion
el puntero que estoy tratando de redimencionar.

Ej: 
```C
// MALA PRACTICA: Tengo error => Devuelve NULL => Pierdo el bloque de memoria a la cual estaba referenciando anteriormente => El bloque de memoria 
//                   quedara ocupando espacio en memoria innecesariamente sin posibilidad de liberarla en tiempo de ejecucion.
pFloat = (float *)realloc(pFloat, 18 * sizeof(float));

// BUENA PRACTICA: Aunque tenga error, sigo teniendo el bloque de memoria reservado referenciado por la variable original.
float   *pAux
        pAux = (float *)realloc(pFloat, 18 * sizeof(float));
        if(!pAux)
        {
          ...
          ...
        }else{
          pFloat = pAux;
        }
```

## Free

Free() es una funcion que nunca pueda dar error. Incluso si se le pasa NULL, ejecutara normalmente. Su funcion es liberar el espacio de memoria que se reservo 
dinamicamente.

```C
free(pFloat);
```
__Nota__: Siempre libere memoria en el mismo bloque que la reservo de ser posible. De este modo, no perdera las referencias y no se le olvidara hacerlo.

Liberar memoria es muy importante debido a que si no se lo hace, la aplicacion tomara memoria sin control alguno dejando obviamente sin memoria para los demas
procesos del programa. Si la aplicacion se ejecutara por mucho tiempo o con grandes cantidades de datos, el programa se quedara sin memoria rapidamente. 
La unica manera de liberar memoria sin el free seria reiniciando la aplicacion. Al reiniciar toda la memoria reservada durante la ejecucion queda libre nuevamente.
        
