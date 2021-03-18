#ifndef LISTAROTEADORES_H
#define LISTAROTEADORES_H

#include "roteador.h"

typedef struct celula_r Celula_R;
typedef struct ListaDeRoteadores ListaRot;

ListaRot* CriaListaRot();

ListaRot* CadastraRoteador(Roteador* rot,ListaRot* lista);// Cadastra o roteador na lista de roteadores

ListaRot* RemoveRoteador(Roteador* rot,ListaRot* listaR);// Remove o roteador da lista de roteadores

void FrequenciaOperadora(ListaRot* listaR,char* operadora); // Imprime a quantidade de roteadores cadastrados de uma operadora

void ImprimeListaRot(ListaRot* listaR);// Printa a lista de roteadores

void LiberaListaRot(ListaRot* listaR);// Destroi a lista de roteadores

Celula_R* retornaPrim_R(ListaRot* lista);

Celula_R* retornaProx_R(Celula_R* cel);

Celula_R* retornaUlt_R(ListaRot* lista);


#endif
