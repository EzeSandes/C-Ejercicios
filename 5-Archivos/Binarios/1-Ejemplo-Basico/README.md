# Ejemplo Basico

Este es un proyecto de ejemplo basico para el manejo de los modos de apertura de los archivos binarios en C.

Utilizando estructuras del tipo "Alumno" leemos, creamos, agregamos y cargamos distintos estudiantes desde un archivo creado.

## Estructuras

### tCad
```
char cad[51];
```

Sirve para evitarse los "strcpy()" ya que al asignar una estructura de tipo "tCad" a otra del mismo tipo, se copiara por bytes sin necesidad de copiar por la funcion de
"string.h"

### tFecha

```
int dia,
    mes,
    anio;
```

### tAlum

```
unsigned    dni;
char        nyap[51];
float       prom;
tFecha      fechaIng; // La estructura "tFecha" DEBE estar definida antes
int         notas[3];
```
