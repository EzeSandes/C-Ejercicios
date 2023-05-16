#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//funciones de crear la matriz
void** crearMatDinamica(int fil,int col,size_t tamElem);
void liberarMatDin(void** mat,int cantF);


//funciones de mostrarla para tipo int y char
void mostrarMatrizDin(void** mat,int fil,int col,void (*mostrarVec)(void*,int));
void mostrarVecInt(void *vec,int tam);
void mostrarVecChar(void *vec,int tam);


//funciones de cargarla para tipo int y char
void cargarMatrizDin(void**mat,int fil,int col,void (*cargar)(void*,int));
void cargarVecInt(void* vec,int tam);
void cargarVecChar(void* vec,int tam);

#endif // FUNCION_H_INCLUDED
