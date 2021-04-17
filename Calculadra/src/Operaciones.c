/*
 * Operaciones.c
 *
 *  Created on: 7 abr. 2021
 *      Author: Santiago
 */
#include <stdio.h>
#include <stdlib.h>


//SUMA
float suma(float a, float b, float* valorSuma)
{
	*valorSuma = a + b;

	return 0;

}

//RESTA
float resta(float a, float b, float* valorResta)
{
	*valorResta = a - b;

	return 0;
}

//DIVISION
float division(float a, float b, float* valorDivision)
{
	*valorDivision = a / b;

	return 0;
}

//MULTIPLICACION
float multiplicacion(float a, float b, float* valorMultiplicacion)
{
	*valorMultiplicacion = a * b;

	return 0;
}

//FACTORIAL
int factorial(float n)
{
	float resultado;
	if(n==1)
	{
		return 1;
	}
	resultado = n * factorial(n-1);

	return resultado;
}
