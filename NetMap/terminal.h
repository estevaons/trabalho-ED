#ifndef TERMINAL_H
#define TERMINAL_H

#include "roteador.h"


typedef struct terminal Terminal;

Terminal* CriaTerminal(int id,char* nome,char* loc); // Cria um terminal novo

int retornaIdTerm(Terminal* term); // retorna o id do terminal

char* retornaNomeTerm(Terminal* term); // retorna o nome do terminal

char* retornaLocTerm(Terminal* term); // retorna a localizaçao do terminal

Celula_R* retornaCelRTerm(Terminal* term); // retorna celula de roteador pro terminal

Roteador* retornaRotTerm(Terminal* term); // retorna o roteador conectado ao terminal

void DesconectaTerminal(Terminal* term); //  desconecta um terminal de um roteador

void ImprimeTerminal(Terminal* term); // imprime um terminal

void LiberaTerminal(Terminal* term); // libera um terminal

#endif