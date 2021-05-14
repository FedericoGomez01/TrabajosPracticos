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
int eEmployee_ObtenerID(int* ID_INCREMENTAL);
int eEmployee_ObtenerIndexLibre(eEmployee array[], int TAM);
int eEmployee_ObtenerIndexOcupado(eEmployee array[], int TAM);
int eEmployee_BuscarPorID(eEmployee array[], int TAM, int ID);
void eEmployee_MostrarUno(eEmployee Employee);
int eEmployee_MostrarTodos(eEmployee array[], int TAM);
int eEmployee_MostrarDadosDeBaja(eEmployee array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eEmployee_Sort(eEmployee array[], int TAM, int criterio);
int ReturnSector(eEmployee Employee, char* SECTOR);
//ABM
eEmployee eEmployee_CargarDatos(void);
eEmployee eEmployee_ModificarUno(eEmployee Employee);
int eEmployee_Alta(eEmployee array[], int TAM, int* id);
int eEmployee_Baja(eEmployee array[], int TAM);
int eEmployee_Modificacion(eEmployee array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif

