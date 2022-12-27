#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#define TAM_CAD 51

typedef struct
{
    char cad[TAM_CAD];
} tCad;

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
    float       prom;
    tFecha      fechaIng; // Debe estar definida antes
    int         notas[3];
//    struct sAlu *tutor;
} tAlum;

/*
 El tam de la estructura NO ES LA SUMA DE LOS TAM DE SUS TIPOS.
 El compilador le asigna y deja mas espacio a una variable si no hay mem para
 que sea mas facil leerlo.

 No siempre coincide con la suma de los tam de cada campo que la componen.
 
 VER MAS: Arquitectura de Computadoras
*/

int ingresarAlumno(tAlum *alu);
int cargarAlumno(tAlum *alu);
void mostrarAlumno(const tAlum *alu);


int crearArchivo(const char *nombreArchivo);
int abrirArchivoBin(const char *nomArchivo, FILE **pf, const char *modo);
int cargarAchivoBin(FILE *pfArch);

void opcionCrearArchivoBin();
void opcionAbrirArchivoBin(FILE **pf);
void opcionCargarArchivoBin(FILE *pf);
void opcionMostrarArchivoBin(FILE *pf);

#endif // ARCHIVOS_H_INCLUDED
