#include "archOperacConjuntos.h"

#define TODO_OK     1
#define ERROR       0

/////////////////////////////////

int opcionAbrirArchivos(FILE **pfEst, FILE **pfEmp)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nAbriendo archivos de pruebas...");

    if(abrirArchivos_EstYEmp(pfEst, pfEmp))
    {
        printf("\nArchivos de pruebas abiertos exitosamente.");
        printf("\n\n//////////////////////////////");
        return TODO_OK;
    }else
        return ERROR;
}

/////////////////////////////////

void opcionCrearLotesDePruebas()
{
    printf("\n\n//////////////////////////////");
    printf("\n\nCreando Lotes de pruebas...");
    crearLoteDePruebas();
    printf("\n\nLotes de pruebas creados exitosamente");
    printf("\n\n//////////////////////////////");
}

/////////////////////////////////

int opcionInterseccionArchivos(FILE *pfEst, FILE *pfEmp)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nInterseccion de archivos de lotes de pruebas...");

    if(interseccionArchivos_EstYEmp(pfEst, pfEmp) == TODO_OK)
    {
        printf("\n\nArchivos interseccionados exitosamente en \" %s \"", NOM_ARCH_INTERSECCION);
        printf("\n\n//////////////////////////////");
        return TODO_OK;
    }else
    {
        printf("\n\nERROR al interseccionar los archivos");
        printf("\n\n//////////////////////////////");
        return ERROR;
    }
}

/////////////////////////////////

void opcionMostrarArchivoInterseccion()
{
    printf("\n\n//////////////////////////////");
    printf("\n\nMostrando archivo de Interseccion\n\n");

    mostrarArchivoInterseccion();

    printf("\n\n//////////////////////////////");
}

/////////////////////////////////

int opcionUnionArchivos(FILE *pfEst, FILE *pfEmp)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nUnion de archivos de lotes de pruebas...");

    if(unionArchivos_EstYEmp(pfEst, pfEmp) == TODO_OK)
    {
        printf("\n\nArchivos unidos exitosamente en \" %s \"", NOM_ARCH_UNION);
        printf("\n\n//////////////////////////////");
        return TODO_OK;
    }else
    {
        printf("\n\nERROR al unir los archivos");
        printf("\n\n//////////////////////////////");
        return ERROR;
    }
}

/////////////////////////////////
void opcionMostrarArchivoUnion()
{
    printf("\n\n//////////////////////////////");
    printf("\n\nMostrando archivo de Union\n\n");

    mostrarArchivo(NOM_ARCH_UNION);

    printf("\n\n//////////////////////////////");
}

/////////////////////////////////

int opcionDiferenciaArchivos_EstMenosEmp(FILE *pfEst, FILE *pfEmp)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nDiferencia de archivos de lotes de pruebas...");

    if(diferenciaAmenosB_EstYEmp(pfEst, pfEmp) == TODO_OK)
    {
        printf("\n\nArchivo de diferencia creado exitosamente en \" %s \"", NOM_ARCH_DIFERENCIA_A_MENOS_B);
        printf("\n\n//////////////////////////////");
        return TODO_OK;
    }else
    {
        printf("\n\nERROR diferencia de los archivos");
        printf("\n\n//////////////////////////////");
        return ERROR;
    }
}

void opcionMostrarArchivoDiferencia_AMenosB()
{
    printf("\n\n//////////////////////////////");
    printf("\n\nMostrando archivo A - B(Est - Emp)\n\n");

    mostrarArchivo(NOM_ARCH_DIFERENCIA_A_MENOS_B);

    printf("\n\n//////////////////////////////");
}
