#ifndef Employee_C_
#define Employee_C_

#include "ArrayEmployees.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/

//ID AUTOINCREMENTAL
int eEmployee_ObtenerID(int* ID_INCREMENTAL) {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	int rtn = *ID_INCREMENTAL += 1;

	return rtn;
}

void eEmployee_Inicializar(eEmployee array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int eEmployee_ObtenerIndexOcupado(eEmployee array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == OCUPADO) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = 1;
				break;
			}
		}
	}

	return rtn;
}

int eEmployee_ObtenerIndexLibre(eEmployee array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eEmployee_BuscarPorID(eEmployee array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idEmployee == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eEmployee_MostrarUno(eEmployee Employee) {
	//PRINTF DE UN SOLO Employee
	char sector[MAX_CHARS_CADENAS];

	if((ReturnSector(Employee, sector))==0)
	{
			printf("%5d %20s %15s %15s\n", Employee.idEmployee, sector,
			Employee.nombre, Employee.apellido);
	}

}


int ReturnSector(eEmployee Employee, char* SECTOR)
{
	int rtn =1;
	switch(Employee.sector)
	{
	case 1:
		strcpy(SECTOR,"ADMINISTRACION");
		rtn =0;
		break;
	case 2:
		strcpy(SECTOR,"DESARROLLADOR");
		rtn =0;
		break;
	case 3:
		strcpy(SECTOR,"DATABASE");
		rtn =0;
		break;
	}


	return rtn;
}
int eEmployee_MostrarTodos(eEmployee array[], int TAM) {
	int i;
	int rtn = 0;

	//CABECERA
	puts("\n\t> LISTADO EMPLEADO");
	printf("%5s %15s %15s %15s\n\n", "ID", "SECTOR", "NOMBRE", "APELLIDO"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM >= 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Employee
				eEmployee_MostrarUno(array[i]);
				//CONTADOR DE Employee
				rtn++;
			}
		}
	}

	return rtn;
}

int eEmployee_MostrarDadosDeBaja(eEmployee array[], int TAM) {
	int i;
	int rtn = 0;

	//CABECERA
	puts("\t> EMPLEADO\n");
	printf("%5s %5s %15s %15s\n\n", "ID", "sector", "NOMBRE", "LUGAR"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Employee
				eEmployee_MostrarUno(array[i]);
				//CONTADOR DE Employee
				rtn++;
			}
		}
	}

	return rtn;
}

eEmployee eEmployee_CargarDatos(void) {
	eEmployee auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL eEmployee_Alta() */

	Get_OnlyAlphabetStringWithSpaces("INGRESE NOMBRE: ", "ERROR. REINGRESE: ",auxiliar.nombre, MAX_CHARS_CADENAS);
	Get_OnlyAlphabetStringWithSpaces("INGRESE APELLIDO: ", "ERROR. REINGRESE: ",auxiliar.apellido, MAX_CHARS_CADENAS);
	auxiliar.salario =Get_Float("INGRESE EL SALARIO:", "ERROR. REINGRESE: ");


	printf("\nSELECCIONE SECTOR\n\t1- ADMINISTRACION\n\t2- DESARROLLADOR\n\t3-DATABASE\n");

	switch (Get_IntRange("OPCION: ", "ERROR. REINGRESE: ", 1, 3)) {

	case ADMINISTRACION:
		auxiliar.sector = ADMINISTRACION;
		break;

	case DESARROLLADOR:
		auxiliar.sector = DESARROLLADOR;
		break;

	case DATABASE:
		auxiliar.sector = DATABASE;
		break;
	}

	return auxiliar;
}

eEmployee eEmployee_ModificarUno(eEmployee Employee) {
	eEmployee auxiliar  = Employee; //A auxiliar le copio los valores que tengo de Eployee para que no me entre basura
	int opc;

	do{
		Menu("[0]- SALIR DE LA CARGA\n"
		"[1]- CAMBIAR NOMBRE\n"
		"[2]- CAMBIAR APELLIDO\n"
		"[3]- CAMBIAR SALARIO\n"
		"[4]- CAMBIAR SECROR\n");
		opc = Get_IntRange("SELECCIONE QUE QUIERE CAMBIAR:", "ERROR. REINGRESE: ", 0, 4);
		switch(opc){
		case 1:
			Get_OnlyAlphabetStringWithSpaces("INGRESE NOMBRE: ", "ERROR. REINGRESE: ",auxiliar.nombre, MAX_CHARS_CADENAS);
			break;
		case 2:
			Get_OnlyAlphabetStringWithSpaces("INGRESE APELLIDO: ", "ERROR. REINGRESE: ",auxiliar.apellido, MAX_CHARS_CADENAS);
			break;
		case 3:
			auxiliar.salario =Get_Float("INGRESE EL SALARIO:", "ERROR. REINGRESE: ");
			break;
		case 4:
				printf("\nSELECCIONE SECTOR\n\t1- ADMINISTRACION\n\t2- DESARROLLADOR\n\t3-DATABASE\n");

				switch (Get_IntRange("OPCION: ", "ERROR. REINGRESE: ", 1, 3)) {

				case ADMINISTRACION:
					auxiliar.sector = ADMINISTRACION;
					break;

				case DESARROLLADOR:
					auxiliar.sector = DESARROLLADOR;
					break;

				case DATABASE:
					auxiliar.sector = DATABASE;
					break;
				}
			break;
		}
	}while(opc != 0);


	return auxiliar;
}

int eEmployee_Alta(eEmployee array[], int TAM, int* id) {
	int rtn = 0;

	eEmployee auxEmployee;

	//BUSCO ESPACIO EN ARRAY
	int index = eEmployee_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Employee AUXILIAR
		auxEmployee = eEmployee_CargarDatos();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxEmployee.isEmpty = OCUPADO;

		//MOSTRAR EL DATO

		if (Validate_Exit_SN("DESEA CONTINUAR SI[S] - NO[N]: ", "ERROR. REINGRESE.")) {
			//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
			auxEmployee.idEmployee = eEmployee_ObtenerID(id);
			//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
			array[index] = auxEmployee;
			//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
			rtn = 1;
		}
	}
	else{
		puts("NO HAY ESPACIO PARA CARGAR MAS EMPLEADOS");
	}

	return rtn;
}

int eEmployee_Baja(eEmployee array[], int TAM) {
	int rtn = 0;
	int idEmployee;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Employee
	if (eEmployee_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Employee DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Employee PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		idEmployee = Get_IntPositive("INGRESE ID A DAR DE BAJA: ","ERROR. REINGRESE: ");
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (eEmployee_BuscarPorID(array, TAM, idEmployee) == -1) {
			puts("NO EXISTE ID.");
			idEmployee = Get_IntPositive("INGRESE ID A DAR DE BAJA: ","ERROR. REINGRESE: ");
		}

		//OBTENGO INDEX DEL ARRAY DE Employee A DAR DE BAJA
		index = eEmployee_BuscarPorID(array, TAM, idEmployee);

		if (Validate_Exit_SN("DESEA CONTINUAR SI[S] - NO[N]: ", "ERROR. REINGRESE.")) {
			//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
			array[index].isEmpty = BAJA;

			//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
			rtn = 1;
		}
	}

	return rtn;
}

int eEmployee_Modificacion(eEmployee array[], int TAM) {
	int rtn = 0;
	int idEmployee;
	int index;
	int flag = 0;
	eEmployee auxiliar;

	//LISTO TODOS LOS Employee
	if (eEmployee_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Employee DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Employee PARA MODIFICAR
	if (flag==1) {
		//PIDO ID A MODIFICAR
		idEmployee = Get_Int("SELLECIONE ID DEL EMPLEADO/A A MODIFICAR:", "ERROR. REINGRESE:");

		//BUSCO INDEX POR ID EN ARRAY
		while (eEmployee_BuscarPorID(array, TAM, idEmployee) == -1) {
			puts("NO EXISTE ID.");
			idEmployee = Get_Int("SELLECIONE ID DEL EMPLEADO/A A MODIFICAR:", "ERROR. REINGRESE:");
		}

		//OBTENGO INDEX DEL ARRAY DE EMPLOYEE A MODIFICAR
		index = eEmployee_BuscarPorID(array, TAM, idEmployee);
		//LLAMO A FUNCION QUE MODIFICA EMPLOYEE
		auxiliar = eEmployee_ModificarUno(array[index]);

		if(Validate_Exit_SN("DESEA APLICAR LA MODIFICACION? S-[SI]  N-[NO]: ", "ERROR, REINGRESE: "))
		{
			array[index].idEmployee = idEmployee;
			array[index].isEmpty = OCUPADO;
			array[index] = auxiliar;
			rtn = 1;
			puts("\n * MODIFICACION DEL EMPLEADO/A EXITOSA");
			eEmployee_MostrarTodos(array, TAM); //PREGUNTAR EN LA CLASE DEL SABADO.


		}
		else
		{
			puts("\n * MODIFICACION DEL EMPLEADO/A EXITOSA");
		}

	}

	return rtn;
}

int eEmployee_Sort(eEmployee array[], int TAM, int criterio) {
	int rtn = 1;
	int i;
	int j;
	eEmployee aux;
	int opc;


	do{

		Menu("[0]- SALIR DE LA CARGA\n"
		"[1]- ORDENAR POR APELLIDO\n"
		"[2]- ORDENAR POR SECTOR\n"
		"[3]- ORDENAR POR ID\n");

		opc = Get_IntRange("COMO QUIERE ORDERAR A LOS EMPLEADOS?: ", "ERROR. REINGRESE: ", 0, 3);
		switch(opc){
		case 1: //ORDERAR POR APELLIDO
			//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
			if (array != NULL && TAM > 0) {
				switch (criterio) {
				case -1:
					for (i = 0; i < TAM - 1; i++) {
						for (j = i + 1; j < TAM; j++) {
							//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
							if (array[i].isEmpty == OCUPADO
									&& array[j].isEmpty == OCUPADO) {
								//CRITERIO DE ORDENAMIENTO
								if (array[i].apellido > array[j].apellido) {
									//INTERCAMBIO POSICIONES EN ARRAY
									aux = array[i];
									array[i] = array[j];
									array[j] = aux;
								}
							}
						}
					}
					rtn = 0;
					break;
				case 1:
					for (i = 0; i < TAM - 1; i++) {
						for (j = i + 1; j < TAM; j++) {
							//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
							if (array[i].isEmpty == OCUPADO
									&& array[j].isEmpty == OCUPADO) {
								//CRITERIO DE ORDENAMIENTO
								if (array[i].apellido < array[j].apellido) {
									//INTERCAMBIO POSICIONES EN ARRAY
									aux = array[i];
									array[i] = array[j];
									array[j] = aux;
								}
							}
						}
					}
					rtn = 0;
					break;
				default:
					//CRITERIO DE ORDENAMIENTO MAL INGRESADO
					rtn = 1;
					break;
				}
			}
			break;
		case 2: //ORDERAR POR SECTOR
					//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
					if (array != NULL && TAM > 0) {
						switch (criterio) {
						case -1:
							for (i = 0; i < TAM - 1; i++) {
								for (j = i + 1; j < TAM; j++) {
									//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
									if (array[i].isEmpty == OCUPADO
											&& array[j].isEmpty == OCUPADO) {
										//CRITERIO DE ORDENAMIENTO
										if (array[i].sector > array[j].sector) {
											//INTERCAMBIO POSICIONES EN ARRAY
											aux = array[i];
											array[i] = array[j];
											array[j] = aux;
										}
									}
								}
							}
							rtn = 0;
							break;
						case 1:
							for (i = 0; i < TAM - 1; i++) {
								for (j = i + 1; j < TAM; j++) {
									//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
									if (array[i].isEmpty == OCUPADO
											&& array[j].isEmpty == OCUPADO) {
										//CRITERIO DE ORDENAMIENTO
										if (array[i].sector < array[j].sector) {
											//INTERCAMBIO POSICIONES EN ARRAY
											aux = array[i];
											array[i] = array[j];
											array[j] = aux;
										}
									}
								}
							}
							rtn = 0;
							break;
						default:
							//CRITERIO DE ORDENAMIENTO MAL INGRESADO
							rtn = 1;
							break;
						}
					}
					break;
		case 3: //ORDERAR POR ID
							//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
							if (array != NULL && TAM > 0) {
								switch (criterio) {
								case -1:
									for (i = 0; i < TAM - 1; i++) {
										for (j = i + 1; j < TAM; j++) {
											//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
											if (array[i].isEmpty == OCUPADO
													&& array[j].isEmpty == OCUPADO) {
												//CRITERIO DE ORDENAMIENTO
												if (array[i].idEmployee > array[j].idEmployee) {
													//INTERCAMBIO POSICIONES EN ARRAY
													aux = array[i];
													array[i] = array[j];
													array[j] = aux;
												}
											}
										}
									}
									rtn = 0;
									break;
								case 1:
									for (i = 0; i < TAM - 1; i++) {
										for (j = i + 1; j < TAM; j++) {
											//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
											if (array[i].isEmpty == OCUPADO
													&& array[j].isEmpty == OCUPADO) {
												//CRITERIO DE ORDENAMIENTO
												if (array[i].idEmployee < array[j].idEmployee) {
													//INTERCAMBIO POSICIONES EN ARRAY
													aux = array[i];
													array[i] = array[j];
													array[j] = aux;
												}
											}
										}
									}
									rtn = 0;
									break;
								default:
									//CRITERIO DE ORDENAMIENTO MAL INGRESADO
									rtn = 1;
									break;
								}
							}
							break;
		}
		eEmployee_MostrarTodos(array, TAM);

	}while(opc != 0);



	return rtn;
}


int eEmployee_PromedioSalario(eEmployee array[], int TAM){
	//CALCULO EL PROMEDIO DE LOS SALARIOS Y LA CANTIDAD DE EMPLEADOS QUE TIENEN UN MAYOR SALARIO QUE EL PROMEDIO


	int rtn= -1;
	float salarioAcumulador =0;
	int empleados = 0;
	int empleadosMayorSalarios = 0;
	float promedioSalario;

	for(int i =0; i<TAM;i++)
	{
		if(array[i].isEmpty == OCUPADO && array[i].salario > 0)
		{
			empleados++;
			salarioAcumulador = salarioAcumulador + array[i].salario;
		}
	}

	promedioSalario = salarioAcumulador / empleados;

	printf("EL TOTAL DE LOS SALARIOS ES: $%.0f\n", salarioAcumulador);
	printf("EL PROMEDIO DE LOS SALARIOS ES: $%.0f\n", promedioSalario);


	for(int i = 0; i< TAM ; i++)
	{
		if(array[i].isEmpty == OCUPADO && promedioSalario < array[i].salario)
		{
			empleadosMayorSalarios++;
		}
	}

	printf("LA CANTIDAD DE EMPLEADOS CON SALARIO MAYOR AL PROMEDIO SON: %d\n", empleadosMayorSalarios);

	return rtn;
}


#endif
