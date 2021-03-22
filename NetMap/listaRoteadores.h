#ifndef listaRoteadores_h
#define listaRoteadores_h

#include "roteador.h"


typedef struct celula_r Celula_R;

typedef struct ListaDeRoteadores ListaRot;


ListaRot* CriaListaRot();

ListaRot* CadastraRoteador(ListaRot* lista,int* idRot,char* nomeRot,char* nomeOperadora);// Cadastra o roteador na lista de roteadores

ListaRot* RemoveRoteador(Celula_R* cel,ListaRot* listaR);// Remove o roteador da lista de roteadores

void FrequenciaOperadora(ListaRot* listaR,char* operadora, FILE* saida); // Imprime a quantidade de roteadores cadastrados de uma operadora

Roteador* retornaRot(Celula_R* cel);

void ConectaRoteadoresEnlaces(Celula_R* cel1,Celula_R* cel2);

void DesconectaRoteadoresEnlaces(Celula_R* cel1,Celula_R* cel2,FILE* log);

void ImprimeListaRot(ListaRot* listaR);// Printa a lista de roteadores

Celula_R* buscaCelRot(char* nomeRot,ListaRot* lista, FILE* log);

int verificaRoteador(Celula_R* cel,ListaRot* lista);

void LiberaListaRot(ListaRot* listaR);// Destroi a lista de roteadores


#endif
