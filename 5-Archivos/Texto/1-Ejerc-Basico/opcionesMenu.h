#ifndef OPCIONESMENU_H_INCLUDED
#define OPCIONESMENU_H_INCLUDED

#include "archivosTxt.h"

///////////////////////////////////

void opcionCrearLoteDePrueba();
int opcionAbrirLoteDePrueba(FILE **pfBin);
int opcionBinarioATxtFijo(FILE *pfBin, const char *nomArchTxt);
int opcionBinarioATxtVariable(FILE *pfBin, const char *nomArchTxt);
int opcionTxtVariableABin(const char *nomArchTxt, const char *nomArchBin);
int opcionTxtFijoABin(const char *nomArchTxt, const char *nomArchBin);

///////////////////////////////////

#endif // OPCIONESMENU_H_INCLUDED
