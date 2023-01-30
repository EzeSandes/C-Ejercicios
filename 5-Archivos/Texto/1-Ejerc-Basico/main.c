#include <stdio.h>
#include <stdlib.h>
#include "opcionesMenu.h"

int main()
{
    FILE    *pfBin = NULL;

    int opcion;

    do
    {
        printf("\n0: Salir\
               \n1: Crear Lote de pruebas( %s )\
               \n2: Abrir Archivo de lote de pruebas\
               \n3: Binario a Txt Fijo\
               \n4: Binario a Txt Variable\
               \n5: Txt Variable a Bin\
               \n6: Txt Fijo a Bin\
               \n7: \
               \n8: Mostrar Archivo BIN de TXT Variable\
               \n9: Mostrar Archivo BIN de TXT Fijo\
               \n10: Mostrar Archivo TXT Fijo x Trozado\
               ", NOM_ARCH_ESTUDIANTES);

        printf("\n\nEscoja una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 0:
            break;

        case 1:
            opcionCrearLoteDePrueba();
            break;

        case 2:
            opcionAbrirLoteDePrueba(&pfBin);
            break;

        case 3:
            opcionBinarioATxtFijo(pfBin, NOM_ARCH_BIN_A_TXT_FIJO);
            break;

        case 4:
            opcionBinarioATxtVariable(pfBin, NOM_ARCH_BIN_A_TXT_VAR);
            break;

        case 5:
            opcionTxtVariableABin(NOM_ARCH_TXT_VAR, NOM_ARCH_TXT_VAR_A_BIN);
            break;

        case 6:
            opcionTxtFijoABin(NOM_ARCH_TXT_FIJO, NOM_ARCH_TXT_FIJO_A_BIN);
            break;

        case 8:
            mostrarArchBin(NOM_ARCH_TXT_VAR_A_BIN);
            break;

        case 9:
            mostrarArchBin(NOM_ARCH_TXT_FIJO_A_BIN);
            break;

        case 10:
            archTxtFijoABin_SinFscanf(NOM_ARCH_TXT_FIJO);
            break;

        default:
            printf("\nOpcion Incorrecta. Ingrese una opcion valida.");
            break;
        }

    }
    while(opcion);



    fclose(pfBin);
    printf("\n\nSaliendo....\nSalida Exitosa");
    printf("\n\n");
    return 0;
}
