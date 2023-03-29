#include "funciones.h"

int main()
{
    int ceVec,ceEmp,tamElem;
    int vec[] = {2,5,7,4,3,1,8,9,0,6};
    ceVec = sizeof(vec)/sizeof(int);
    //qsort(vec,ceVec,sizeof(int),compararInt);
    /// qsort(vec,sizeof(vec[0]),compararInt)
   // mostrar(vec,ceVec);


    tEmpleado empleados[] =
    {
        {03, "Beca", "Facundo", 10000},
        {24, "Coco", "Eduardo", 10000},
        {32, "Alvez", "Martin", 10000},
        {96, "Alvorado", "Martin", 10000},
        {75, "Albez", "Victoria", 10000},
        {31, "Estrella", "Maria", 10000},
        {99, "Armando", "Rau", 10000},
        {45, "Beca", "Facundo", 10000},
        {74, "Armando", "Raul", 10000},
        {63, "Augusto", "Esteban", 10000},
        {56, "Azcuenaga", "Federico", 10000},
        {33, "Basili", "Andres", 1000},
        {39, "Cisco", "Esteban", 20000},
        {23, "Estrella", "Mauricio", 10000},
        {97, "Augusto", "Esteban", 10000},

    };

    printf("\n");
    ceEmp = sizeof(empleados)/sizeof(tEmpleado);
    // El "qsort" que ya viene implementado en C, utiliza funciones genericas que debemos pasarle
    // de acuerdo al tipo de dato.
    qsort(empleados,ceEmp,sizeof(tEmpleado),compararEmp);
 //   mostrarEmp(empleados,ceEmp);

    tamElem = sizeof(int);
    ordenarVecPorSeleccion(vec,ceVec,tamElem,compararInt,intercambioInt);
    mostrar(vec,ceVec);

    printf("\n\n");

    ordenarVecPorSeleccion(empleados,ceEmp,sizeof(tEmpleado),compararEmp,intercambioEmp);
    mostrarEmp(empleados,ceEmp);
    return 0;
}


