#include "opcionesMenu.h"

#define TODO_OK 1
#define ERROR   0

void opcionCrearLoteDePrueba()
{
    printf("\n\n//////////////////////////////");
    printf("\n\nCreando Lotes de pruebas...");
    crearLoteDePruebas();
    printf("\n\nLotes de pruebas creados exitosamente");
    printf("\n\n//////////////////////////////");
}

//////////////////////

int opcionAbrirLoteDePrueba(FILE **pfBin)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nAbriendo archivo de prueba...");

    if(abrirArchivoBin(pfBin))
    {
        printf("\nArchivo de prueba abierto exitosamente.");
        printf("\n\n//////////////////////////////");
        return TODO_OK;
    }else
        return ERROR;
}

int opcionBinarioATxtFijo(FILE *pfBin, const char *nomArchTxt)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nConvirtiendo archivo Bin de prueba a Txt Fijo...");

    if(archBinATxt(pfBin, nomArchTxt, 'F'))// F == Long Fija
    {
        printf("\nArchivo de prueba convertido exitosamente.");
        printf("\n\n//////////////////////////////");
        return TODO_OK;
    }else
        return ERROR;
}

////////////////

int opcionBinarioATxtVariable(FILE *pfBin, const char *nomArchTxt)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nConvirtiendo archivo Bin de prueba a Txt Variable...");

    if(archBinATxt(pfBin, nomArchTxt, 'V'))// V == Long Variable
    {
        printf("\nArchivo de prueba convertido exitosamente.");
        printf("\n\n//////////////////////////////");
        return TODO_OK;
    }else
        return ERROR;
}

/////////////////

int opcionTxtVariableABin(const char *nomArchTxt, const char *nomArchBin)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nConvirtiendo archivo Txt Variable a Bin...");

    if(archTxtABin(nomArchTxt, nomArchBin, 'V'))
    {
        printf("\nArchivo de Txt Var a Bin convertido exitosamente.");
        printf("\n\n//////////////////////////////");
        return TODO_OK;
    }else
        return ERROR;
}

int opcionTxtFijoABin(const char *nomArchTxt, const char *nomArchBin)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nConvirtiendo archivo Txt Fijo a Bin...");

    if(archTxtABin(nomArchTxt, nomArchBin, 'F'))
    {
        printf("\nArchivo de Txt Fijo a Bin convertido exitosamente.");
        printf("\n\n//////////////////////////////");
        return TODO_OK;
    }else
        return ERROR;
}
