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
	FILE* f;
	char buffer[4][20];
	Employee* lista = employee_new();
	int cant;
	int rtn =0;
	f = fopen("data.csv","r");
	if(f == NULL)
	{
	  printf("No se pudo abrir el archivo. Me voy a cerrar.\n");
	  system("pause");
	  exit(EXIT_FAILURE);
	}

	fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
	//printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);

	while( !feof(f) )
	{
		cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		if( cant < 4){
			break;
		}
		Employee* nuevoEmpleado = employee_newParametros(buffer[0], buffer[1],buffer[2],buffer[3]);
		ll_add(pArrayListEmployee, nuevoEmpleado);
		rtn =1;

	}
	fclose(f);
	free(lista);
	if(rtn==1)
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
	FILE* f;
	int rtn =0;
	f = fopen("datab.bin","rb");
	if(f == NULL)
	{
	  printf("No se pudo abrir el archivo.\n");
	  system("pause");
	  exit(EXIT_FAILURE);
	}

	while( !feof(f) )
	{
		Employee* nuevoEmpleado = employee_new();
		fread(nuevoEmpleado,sizeof(Employee), 1, f);
		ll_add(pArrayListEmployee, nuevoEmpleado);
		rtn ++;
	}
	printf("ento al while %d",rtn);
	if(rtn==1)
		puts("SE LEYO CORRECTAMENTE");
	fclose(f);
	return rtn;
}
