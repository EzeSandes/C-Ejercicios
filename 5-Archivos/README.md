 # Teoria basica
 Hasta el momento, toda la informacion procesada en los diferentes programas se perdia al cerrar el programa. Sin embargo, en la gran mayoria de casos es de utilidad querer
 tener informacion persistente almacenada en disco para un posterior procesamiento de lectura, escritura y demas. 
 
 ### Hay dos tipos de archivos en C

- Texto
- Binario

## Binario
- Copia directamente una porcion de memoria. No analiza nada
- Ventaja: Al copiar directamente porciones de memoria(bytes) es muy rapido ya que no hay ningun tipo de procesamiento en el medio.
- Desv: Es dependiente de la arquitectura con la cual trabajo. Si trabajo en 64bits y otro en 16bits habra problemas de lectura.

## Texto
- Si necesito compartir archivos entre aplicaciones conviene en .txt. Esto es devido a que no importa la arquitectura que se este usando, todos pueden leer ASCII.
- Transforma cada elemento a su codigo ASCII, lo cual es ventajoso si se quiere ver a simple vista la informacion procesada/guardada.
- DESV: Asi como se puede leer a simple vista el archivo, si guardo passwords o cualquier otra informacion sensible no es conveniente.

## Forma de acceso
- Secuencial: Me paro en un punto del archivo y desde ahi voy leyendo uno por uno.
- Aleatoria o Directa: Directamente me paro en donde esta la informacion que quiero leer sin necesidad de leer todos los regs que estan antes o despues de eso.

## Forma de flujo de la informacion
- Entrada: Cuando es de Lectura(leo del archivo).
- Salida: Cuando grabo inform. en el archivo.
- Entrada/Salida.

## Cuadro de tipos de apertura de archivos.

|  | Modo Apertura | Si Existe | Si No Existe | Entrada y Salida |
|-|-|-|-|-|
| Entrada - Lectura | r | Abre al principio | retorna NULL | r+ |
| Salida - Escritura | w | Vacia el archivo que existe y abre vacio | Crea archivo vacio | w+ (crear el archivo y puedo leerlo tambien) |
| Append - Agregar inform. | a | Abre al final. Siempre graba al final | Crea el archivo | a+ 

El + es de la operacion q me falta:
- r+ == Lectura + Escritura
- w+ == Escritura + Lectura

## Cierre de archivos

Siempre es importante cerrar los archivos una vez que se termine de trabajar con ellos. Es importante debido a que otras aplicaciones, o en el mismo programa,
se reutilice el mismo archivo. Si no se lo cerro correctamente habra problemas en la ejecucion.

Los archivos siempre se cierran en el mismo nivel que fue abierto, es decir:

```
pf = abrirArchivo("Ejemplo.txt");

ejecutar();

cerrarArchivo(pf);
```

En el pseudocodigo anterior, "pf"(puntero del archivo) se cierra en el mismo bloque que se abrio y no dentro de la funcion "ejecutar()".
