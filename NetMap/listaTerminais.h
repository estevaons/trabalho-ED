#ifndef LISTATERMINAIS_H
#define LISTATERMINAIS_H

#include "terminal.h"

typedef struct ListaDeTerminais ListaTerm;

ListaTerm* CadastraTerminal(Terminal* term); // Cadastra um terminal a lista

ListaTerm* RemoveTerminal(Terminal* term); // Remove um terminal da lista

void FrequenciaTerminal(ListaTerm* listaT , char* loc); // Imprime a quantidade de terminais cadastrados em uma localização

char* EnviaPacotesDados(Terminal* term1, Terminal* term2); // verifica se é possivel enviar dados do term1 para o term2

void ImprimeListaTerm(ListaTerm* listaT); // Imprime a lista de terminais

void LiberaListaTerm(ListaTerm* listaT); // Libera a lista de terminais

#endif