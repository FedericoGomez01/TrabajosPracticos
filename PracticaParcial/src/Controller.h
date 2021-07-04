int controller_loadFromText(LinkedList* pArrayListFilms);
int controller_loadFromBinary(char* path , LinkedList* pArrayListFilms);
int controller_addFilms(LinkedList* pArrayListFilms, int id);
int controller_editFilms(LinkedList* pArrayListFilms);
int controller_removeFilms(LinkedList* pArrayListFilms);
int controller_ListFilms(LinkedList* pArrayListFilms);
int controller_sortFilms(LinkedList* pArrayListFilms);
int controller_saveAsText(char* path , LinkedList* pArrayListFilms);
int controller_saveAsBinary(char* path , LinkedList* pArrayListFilms);

int controller_leeUltimoId();
void controller_EscribirUltimoId();
