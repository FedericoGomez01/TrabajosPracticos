/*
 ============================================================================
 Name        : Calculadra.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

int main(void)
{
	setbuf(stdout, NULL);

	int menu;
	float a;
	float b;
	float factorialA;
	float factorialB;
	float valorSuma;
	float valorResta;
	float valorDivision;
	float valorMultiplicacion;

	do{
		printf("\n---MENU---\n"
				"1-Ingresar un operador\n"
				"2-Ingresar el segundo operador\n"
				"3-Calcular todas las operaciones\n"
				"4-Mostrar los resultados\n"
				"5-Salir");
		fflush(stdin);
		scanf("%d", &menu);


		switch(menu)
		{
			case 1:
				printf("\nIngrese un numero");
				fflush(stdin);
				scanf("%f" ,&a);
				break;
			case 2:
				printf("\nIngrese el segundo numero");
				fflush(stdin);
				scanf("%f", &b);

				break;
			case 3:
				suma(a,b, &valorSuma);
				resta(a,b, &valorResta);
				division(a,b, &valorDivision);
				multiplicacion(a,b, &valorMultiplicacion);
				factorialA = factorial(a);
				factorialB = factorial(b);

				break;
			case 4:

				printf("\nLa suma de %.2f + %.2f es = %.2f",a,b, valorSuma);
				printf("\nLa resta de %.2f - %.2f es = %.2f", a, b, valorResta);
				printf("\nLa divisioin de %.2f / %.2f es = %.2f",a,b, valorDivision);
				printf("\nLa multiplicacion de %.2f * %.2f es = %.2f",a , b, valorMultiplicacion);
				printf("\nEl factorial de %f es: %.2f", a, factorialA);
				printf("\nEl factorial de %f es: %.2f", b, factorialB);
				break;

		}
	} while(menu != 5);


	if(menu == 5)
		printf("Gracias por usar la calculadora");

	return EXIT_SUCCESS;
}


