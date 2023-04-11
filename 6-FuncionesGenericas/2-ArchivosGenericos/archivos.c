#include "archivos.h"

#define ERROR   0
#define TODO_OK 1

//////////////////////////////////

int crearLoteDePruebas()
{
    FILE    *pfEmp;

    tEmpleado empleados[] =
    {
        {75, "Albez", "Victoria", 20000},
        {32, "Alvez", "Martin", 10000},
        {96, "Alvorado", "Martin", 10000},
        {99, "Armando", "Rau", 10000},
        {74, "Armando", "Raul", 10000},
        {63, "Augusto", "Esteban", 10000},
        {97, "Augusto", "Esteban", 10000},
        {56, "Azcuenaga", "Federico", 10000},
        {33, "Basili", "Andres", 1000},
        {45, "Beca", "Facundo", 10000},
        {03, "Beka", "Facundo", 10000},
        {39, "Cisco", "Esteban", 20000},
        {24, "Coco", "Eduardo", 10000},
        {31, "Estrella", "Maria", 10000},
        {23, "Estrella", "Mauricio", 10000},
        {13, "Estrella", "Patricio", 20000},
    };


    pfEmp = fopen(NOM_ARCH_EMPLEADOS, "wb");
    if(!pfEmp)
    {
        perror("\nERROR. pfEmp");
        return ERROR;
    }

    fwrite(empleados, sizeof(empleados), 1, pfEmp);

    fclose(pfEmp);
    return TODO_OK;
}


//////////////////////////////////

int abrirArchivo(const char *nomArch, FILE **pf, const char *modo)
{
    *pf = fopen(nomArch, modo);
    if(!*pf)
        return ERROR;

    return TODO_OK;
}

//////////////////////////////////

int leerArchivoBin(FILE *pf, void *registro, size_t tamRegistro,
                   void (*accion)(FILE *, void *))
{

    if(!pf)
        return ERROR;

    rewind(pf);

    fread(registro, tamRegistro, 1, pf);
    while(!feof(pf))
    {
        accion(pf, registro);
        fread(registro, tamRegistro, 1, pf);
    }

    return TODO_OK;
}

//////////////////////////////////

void mostrarReg_emp(FILE *pf, void *reg)
{
    tEmpleado *emp = (tEmpleado *)reg;

    printf("\n%s, %s %*s Saldo: %.2lf\n",
           emp->apellido,
           emp->nombre,
           30, "",
           emp->sueldo);

}

//////////////////////////////////

void actualizar_emp(FILE *pf, void *reg)
{
    tEmpleado *emp = (tEmpleado *)reg;

    if(emp->sueldo >= 20000)
    {
        emp->sueldo = 99999;
        fseek(pf, -(long)sizeof(tEmpleado), SEEK_CUR);
        fwrite(emp, sizeof(tEmpleado), 1, pf);
        fseek(pf, 0L, SEEK_CUR);
    }
}

//////////////////////////////////

int leerArchivoTxt(FILE *pf, void *registro,
                   void obtenerReg(char *linea, void *reg),
                   void (*accion)(void *reg))
{
    // El tam de cad deberia ser dinamico dependiendo del tam de la estructura
    char cad[TAM_MAX_ESTRUCTURA];

    if(!pf)
        return ERROR;

    rewind(pf);

    while(fgets(cad, sizeof(cad), pf))
    {
        obtenerReg(cad, registro);
        accion(registro);
    }

    return TODO_OK;
}

//////////////////////////////////

void obtenerReg_alu(char *linea, void *reg)
{
    tAlumno *alu = (tAlumno *)reg;

    sscanf(linea, "%8u%50[^\n]%1c%2d%2d%4d%4f\n",
           &alu->dni, alu->nyap, &alu->sexo,
           &alu->fechaIng.dia, &alu->fechaIng.mes, &alu->fechaIng.anio,
           &alu->prom);
}

//////////////////////////////////

void mostrarReg_alu(void *reg)
{
    tAlumno *alu = (tAlumno *)reg;

    printf("\n\n%s\t\t%u", alu->nyap, alu->dni);
}
//////////////////////////////////
