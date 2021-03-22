#ifndef terminal_h
#define terminal_h

#include "listaRoteadores.h"


typedef struct terminal Terminal;

Terminal* CriaTerminal(int id,char* nome,char* loc); // Cria um terminal novo

int retornaIdTerm(Terminal* term); // retorna o id do terminal

char* retornaNomeTerm(Terminal* term); // retorna o nome do terminal

Celula_R* retornaCelRTerm(Terminal* term);

char* retornaLocTerm(Terminal* term); // retorna a localizaçao do terminal

void ImprimeTerminal(Terminal* term); // imprime um terminal

void LiberaTerminal(Terminal* term); // libera um terminal

#endif