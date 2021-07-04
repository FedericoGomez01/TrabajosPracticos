#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Films.h"
#include "Parser.h"
#include "Biblioteca.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFilms LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListFilms)
{
	int rtn=1;
	char nombre[50];
	FILE* pFile = NULL;
	Get_String("INGRESE EL NOMBRE DEL ARCHIVO: (DatosNombre)", "ERROR. REINGRESE: ", nombre, 50);
	strcat(nombre, ".csv");
	if(nombre!=NULL)
	{
		pFile = fopen(nombre,"r");
		if(pFile!= NULL){
			parser_FilmsFromText(pFile , pArrayListFilms);
			rtn=0;
		}
		fclose(pFile);
	}else
	{
		puts("NO SE ENCONTRO EL ARCHIVO");
	}
    return rtn;
}


int controller_ventas(LinkedList* this)
{
	if( this != NULL)
	{
		//Films_controlVentas();
	}
	return 0;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListFilms LinkedList*
 * \return int
 *
 */
/*
int controller_addFilms(LinkedList* pArrayListFilms, int id){
	Films* nuevoEmpleado = Films_new();
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int rtn =-1;
	Get_String("INGRESE EL NOMBRE DEL NUEVO EMPLEADO: ", "ERROR. REINGRESE EL NOMBRE", nombre, 128);

	horasTrabajadas =Get_IntRange("INGRESE LAS HORAS TRABAJADAS: ", "ERROR. REINGRESE LAS HORAS TRABAJADAS: ", 0, 720);

	sueldo=Get_IntRange("INGRESE EL SUELDO DEL EMPLEADO: ", "ERROR. REINGRESE EL SUELDO DEL EMPLEADO: ", 10000, 100000);
	if(Validate_Exit_SN("ESTA SEGURO QUE DESEA INGRESAR ESTS DATOS ? [S]-SI [N]-NO", "ERROR. REINGRESE: ")){
		Films_setId(nuevoEmpleado, id);
		Films_setNombre(nuevoEmpleado, nombre);
		Films_setHorasTrabajadas(nuevoEmpleado, horasTrabajadas);
		Films_setSueldo(nuevoEmpleado, sueldo);
		ll_add(pArrayListFilms, nuevoEmpleado);
		rtn=1;
	}

	controller_EscribirUltimoId();
    return rtn;
}
//
// \brief Modificar datos de empleado
// *
// * \param path char*
// * \param pArrayListFilms LinkedList*
// * \return int
// *
//
int controller_editFilms(LinkedList* pArrayListFilms)
{
	Films* emp;
	int id;
	int rtn= -1;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	id = Get_IntPositive("INGRESE EL ID DEL EMPLEADO A MODIFICAR: ", "ERROR. REINGRESE: ");
	//id--;
	emp =ll_get(pArrayListFilms, (id-1));
	if(Films_printOne(emp)!=1){
		puts("\tNO SE PUDO ENCONTRAR EL EMPLEADO CON ESE ID\n");
	}else{
		Get_String("INGRESE EL NOMBRE DEL NUEVO EMPLEADO: ", "ERROR. REINGRESE EL NOMBRE", nombre, 128);
		horasTrabajadas =Get_IntRange("INGRESE LAS HORAS TRABAJADAS: ", "ERROR. REINGRESE LAS HORAS TRABAJADAS: ", 0, 720);
		sueldo=Get_IntRange("INGRESE EL SUELDO DEL EMPLEADO: ", "ERROR. REINGRESE EL SUELDO DEL EMPLEADO: ", 10000, 100000);

		if(Validate_Exit_SN("ESTA SEGURO QUE DESEA INGRESAR ESTS DATOS ? [S]-SI [N]-NO", "ERROR. REINGRESE: ")){
			Films_setId(emp, id);
			Films_setNombre(emp, nombre);
			Films_setHorasTrabajadas(emp, horasTrabajadas);
			Films_setSueldo(emp, sueldo);
			rtn =1;
			puts("DATOS CARGADOS EXITOSAMENTE");
			Films_printOne(emp);
		}
	}
	return rtn;
}

// \brief Baja de empleado
// *
// * \param path char*
// * \param pArrayListFilms LinkedList*
// * \return int
// *
//
int controller_removeFilms(LinkedList* pArrayListFilms)
{
	int index;
	if(pArrayListFilms!= NULL){

		index = Get_IntRange("INGRESE EL INDICE DEL EMPLEADO QUE QUIERE BORRAR: ", "ERROR. REINGRESE: ", 1, ll_len(pArrayListFilms));
		index--;
		ll_remove(pArrayListFilms, index);
	}
    return 1;
}


*/
int controller_ListFilms(LinkedList* pArrayListFilms)
{
	int i;
	int id;
	char nombre[128];
	int dia;
	char horario;
	int sala;
	int cantidadEntradas;
	int len = ll_len(pArrayListFilms);
	Films* auxEmpleado =NULL;

	printf("\n");
	printf("ID, NOMBRE,         DIA,     HORARIO,   SALA,      CANTIDAD DE ENTRADAS\n");
	if(pArrayListFilms != NULL){
		for(i=0; i< len; i++)
		{
			auxEmpleado =ll_get(pArrayListFilms, i);
			if(auxEmpleado != NULL){
				Films_getId(auxEmpleado, &id);
				Films_getNombre(auxEmpleado, nombre);
				Films_getDia(auxEmpleado, &dia);
				Films_getHorario(auxEmpleado, &horario);
				Films_getSala(auxEmpleado, &sala);
				Films_getCantidadEntradas(auxEmpleado, &cantidadEntradas);
				printf("%d, %90s, %5d, %10s, %10d, %10d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->dia, auxEmpleado->horario, auxEmpleado->sala, auxEmpleado->cantidadEntradas );
			}
		}
	}
    return 1;
}

/*
int controller_sortFilms(LinkedList* pArrayListFilms)
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
	Films* Films_I = NULL;
	Films* Films_J = NULL;
	Films aux;
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

	if (pArrayListFilms != NULL) {
		switch (criterio) {
		case 1:
			puts("ESTA OPERACION PUEDE TARDAR UNOS SEGUNDOS. ESPERE, POR FAVOR");
			for (int i = 0; i < (ll_len(pArrayListFilms)  - 1); i++) {
				Films_I = ll_get(pArrayListFilms, i);
				for (int j = i + 1; j < (ll_len(pArrayListFilms)) ; j++) {
					Films_J = ll_get(pArrayListFilms, j);
					switch(opc){
					case 1:
						Films_getId(Films_I, &idI);
						Films_getId(Films_J, &idJ);
						if ( idI > idJ) {
							aux = *(Films_I);
							*(Films_I) = *(Films_J);
							*(Films_J) = aux;
							rtn = 0;
						}
						break;
					case 2:
						Films_getNombre(Films_I, nombreI);
						Films_getNombre(Films_J, nombreJ);
						if (strcmp(nombreI, nombreJ)>0) {
							aux = *(Films_I);
							*(Films_I) = *(Films_J);
							*(Films_J) = aux;
							rtn = 0;
							}
						break;
					case 3:
						Films_getHorasTrabajadas(Films_I, &horasTrabajadasI);
						Films_getHorasTrabajadas(Films_J, &horasTrabajadasJ);
						if (horasTrabajadasI > horasTrabajadasJ) {
							aux = *(Films_I);
							*(Films_I) = *(Films_J);
							*(Films_J) = aux;
							rtn = 0;
						}
						break;
					case 4:
						Films_getSueldo(Films_I, &sueldoI);
						Films_getSueldo((Films_J), &sueldoJ);
						if (sueldoI > sueldoJ) {
							aux = *(Films_I);
							*(Films_I) = *(Films_J);
							*(Films_J) = aux;
							rtn = 0;
						}
						break;
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < (ll_len(pArrayListFilms)  - 1); i++) {
				Films_I = ll_get(pArrayListFilms, i);
				for (int j = i + 1; j < ll_len(pArrayListFilms) ; j++) {
					Films_J = ll_get(pArrayListFilms, j);
					switch(opc){
					case 1:
						Films_getId(Films_I, &idI);
						Films_getId(Films_J, &idJ);
						if (idI < idJ) {
							aux = *(Films_I);
							*(Films_I) = *(Films_J);
							*(Films_J) = aux;
							rtn = 0;
						}
						break;
					case 2:
						Films_getNombre(Films_I, nombreI);
						Films_getNombre(Films_J, nombreJ);
						if (strcmp(nombreI, nombreJ)<0) {
							aux = *(Films_I);
							*(Films_I) = *(Films_J);
							*(Films_J) = aux;
							rtn = 0;
						}
						break;
					case 3:
						Films_getHorasTrabajadas(Films_I, &horasTrabajadasI);
						Films_getHorasTrabajadas(Films_J, &horasTrabajadasJ);
						if (horasTrabajadasI < horasTrabajadasJ) {
							aux = *(Films_I);
							*(Films_I) = *(Films_J);
							*(Films_J) = aux;
							rtn = 0;
						}
						break;
					case 4:
						Films_getSueldo(Films_I, &sueldoI);
						Films_getSueldo(Films_J, &sueldoJ);
						if (sueldoI < sueldoJ) {
							aux = *(Films_I);
							*(Films_I) = *(Films_J);
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
			controller_ListFilms(pArrayListFilms);
		}
	}else{
		puts("ALGO SALIÓ MAL");
	}
	return rtn;
}


int controller_saveAsText(char* path , LinkedList* pArrayListFilms)
{
	int rtn=-1;
	int cant;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	Films* emp;
	FILE* aux;

	aux = fopen(path,"w");
	if(aux != NULL){
		fprintf(aux,"ID, NOMBRE, HORAS TRABAJADAS, SUELDO\n");
		for(int i =0; i< ll_len(pArrayListFilms); i++){
			emp = ll_get(pArrayListFilms, i);
			if(emp!=NULL){
				Films_getId(emp, &id);
				Films_getNombre(emp, nombre);
				Films_getHorasTrabajadas(emp, &horasTrabajadas);
				Films_getSueldo(emp, &sueldo);
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


int controller_saveAsBinary(char* path , LinkedList* pArrayListFilms)
{
	int rtn=0;
	int validacion;
	FILE* File;
	Films* emp;
	File = fopen(path,"wb");
	if(File != NULL){
		for(int i =0; i< ll_len(pArrayListFilms); i++){
			emp = ll_get(pArrayListFilms, i);
			if(emp!=NULL){
				validacion =fwrite(emp,sizeof(Films), 1, File);
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
*/

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
