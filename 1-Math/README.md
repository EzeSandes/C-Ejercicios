# Consignas

## 1 - Factorial
El factorial de un número natural incluido el 0, se calcula de la siguiente manera:

    1 si N = 0

    N! = N. (N - 1)! si N > 0

o sea, 
     
     N! = N. (N - 1). (N - 2). …. 3. 2. 1

Ejemplo: 

    5! = 5. 4. 3. 2. 1 = 120


Desarrollar una función para calcular el factorial de un entero.

## 2 - Combinatoria M sobre N
Dados dos números enteros m y n (m >= n y n>= 0), el número combinatorio se calcula de la siguiente manera:

    (m sobre n) = m ! / (n!.(m−n)!)

Desarrollar una función para calcular el combinatorio m sobre n.

## 3 - Exponencial _e_
Dado un número entero X y una tolerancia (TOL), puede obtenerse ex mediante la suma de los términos de la serie:

    e^x = 1 + (X^1 / 1) + (X^2 / (1 ∗ 2)) + (X^3 / (1 ∗ 2 ∗ 3)) + (X^4 / (1 ∗ 2 ∗ 3 ∗ 4 )) + .. ..

El proceso termina cuando se obtiene un término calculado que sea menor que la tolerancia TOL.

Desarrollar una función para calcular el ex, dados X y TOL.

## 4 - Absoluto
Desarrollar una función para calcular el valor absoluto de un numero.

## 5 - Fibonacci: Pertenece a Fibonacci?
En la serie de Fibonacci, cada término es la suma de los dos anteriores y los dos primeros términos son 1
      
      Serie: 1 1 2 3 5 8 13 21 34 ...
      
Desarrollar una función para determinar si un entero pertenece a la serie de Fibonacci.

__Nota__: Es posible resolver este ejercicio con 'Recursividad'. En la parte de _rucursividad_ se encuentra resuelto sin el uso de ciclos.

## 6 - Sen(x)
Dados X y una tolerancia TOL es posible calcular el seno (x) mediante la suma de los términos de la serie:

    seno(x) = x - x^3 / 3! + x^5 / 5! - x^7/ 7! + x^9 / 9! -x^11 / 11! + ...

Este proceso continúa mientras el término calculado (en valor absoluto) sea mayor que la tolerancia.

Desarrollar una función que obtenga el seno de X con tolerancia TOL, utilizando dicha serie.

## 7 - Clasificacion de Numeros Naturales
Un número natural es perfecto, deficiente o abundante según que la suma de sus divisores positivos menores que él sea igual, menor o mayor que él. 
Por ejemplo: 

| Número | Divisores positivos menores que él | Suma de los divisores | Clasificación |
--- |--- |--- |--- |
| 6  | 1, 2, 3 | 6 | PERFECTO |
10 | 1, 2, 5 | 8 | DEFICIENTE |
12 | 1, 2, 3, 4, 6 | 16 | ABUNDANTE |

Desarrollar una función que determine si un número natural es perfecto, deficiente o abundante.

## 8 - Producto por sumas
Dados dos números naturales (incluido el cero), obtener su producto por sumas sucesivas.

## 9 - Cociente Entero
Dados dos números naturales A y B, desarrollar una función para obtener el cociente entero A/B y el resto. (A puede ser 0; B, no).

## 10 - Suma primeros N numeros Naturales
Construir un programa que lea un número natural N y calcule la suma de los primeros N números naturales.

## 11 - Suma primeros N numeros pares
Construir un programa que lea un número natural N y calcule la suma de los primeros N números pares.

## 12 - Suma primeros N numeros pares menores
Construir un programa que lea un número natural N y calcule la suma de los números pares menores que N.

## 13 - Numero Primo
Desarrollar una función que determine si un número natural es primo.

## 14 - Multiplicacion Rusa

El método de multiplicación rusa de dos números naturales, consiste en lo siguiente:

Se divide sucesivamente por 2 (división entera) a uno de sus factores hasta obtener 1.
Paralelamente, se multiplica sucesivamente por 2 al otro factor.

La suma de éstos últimos números obtenidos que se correspondan con números impares obtenidos en las divisiones, es el producto buscado 
(Se consideran los factores originales para la suma correspondiente).

Por ejemplo para: 35 x 8 

    35  8                         8, 16 y 256 se corresponden con impares (35, 17 y 1). 
    17  16                        8 + 16 +256 = 280
    8   32
    4   64
    2   128
    1   256

## 15 - Parte Entera
Desarrollar una función para obtener la parte entera de un número real.
