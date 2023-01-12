#include "archOperacConjuntos.h"

#define TODO_OK     1
#define ERROR       0

int unionArchivos_EstYEmp(FILE *pfEst, FILE *pfEmp)
{
    /*
    struct sPersona{
        unsigned    dni;
        char        apellido[TAM_CAD],
                    nombre[TAM_CAD];
    };
    struct sPersona persona;
    */
    tEstudiante estudiante;
    tEmpleado empleado;

    FILE *pfUnion;

    int comp;

    pfUnion = fopen(NOM_ARCH_UNION, "wb");
    if(!pfUnion)
    {
        perror(NOM_ARCH_UNION);
        return ERROR;
    }

    // Aseguro estar al principio de ambos archivos
    rewind(pfEst);
    rewind(pfEmp);

    fread(&estudiante, sizeof(tEstudiante), 1, pfEst);
    fread(&empleado, sizeof(tEmpleado), 1, pfEmp);

    while(!feof(pfEmp) && !feof(pfEst))
    {
        comp = comparacion_EstYEmp(&estudiante, &empleado);

        if(!comp)
        {
//            persona = (struct sPersona){estudiante.dni, estudiante.apellido, estudiante.nombre};
//            fwrite(&persona, sizeof(struct sPersona), 1, pfUnion);
            fwrite(&empleado.persona, sizeof(tPersona), 1, pfUnion);

            // Si son dos archivos distintintos no necesito un fseek(0L)
            fread(&estudiante, sizeof(tEstudiante), 1, pfEst);
            fread(&empleado, sizeof(tEmpleado), 1, pfEmp);
        }

        if(comp < 0)
        {
            fwrite(&estudiante.persona, sizeof(tPersona), 1, pfUnion);
            fread(&estudiante, sizeof(tEstudiante), 1, pfEst);
        }

        if(comp > 0)
        {
            fwrite(&empleado.persona, sizeof(tPersona), 1, pfUnion);
            fread(&empleado, sizeof(tEmpleado), 1, pfEmp);
        }
    }


    while(!feof(pfEst))
    {
//        persona = (struct sPersona){estudiante.dni, estudiante.apellido, estudiante.nombre};
//        fwrite(&persona, sizeof(struct sPersona), 1, pfUnion);
        fwrite(&estudiante.persona, sizeof(tPersona), 1, pfUnion);
        fread(&estudiante, sizeof(tEstudiante), 1, pfEst);
    }

    while(!feof(pfEmp))
    {
//        persona = (struct sPersona){empleado.dni, empleado.apellido, empleado.nombre};
//        fwrite(&persona, sizeof(struct sPersona), 1, pfUnion);
        fwrite(&empleado.persona, sizeof(tPersona), 1, pfUnion);
        fread(&empleado, sizeof(tEmpleado), 1, pfEmp);
    }

    fclose(pfUnion);
    return TODO_OK;
}
