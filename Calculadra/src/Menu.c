/*
 * Menu.c
 *
 *  Created on: 17 abr. 2021
 *      Author: Santiago
 */
#include <stdio.h>

int Menu(int* a, int* b)
{
	int retorno;
	printf("\n---MENU---\n"
			"1-Ingresar un operador\n"
			"2-Ingresar el segundo operador\n"
			"3-Calcular todas las operaciones\n"
			"4-Mostrar los resultados\n"
			"5-Salir");
	fflush(stdin);
	scanf("%d", &retorno);

	return retorno;
}
