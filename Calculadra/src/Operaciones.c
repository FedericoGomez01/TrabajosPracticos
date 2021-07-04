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
	int rtn;

	if(b==0)
	{
		rtn = -1;
	}
	else
	{
		if(a==0)
		{
			*valorDivision =0;

		}else
		{
			*valorDivision = (float)a / b;

		}
		rtn =0;
	}


	return rtn;
}

//MULTIPLICACION
void multiplicacion(int a, int b, float* valorMultiplicacion)
{
	if(a != 0 && b != 0)
	{
		*valorMultiplicacion = a * b;
	}else{
		*valorMultiplicacion =0;
	}
}

//FACTORIAL
int factorial(int n)
{
	int resultado;
	if(n >=0)
	{
		if(n==1 || n==0)
		{
			resultado = 1;
		}
		else
		{

			resultado = n * factorial(n-1);
		}
	}
	else{
		resultado = -1;
	}


	return resultado;
}
