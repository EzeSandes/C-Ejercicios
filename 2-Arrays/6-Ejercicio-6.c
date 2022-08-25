#define     TRUE    1
#define     FALSE   0

#define     TODO_OK 1
#define     ERROR   -1;
#define     NO_ENCONTRADO   -2

int sonVectoresDisjuntos(int *vec1, int *vec2, int cantElementosVec1, int cantElementosVec2)
{
    int *pFinVec1 = vec1 + cantElementosVec1,
        *pFinVec2 = vec2 + cantElementosVec2,
        *pLecturaVec2;

    // Si uno de los vectores es CONJUNTO VACIO => son Disjuntos
    // A INTERSECCION Conjunto vacio == conjunto vacio por propiedad de conjuntos.
    if(!cantElementosVec1 || !cantElementosVec2)
        return TRUE;

    while(vec1 < pFinVec1)
    {
        pLecturaVec2 = vec2;
        while(*vec1 != *pLecturaVec2 && pLecturaVec2 < pFinVec2)
            pLecturaVec2++;

        // Debo preguntar si pLecturaVec2 < pFinVec2 tambien xq puede que el nro que sigue
        // por fuera del vector coincida con el que busco, dandome un resultado erroneo porque
        // se paso del rango permitido.
        if(*pLecturaVec2 == *vec1 && pLecturaVec2 < pFinVec2)
            return FALSE;

        vec1++;
    }

    return TRUE;
}

int sonDisjuntos(int * v1, int * v2, int cantElem1,int cantElem2)
{
    int i,
        j,
        *pInicial = v2;
    
    if(!cantElem1 || !cantElem2)
        return TRUE;
    
    for(i=0 ; i < cantElem1; i++,v1++)      // Recorrido del primer vector
    {
        v2 = pInicial;						// En cada iteracion vuelvo al primer valor del vector 2

        for(j=0 ; j < cantElem2; j++,v2++)  // Recorrido del segundo vector
            if(*v1 == *v2)					// Si encuentra un elemento en comun entonces corta el ciclo, ya que no necesita seguir recorriendo
                return 0;

    }

    return 1;
}
