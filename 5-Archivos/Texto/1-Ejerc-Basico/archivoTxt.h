#ifndef ARCHIVOSTXT_H_INCLUDED
#define ARCHIVOSTXT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////

#define TAM_CAD 51

#define NOM_ARCH_ESTUDIANTES    "alumnos.dat"
#define NOM_ARCH_BIN_A_TXT_FIJO    "alumnosTxtFijo.txt"
#define NOM_ARCH_BIN_A_TXT_VAR    "alumnosTxtVariable.txt"
#define NOM_ARCH_TXT_VAR_A_BIN    "alumnosTxtVariableABin.dat"
#define NOM_ARCH_TXT_FIJO_A_BIN    "alumnosTxtFijoABin.dat"

#define NOM_ARCH_TXT_VAR            NOM_ARCH_BIN_A_TXT_VAR
#define NOM_ARCH_TXT_FIJO           NOM_ARCH_BIN_A_TXT_FIJO

///////////////////////////////////////

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

int crearLoteDePruebas();
int abrirArchivoBin(FILE **pfBin);
int archBinATxt(FILE *pfBin, const char *nomArchTxt, char formatoTxt);
int archTxtABin(const char *nomArchTxt, const char *nomArchBin ,char formatoTxt);
void mostrarAlumno(const tAlumno *alu);

int mostrarArchBin(const char *nomArchBin);

int archTxtFijoABin_SinFscanf(const char *nomArchTxt);

#endif // ARCHIVOSTXT_H_INCLUDED
