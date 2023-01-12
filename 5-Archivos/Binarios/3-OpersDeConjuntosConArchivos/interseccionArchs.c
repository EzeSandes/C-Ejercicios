#include "archOperacConjuntos.h"

#define TODO_OK     1
#define ERROR       0

////////////////////////////////////////

int interseccionArchivos_EstYEmp(FILE *pfEst, FILE *pfEmp)
{
    tEstudiante estudiante;
    tEmpleado empleado;

    FILE *pfInterseccion;

    int comp;

    pfInterseccion = fopen(NOM_ARCH_INTERSECCION, "wb");
    if(!pfInterseccion)
    {
        perror(NOM_ARCH_INTERSECCION);
        return ERROR;
    }

    rewind(pfEst);
    rewind(pfEmp);

    fread(&estudiante, sizeof(tEstudiante), 1, pfEst);
    fread(&empleado, sizeof(tEmpleado), 1, pfEmp);
    while(!feof(pfEst) && !feof(pfEmp))
    {
        comp = comparacion_EstYEmp(&estudiante, &empleado);

        if(!comp)
        {
            // COLOCO LOS ESTUDIANTES QUE SON EMPLEADOS
            fwrite(&estudiante, sizeof(tEstudiante), 1, pfInterseccion);

            // Si son archivos separados no necesita el fseek con 0L
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

    // Si alguno de ellos termina primero => ya no hay interseccion
    // entre ambos. Por lo tanto, termino el programa.

    fclose(pfInterseccion);
    return TODO_OK;
}

////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
