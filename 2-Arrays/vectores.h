void mostrarVec_int(int *vec, int n);
int cargarVector(int *vec, int cantElem, int tam);

int insertarEnVector_INT(int *vec, int dato, int pos, int *cantElem, int tam);
int insertarEnVectorEnOrden_INT(int *vec, int dato, int *cantElem, int tam); 
int eliminarDeVectorPorPos_INT(int *vec, int pos, int *cantElem); 
int eliminarPrimeraAparicionEnVector_INT(int *vec, int dato, int *cantElem); 
int eliminarTodasAparicionesDeVector_int(int *vec, int dato, int *cantElem); 

int sonVectoresDisjuntos(int *vec1, int *vec2, int cantElementosVec1, int cantElementosVec2);
