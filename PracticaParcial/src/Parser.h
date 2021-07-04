#ifndef PARSER_H_
#define PARSER_H_

int parser_FilmsFromText(FILE* pFile , LinkedList* pArrayListFilms);

int parser_FilmsFromBinary(FILE* pFile , LinkedList* pArrayListFilms);

int parser_obterenUltimoId(FILE* pFile);


#endif /* PARSER_H_ */
