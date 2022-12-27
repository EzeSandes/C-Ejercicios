#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "archivos.h"

#define     ERROR   0
#define     TODO_OK 1

float calcularPromedio(const int *vec, int cantElem);

////////////////////////////

float calcularPromedio(const int *vec, int cantElem)
{
    int i;
    float suma = 0;

    for(i = 0; i < cantElem; i++)
    {
        suma += *vec;
        vec++;
    }

    return suma / cantElem;
}

///////////////////////////////////////////////////////

int ingresarAlumno(tAlum *alu)
{
    /// NO IMPORTA EL ORDEN
    tFecha fecha = { .dia = 8, .mes = 4, .anio = 2022};
//    tFecha fecha = { .dia = 8, .mes = 4, .anio = 2022};
//    tFecha fecha = { dia : 8, mes : 4, anio : 2022};
//    tFecha fecha = { mes : 4, dia : 8, anio : 2022};

    /// IMPORTA EL ORDEN
//    tFecha fecha = { 8, 4, 2022};

    printf("DNI: ");
    scanf("%u", &alu->dni);

    if(!alu->dni)
        return 0;

    printf("\nNombre y Apellido: ");
    fflush(stdin);
    gets(alu->nyap);

    printf("\nPromedio: ");
    scanf("%f", &alu->prom);

    alu->fechaIng = fecha;

    return TODO_OK;
}

////////////////////////////

int cargarAlumno(tAlum *alu)
{
    int i,
        *pNotas = alu->notas;

/// NO IMPORTA EL ORDEN
    tFecha fecha = { .dia = 8, .mes = 4, .anio = 2022};
//    tFecha fecha = { .dia = 8, .mes = 4, .anio = 2022};
//    tFecha fecha = { dia : 8, mes : 4, anio : 2022};
//    tFecha fecha = { mes : 4, dia : 8, anio : 2022};

    /// IMPORTA EL ORDEN
//    tFecha fecha = { 8, 4, 2022};

    printf("\n\nDNI(0 para salir): ");
    scanf("%u", &alu->dni);

    if(!alu->dni)
        return 0;

    printf("\nNombre y Apellido: ");
    fflush(stdin);
    gets(alu->nyap);


    for(i = 0; i < sizeof(alu->notas) / sizeof(int); i++)
    {
        printf("\nNota %d: ", i + 1);
        scanf("%d", pNotas);
        pNotas++;
    }

//    printf("\nPromedio: ");
//    scanf("%f", &alu->prom);

    alu->prom = calcularPromedio(alu->notas, sizeof(alu->notas) / sizeof(int));

    alu->fechaIng = fecha;

    return TODO_OK;
}

////////////////////////////

void mostrarAlumno(const tAlum *alu)
{
    int i;
    int *pNotas = (int *)alu->notas;

    printf("\n\n//////////////////");
    printf("\nDNI: %u", alu->dni);
    printf("\nNombre y Apellido: %s", alu->nyap);

    printf("\nNotas: ");
    for(i = 0; i < sizeof(alu->notas) / sizeof(int); i++)
    {
        printf(" %d |", *pNotas);
        pNotas++;
    }

//    printf("\nNotas: %d | %d | %d |", alu->notas[0], alu->notas[1], alu->notas[2]);
    printf("\nPromedio: %.2f", alu->prom);
    printf("\nFecha Ingreso: %d / %d / %d", alu->fechaIng.dia, alu->fechaIng.mes, alu->fechaIng.anio);
}

////////////////////////////

int crearArchivo(const char *nombreArchivo)
{
    // Deberia preguntar al usuario por el nombre del archivo a crear previamente
    // por fuera de la funcion.
    FILE *pf = fopen(nombreArchivo, "wb");

    if(!pf)
        return ERROR;

    fclose(pf);
    return TODO_OK;
}

////////////////////////////

int abrirArchivoBin(const char *nomArchivo, FILE **pf, const char *modo)
{
    *pf = fopen(nomArchivo, modo);

    return *pf ? TODO_OK : ERROR;
}

////////////////////////////

int cargarAchivoBin(FILE *pfArch)
{
    tAlum alu;

    if(!pfArch)
        return ERROR;

    while(cargarAlumno(&alu))
        fwrite(&alu, sizeof(tAlum), 1, pfArch);

    return TODO_OK;
}
////////////////////////////

void opcionCrearArchivoBin()
{
    char nomArchivo[TAM_CAD] = "alumnos.dat";

    printf("\n\n/////////////////////////");
    printf("\n\n\t\t\t\tCrear Archivo.");

    // DESCOMENTAR SI SI QUIERE PREGUNTAR POR EL NOMBRE AL USUARIO
//    printf("\nNombre del archivo .bin a crear: ");
//    fflush(stdin);
//    gets(nomArchivo);

    printf(crearArchivo(nomArchivo)? "\nArchivo creado exitosamente." :
                   "\nNo se pudo crear el archivo.");

    printf("\n/////////////////////////");
}

////////////////////////////

void opcionAbrirArchivoBin(FILE **pf)
{
    char nomArchivo[TAM_CAD] = "alumnos.dat";

    printf("\n\n/////////////////////////");
    printf("\n\n\t\t\t\tAbrir Archivo.");

    // DESCOMENTAR SI SI QUIERE PREGUNTAR POR EL NOMBRE AL USUARIO
//    printf("\nNombre del archivo .bin a abrir: ");
//    fflush(stdin);
//    gets(nomArchivo);

    printf(abrirArchivoBin(nomArchivo, pf, "r+b")? "\nArchivo abierto exitosamente." :
                   "\nNo se pudo Abrir el archivo. Compruebe el nombre del mismo\
                   o que se encuentre en la misma carpeta del proyecto.");

    printf("\n\n/////////////////////////\n\n");
}

////////////////////////////

void opcionCargarArchivoBin(FILE *pf)
{
    printf("\n\n/////////////////////////");

    printf("\n\n\t\t\t\tCarga de Archivos.");

    printf(cargarAchivoBin(pf)? "\n\nCarga realizada exitosamente." : "\n\nError al cargar el archivo. Asegurese de haberlo abierto previamente correctamente");
    printf("\n\n/////////////////////////\n\n");
}

////////////////////////////

void opcionMostrarArchivoBin(FILE *pf)
{
    tAlum alu;

    if(!pf)
    {
        printf("\nERROR al mostrar el archivo. Asegurece de haberlo abierto correctamente.\n");
        printf("\n\n/////////////////////////\n\n");
        return;
    }

    printf("\n\n/////////////////////////");
    printf("\n\n\t\t\t\tMostrando Registros del Archivo.");

    rewind(pf); // Me aseguro que el puntero este apuntando al principio del arch.
    fread(&alu, sizeof(tAlum), 1, pf);
    while(!feof(pf))
    {
        mostrarAlumno(&alu);
        fread(&alu, sizeof(tAlum), 1, pf);
    }

    printf("\n\n/////////////////////////\n\n");
}

////////////////////////////
////////////////////////////
