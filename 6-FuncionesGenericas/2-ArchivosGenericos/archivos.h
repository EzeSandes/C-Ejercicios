#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

#define NOM_ARCH_EMPLEADOS  "empelados.dat"
#define NOM_ARCH_ALUMNOS    "alumnosFijo.txt"
#define TAM_NOMBRE_EMP      31
#define TAM_APELLIDO_EMP    31

#define TAM_NOMYAP_ALUM     51

// Aca cambio el tamanio dependiendo de la estructura
#define TAM_MAX_ESTRUCTURA  (TAM_NOMBRE_EMP + TAM_APELLIDO_EMP + 20 )

typedef struct
{
    int dia,
        mes,
        anio;
} tFecha;

typedef struct
{
    unsigned    dni;
    char        apellido[TAM_APELLIDO_EMP],
                nombre[TAM_NOMBRE_EMP];
    double      sueldo;
} tEmpleado;

typedef struct sAlu
{
    unsigned    dni;
    char        nyap[TAM_NOMYAP_ALUM];
    char        sexo;
    tFecha      fechaIng;
    float       prom;
} tAlumno;


int crearLoteDePruebas();
int abrirArchivo(const char *nomArch, FILE **pf, const char *modo);
int leerArchivoBin(FILE *pf, void *registro, size_t tamRegistro,
                   void (*accion)(FILE *, void *));

void mostrarReg_emp(FILE *pf, void *reg);
void actualizar_emp(FILE *pf, void *reg);

int leerArchivoTxt(FILE *pf, void *registro,
                   void obtenerReg(char *linea, void *reg),
                   void (*accion)(void *reg));
void obtenerReg_alu(char *linea, void *reg);
void mostrarReg_alu(void *reg);

#endif // ARCHIVOS_H_INCLUDED
