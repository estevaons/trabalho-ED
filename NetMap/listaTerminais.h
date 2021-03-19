#ifndef LISTATERMINAIS_H
#define LISTATERMINAIS_H

#include "terminal.h"

typedef struct ListaDeTerminais ListaTerm;

ListaTerm* CriaListaTerm();

ListaTerm* CadastraTerminal(Terminal* term,ListaTerm* lista); // Cadastra um terminal a lista

void RemoveTerminal(Terminal* term,ListaTerm* listaT,FILE* log); // Remove um terminal da lista

void FrequenciaTerminal(ListaTerm* listaT , char* loc,FILE* saida); // Imprime a quantidade de terminais cadastrados em uma localização

void ImprimeListaTerm(ListaTerm* listaT); // Imprime a lista de terminais

Terminal* buscaTerminal(char* nomeTerm,ListaTerm* lista, FILE* log);

void LiberaListaTerm(ListaTerm* listaT); // Libera a lista de terminais

#endif