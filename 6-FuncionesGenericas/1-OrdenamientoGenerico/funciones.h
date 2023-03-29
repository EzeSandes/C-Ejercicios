#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned    dni;
    char        apellido[31],
                nombre[31];
    double      sueldo;
} tEmpleado;

int compararInt(const void *elem1, const void *elem2);
void mostrar(int* vec,int ceVec);
int compararEmp(const void *elem1, const void *elem2);
void mostrarEmp(tEmpleado* emp,int ceEmp);
void ordenarVecPorSeleccion(void *vec,int ceVec,int tamElem,int(*comparar)(const void *, const void *),void(*intercambio)(void *,void *));
void intercambioInt(void *pInicio, void *pMenor);
void intercambioEmp(void *pInicio, void *pMenor);

#endif // FUNCIONES_H_INCLUDED
