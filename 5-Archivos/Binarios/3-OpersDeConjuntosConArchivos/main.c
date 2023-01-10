#include <stdio.h>
#include <stdlib.h>
#include "archOperacConjuntos.h"

int main()
{
    int opcion;
    FILE    *pfEst = NULL,
            *pfEmp = NULL;

    do{
        printf("\n0: Salir\
               \n1: Crear Lote de pruebas\
               \n2: Abrir Archivos del lote de pruebas\
               \n3: Interseccion de Archivos de pruebas\
               \n4: Mostrar Arch Interseccion(estudiantes que son empleados)\
               \n5: Unir archivos de lote de pruebas\
               \n6: Mostrar Arch Union\
               \n7: Diferencia A - B (Est - Emp)\
               \n8: Mostrar Archivo A - B (Est - Emp)\
               ");

        printf("\n\nEscoja una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 0:
            break;

        case 1:
            opcionCrearLotesDePruebas();
            break;

        case 2:
            opcionAbrirArchivos(&pfEst, &pfEmp);
            break;

        case 3:
            opcionInterseccionArchivos(pfEst, pfEmp);
            break;

        case 4:
            opcionMostrarArchivoInterseccion();
            break;

        case 5:
            opcionUnionArchivos(pfEst, pfEmp);
            break;

        case 6:
            opcionMostrarArchivoUnion();
            break;

        case 7:
            opcionDiferenciaArchivos_EstMenosEmp(pfEst, pfEmp);
            break;

        case 8:
            opcionMostrarArchivoDiferencia_AMenosB();
            break;

        default:
            printf("\nOpcion Incorrecta. Ingrese una opcion valida.");
            break;
        }
    }while(opcion);

    if(pfEmp || pfEst)
    {
        fclose(pfEmp);
        fclose(pfEst);
    }

    printf("\nSalida exitosa.");
    printf("\n\n");
    return 0;
}
