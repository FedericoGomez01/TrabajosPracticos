#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Films.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFilms LinkedList*
 * \return int
 *
 */
int parser_FilmsFromText(FILE* pFile , LinkedList* pArrayListFilms)
{
	char buffer[6][200];
	int cant;
	int rtn =0;
	if(pFile == NULL)
	{
	  printf("No se pudo abrir el archivo. Me voy a cerrar.\n");
	  system("pause");
	  exit(EXIT_FAILURE);
	}

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,]%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4], buffer[5]);

	while( !feof(pFile) )
	{					//		1	2		3		4	5	enter
		cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4], buffer[5]);
		if( cant < 6){
			break;
		}
		//printf("%s, %90s, %5s, %10s, %10s, %10s\n", buffer[0], buffer[1],buffer[2],buffer[3],buffer[4], buffer[5]);
		Films* nuevoEmpleado = Films_newParametros(buffer[0], buffer[1],buffer[2],buffer[3],buffer[4], buffer[5]);
		//printf("%d, %90s, %5d, %10s, %10d, %10d\n", nuevoEmpleado->id, nuevoEmpleado->nombre, nuevoEmpleado->dia, nuevoEmpleado->horario, nuevoEmpleado->sala, nuevoEmpleado->cantidadEntradas );
		ll_add(pArrayListFilms, nuevoEmpleado);
		rtn ++;

	}
	if(rtn==415)
		puts("SE LEYO CORRECTAMENTE");
	return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListFilms LinkedList*
 * \return int
 *
 */
int parser_FilmsFromBinary(FILE* pFile , LinkedList* pArrayListFilms)
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
		Films* nuevoEmpleado = Films_new();
		validacion=fread(nuevoEmpleado,sizeof(Films), 1, pFile);
		if(validacion ==1){
			ll_add(pArrayListFilms, nuevoEmpleado);
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
