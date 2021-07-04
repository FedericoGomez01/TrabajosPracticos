#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option;
    int flagGuardado=0;
    LinkedList* listaEmpleados = ll_newLinkedList();


    do{
    	int idAutoincremental = controller_leeUltimoId();
    	Menu("\n=================================================================================\n"
			 "                                     MENU                                        \n"
			 "=================================================================================\n"
			"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
			"2. Cargar los datos de los empleados desde el archivo datab.bin (modo binario).\n"
			"3. Alta de empleado\n"
			"4. Modificar datos de empleado\n"
			"5. Baja de empleado\n"
			"6. Listar empleados\n"
			"7. Ordenar empleados\n"
			"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
			"9. Guardar los datos de los empleados en el archivo datab.bin (modo binario).\n"
			"10. Salir\n");
    	option = Get_IntRange("INICIE EL MENU: ", "ERROR. REINGRESE: ", 1, 10);
		switch(option)
        {
            case 1:
            	if(ll_len(listaEmpleados)>0 && listaEmpleados!=NULL){
                	if(Validate_Exit_SN("DESEA SOBREESCRIBIR LOS DATOS CARGADOS?: [S]-SI [N]-NO", "ERROR. REINGRESE: ")){
                		ll_clear(listaEmpleados);
                		controller_loadFromText("datos.csv",listaEmpleados);
                    	break;
                	}else{
                    	controller_loadFromText("datos.csv",listaEmpleados);
                	}
            	}else{
                	controller_loadFromText("datos.csv",listaEmpleados);
            	}
                break;
            case 2:
            	if(ll_len(listaEmpleados)>0 && listaEmpleados!=NULL){
                	if(Validate_Exit_SN("DESEA SOBREESCRIBIR LOS DATOS CARGADOS?: [S]-SI [N]-NO", "ERROR. REINGRESE: ")){
                		ll_clear(listaEmpleados);
                		controller_loadFromBinary("datab.bin", listaEmpleados);;
                    	break;
                	}else{
                    	controller_loadFromBinary("datab.bin", listaEmpleados);;
                	}
            	}else{
                	controller_loadFromBinary("datab.bin", listaEmpleados);;
            	}
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados, idAutoincremental);
            	break;
            case 4:
            	if(ll_len(listaEmpleados)>0 && listaEmpleados!=NULL){
            		controller_editEmployee(listaEmpleados);
            	}else{
            		puts("DEBE CARGAR UNA LISTA DE EMPLEADOS");
            	}
                break;
            case 5:
            	if(ll_len(listaEmpleados)>0 && listaEmpleados!=NULL){
					controller_removeEmployee(listaEmpleados);
            	}else{
            		puts("DEBE CARGAR UNA LISTA DE EMPLEADOS");
            	}
            	break;
            case 6:
            	if(ll_len(listaEmpleados)>0 && listaEmpleados!=NULL){
            		controller_ListEmployee(listaEmpleados);
            	}else{
            		puts("DEBE CARGAR UNA LISTA DE EMPLEADOS");
            	}
            	break;
            case 7:
            	if(ll_len(listaEmpleados)>0 && listaEmpleados!=NULL){
            		controller_sortEmployee(listaEmpleados);
            	}else{
            		puts("DEBE CARGAR UNA LISTA DE EMPLEADOS");
            	}
                break;
            case 8:
            	if(ll_len(listaEmpleados)>0 && listaEmpleados!=NULL){
            		controller_saveAsText("dataCopia.csv", listaEmpleados);
            		flagGuardado=1;
            	}else{
            		puts("DEBE CARGAR UNA LISTA DE EMPLEADOS");
            	}
            	break;
            case 9:
            	if(ll_len(listaEmpleados)>0 && listaEmpleados!=NULL){
            		controller_saveAsBinary("datab.bin", listaEmpleados);
            		flagGuardado=1;
            	}else{
            		puts("DEBE CARGAR UNA LISTA DE EMPLEADOS");
            	}
            	break;
            case 10:
            	if(ll_len(listaEmpleados)>0 && listaEmpleados!=NULL){
            		if(flagGuardado!=1){
            			if(Validate_Exit_SN("DESEA SALIR SIN GUARDAR? [S]-SI  [N]-NO", "ERROR. REINGRESE: ")){
							ll_deleteLinkedList(listaEmpleados);
            				option =10;
						}else{

							Menu("\n=================================================================================\n"
								 "                                     MENU                                        \n"
								 "=================================================================================\n"
								"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
								"2. Cargar los datos de los empleados desde el archivo datab.bin (modo binario).\n"
								"3. Alta de empleado\n"
								"4. Modificar datos de empleado\n"
								"5. Baja de empleado\n"
								"6. Listar empleados\n"
								"7. Ordenar empleados\n"
								"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
								"9. Guardar los datos de los empleados en el archivo datab.bin (modo binario).\n"
								"10. Salir\n");
							option = Get_IntRange("INICIE EL MENU: ", "ERROR. REINGRESE: ", 1, 10);
						}
            		}else{
            			option =10;
						ll_deleteLinkedList(listaEmpleados);
            		}
            	}
            	break;
        }
    }while(option != 10);
    puts("GRACIAS POR USAR EL PROGRAMA!");
    return 0;
}

