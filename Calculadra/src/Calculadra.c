
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
#include <ctype.h>
#include "Menu.h"

int main(void)
{
	setbuf(stdout, NULL);

	int menu;
	int a;
	int b;
	int factorialA;
	int factorialB;
	int valorSuma;
	int valorResta;
	float valorDivision;
	int valorMultiplicacion;
	int validacionA;
	int validacionB;
	int rtndivision;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 =0;
	do{
		menu =Menu(&a, &b);

		switch(menu)
		{
			case 1:

					printf("\nIngrese un numero");
					fflush(stdin);
					validacionA = scanf("%d" ,&a); //ValidacionA usado para que scanf me rotorne 0 cuando no recibe el valor solicitado


					while(!validacionA) //Si validacionA es distinto de 1 entra (si no es un numero int)
					{
						printf("\nERROR. Ingrese un numero");
						fflush(stdin);
						validacionA = scanf("%d" ,&a);
					}
					printf("Primer numero recibido!");
					flag1=1;

				break;
			case 2:


				printf("\nIngrese el segundo numero");
				fflush(stdin);
				validacionB = scanf("%d", &b);

				while(!validacionB)
				{
					printf("\nError. Reingrese el segundo numero");
					fflush(stdin);
					validacionB = scanf("%d", &b);
				}

				printf("Segundo numero recibido!");
				flag2=1;

				break;
			case 3:
				if(flag1==1 && flag2==1)
				{
					suma(a,b, &valorSuma);
					resta(a,b, &valorResta);
					rtndivision = division(a,b, &valorDivision);
					multiplicacion(a,b, &valorMultiplicacion);
					factorialA = factorial(a);
					factorialB = factorial(b);
					printf("Calculado!");
					flag3=1;
				}
				else
				{
					printf("No inicializo los dos numeros");
				}

				break;
			case 4:
				if(flag3 == 1)
				{
					printf("\nLa suma de %d + %d es = %d",a,b, valorSuma);
					printf("\nLa resta de %d - %d es = %d", a, b, valorResta);
					if(rtndivision != -1)
					{
						printf("\nLa divisioin de %d / %d es = %.2f",a,b, valorDivision);

					}
					else{
						printf("\nNo se puede dividir por 0");
					}
					printf("\nLa multiplicacion de %d * %d es = %d",a , b, valorMultiplicacion);
					if(factorialA != -1)
					{
						printf("\nEl factorial de %d es: %d", a, factorialA);
					}
					else{
						printf("\nNo se puede sacar un factorial de un numero negativo");
					}
					if(factorialB != -1)
					{
						printf("\nEl factorial de %d es: %d", a, factorialB);
					}
					else{
						printf("\nNo se puede sacar un factorial de un numero negativo");
					}
				}
				else
				{
					printf("\nNo realizo los calculos");
				}

				break;

		}
	} while(menu != 5);


	if(menu == 5)
		printf("\nGracias por usar la calculadora");

	return EXIT_SUCCESS;
}

