#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Films.h"
#include "LinkedList.h"

Films* Films_new(){

	return (Films*)malloc(sizeof(Films));
}


Films* Films_newParametros(char* idStr,char* nombreStr,char* diaStr, char* horario, char* sala, char* cantidadEntradas){

	Films* pFilms = Films_new();
	if(idStr != NULL && nombreStr != NULL && diaStr != NULL && horario != NULL){
		if(Films_setId(pFilms, atoi(idStr)) &&
			Films_setNombre(pFilms, &(*nombreStr))&&
			Films_setDia(pFilms, atoi(diaStr))&&
			Films_setHorario(pFilms, &(*horario)) &&
			Films_setSala(pFilms, atoi(sala))&&
			Films_setCantidadEntradas(pFilms, atoi(cantidadEntradas))){

		}else{
			pFilms =NULL;
		}
	}
	return pFilms;
}

int Films_setId(Films* this,int id){

	int rtn=0;
	if(this != NULL){
		(*this).id = id;
		rtn=1;
	}
	return rtn;
}
int Films_getId(Films* this,int* id){

	int rtn=0;
	if(this != NULL){

		*id = (*this).id;
		rtn=1;
	}
	return rtn;
}

int Films_setNombre(Films* this,char* nombre){

	int rtn=0;
	if(this != NULL){
		strcpy((*this).nombre , nombre);
		rtn=1;
	}
	return rtn;
}

int Films_getNombre(Films* this,char* nombre){

	int rtn=0;
	if(this != NULL){
		strcpy(nombre,(*this).nombre);
		rtn=1;
	}
	return rtn;
}

int Films_setDia(Films* this,int dia){
	int rtn=0;
	if(this != NULL){
		(*this).dia = dia;
		rtn=1;
	}
	return rtn;
}

int Films_getDia(Films* this,int* dia){
	int rtn=0;
	if(this != NULL){
		*dia = (*this).dia;
		rtn=1;
	}
	return rtn;
}

int Films_setHorario(Films* this,char* horario){
	int rtn=0;
	if(this != NULL){

		strcpy((*this).horario, horario);
		rtn=1;
	}
	return rtn;

}
int Films_getHorario(Films* this,char* horario){
	int rtn=0;
	if(this != NULL){

		strcpy(horario, (*this).horario);
		rtn=1;
	}
	return rtn;

}

int Films_setSala(Films* this,int sala){
	int rtn=0;
	if(this != NULL){

		(*this).sala = sala;
		rtn=1;
	}
	return rtn;

}

int Films_getSala(Films* this,int* sala){
	int rtn=0;
	if(this != NULL){

		*sala =(*this).sala;
		rtn=1;
	}
	return rtn;

}


int Films_setCantidadEntradas(Films* this,int cantidadEntradas){
	int rtn=0;
	if(this != NULL){

		(*this).cantidadEntradas = cantidadEntradas;
		rtn=1;
	}
	return rtn;
}

int Films_getCantidadEntradas(Films* this,int* cantidadEntradas){
	int rtn=0;
	if(this != NULL){

		*cantidadEntradas =(*this).cantidadEntradas;
		rtn=1;
	}
	return rtn;

}

int Films_printOne(Films* this){

	int rtn =-1;

	if(this != NULL){
		printf("ID -  NOMBRE - horario - sala - cantidadEntradas\n");
		printf("%d, %5s, %10s, %10d, %10d\n", (*this).id, (*this).nombre,(*this).horario,(*this).sala, (*this).cantidadEntradas);
		rtn =1;
	}
	return rtn;
}

