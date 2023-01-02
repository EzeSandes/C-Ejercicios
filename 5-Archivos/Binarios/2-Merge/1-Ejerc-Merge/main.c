#include <stdio.h>
#include <stdlib.h>
#include "ejercArchivos.h"

int main()
{
    FILE    *pfEmp = NULL,
            *pfEst = NULL;

    int opcion;

    do{
        printf("\n\n0: Salir\
               \n1: Crear Lotes de Pruebas(%s, %s)\
               \n2: Abrir Archivos de pruebas \
               \n3: Mostrar %s\
               \n4: Mostrar %s\
               \n5: Actualizar %s",
               NOM_ARCH_ESTUDIANTES, NOM_ARCH_EMPLEADOS,
               NOM_ARCH_ESTUDIANTES, NOM_ARCH_EMPLEADOS,
               NOM_ARCH_EMPLEADOS);

        printf("\n\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 0:
//            printf("\nSaliendo...");
            break;

        case 1:
            opcionCrearLoteDePruebas();
            break;

        case 2:
            opcionAbrirArchivosDePruebas(&pfEmp, &pfEst);
            break;

        case 3:
            opcionMostrarArchivoEstudiante(pfEst);
            break;

        case 4:
            opcionMostrarArchivoEmpleados(pfEmp);
            break;

        case 5:
            opcionActualizarArchivos(pfEmp, pfEst);
            break;

        default:
            printf("\nOpcion incorrecta. Intente nuevamente.");
            break;
        }

    }while(opcion);

    if(pfEmp || pfEst)
    {
        fclose(pfEmp);
        fclose(pfEst);
    }

    printf("\n\nSaliendo...\nSalida exitosa.");
    return EXIT_SUCCESS;
}
