#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char buffer[4][20];
	int cant;
	int rtn =0;
	if(pFile == NULL)
	{
	  printf("No se pudo abrir el archivo. Me voy a cerrar.\n");
	  system("pause");
	  exit(EXIT_FAILURE);
	}

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

	while( !feof(pFile) )
	{
		cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		if( cant < 4){
			break;
		}
		Employee* nuevoEmpleado = employee_newParametros(buffer[0], buffer[1],buffer[2],buffer[3]);
		ll_add(pArrayListEmployee, nuevoEmpleado);
		rtn ++;
	}
	if(rtn==1000)
		puts("SE LEYO CORRECTAMENTE");
	return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn =0;
	int validacion;
	if(pFile == NULL)
	{
	  printf("No se pudo abrir el archivo.\n");
	  system("pause");
	  exit(EXIT_FAILURE);
	}

	while( !feof(pFile) )
	{
		Employee* nuevoEmpleado = employee_new();
		validacion=fread(nuevoEmpleado,sizeof(Employee), 1, pFile);
		if(validacion ==1){
			ll_add(pArrayListEmployee, nuevoEmpleado);
			rtn ++;
		}
	}
	if(rtn==1000)
		puts("SE LEYO CORRECTAMENTE");
	return rtn;
}

int parser_obterenUltimoId(FILE* pFile){

	int id;
	char buffer[2000];
	if(pFile != NULL){
		fgets(buffer,2000,pFile);
		id=atoi(buffer);
	}
	return id;
}
