#include "archivosTxt.h"
#include <string.h>

#define TODO_OK 1
#define ERROR   0


///////////////////////////////////

int mostrarArchBin(const char *nomArchBin)
{
    FILE    *pf;
    tAlumno alumno;

    pf = fopen(nomArchBin, "rb");
    if(!pf)
        return ERROR;

    fread(&alumno, sizeof(tAlumno), 1, pf);
    while(!feof(pf))
    {
        mostrarAlumno(&alumno);
        fread(&alumno, sizeof(tAlumno), 1, pf);
    }

    fclose(pf);
    return TODO_OK;
}

void mostrarAlumno(const tAlumno *alu)
{
    printf("\n%u | %c | %s | %.2f | %d / %d / %d\n", alu->dni, alu->sexo, alu->nyap, alu->prom,
           alu->fechaIng.dia, alu->fechaIng.mes, alu->fechaIng.anio);
}

///////////////////////////////////////

int crearLoteDePruebas()
{
    FILE    *pfEst;

    tAlumno estudiantes[] =
    {
        {2, "AAA AAAAAA AA AAAAAAAAAAAAAAA BBBBBBBBB BBBBBBBBBC", 'M', { 29, 4, 2022},8},
        {32, "Alvez Martin de los Sauces", 'M', { 29, 4, 2022}, 7.8},
        {3, "Ana Maria de las Rosas", 'F', { 29, 4, 2022}, 9.5},
        {74, "Armando Esteban Raul", 'M', { 29, 4, 2022},6},
        {63, "Augusto Esteban", 'M', { 29, 4, 2022}, 8},
        {31, "Estrella Maria", 'F', { 29, 4, 2022}, 9},
        {13, "Estrella Patricio", 'M', { 29, 4, 2022}, 9},
        {75, "Jaime Nick", 'M', { 29, 4, 2022}, 5},
        {88, "Jaime Nicolas", 'M', { 29, 4, 2022}, 4.5},
        {10, "Lopez Juieta Rosalia", 'F', { 29, 4, 2022}, 8},
        {68, "Lopez Leonardo", 'M', { 29, 4, 2022}, 2},
        {65, "Mujica Pepito", 'M', { 29, 4, 2022}, 6.5},
        {20, "Perez Esteban de los Hornos", 'M', { 29, 4, 2022}, 8},
        {55, "Perez Micaela", 'F', { 29, 4, 2022}, 6.9},
        {50, "Perez Juan Manuel", 'M', { 29, 4, 2022}, 9},
    };

    pfEst = fopen(NOM_ARCH_ESTUDIANTES, "wb");
    if(!pfEst)
    {
        perror("\nERROR. pfEst");
        return ERROR;
    }

    fwrite(estudiantes, sizeof(estudiantes), 1, pfEst);

    fclose(pfEst);
    return TODO_OK;
}

///////////////////////////////////

int abrirArchivoBin(FILE **pfBin)
{
    *pfBin = fopen(NOM_ARCH_ESTUDIANTES, "rb");
    if(!*pfBin)
    {
        printf("\n\nERROR, ");
        perror(NOM_ARCH_ESTUDIANTES);
        return ERROR;
    }

    return TODO_OK;
}

///////////////////////////////////

int archBinATxt(FILE *pfBin, const char *nomArchTxt, char formatoTxt)
{
    FILE *pfTxt;
    char *formato = formatoTxt == 'F' ? "%8u%-50s%1c%02d%02d%04d%02.2f\n" : "%u|%s|%c|%d-%d-%d|%2.2f\n";

    tAlumno alumno;

    rewind(pfBin);

    pfTxt = fopen(nomArchTxt, "wt");
    if(!pfTxt)
        return ERROR;

    fread(&alumno, sizeof(tAlumno), 1, pfBin);
    while(!feof(pfBin))
    {
        fprintf(pfTxt, formato,
                alumno.dni, alumno.nyap, alumno.sexo,
                alumno.fechaIng.dia, alumno.fechaIng.mes, alumno.fechaIng.anio,
                alumno.prom);

        fread(&alumno, sizeof(tAlumno), 1, pfBin);
    }

    fclose(pfTxt);
    return TODO_OK;
}

///////////////////////////////////

int archTxtABin(const char *nomArchTxt, const char *nomArchBin,char formatoTxt)
{
    FILE    *pfTxt,
            *pfBin;

    tAlumno alumno;
    char *formato = formatoTxt == 'F' ? "%8u%50[^\n]%c%2d%2d%4d%4f\n" : "%u|%[^|]|%c|%d-%d-%d|%f\n";

    pfTxt = fopen(nomArchTxt, "rt");
    if(!pfTxt)
        return ERROR;

    pfBin = fopen(nomArchBin, "wb");
    if(!pfBin)
    {
        fclose(pfTxt);
        return ERROR;
    }

    while(fscanf(pfTxt, formato, &alumno.dni, alumno.nyap, &alumno.sexo,
                 &alumno.fechaIng.dia, &alumno.fechaIng.mes, &alumno.fechaIng.anio,
                 &alumno.prom) != EOF)
    {
        fwrite(&alumno, sizeof(tAlumno), 1, pfBin);
    }

    fclose(pfBin);
    fclose(pfTxt);
    return TODO_OK;
}

/////////////////////////////////////

/// "%8u%50[^\n]%c%2d%2d%4d%4f\n"
void obtenerAlumno_Fijo(char *cad, tAlumno *alu)
{
    char *aux = strrchr(cad, '\n');
    *aux = '\0';

    aux -= 4;
    sscanf(aux, "%f", &alu->prom);
    *aux = '\0';

    aux -= 8;
    sscanf(aux, "%2d%2d%4d", &alu->fechaIng.dia, &alu->fechaIng.mes, &alu->fechaIng.anio);
    *aux = '\0';

    aux -= 1;
    alu->sexo = *aux;
    *aux = '\0';

    aux -= 50;
    strcpy(alu->nyap, aux);
    *aux = '\0';

    sscanf(cad, "%8u", &alu->dni);
}

///////////////////////////////////

int archTxtFijoABin_SinFscanf(const char *nomArchTxt)
{
    FILE    *pfTxt;

    tAlumno alumno;

    char cad[201];

    pfTxt = fopen(nomArchTxt, "rt");
    if(!pfTxt)
        return ERROR;

    while(fgets(cad, sizeof(cad), pfTxt))
    {
        obtenerAlumno_Fijo(cad, &alumno);
        printf("\n/////////////\n");
        mostrarAlumno(&alumno);
    }

    fclose(pfTxt);
    return TODO_OK;
}

///////////////////////////////////
///////////////////////////////////
