#include "funciones.h"

int compararInt(const void *elem1, const void *elem2)
{
    return *(int*)elem2 - *(int*)elem1;
}

void mostrar(int * vec,int ceVec)
{
    int i;
    for(i=0; i<ceVec; i++)
    {
        printf("%d \t ",*vec);
        vec++;
    }
}

int compararEmp(const void *elem1,const void *elem2)
{
    int res;
    tEmpleado * emp1 = (tEmpleado*) elem1;
    tEmpleado * emp2 = (tEmpleado*) elem2;
    if((res = strcmp(emp2->apellido,emp1->apellido)) == 0)
    {
        if((res = strcmp(emp2->nombre,emp1->nombre)) == 0)
            return emp2->dni - emp1->dni;
    }
    return res;
}

void mostrarEmp(tEmpleado* emp,int ceEmp)
{
    int i;
    for(i=0; i<ceEmp; i++)
    {
        printf("\nNombre completo: %s %s \nDNI: %u\n",emp->apellido,emp->nombre,emp->dni);
        emp++;
    }
}


/// Funcion de buscar el menor y otra de ordenar
void ordenarVecPorSeleccion(void *vec,int ceVec,int tamElem,int(*comparar)(const void *, const void *),void(*intercambio)(void *,void *))
{
    void *pInicio = vec;             /// Este esta en el inicio
    void *pRecorrer = vec;          /// Y este va a buscar el menor
    void *pMenor = vec;            /// Una vez encontrado el primer menor,seguimos recorriendo el vector con este

    int i, j;
    for(i=0;i<ceVec;i++)
    {
        pMenor = pInicio;
        pRecorrer = pInicio + tamElem;
        for(j=i+1;j<ceVec;j++)
        {
            if(comparar(pRecorrer,pMenor) > 0)
                pMenor = pRecorrer;
            pRecorrer += tamElem;
        }
            intercambio(pInicio,pMenor);
            pInicio += tamElem;
    }
}

void intercambioInt(void *pInicio, void *pMenor)
{
    int *a1 = (int*) pInicio;
    int *a2 = (int*) pMenor;
    int aux;

    aux = *a1;
    *a1 = *a2;
    *a2 = aux;
}

void intercambioEmp(void *pInicio, void *pMenor)
{
    tEmpleado *a1 = (tEmpleado*) pInicio;
    tEmpleado *a2 = (tEmpleado*) pMenor;
    tEmpleado aux;

    aux = *a1;
    *a1 = *a2;
    *a2 = aux;

}

