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
	float valorSuma;
	float valorResta;
	float valorDivision;
	float valorMultiplicacion;
	int flagPrimerNumero =0;
	int flagSegundoNumero =0;

	do{
		printf("---MENU---\n"
				"1-Ingresar un operador\n"
				"2-Ingresar el segundo operador\n"
				"3-Calcular todas las operaciones\n"
				"4-Mostrar los resultados\n"
				"5-Salir");
		fflush(stdin);
		scanf("%d", &menu);

		printf("Que operacion quiere realizar?: s=suma, r=resta, d=division, m=miltiplicacion f=factorial");
		fflush(stdin);
		scanf("%c", &c);

		switch(menu)
		{
			case 1:
				if(flagPrimerNumero==0)
				{
					printf("\nIngrese un numero");
					fflush(stdin);
					scanf("%f" ,&a);
					flagPrimerNumero =1;
				}
				else{
					printf("\nYa ingreso el primer numero");
				}
				break;
			case 2:
				if(flagSegundoNumero ==0)
				{
					printf("\nIngrese el segundo numero");
					fflush(stdin);
					scanf("%f", &b);
				}
				else
				{
					printf("\nYa ingreso el segundo numero");
				}

				break;
			case 3:
				if(flagPrimerNumero != 0 && flagSegundoNumero != 0)
				{
					suma(a,b, &valorSuma);
					resta(a,b, &valorResta);
					if(b == 0)
					{
						printf("\nNo es psoible dividir por 0");
					}
					else
					{
						division(a,b, &valorDivision);
					}

					multiplicacion(a,b, &valorMultiplicacion);
					factorial(a, &factorialA);
					factorial(b, &factorialB);
				}
				else
				{
					printf("No inicio los numeros a calcular");
				}

				break;
			case 4:

				printf("\nLa suma de %.2f + %.2f es = %.2f",a,b, valorSuma);
				printf("\nLa resta de %.2f - %.2f es = %.2f", a, b, valorResta);
				printf("\nLa divisioin de %.2f / %.2f es = %.2f",a,b, valorDivision);
				printf("\nLa multiplicacion de %.2f * %.2f es = %.2f",a , b, valorMultiplicacion);
				printf("\nEl factorial de %f es: %d", a, factorialA);
				printf("\nEl factorial de %f es: %d", b, factorialB);
				break;
			case 5:

				respuesta =0;
				break;
		}
	} while(respuesta);


	if(respuesta == 0)
		printf("Gracias por usar la calculadora");

	return EXIT_SUCCESS;
}


