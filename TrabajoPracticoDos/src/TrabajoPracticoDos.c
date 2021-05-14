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
	//int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	eEmployee Employee[TAM_ESTRUCTURA];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	eEmployee_Inicializar(Employee, TAM_ESTRUCTURA);


	//BUCLE DE MENU
	do {
		Menu("[0] - SALIR\n"
			"[1] - ALTA EMPLEADOs\n"
			"[2] - BAJA\n"
			"[3] - MODIFICACION ELEADOS\n"
			"[4] - LISTAR EMPLEADOS\n");
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
					"[2] - BAJA\n"
					"[3] - MODIFICACION ELEADOS\n"
					"[4] - LISTAR EMPLEADOS\n");
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
			system("pause");
			break;
		case 2:
			//BAJA
			if(eEmployee_ObtenerIndexOcupado(Employee, TAM_ESTRUCTURA)== 1)
			{
				if (eEmployee_Baja(Employee, TAM_ESTRUCTURA)) {
					puts("\n * BAJA DEL EMPLEADO/A EXITOSA");
					eEmployee_MostrarTodos(Employee, TAM_ESTRUCTURA);
				} else {
					puts("\n * BAJA DE EMPLEADO/A CANCELADA");
				}
			}
			else{
				puts("NO SE INGRESO NINGUN EMPEADO/A");
			}

			system("pause");
			break;
		case 3:
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
		case 4:
			//LISTADO Employee
			if(eEmployee_ObtenerIndexOcupado(Employee, TAM_ESTRUCTURA)==1)//modificar por funcion de buscar un alta
			{
				if (eEmployee_MostrarTodos(Employee, TAM_ESTRUCTURA)) {
					system("pause");
				} else {
					puts("NO HAY NINGUN DATO PARA MOSTRAR");
				}

			}
			else{
				puts("NO SE INGRESO NINGUN EMPLEADO/A");
			}

			break;
			break;

			/*case 5:
			 //ORDENAR Employee
			 criterioDeOrdenamiento = -1; //PEDIR CRITERIO DE ORDENAMIENTO
			 eEmployee_Sort(Employee, TAM_ESTRUCTURA, criterioDeOrdenamiento);
			 system("pause");
			 break;*/
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
