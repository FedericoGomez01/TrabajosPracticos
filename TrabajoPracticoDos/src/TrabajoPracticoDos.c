#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

#define TAM_ESTRUCTURA 5


int main(void) {

	setbuf(stdout, NULL);

	int opc;
	int id = 999; // valor para id autoingremental
	int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	eEmployee Employee[TAM_ESTRUCTURA];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	eEmployee_Inicializar(Employee, TAM_ESTRUCTURA);


	//BUCLE DE MENU
	do {
		Menu("[0] - SALIR\n"
			"[1] - ALTA EMPLEADOS\n"
			"[2] - MODIFICACION EMPLEADOS\n"
			"[3] - BAJA EMPLEADOS\n"
			"[4] - ORDENAR EMPLEADOS\n");
		opc = Get_IntRange("INICIE EL MENU: ", "ERROR. REINGRESE: ", 0, 4);

		//MENU SWITCH
		switch (opc) {
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			if(Validate_Exit_SN("DESEA SALIR: S-[SI]  N-[NO]", "ERROR. REINGRESE:"))
			{
				opc = 0;
			}
			else
			{
				Menu("[0] - SALIR\n"
					"[1] - ALTA EMPLEADOS\n"
					"[2] - MODIFICACION EMPLEADOS\n"
					"[3] - BAJA EMPLEADOS\n"
					"[4] - ORDERAR EMPLEADOS\n");
				opc = Get_IntRange("INICIE EL MENU: ", "ERROR. REINGRESE: ", 0, 4);
			}
			break;
		case 1:
			//ALTA
			if (eEmployee_Alta(Employee, TAM_ESTRUCTURA, &id)) {
				puts(" * EMPLEADO DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * LA/EL EMPLEADA/O NO SE DIO DE ALTA.");
			}
			break;
		case 2:
			//MODIFICACION
			if(eEmployee_ObtenerIndexOcupado(Employee, TAM_ESTRUCTURA)== 1)
			{
				eEmployee_Modificacion(Employee, TAM_ESTRUCTURA);
			}
			else
			{
				puts("NO SE INGRESO NINGUN EMPLEADO/A");
			}
			break;
		case 3:
			//BAJA
			if(eEmployee_ObtenerIndexOcupado(Employee, TAM_ESTRUCTURA)== 1)
			{
				if (eEmployee_Baja(Employee, TAM_ESTRUCTURA)) {
					puts("\n * BAJA DEL EMPLEADO/A EXITOSA");

				} else {
					puts("\n * BAJA DE EMPLEADO/A CANCELADA");
				}
			}
			else{
				puts("NO SE INGRESO NINGUN EMPEADO/A");
			}
			break;

		case 4:
			//LISTADO Employee
			if(eEmployee_ObtenerIndexOcupado(Employee, TAM_ESTRUCTURA)==1)//modificar por funcion de buscar un alta
			{
				switch(Get_IntRange("DESEA:\n\t>[1]-ORDENAR ALFABETICAMENTE\n\t>[2]-TOTAL Y PROMEDIO DE SALARIOS ", "ERROR. REINGRESE: ", 1, 2))
				{
				case 1:
					 //ORDENAR Employee
					 criterioDeOrdenamiento = Get_Int("INGRESE UN CRITERIO DE ORDENAMIENTO 1-[MAYOR A MENOR] -1-[MENOR A MAYOR]: ", "ERROR. REINGRESE: ");
					 eEmployee_Sort(Employee, TAM_ESTRUCTURA, criterioDeOrdenamiento);
					break;

				case 2:
					eEmployee_PromedioSalario(Employee, TAM_ESTRUCTURA);
					break;
				}
			}
			else{
				puts("NO SE INGRESO NINGUN EMPLEADO/A");
			}
			break;

		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
