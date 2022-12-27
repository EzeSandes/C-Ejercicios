#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivos.h"

int main()
{
    int opcion;
    FILE    *pf = NULL;

    do
    {
         printf("\n0: Salir\
                \n1: Crear Archivo Bin\
                \n2: Abrir Archivo Bin \
                \n3: Cargar Arch Alumnos Bin\
                \n4: Mostrar Arch Alumnos Bin");

        printf("\n\nElija una opcion(0 -> salir): ");
        fflush(stdin); // No necesario
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 0:
            printf("\n\nSaliendo...");
            printf("\nSalida exitosa. Gracias!");
            break;

        case 1:
            opcionCrearArchivoBin();
            break;

        case 2:
            opcionAbrirArchivoBin(&pf);
            break;

        case 3:
            opcionCargarArchivoBin(pf);
            break;

        case 4:
            opcionMostrarArchivoBin(pf);
            break;

        default:
            printf("\nOpcion no valida. Por favor, intente nuevamente.\n\n");
            break;
        }
    }
    while(opcion);

    fclose(pf);
    printf("\n\n");
    return 0;
}
