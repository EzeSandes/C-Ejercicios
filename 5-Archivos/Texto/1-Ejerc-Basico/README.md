# Ejercicio

Crear un menu con las siguientes operaciones sobre archivos de texto. Cada opcion debe ejecutar la accion esperada sobre un archivo de texto.

- Crear Lote de pruebas.
- Abrir Archivo de lote de pruebas
- Binario a Txt Fijo
- Binario a Txt Variable
- Txt Variable a Bin
- Txt Fijo a Bin
- Mostrar Archivo BIN de TXT Variable
- Mostrar Archivo BIN de TXT Fijo
- Mostrar Archivo TXT Fijo x Trozado

En el ejemplo resuelto, elijo hacerlo con las siguientes estructuras, pero obviamente puede hacerlas con las que quiera

```C
#define TAM_CAD 51

typedef struct
{
    int dia,
        mes,
        anio;
} tFecha;

typedef struct sAlu
{
    unsigned    dni;
    char        nyap[TAM_CAD];
    char        sexo;
    tFecha      fechaIng;
    float       prom;
} tAlumno;
```
