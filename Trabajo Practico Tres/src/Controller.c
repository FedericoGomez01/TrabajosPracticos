#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Biblioteca.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int rtn=1;
	FILE* pFile;

	pFile = fopen(path,"r");
	if(pFile!= NULL){
		parser_EmployeeFromText(pFile , pArrayListEmployee);
		rtn=0;
	}
	fclose(pFile);
    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int rtn=1;
	FILE* pFile;

	pFile = fopen(path,"rb");
	if(pFile!= NULL){
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		rtn=0;
	}
	fclose(pFile);
    return rtn;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id){
	Employee* nuevoEmpleado = employee_new();
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int rtn =-1;
	Get_String("INGRESE EL NOMBRE DEL NUEVO EMPLEADO: ", "ERROR. REINGRESE EL NOMBRE", nombre, 128);

	horasTrabajadas =Get_IntRange("INGRESE LAS HORAS TRABAJADAS: ", "ERROR. REINGRESE LAS HORAS TRABAJADAS: ", 0, 720);

	sueldo=Get_IntRange("INGRESE EL SUELDO DEL EMPLEADO: ", "ERROR. REINGRESE EL SUELDO DEL EMPLEADO: ", 10000, 100000);
	if(Validate_Exit_SN("ESTA SEGURO QUE DESEA INGRESAR ESTS DATOS ? [S]-SI [N]-NO", "ERROR. REINGRESE: ")){
		employee_setId(nuevoEmpleado, id);
		employee_setNombre(nuevoEmpleado, nombre);
		employee_setHorasTrabajadas(nuevoEmpleado, horasTrabajadas);
		employee_setSueldo(nuevoEmpleado, sueldo);
		ll_add(pArrayListEmployee, nuevoEmpleado);
		rtn=1;
	}

	controller_EscribirUltimoId();
    return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* emp;
	int id;
	int rtn= -1;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	id = Get_IntPositive("INGRESE EL ID DEL EMPLEADO A MODIFICAR: ", "ERROR. REINGRESE: ");
	//id--;
	emp =ll_get(pArrayListEmployee, (id-1));
	if(employee_printOne(emp)!=1){
		puts("\tNO SE PUDO ENCONTRAR EL EMPLEADO CON ESE ID\n");
	}else{
		Get_String("INGRESE EL NOMBRE DEL NUEVO EMPLEADO: ", "ERROR. REINGRESE EL NOMBRE", nombre, 128);
		horasTrabajadas =Get_IntRange("INGRESE LAS HORAS TRABAJADAS: ", "ERROR. REINGRESE LAS HORAS TRABAJADAS: ", 0, 720);
		sueldo=Get_IntRange("INGRESE EL SUELDO DEL EMPLEADO: ", "ERROR. REINGRESE EL SUELDO DEL EMPLEADO: ", 10000, 100000);

		if(Validate_Exit_SN("ESTA SEGURO QUE DESEA INGRESAR ESTS DATOS ? [S]-SI [N]-NO", "ERROR. REINGRESE: ")){
			employee_setId(emp, id);
			employee_setNombre(emp, nombre);
			employee_setHorasTrabajadas(emp, horasTrabajadas);
			employee_setSueldo(emp, sueldo);
			rtn =1;
			puts("DATOS CARGADOS EXITOSAMENTE");
			employee_printOne(emp);
		}
	}
	return rtn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int index;
	if(pArrayListEmployee!= NULL){

		index = Get_IntRange("INGRESE EL INDICE DEL EMPLEADO QUE QUIERE BORRAR: ", "ERROR. REINGRESE: ", 1, ll_len(pArrayListEmployee));
		index--;
		ll_remove(pArrayListEmployee, index);
	}
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int len = ll_len(pArrayListEmployee);
	Employee* auxEmpleado =NULL;

	printf("\n");
	printf("ID, NOMBRE, HORAS TRABAJADAS, SUELDO\n");
	if(pArrayListEmployee != NULL){
		for(i=0; i< len; i++)
		{
			auxEmpleado =ll_get(pArrayListEmployee, i);
			if(auxEmpleado != NULL){
				employee_getId(auxEmpleado, &id);
				employee_getNombre(auxEmpleado, nombre);
				employee_getHorasTrabajadas(auxEmpleado, &horasTrabajadas);
				employee_getSueldo(auxEmpleado, &sueldo);
				printf("%d, %s, %d, %d\n",  id , nombre, horasTrabajadas, sueldo);
			}
		}
	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = 1;
	int criterio;
	int opc;
	int idI;
	int idJ;
	char nombreI[128];
	char nombreJ[128];
	int horasTrabajadasI;
	int horasTrabajadasJ;
	int sueldoI;
	int sueldoJ;
	Employee* employee_I = NULL;
	Employee* employee_J = NULL;
	Employee aux;
	printf("QUE CRITERIO DE ORDENAMIENTO DESEA ELEGIR? [1]-MENOR A MAYOR  [2]-MAYOR A MENOR");
    scanf("%d", &criterio);

    while(criterio != 1 && criterio!= 2){
    	printf("ERROR. REINGRESE QUE CRITERIO DE ORDENAMIENTO DESEA ELEGIR? [1]-MENOR A MAYOR  [2]-MAYOR A MENOR");
		scanf("%d", &criterio);
    }
    printf("QUE DESEO ORDENAR CON ESE CRITERIO?\n"
    		"[1]-ID\n"
    		"[2]-NOMBRE\n"
    		"[3]-HORAS TRABAJADAS\n"
    		"[4]-SUELDO\n");
    scanf("%d", &opc);

    while(opc != 1 && opc!= 2 && opc!=3 &&opc!=4){
        printf("QUE DESEO ORDENAR CON ESE CRITERIO?\n"
        		"[1]-ID\n"
        		"[2]-NOMBRE\n"
        		"[3]-HORAS TRABAJADAS\n"
        		"[4]-SUELDO\n");
        scanf("%d", &opc);
    }

	if (pArrayListEmployee != NULL) {
		switch (criterio) {
		case 1:
			puts("ESTA OPERACION PUEDE TARDAR UNOS SEGUNDOS. ESPERE, POR FAVOR");
			for (int i = 0; i < (ll_len(pArrayListEmployee)  - 1); i++) {
				employee_I = ll_get(pArrayListEmployee, i);
				for (int j = i + 1; j < (ll_len(pArrayListEmployee)) ; j++) {
					employee_J = ll_get(pArrayListEmployee, j);
					switch(opc){
					case 1:
						employee_getId(employee_I, &idI);
						employee_getId(employee_J, &idJ);
						if ( idI > idJ) {
							aux = *(employee_I);
							*(employee_I) = *(employee_J);
							*(employee_J) = aux;
							rtn = 0;
						}
						break;
					case 2:
						employee_getNombre(employee_I, nombreI);
						employee_getNombre(employee_J, nombreJ);
						if (strcmp(nombreI, nombreJ)>0) {
							aux = *(employee_I);
							*(employee_I) = *(employee_J);
							*(employee_J) = aux;
							rtn = 0;
							}
						break;
					case 3:
						employee_getHorasTrabajadas(employee_I, &horasTrabajadasI);
						employee_getHorasTrabajadas(employee_J, &horasTrabajadasJ);
						if (horasTrabajadasI > horasTrabajadasJ) {
							aux = *(employee_I);
							*(employee_I) = *(employee_J);
							*(employee_J) = aux;
							rtn = 0;
						}
						break;
					case 4:
						employee_getSueldo(employee_I, &sueldoI);
						employee_getSueldo((employee_J), &sueldoJ);
						if (sueldoI > sueldoJ) {
							aux = *(employee_I);
							*(employee_I) = *(employee_J);
							*(employee_J) = aux;
							rtn = 0;
						}
						break;
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < (ll_len(pArrayListEmployee)  - 1); i++) {
				employee_I = ll_get(pArrayListEmployee, i);
				for (int j = i + 1; j < ll_len(pArrayListEmployee) ; j++) {
					employee_J = ll_get(pArrayListEmployee, j);
					switch(opc){
					case 1:
						employee_getId(employee_I, &idI);
						employee_getId(employee_J, &idJ);
						if (idI < idJ) {
							aux = *(employee_I);
							*(employee_I) = *(employee_J);
							*(employee_J) = aux;
							rtn = 0;
						}
						break;
					case 2:
						employee_getNombre(employee_I, nombreI);
						employee_getNombre(employee_J, nombreJ);
						if (strcmp(nombreI, nombreJ)<0) {
							aux = *(employee_I);
							*(employee_I) = *(employee_J);
							*(employee_J) = aux;
							rtn = 0;
						}
						break;
					case 3:
						employee_getHorasTrabajadas(employee_I, &horasTrabajadasI);
						employee_getHorasTrabajadas(employee_J, &horasTrabajadasJ);
						if (horasTrabajadasI < horasTrabajadasJ) {
							aux = *(employee_I);
							*(employee_I) = *(employee_J);
							*(employee_J) = aux;
							rtn = 0;
						}
						break;
					case 4:
						employee_getSueldo(employee_I, &sueldoI);
						employee_getSueldo(employee_J, &sueldoJ);
						if (sueldoI < sueldoJ) {
							aux = *(employee_I);
							*(employee_I) = *(employee_J);
							rtn = 0;
						}
						break;
					}
				}
			}
			break;
		}
	}
	if(rtn ==0){
		puts("ORDENAMIENTO EXITOSO!");
		if(Validate_Exit_SN("DESEA MOSTRAR LA LISTA ORENADA? [S]-SI [N]-NO","ERROR. REINGRESE: ")){
			controller_ListEmployee(pArrayListEmployee);
		}
	}else{
		puts("ALGO SALIÓ MAL");
	}
	return rtn;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	int cant;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	Employee* emp;
	FILE* aux;

	aux = fopen(path,"w");
	if(aux != NULL){
		fprintf(aux,"ID, NOMBRE, HORAS TRABAJADAS, SUELDO\n");
		for(int i =0; i< ll_len(pArrayListEmployee); i++){
			emp = ll_get(pArrayListEmployee, i);
			if(emp!=NULL){
				employee_getId(emp, &id);
				employee_getNombre(emp, nombre);
				employee_getHorasTrabajadas(emp, &horasTrabajadas);
				employee_getSueldo(emp, &sueldo);
				cant =fprintf(aux, "%d, %s, %d, %d\n", id, nombre, horasTrabajadas, sueldo);
				if(cant<0){
					puts("ERROR AL CARGAR");
					exit(1);
				}
			}
		rtn =1;
		}
		if(rtn==1){
			puts("GUARDADO CON EXITO");
		}

	}
	fclose(aux);
    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int rtn=0;
	int validacion;
	FILE* File;
	Employee* emp;
	File = fopen(path,"wb");
	if(File != NULL){
		for(int i =0; i< ll_len(pArrayListEmployee); i++){
			emp = ll_get(pArrayListEmployee, i);
			if(emp!=NULL){
				validacion =fwrite(emp,sizeof(Employee), 1, File);
				if(validacion !=1){
					free(emp);
					break;
				}else{
					rtn ++;
				}
			}
		}
		if(rtn==1000){
			puts("GUARDADO CON EXITO");
		}
		printf("%d", rtn);
	}
	fclose(File);
    return rtn;
}

int controller_leeUltimoId(){

	FILE* pFile = NULL;
	int id=-1;
	pFile = fopen("Ultimo.txt", "r");

	if(pFile != NULL){
		id = parser_obterenUltimoId(pFile);
		id++;
	}
	fclose(pFile);

	return id;
}


void controller_EscribirUltimoId(){

	FILE* pFile =NULL;
	int id = controller_leeUltimoId();
	pFile = fopen("Ultimo.txt", "w");
	if(pFile!=NULL){

		fprintf(pFile,"%d", id);
	}
	fclose(pFile);
}
