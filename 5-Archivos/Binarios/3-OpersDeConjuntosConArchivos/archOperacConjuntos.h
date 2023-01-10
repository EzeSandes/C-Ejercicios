#ifndef ARCHOPERACCONJUNTOS_H_INCLUDED
#define ARCHOPERACCONJUNTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////// DEFINES

#define TAM_CAD 51

#define NOM_ARCH_ESTUDIANTES    "estudiantes.dat"
#define NOM_ARCH_EMPLEADOS    "empleados.dat"

#define NOM_ARCH_INTERSECCION   "interseccionEstYEmp.dat"
#define NOM_ARCH_UNION          "unionEstYEmp.dat"
#define NOM_ARCH_DIFERENCIA_A_MENOS_B          "diferenciaAmenosB.dat"

///////////////////////////////////////

typedef struct
{
    unsigned    dni;
    char        apellido[TAM_CAD],
                nombre[TAM_CAD];
}tPersona;

typedef struct
{
    tPersona    persona;
    double      sueldo;
} tEmpleado;

typedef struct
{
    tPersona    persona;
    float       promedio;
} tEstudiante;


/////////////////////////////////////// UTILIDADES

int crearLoteDePruebas();
int comparacion_EstYEmp(const tEstudiante *est, const tEmpleado *emp);
int abrirArchivos_EstYEmp(FILE **pfEst, FILE **pfEmp);

void mostrarEstudiante(const tEstudiante *est);
void mostrarPersona(const tPersona *per);
int mostrarArchivoInterseccion();
int mostrarArchivo(const char *nomArch);

/////////////////////////////////////// OPCIONES

int opcionAbrirArchivos(FILE **pfEst, FILE **pfEmp);
void opcionCrearLotesDePruebas();
int opcionInterseccionArchivos(FILE *pfEst, FILE *pfEmp);
int opcionUnionArchivos(FILE *pfEst, FILE *pfEmp);
int opcionDiferenciaArchivos_EstMenosEmp(FILE *pfEst, FILE *pfEmp);

void opcionMostrarArchivoInterseccion();
void opcionMostrarArchivoUnion();
void opcionMostrarArchivoDiferencia_AMenosB();

/////////////////////////////////////// OPERACIONES

int interseccionArchivos_EstYEmp(FILE *pfEst, FILE *pfEmp);
int unionArchivos_EstYEmp(FILE *pfEst, FILE *pfEmp);
int diferenciaAmenosB_EstYEmp(FILE *pfA, FILE *pfB);

///////////////////////////////////////
///////////////////////////////////////

#endif // ARCHOPERACCONJUNTOS_H_INCLUDED
