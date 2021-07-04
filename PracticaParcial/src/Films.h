#ifndef FILMS_H_
#define FILMS_H_

typedef struct
{
    int id;
    char nombre[200];
    int dia;
    char horario[200];
    int sala;
    int cantidadEntradas;
}Films;

Films* Films_new();
Films* Films_newParametros(char* idStr,char* nombreStr,char* diaStr, char* horario, char* sala, char* cantidadEntradas);
void Films_delete();

int Films_setId(Films* this,int id);
int Films_getId(Films* this,int* id);

int Films_setNombre(Films* this,char* nombre);
int Films_getNombre(Films* this,char* nombre);

int Films_setDia(Films* this,int dia);
int Films_getDia(Films* this,int* dia);


int Films_setHorario(Films* this,char* horario);
int Films_getHorario(Films* this,char* horario);

int Films_setSala(Films* this,int sala);
int Films_getSala(Films* this,int* sala);

int Films_setCantidadEntradas(Films* this,int cantidadEntradas);
int Films_getCantidadEntradas(Films* this,int* cantidadEntradas);


int Films_printOne(Films* this);



#endif /* FILMS_H_ */
