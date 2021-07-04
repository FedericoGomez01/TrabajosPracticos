#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new(){

	return (Employee*)malloc(sizeof(Employee));
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo){

	Employee* pEmployee = employee_new();

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldo != NULL){
		if(employee_setId(pEmployee, atoi(idStr)) && employee_setNombre(pEmployee, &(*nombreStr))&&
		employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr))&&
		employee_setSueldo(pEmployee, atoi(sueldo))){

		}else{
			pEmployee =NULL;
		}
	}

	return pEmployee;
}

int employee_setId(Employee* this,int id){

	int rtn=0;
	if(this != NULL){

		(*this).id = id;
		rtn=1;
	}
	return rtn;
}
int employee_getId(Employee* this,int* id){

	int rtn=0;
	if(this != NULL){

		*id = (*this).id;
		rtn=1;
	}
	return rtn;
}

int employee_setNombre(Employee* this,char* nombre){

	int rtn=0;
	if(this != NULL){
		strcpy((*this).nombre , nombre);
		rtn=1;
	}
	return rtn;
}

int employee_getNombre(Employee* this,char* nombre){

	int rtn=0;
	if(this != NULL){
		strcpy(nombre,(*this).nombre);
		rtn=1;
	}
	return rtn;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int rtn=0;
	if(this != NULL){

		(*this).horasTrabajadas = horasTrabajadas;
		rtn=1;
	}
	return rtn;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int rtn=0;
	if(this != NULL){

		*horasTrabajadas =(*this).horasTrabajadas;
		rtn=1;
	}
	return rtn;

}

int employee_setSueldo(Employee* this,int sueldo){
	int rtn=0;
	if(this != NULL){

		(*this).sueldo = sueldo;
		rtn=1;
	}
	return rtn;

}

int employee_getSueldo(Employee* this,int* sueldo){
	int rtn=0;
	if(this != NULL){

		*sueldo =(*this).sueldo;
		rtn=1;
	}
	return rtn;

}

int employee_printOne(Employee* this){

	int rtn =-1;

	if(this != NULL){
		printf("ID -  NOMBRE - HS.TRABAJADAS - SUELDO\n");
		printf("%d, %5s, %10d, %10d\n", (*this).id, (*this).nombre,(*this).horasTrabajadas,(*this).sueldo);
		rtn =1;
	}
	return rtn;
}

