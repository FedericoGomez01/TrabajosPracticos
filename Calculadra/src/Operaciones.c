/*
 * Operaciones.c
 *
 *  Created on: 7 abr. 2021
 *      Author: Santiago
 */
#include <stdio.h>
#include <stdlib.h>


//SUMA
int suma(int a, int b, int* valorSuma)
{
	*valorSuma = a + b;

	return 0;

}

//RESTA
int resta(int a, int b, int* valorResta)
{
	*valorResta = a - b;

	return 0;
}

//DIVISION
int division(int a, int b, float* valorDivision)
{
	*valorDivision = (float)a / b;

	return 0;
}

//MULTIPLICACION
int multiplicacion(int a, int b, float* valorMultiplicacion)
{

	*valorMultiplicacion = a * b;

	return 0;
}

//FACTORIAL
int factorial(int n)
{
	int resultado;
	if(n==1 || n==0)
	{
		resultado = 1;
	}
	else
	{

		resultado = n * factorial(n-1);
	}


	return resultado;
}
