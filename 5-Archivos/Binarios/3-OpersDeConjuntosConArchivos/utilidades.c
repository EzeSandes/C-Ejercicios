#include <string.h>
#include "archOperacConjuntos.h"

#define TODO_OK     1
#define ERROR       0

int comparacion_EstYEmp(const tEstudiante *est, const tEmpleado *emp)
{
    int res;

    if((res = strcmp(est->persona.apellido, emp->persona.apellido)) == 0)
        if((res = strcmp(est->persona.nombre, emp->persona.nombre)) == 0)
            return est->persona.dni - emp->persona.dni;

    return res;
}

///////////////////////////////

int abrirArchivos_EstYEmp(FILE **pfEst, FILE **pfEmp)
{
    *pfEst = fopen(NOM_ARCH_ESTUDIANTES, "rb");
    if(!*pfEst)
    {
        printf("ERROR al abrir: %s", NOM_ARCH_ESTUDIANTES);
        return ERROR;
    }

    *pfEmp = fopen(NOM_ARCH_EMPLEADOS, "rb");
    if(!*pfEmp)
    {
        fclose(*pfEst);
        printf("ERROR al abrir: %s", NOM_ARCH_EMPLEADOS);
        return ERROR;
    }

    return TODO_OK;
}

///////////////////////////////

int crearLoteDePruebas()
{
    FILE    *pfEst,
            *pfEmp;

    tEmpleado empleados[] =
    {
        {{75, "Albez", "Victoria"}, 10000},
        {{32, "Alvez", "Martin"}, 10000},
        {{96, "Alvorado", "Martin"}, 10000},
        {{99, "Armando", "Rau"}, 10000},
        {{74, "Armando", "Raul"}, 10000},
        {{63, "Augusto", "Esteban"}, 10000},
        {{97, "Augusto", "Esteban"}, 10000},
        {{56, "Azcuenaga", "Federico"}, 10000},
        {{33, "Basili", "Andres"}, 1000},
        {{45, "Beca", "Facundo"}, 10000},
        {{03, "Beka", "Facundo"}, 10000},
        {{39, "Cisco", "Esteban"}, 20000},
        {{24, "Coco", "Eduardo"}, 10000},
        {{31, "Estrella", "Maria"}, 10000},
        {{23, "Estrella", "Mauricio"}, 10000},
        {{13, "Estrella", "Patricio"}, 20000},
        {{29, "Gonzalez", "Gonzalo"}, 10000},
        {{58, "Gonzalez", "Lucas"}, 10000},
        {{30, "Gonzalez", "Luciano"}, 10000},
        {{75, "Jaime", "Nick"}, 10000},
        {{88, "Jaime","Nicolas"}, 10000},
        {{10, "Lopez", "Facundo"}, 10000},
        {{68, "Lopez", "Leonardo"}, 10000},
        {{21, "Mujica", "Pablo"}, 10000},
        {{65, "Mujica", "Pepito"}, 10000},
        {{20, "Perez", "Esteban"}, 10000},
        {{55, "Perez", "Juan"}, 10000},
        {{50, "Perez", "Juan"}, 10000},
        {{83, "Torres", "Esteban"}, 20000},
        {{46, "Torres", "Federico"}, 10000},
        {{12, "Torres", "Leila"}, 10000},
        {{66, "Torrez", "Janette"}, 10000},
        {{77, "Victoria", "Victoria"}, 10000},
    };

    tEstudiante estudiantes[] =
    {
        {{02, "AA", "A"}, 8},
        {{32, "Alvez", "Martin"}, 7.8},
        {{96, "Alvorado", "Martin"}, 5},
        {{99, "Armando", "Rau"}, 7},
        {{74, "Armando", "Raul"}, 6},
        {{63, "Augusto", "Esteban"}, 8},
        {{31, "Estrella", "Maria"}, 6},
        {{23, "Estrella", "Mauricio"}, 8.5},
        {{13, "Estrella", "Patricio"}, 9},
        {{75, "Jaime", "Nick"}, 5},
        {{88, "Jaime", "Nicolas"}, 4.5},
        {{10, "Lopez", "Facundo"}, 8},
        {{68, "Lopez", "Leonardo"}, 2},
        {{21, "Mujica", "Pablo"}, 9},
        {{65, "Mujica", "Pepito"}, 6.5},
        {{20, "Perez", "Esteban"}, 8},
        {{55, "Perez", "Juan"}, 6.9},
        {{50, "Perez", "Juan"}, 9},
        {{100, "Sosa", "Leonardo"}, 9},
    };

/*    tEmpleado empleados[] =
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
*/
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

///////////////////////////////

int mostrarArchivoInterseccion()
{
    FILE    *pfEst;
    tEstudiante estudiante;

    pfEst = fopen(NOM_ARCH_INTERSECCION, "rb");
    if(!pfEst)
    {
        perror("\nERROR. pfInterseccion");
        return ERROR;
    }

    fread(&estudiante, sizeof(tEstudiante), 1, pfEst);
    while(!feof(pfEst))
    {
        mostrarEstudiante(&estudiante);
        fread(&estudiante, sizeof(tEstudiante), 1, pfEst);
    }

    fclose(pfEst);
    return TODO_OK;
}
///////////////////////////////

void mostrarEstudiante(const tEstudiante *est)
{
    printf("\n\n///////");
    printf("\n\nApellido: %s", est->persona.apellido);
    printf("\nNombre: %s", est->persona.nombre);
    printf("\nDNI: %u", est->persona.dni);
    printf("\nPromedio: %.2f", est->promedio);
}

///////////////////////////////

void mostrarPersona(const tPersona *per)
{
    printf("\n\n///////");
    printf("\nDNI: %u", per->dni);
    printf("\n\nApellido: %s", per->apellido);
    printf("\nNombre: %s", per->nombre);
}

///////////////////////////////

int mostrarArchivo(const char *nomArch)
{
    FILE    *pf;
    tPersona persona;

    pf = fopen(nomArch, "rb");
    if(!pf)
    {
        printf("\nERROR. %s", nomArch);
        perror("");
        return ERROR;
    }

    fread(&persona, sizeof(tPersona), 1, pf);
    while(!feof(pf))
    {
        mostrarPersona(&persona);
        fread(&persona, sizeof(tPersona), 1, pf);
    }

    fclose(pf);
    return TODO_OK;
}
