#include "archivos.h"

int main()
{
    /*
    FILE *pfBin;
    tEmpleado empleado;

//    crearLoteDePruebas();
    abrirArchivo(NOM_ARCH_EMPLEADOS, &pfBin, "r+b");

    leerArchivoBin(pfBin, &empleado, sizeof(tEmpleado), actualizar_emp);
    leerArchivoBin(pfBin, &empleado, sizeof(tEmpleado), mostrarReg_emp);

    fclose(pfBin);
    */

    /// TXT
    FILE *pfTxt;
    tAlumno alumno;

    abrirArchivo(NOM_ARCH_ALUMNOS, &pfTxt, "rt");

    leerArchivoTxt(pfTxt, &alumno, obtenerReg_alu, mostrarReg_alu);

    printf("\n\n");
    return 0;
}
