#include<stdio.h>
#include <math.h>
#include "funciones.h"

#define TRUE    1
#define FALSE   0
/*
Esta funcion permite calcular factoriales hasta el numero 17 inclusive
*/
long long int factorial(unsigned num)
{
    long long int resultado = 1;

    if(num == 0)
        return 1;

    // C permite obviar la condicion inicial pero es preferible
    // usar una condicion inicial con otra variable ya que en otros
    // lenguajes, no es posible hacer esto y se necesita una variable
    // inicial.
    for(; num > 1; num--)
        resultado *= num;

    return resultado;
}

////////////////////////////////
/*"m" numeros combinados de a "n" dan X cantidad de combinaciones posibles*/
unsigned combinatoriaMsobreN(unsigned m, unsigned n)
{
    return m >= n && n >= 0 ? factorial(m) / (factorial(n) * factorial(m - n)) : 0;
}

////////////////////////////////

double exponencialE(int num, float tol)
{
    double resultado = 1;
    double resTermino = 0;
    int cont = 1;

    do
    {
        resultado += resTermino;
        resTermino = pow_MIO(num, cont) / factorial(cont);
        cont++;
    }
    while(resTermino > tol);

    return resultado;
}

////////////////////////////////

double pow_MIO(double base, double exponente)
{
    double resultado = 1;

    if(exponente == 0)
        return 1;

    if(base == 0)
        return 0;

    for(; exponente > 0; exponente--)
        resultado *= base;
    return resultado;
}

////////////////////////////////

int absoluto(int num)
{
    return num < 0 ? -num : num;
}

////////////////////////////////

// EJERC_5 -- Fibonacci

int perteneceAFibonacci(unsigned num)
{
    long int    auxTermAnt,
         terminoAnt = 1,
         termSig = 1;

    while(termSig <= num)
    {
        if(termSig == num)
            return TRUE;

        auxTermAnt = terminoAnt;
        terminoAnt = termSig;
        termSig += auxTermAnt;
    }

    return FALSE;
}



////////////////////////////////

double senX(int num, float tol)
{
    int signo = -1;
    int cont = 3;
    double resTerm = 0;
    double resTotal = num;

    do
    {
        resTotal += resTerm;
        resTerm = (double)pow(num, cont) / (factorial(cont));
        resTerm *= signo;
        signo *= -1; // Con esto le cambio el signo en "Tic-tac"
        cont += 2;

        /*
        Puede ser mas eficiente dependiendo de si el uso de la funcion
        sea contantemente o cada vez en cuando.
        termAct, termAnt

        pot *= x * x
        fact * i * (i + 1)

        */
    }
    while(fabs(resTerm) > tol);

    return resTotal;
}
/*
double seno(double x, float TOL)
{
    double resultado=0;
    double resultado_anterior=0;
    int sumador = 1;

    do
    {
        resultado_anterior = resultado;

        resultado+= potencial(x,sumador)/factorial(sumador);
        sumador+=2;
        resultado-= potencial(x,sumador)/factorial(sumador);
        sumador+=2;
    }
    while(positivo(resultado-resultado_anterior) >= TOL);



    return resultado;
}
*/
////////////////////////////////

/*
Un número natural es perfecto, deficiente o abundante según que
la suma de sus divisores positivos menores que él sea igual, menor o
mayor que él.

Por ejemplo:
Número Divisores positivos menores que él Suma de los divisores Clasificación
6 1, 2, 3 6 PERFECTO
10 1, 2, 5 8 DEFICIENTE
12 1, 2, 3, 4, 6 16 ABUNDANTE
Desarrollar una función que determine si un número natural es perfecto, deficiente o abundante.

*/

int calcularClasificacion(int num)
{
    int     i,
            suma = 1;

    for(i = 2; i < num; i++)
    {
        if(num % i == 0)
            suma += i;
    }

    return suma;
}

void mostrarClasificacion(int num)
{
    int resultado;

    if(num < 0)
    {
        printf("No es posible usar un numero menor a cero.");
        return;
    }

    resultado = calcularClasificacion(num);

    if(resultado == num)
    {
        printf("Perfecto");
        return;
    }

    if(resultado < num)
    {
        printf("Deficiente");
        return;
    }
    else
        printf("Abundante");
}

////////////////////////////////
/*
    Z           x       Y
multiplicando       multiplicador
*/
int productosPorSuma(int multiplicando, int multiplicador)
{
    int suma = 0;
    for(; multiplicador > 0; multiplicador--)
        suma += multiplicando;

    return suma;
}

////////////////////////////////

int cocienteEntero(int dividendo, int divisor)
{
    int i;

    if(divisor == 0)
        return -1; // No se puede dividir por cero

    if(dividendo < divisor)
        return 0;

    i = 1;
    while(divisor * i <= dividendo)
        i++;

    dividendo -= divisor * (i - 1);

    return i - 1;
}

////////////////////////////////

/// EJERC_10

int sumaNumerosNaturales(int num)
{
    int suma = 0;
    for(; num > 0; num--)
        suma += num;

    return suma;
}

////////////////////////////////
/// EJERC_11
int sumaNumerosNaturalesPares(int num)
{
    int suma = 0;
    for(; num > 0; num--)
        if(num % 2 == 0)
            suma += num;

    return suma;
}

////////////////////////////////
// EJERC_13
int esNumeroPrimo(int num)
{
    int i;

    for(i = 2; i < num; i++)
        if(num % i == 0)
            return FALSE;

    return TRUE;
}

////////////////////////////////
// EJERC_20

int multiplicacionRusa(int num1, int num2)
{
    int i,
        j,
        resultado = 0;

    for(i = num1, j = num2; i > 1; i /= 2, j *= 2)
    {
        if(i % 2 != 0)
            resultado += j;
    }

    return resultado + j;
}

/////////////////////////////////

int parteEntera(double num)
{
    return (int)num;
}

/////////////////////////////////


