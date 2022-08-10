#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"

#define TAM 10

int sonDisjuntos(int *v1, int *v2, int cantElem1, int cantElem2);

int main()
{
//    int vector[TAM] = {1, 2, 3, 4, 5, 6, 7, 8};
//    int vector[TAM] = {1, 2, 3, 2, 1, 6, 7, 8};

//    int vector1[TAM] = {0, 2, 3, 4, 5, 6, 7, 9};
//    int vector2[TAM];
//    int vector1[TAM] = {0, 2, 3, 4, 5, 6, 7, 9};
//    int vector2[TAM] = {8, 10, 11, 12, 13, 14, 15, 16};

//    int vector[TAM];
//    int cantElemVec1 = TAM - 2;
//    int cantElemVec2 = 0;
//    int pos = 10;

//    cargarVector(vector, cantElem, TAM);

//    printf("\nVECTOR:\n\t");
//    mostrarVec_int(vector, cantElem);
    printf("\n\n");

//    eliminarTodasAparicionesDeVector_int(vector, 1, &cantElem);
//    int x = sonVectoresDisjuntos(vector1, vector2, cantElemVec1, cantElemVec2);
//    printf("%s", x ? "Si son vectores disjuntos\n" : "No son vectores disjuntos\n");

///////

    int vector1[TAM] = {0, 2, 3, 4, 5, 6, 7, 9};
    int vector2[TAM] = {0, 9, 12, 13, 9};

    int cantElemVec1 = TAM - 2;
    int cantElemVec2 = 0;

    int x = sonDisjuntos(vector1, vector2, cantElemVec1, cantElemVec2);
    printf("%s", x ? "Si son vectores disjuntos\n" : "No son vectores disjuntos\n");

///////

//    printf("\nVECTOR:\n\t");
//    mostrarVec_int(vector, cantElem);
//    printf("\nCant Elem: %d", cantElem);

    printf("\n\n");
    return 0;
}

int sonDisjuntos(int *v1, int * v2, int cantElem1, int cantElem2)
{
    int i,
        j,
        *pInicial = v2;
    
  for(i = 0 ; i < cantElem1; i++, v1++)      // Recorrido del primer vector
    {
        v2 = pInicial;						// En cada iteración vuelvo al primer valor del vector 2

        for(j = 0 ; j < cantElem2; j++, v2++)  // Recorrido del segundo vector
            if(*v1 == *v2)					// Si encuentra un elemento en común entonces corta el ciclo, ya que no necesita seguir recorriendo
                return 0;
    }
    return 1;
}
