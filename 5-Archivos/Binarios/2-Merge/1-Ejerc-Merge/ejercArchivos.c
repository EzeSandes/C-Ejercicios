#include "ejercArchivos.h"
#include <string.h>

#define TODO_OK 1
#define ERROR   0

///////////////////////////////////////

int crearLoteDePruebas()
{
    FILE    *pfEst,
            *pfEmp;

    tEmpleado empleados[] =
    {
        {75, "Albez", "Victoria", 10000},
        {32, "Alvez", "Martin", 10000},
        {96, "Alvorado", "Martin", 10000},
        {99, "Armando", "Rau", 10000},
        {74, "Armando", "Raul", 10000},
        {63, "Augusto", "Esteban", 10000},
        {97, "Augusto", "Esteban", 10000},
        {56, "Azcuenaga", "Federico", 10000},
        {33, "Basili", "Andres", 1000},
        {45, "Beca", "Facundo", 10000},
        {03, "Beka", "Facundo", 10000},
        {39, "Cisco", "Esteban", 20000},
        {24, "Coco", "Eduardo", 10000},
        {31, "Estrella", "Maria", 10000},
        {23, "Estrella", "Mauricio", 10000},
        {13, "Estrella", "Patricio", 20000},
        {29, "Gonzalez", "Gonzalo", 10000},
        {58, "Gonzalez", "Lucas", 10000},
        {30, "Gonzalez", "Luciano", 10000},
        {75, "Jaime", "Nick", 10000},
        {88, "Jaime","Nicolas", 10000},
        {10, "Lopez", "Facundo", 10000},
        {68, "Lopez", "Leonardo", 10000},
        {21, "Mujica", "Pablo", 10000},
        {65, "Mujica", "Pepito", 10000},
        {20, "Perez", "Esteban", 10000},
        {55, "Perez", "Juan", 10000},
        {50, "Perez", "Juan", 10000},
        {83, "Torres", "Esteban", 20000},
        {46, "Torres", "Federico", 10000},
        {12, "Torres", "Leila", 10000},
        {66, "Torrez", "Janette", 10000},
        {11, "Trump", "Pato Donald", 10000},
        {77, "Victoria", "Victoria", 10000},
        {75, "Zuckov", "Vicky", 20000},
        {71, "Zuckov", "Vasili", 10000},
    };

    tEstudiante estudiantes[] =
    {
        {02, "AA", "A", 8},
        {32, "Alvez", "Martin", 7.8},
        {96, "Alvorado", "Martin", 5},
        {99, "Armando", "Rau", 7},
        {74, "Armando", "Raul", 6},
        {63, "Augusto", "Esteban", 8},
        {31, "Estrella", "Maria", 6},
        {23, "Estrella", "Mauricio", 8.5},
        {13, "Estrella", "Patricio", 9},
        {75, "Jaime", "Nick", 5},
        {88, "Jaime", "Nicolas", 4.5},
        {10, "Lopez", "Facundo", 8},
        {68, "Lopez", "Leonardo", 2},
        {21, "Mujica", "Pablo", 9},
        {65, "Mujica", "Pepito", 6.5},
        {20, "Perez", "Esteban", 8},
        {55, "Perez", "Juan", 6.9},
        {50, "Perez", "Juan", 9},
        {11, "Trump", "Pato Donald", 8.5},
    };

    pfEst = fopen(NOM_ARCH_ESTUDIANTES, "wb");
    if(!pfEst)
    {
        perror("\nERROR. pfEst");
        return ERROR;
    }

    pfEmp = fopen(NOM_ARCH_EMPLEADOS, "wb");
    if(!pfEmp)
    {
        perror("\nERROR. pfEmp");
        fclose(pfEst);
        return ERROR;
    }

    fwrite(estudiantes, sizeof(estudiantes), 1, pfEst);
    fwrite(empleados, sizeof(empleados), 1, pfEmp);

    fclose(pfEst);
    fclose(pfEmp);
    return TODO_OK;
}

///////////////////////////////////////

void ejercicioActualizarArchivos(FILE *pfEmp, FILE *pfEst)
{
    int comp;
    tEmpleado empleado;
    tEstudiante estudiante;

    // Aseguro estar al principio de ambos archivos.
    rewind(pfEmp);
    rewind(pfEst);

    fread(&estudiante, sizeof(tEstudiante), 1, pfEst);
    fread(&empleado, sizeof(tEmpleado), 1, pfEmp);
    while(!feof(pfEst) && !feof(pfEmp))
    {
        comp = comparacionEstYEmp(&estudiante, &empleado);

        if(!comp)// == 0
        {
            criteriosDeActualizacion(&estudiante, &empleado);
            actualizarArchivoEmpleado(pfEmp, &empleado);
            fread(&estudiante, sizeof(tEstudiante), 1, pfEst);
            fread(&empleado, sizeof(tEmpleado), 1, pfEmp);
        }

        if(comp < 0)
        {
            fread(&estudiante, sizeof(tEstudiante), 1, pfEst);
        }

        if(comp > 0)
        {
            fread(&empleado, sizeof(tEmpleado), 1, pfEmp);
        }
    }
}

///////////////////////////////////////

int comparacionEstYEmp(const tEstudiante *est, const tEmpleado *emp)
{
    int res;

    if((res = strcmp(est->apellido, emp->apellido)) == 0)
        if((res = strcmp(est->nombre, emp->nombre)) == 0)
            return est->dni - emp->dni;

    return res;
}

///////////////////////////////////////

void criteriosDeActualizacion(const tEstudiante *est, tEmpleado *emp)
{
    float porcentajeDeAumento = 0.728;

    /// Actualizo todo lo que tengo que actualizar aca.
    // Si en un futuro tengo mas condiciones, las coloco todas en esta funcion.
    if(est->promedio > 7)
    {
        emp->sueldo += emp->sueldo * porcentajeDeAumento;
    }
}

///////////////////////////////////////

void actualizarArchivoEmpleado(FILE *pfEmp, const tEmpleado *emp)
{
    fseek(pfEmp, -(long)sizeof(tEmpleado), SEEK_CUR);
    fwrite(emp, sizeof(tEmpleado), 1, pfEmp);
    fseek(pfEmp, 0L, SEEK_CUR);
}

///////////////////////////////////////

void opcionCrearLoteDePruebas()
{
    printf("\n\n//////////////////////////////");
    printf("\n\nCreando Lotes de pruebas...");
    crearLoteDePruebas();
    printf("\n\nLotes de pruebas creados exitosamente");
    printf("\n\n//////////////////////////////");
}

///////////////////////////////////////

int opcionAbrirArchivosDePruebas(FILE **pfEmp, FILE **pfEst)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nAbriendo archivos de pruebas...");

    *pfEmp = fopen(NOM_ARCH_EMPLEADOS, "r+b"); // r+b xq es el que voy a actualizar
    if(!*pfEmp)
    {
        printf("\n");
        perror(NOM_ARCH_EMPLEADOS);
        return ERROR;
    }

    *pfEst = fopen(NOM_ARCH_ESTUDIANTES, "rb");
    if(!*pfEst)
    {
        fclose(*pfEmp);
        printf("\n");
        perror(NOM_ARCH_ESTUDIANTES);
        return ERROR;
    }

    printf("\nArchivos de pruebas abiertos exitosamente.");
    return TODO_OK;
}

///////////////////////////////////////

void opcionActualizarArchivos(FILE *pfEmp, FILE *pfEst)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nActualizando...");
    ejercicioActualizarArchivos(pfEmp, pfEst);
    printf("\nArchivo/s actualizado/s.");
    printf("\n\n//////////////////////////////");
}

///////////////////////////////////////

void opcionMostrarArchivoEstudiante(FILE *pf)
{
    tEstudiante estudiante;

    rewind(pf);

    printf("\n\n//////////////////////////////");
    printf("\n\nMostrando archivo de Estudiantes\n\n");

    fread(&estudiante, sizeof(tEstudiante), 1, pf);
    while(!feof(pf))
    {
        mostrarEstudiante(&estudiante);
        fread(&estudiante, sizeof(tEstudiante), 1, pf);
    }

    printf("\n\n//////////////////////////////");
}

///////////////////////////////////////

void opcionMostrarArchivoEmpleados(FILE *pf)
{
    tEmpleado empleado;

    rewind(pf);

    printf("\n\n//////////////////////////////");
    printf("\n\nMostrando archivo de Empleados\n\n");

    fread(&empleado, sizeof(tEmpleado), 1, pf);
    while(!feof(pf))
    {
        mostrarEmpleado(&empleado);
        fread(&empleado, sizeof(tEmpleado), 1, pf);
    }

    printf("\n\n//////////////////////////////");
}

///////////////////////////////////////

void mostrarEstudiante(const tEstudiante *est)
{
    printf("\n\n///////");
    printf("\n\nApellido: %s", est->apellido);
    printf("\nNombre: %s", est->nombre);
    printf("\nDNI: %u", est->dni);
    printf("\nPromedio: %.2f", est->promedio);
}

///////////////////////////////////////

void mostrarEmpleado(const tEmpleado *emp)
{
    printf("\n\n///////");
    printf("\n\nApellido: %s", emp->apellido);
    printf("\nNombre: %s", emp->nombre);
    printf("\nDNI: %u", emp->dni);
    printf("\nSueldo: %.2f", emp->sueldo);
}

///////////////////////////////////////
