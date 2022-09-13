#define ESPACIOS  5

void mostrarVec(int *vec, int cantElem)
{
    int i;

    for(i = 0; i < cantElem; i++, vec++)
        printf("%*.2d", ESPACIOS, *vec);
//        printf("%*c%.2d", ESPACIOS, ' ', *vec);
}

// Elijo una cantidad de espacios de '5'
