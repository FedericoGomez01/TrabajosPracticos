/*
 * Operaciones.c
 *
 *  Created on: 7 abr. 2021
 *      Author: Santiago
 */
#include <stdio.h>
#include <stdlib.h>


//SUMA
int suma(float a, float b, float* valorSuma)
{
	float resultado;

	*valorSuma = a + b;

	return 0;

}

//RESTA
int resta(float a, float b, float* valorResta)
{
	float resultado;

	*valorResta = a - b;

	return 0;
}

//DIVISION
int division(float a, float b, float* valorDivision)
{
	*valorDivision = a / b;

	return 0;
}

//MULTIPLICACION
int multiplicacion(float a, float b, float* valorMultiplicacion)
{
	*valorMultiplicacion = a * b;

	return 0;
}

//FACTORIAL
int factorial(float n, float* resultado)
{
;
	if(n==1)
		return 1;

	*resultado = n*factorial(n-1);
	return 0;

}
