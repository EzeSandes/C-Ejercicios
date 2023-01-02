#ifndef EJERCARCHIVOS_H_INCLUDED
#define EJERCARCHIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////

#define TAM_CAD 51

#define NOM_ARCH_ESTUDIANTES    "estudiantes.dat"
#define NOM_ARCH_EMPLEADOS    "empleados.dat"
///////////////////////////////////////

typedef struct
{
    unsigned    dni;
    char        apellido[TAM_CAD],
                nombre[TAM_CAD];
    double      sueldo;
} tEmpleado;

typedef struct
{
    unsigned    dni;
    char        apellido[TAM_CAD],
                nombre[TAM_CAD];
    float       promedio;
} tEstudiante;

///////////////////////////////////////

////// OPCIONES

void opcionCrearLoteDePruebas();
int opcionAbrirArchivosDePruebas(FILE **pfEmp, FILE **pfEst);
void opcionActualizarArchivos(FILE *pfEmp, FILE *pfEst);
void opcionMostrarArchivoEstudiante(FILE *pf);
void opcionMostrarArchivoEmpleados(FILE *pf);

//////

int crearLoteDePruebas();
void ejercicioActualizarArchivos(FILE *pfEmp, FILE *pfEst);
void actualizarArchivoEmpleado(FILE *pfEmp, const tEmpleado *emp);
int comparacionEstYEmp(const tEstudiante *est, const tEmpleado *emp);
void criteriosDeActualizacion(const tEstudiante *est, tEmpleado *emp);
void actualizarArchivoEmpleado(FILE *pfEmp, const tEmpleado *emp);

void mostrarEstudiante(const tEstudiante *est);
void mostrarEmpleado(const tEmpleado *emp);

///////////////////////////////////////

#endif // EJERCARCHIVOS_H_INCLUDED
