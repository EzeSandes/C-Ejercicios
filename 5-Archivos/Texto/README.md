# Archivos de Texto

- Cada char es tomado del codigo ASCII.
- Perfecto para compartir archivos entre aplicaciones. Cualquier lenguaje puede procesar archivos de texto.
- Siempre acceso secuencial ya que no puedo llegar directamente al dato.

**Nota: Es importante saber los modificadores del scanf() y printf() para la lectura y escritura de archivos de texto.**

## Tipos de Archivos de Texto

### Long. Fija

Cada variable SIEMPRE tendra la misma longitud en el archivo. Si el DNI ocupa 8 lugares, entonces SIEMPRE tendre 8 lugares.

No necesito ningun separador xq es fija, se que "X" cant de bytes es para una variable y luego "Y" byte para otra.

### Long. Variable

Necesito el delimitador-separador (;|-) Algo que no forme parte de mi conjunto de datos para saber donde termina y comienza una variable nueva.

Ej:

```
dni|nombre y apellido|edad|sueldo|dia/mes/anio\n
```

## Grabar Archivo

```C
FILE *pf;

pf = fopen("ruta\\ o nombreReal", "modo con t")
// VERIFICO LA APERTURA DEL ARCHIVO
if(!pf)
    return ERROR;

/// Grabar en un archivo
fputc();
fputs(); // No tiene formato. Debo armar la cadena primero y eso se lo paso

int fprintf(FILE *pf, const char *formato, ...variables);
// Vent: Tiene formato. Arma la cadena por mi directamente.
// retorna la cant. de caracteres o un valor negativo si hay error.

```

## Leer archivo

```C
fgetc();
fgets();
fscanf();

// Empeizan con "s" == desde un STRING lee
sscanf();
sprintf(); // Imprime en una cadena
```
