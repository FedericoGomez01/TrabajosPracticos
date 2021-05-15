#define Employee_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblioteca.h"
#ifndef EEmployee_H_
#define EEmployee_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define TAM_ESTRUCTURA 5

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define ADMINISTRACION 1
#define DESARROLLADOR 2
#define DATABASE 3

//*** ESTRUCTURA
typedef struct {
	int idEmployee;
	char nombre[MAX_CHARS_CADENAS];
	char apellido[MAX_CHARS_CADENAS];
	float salario;
	int sector;
	int isEmpty;
} eEmployee;
//***

/** INICIO CABECERAS DE FUNCION*/
void eEmployee_Inicializar(eEmployee array[], int TAM);
/*
 * Initiate isEmpty value from my structure
 *
 * @param receive an array of type eEmployee with the size of the structure
 *
 * @return void
*/

int eEmployee_ObtenerID(int* ID_INCREMENTAL);
/*
 * Sum a value from past parameter
 *
 * @param receive a value from integer type of pointer
 *
 * @return a value increased
*/

int eEmployee_ObtenerIndexLibre(eEmployee array[], int TAM);
/*
 * Obtain the index which is free from an array
 *
 * @param receive an array of type eEmployee with the size of the structure
 *
 * @return -1 if it didn't find any or the position of array which is free
*/

int eEmployee_ObtenerIndexOcupado(eEmployee array[], int TAM);
/*
 * Obtain the index which is used from an array
 *
 * @param receive an array of type eEmployee with the size of the structure
 *
 * @return -1 if it didn't find any or the position of array which is used
*/

int eEmployee_BuscarPorID(eEmployee array[], int TAM, int ID);
/*
 * Obtain the index through ID
 *
 * @param receive an array of type eEmployee with the size of the structure and the ID received
 *
 * @return -1 if it didn't find any or the position of array with that ID
*/

void eEmployee_MostrarUno(eEmployee Employee);
/*
 * Print in the console whatever it is in the position of the array of my structure
 *
 * @param receive a position from my array of eEmployee type
 *
 * @return  -1 if it didn't find any or the position of array which is used
*/

int eEmployee_MostrarTodos(eEmployee array[], int TAM);
/*
 * Print in the console all of my structure
 *
 * @param receive an array of eEmployee type with the size of the structure
 *
 * @return  0 if it didn't find any or the quantity which shows
*/


int eEmployee_MostrarDadosDeBaja(eEmployee array[], int TAM);
/*
 * Print in the console everything which is discharged of my structure
 *
 * @param receive an array of eEmployee type with the size of the structure
 *
 * @return  0 if it didn't find any or the quantity which is discharged
*/

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eEmployee_Sort(eEmployee array[], int TAM, int criterio);
/*
 * Sort by criteria the information of employee
 *
 * @param receive an array of eEmployee type with the size of the structure and the criteria received by the user
 *
 * @return  1 if there are any errors or 0 if code works good.
*/

int ReturnSector(eEmployee Employee, char* SECTOR);
/*
 * Copy the sector at employee's array
 *
 * @param receive a position from my array of eEmployee type with the sector's pointer
 *
 * @return  1 if there are any errors or 0 if code works good.
*/
//ABM
eEmployee eEmployee_CargarDatos(void);
/*
 * Save the information received by the user.
 *
 * @param void
 *
 * @return a position of array which is eEmployee type with was charged by the user
*/
eEmployee eEmployee_ModificarUno(eEmployee Employee);
/*
 * modify a position of array which is eEmployee type
 *
 * @param receive a position from my array of eEmployee type
 *
 * @return a position of array which is eEmployee type with was charged by the user
*/
int eEmployee_Alta(eEmployee array[], int TAM, int* id);
/*
 * charge the user's information
 *
 * @param receive an array of type eEmployee with the size of the structure and the ID's pointer
 *
 * @return 0 if there are any errors or 1 if code works good.
*/
int eEmployee_Baja(eEmployee array[], int TAM);
/*
 * discharge the user's information
 *
 * @param receive an array of type eEmployee with the size of the structure
 *
 * @return 0 if there are any errors or 1 if code works good.
*/
int eEmployee_Modificacion(eEmployee array[], int TAM);
/*
 * revise that array is used and calls eEmpolyee_ModificarUno function and validates the user accepting or skipping
 *
 * @param receive an array of type eEmployee with the size of the structure
 *
 * @return 0 if there are any errors or 1 if code works good.
*/
//PROMEDIO
int eEmployee_PromedioSalario(eEmployee array[], int TAM);
/*
 * calculates the average of employee's salary and how many of theme is higher than the average
 *
 * @param receive an array of type eEmployee with the size of the structure
 *
 * @return -1 if there are any errors or 1 if code works good.
*/
/** FIN CABECERAS DE FUNCION*/
#endif

