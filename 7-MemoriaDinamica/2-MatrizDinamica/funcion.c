#include "funcion.h"

void** crearMatDinamica(int fil, int col, size_t tamElem)
{
    void **mat;
    void **iniMat;
    void *crearFil;
    int i,
        cantF=0;

    mat = (void **)malloc(fil * sizeof(void *));
    if(mat == NULL)
        return NULL;

    iniMat = mat;

    for(i = 0; i < fil; i++)
    {
        crearFil = malloc(col * tamElem);
        if(crearFil == NULL)
        {
            while(cantF > 0)
            {
                free(*mat);
                mat--;
                cantF--;
            }
            free(mat);
            return NULL;
        }
        mat[i] = crearFil; // Desreferencia y queda void* que sabe cuanto copia x eso puede hacerlo(las dir de memoria ocupan siempre lo mismo)
        cantF++;
    }

    return iniMat;
}

void liberarMatDin(void **mat,int cantF)
{
    int i;

    for(i=0; i<cantF; i++)
    {
        free(*mat);
        mat++;
    }
    mat -= cantF;
    free(mat);
}

void mostrarMatrizDin(void **mat, int fil, int col, void (*mostrarVec)(void *, int))
{
    int i;
    printf("\n Matriz:");
    for(i = 0; i< fil; i++)
    {
        printf("\n");
        mostrarVec(mat[i], col);
    }
}

void mostrarVecInt(void *vec,int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        printf("\t |%d|", *(int *)vec);
        vec += sizeof(int);
    }
    printf("\n");
}

void mostrarVecChar(void *vec, int tam)
{
    int i;

    for(i=0; i< tam; i++)
    {
        printf("\t |%c|", *(char *)vec);
        vec += sizeof(char);
    }
    printf("\n");
}

void cargarMatrizDin(void**mat, int fil, int col, void (*cargar)(void *, int))
{
    int i;
    for(i = 0; i < fil; i++)
    {
        cargar(mat[i], col);
    }
}

void cargarVecInt(void *vec,int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        *((int *)vec) = i + 1;
        vec += sizeof(int);
    }
}

void cargarVecChar(void *vec, int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        *((char *)vec) = i + 1;
        vec += sizeof(char);
    }
}
