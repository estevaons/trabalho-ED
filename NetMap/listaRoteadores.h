#ifndef LISTAROTEADORES_H
#define LISTAROTEADORES_H

#include "roteador.h"
#include "terminal.h"

typedef struct celula_r Celula_R;

typedef struct ListaDeRoteadores ListaRot;


ListaRot* CriaListaRot();

ListaRot* CadastraRoteador(ListaRot* lista,int* idRot,char* nomeRot,char* nomeOperadora);// Cadastra o roteador na lista de roteadores

ListaRot* RemoveRoteador(Celula_R* cel,ListaRot* listaR);// Remove o roteador da lista de roteadores

void FrequenciaOperadora(ListaRot* listaR,char* operadora, FILE* saida); // Imprime a quantidade de roteadores cadastrados de uma operadora

void ImprimeListaRot(ListaRot* listaR);// Printa a lista de roteadores

Celula_R* buscaCelRot(char* nomeRot,ListaRot* lista, FILE* log);

void LiberaListaRot(ListaRot* listaR);// Destroi a lista de roteadores


#endif
