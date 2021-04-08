/*
 * Operaciones.c
 *
 *  Created on: 7 abr. 2021
 *      Author: Santiago
 */
#include <stdio.h>
#include <stdlib.h>


//SUMA
void suma(float a, float b)
{
	float resultado;

	resultado = a + b;

	printf("\nLa suma de %.2f + %.2f es = %.2f", a, b, resultado);

}

//RESTA
void resta(float a, float b)
{
	float resultado;

	resultado = a - b;

	printf("\nLa resta de %.2f - %.2f es = %.2f", a, b, resultado);

}

//DIVISION
void division(float a, float b)
{
	float resultado;
	if(b == 0)
	{
		printf("\nNo es psoible dividir por 0");
	}
	else
	{
		resultado = a / b;

		printf("\nLa division de %.2f / %.2f es = %.2f", a, b, resultado);
	}
}

//MULTIPLICACION
void multiplicacion(float a, float b)
{
	float resultado;

	resultado = a * b;
	printf("\nLa multiplicacion de %.2f * %.2f es = %.2f", a, b, resultado);

}

//FACTORIAL
int factorial(float n)
{
	int resultado;
	if(n==1)
		return 1;

	resultado = n*factorial(n-1);
	return resultado;

}
