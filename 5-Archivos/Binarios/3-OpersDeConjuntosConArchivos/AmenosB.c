#include "archOperacConjuntos.h"

#define TODO_OK     1
#define ERROR       0

/// B - A es igual con la diferencia que los fread de comp de estudiantes seran de empleados y viceversa.

int diferenciaAmenosB_EstYEmp(FILE *pfA, FILE *pfB)
{
    tEstudiante estudiante;
    tEmpleado empleado;

    FILE *pfNuevo;

    int comp;

    pfNuevo = fopen(NOM_ARCH_DIFERENCIA_A_MENOS_B, "wb");
    if(!pfNuevo)
    {
        perror(NOM_ARCH_DIFERENCIA_A_MENOS_B);
        return ERROR;
    }

    // Aseguro estar al principio de ambos archivos
    rewind(pfA);
    rewind(pfB);

    fread(&estudiante, sizeof(tEstudiante), 1, pfA);
    fread(&empleado, sizeof(tEmpleado), 1, pfB);

    while(!feof(pfA) && !feof(pfB))
    {
        comp = comparacion_EstYEmp(&estudiante, &empleado);

        if(!comp)
        {
            fread(&estudiante, sizeof(tEstudiante), 1, pfA);
            fread(&empleado, sizeof(tEmpleado), 1, pfB);
        }

        if(comp < 0)
        {
            // Lo que se encuentra en el Archivo A(aca es Estudiante)
            // escribo en el archivo nuevo
            fwrite(&estudiante.persona, sizeof(tPersona), 1, pfNuevo);
            fread(&estudiante, sizeof(tEstudiante), 1, pfA);
        }

        if(comp > 0)
        {
            fread(&empleado, sizeof(tEmpleado), 1, pfB);
        }
    }

    while(!feof(pfA))
    {
        fwrite(&estudiante.persona, sizeof(tPersona), 1, pfNuevo);
        fread(&estudiante, sizeof(tEstudiante), 1, pfA);
    }

    fclose(pfNuevo);
    return TODO_OK;
}
