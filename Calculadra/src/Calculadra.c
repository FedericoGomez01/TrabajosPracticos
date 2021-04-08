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
	char c;
	int factorialA;
	int factorialB;
	int respuesta;

	do{
		printf("---MENU---\n"
				"1-Ingresar un operador\n"
				"2-Ingresar el segundo operador\n"
				"3-Desea usar una operacion?\n"
				"4-Mostrar los resultados\n"
				"5-Salir");
		fflush(stdin);
		scanf("%d", &menu);


		printf("Ingrese un numero");
		fflush(stdin);
		scanf("%f" ,&a);

		printf("Ingrese un numero");
		fflush(stdin);
		scanf("%f", &b);

		printf("Que operacion quiere realizar?: s=suma, r=resta, d=division, m=miltiplicacion f=factorial");
		fflush(stdin);
		scanf("%c", &c);

		switch(c)
		{
			case 's':
				suma(a, b);
				break;
			case 'r':
				resta(a, b);
				break;
			case 'd':
				division(a, b);
				break;
			case 'm':
				multiplicacion(a, b);
				break;
			case 'f':
				factorial(a);
				factorialA = factorial(a);
				printf("\nEl factorial de %f es: %d", a, factorialA);
				factorial(b);
				factorialB = factorial(b);
				printf("\nEl factorial de %f es: %d", b, factorialB);
				break;
		}

		printf("\nDesea hacer otra operacion?: 1=si, 0=no");
		fflush(stdin);
		scanf("%d", &respuesta);
	} while(respuesta);


	if(respuesta == 0)
		printf("Gracias por usar la calculadora");

	return EXIT_SUCCESS;
}


