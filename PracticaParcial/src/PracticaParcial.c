#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Films.h"

/****************************************************
    Menu:
     1. Cargar los datos de los PELICULAS desde el archivo MOCK_DATA.csv (modo texto).
     2. Cargar los datos de los PELICULAS desde el archivo MOCK_DATA.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar PELICULAS
     7. Ordenar PELICULAS
     8. Guardar los datos de los PELICULAS en el archivo MOCK_DATA.csv (modo texto).
     9. Guardar los datos de los PELICULAS en el archivo MOCK_DATA.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option;
    LinkedList* listaPELICULAS = ll_newLinkedList();


    do{
    	Menu("\n=================================================================================\n"
			 "                                     MENU                                        \n"
			 "=================================================================================\n"
			"1. Cargar los datos de los PELICULAS desde el archivo MOCK_DATA.csv (modo texto).\n"
			"2. Imprimir ventas\n"
			"3. Generar archivo de montos\n"
			"4. Informes\n"
			"5. Salir\n"
			"6. Imprimir todo");
    	option = Get_IntRange("INICIE EL MENU: ", "ERROR. REINGRESE: ", 1, 6);
		switch(option)
        {
            case 1:
				controller_loadFromText(listaPELICULAS);
                break;
            case 2:
            	//controller_ventas(listaPELICULAS);
            	break;
            case 3:

            	break;
            case 4:

                break;
            case 7:
            	if(ll_len(listaPELICULAS)>0 && listaPELICULAS!=NULL){
					//controller_removeFilms(listaPELICULAS);
            	}else{
            		puts("DEBE CARGAR UNA LISTA DE PELICULAS");
            	}
            	break;
            case 6:
            	if(ll_len(listaPELICULAS)>0 && listaPELICULAS!=NULL){
            		controller_ListFilms(listaPELICULAS);
            	}else{
            		puts("DEBE CARGAR UNA LISTA DE PELICULAS");
            	}
            	break;
//            case 7:
//            	if(ll_len(listaPELICULAS)>0 && listaPELICULAS!=NULL){
//            		//controller_sortFilms(listaPELICULAS);
//            	}else{
//            		puts("DEBE CARGAR UNA LISTA DE PELICULAS");
//            	}
//                break;
//            case 8:
//            	if(ll_len(listaPELICULAS)>0 && listaPELICULAS!=NULL){
//            		//controller_saveAsText("MOCK_DATACopia.csv", listaPELICULAS);
//            		flagGuardado=1;
//            	}else{
//            		puts("DEBE CARGAR UNA LISTA DE PELICULAS");
//            	}
//            	break;
//            case 9:
//            	if(ll_len(listaPELICULAS)>0 && listaPELICULAS!=NULL){
//            		//controller_saveAsBinary("MOCK_DATAb.bin", listaPELICULAS);
//            		flagGuardado=1;
//            	}else{
//            		puts("DEBE CARGAR UNA LISTA DE PELICULAS");
//            	}
//            	break;
            case 5:
				option =5;
				ll_deleteLinkedList(listaPELICULAS);
            	break;
        }
    }while(option != 5);
    puts("GRACIAS POR USAR EL PROGRAMA!");
    return 0;
}

