#ifndef LISTAROTEADORES_H
#define LISTAROTEADORES_H

#include "roteador.h"
#include "terminal.h"

typedef struct ListaDeRoteadores ListaRot;

ListaRot* CriaListaRot();

ListaRot* CadastraRoteador(Roteador* rot,ListaRot* lista);// Cadastra o roteador na lista de roteadores

ListaRot* RemoveRoteador(Roteador* rot,ListaRot* listaR);// Remove o roteador da lista de roteadores

void FrequenciaOperadora(ListaRot* listaR,char* operadora, FILE* saida); // Imprime a quantidade de roteadores cadastrados de uma operadora

void ImprimeListaRot(ListaRot* listaR);// Printa a lista de roteadores

void EnviaPacotesDados(Terminal* term1, Terminal* term2,ListaRot* listaR,FILE*saida); // verifica se é possivel enviar dados do term1 para o term2

Roteador* buscaRoteador(char* nomeRot,ListaRot* lista, FILE* log);

void LiberaListaRot(ListaRot* listaR);// Destroi a lista de roteadores


#endif
