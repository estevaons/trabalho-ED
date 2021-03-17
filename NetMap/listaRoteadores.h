#ifndef LISTAROTEADORES_H
#define LISTAROTEADORES_H

#include "roteador.h"

typedef struct ListaDeRoteadores ListaRot;

ListaRot* CriaListaRot();

ListaRot* CadastraRoteador(Roteador* rot,ListaRot* lista);// Cadastra o roteador na lista de roteadores

ListaRot* RemoveRoteador(Roteador* rot,ListaRot* listaR);// Remove o roteador da lista de roteadores

void FrequenciaOperadora(ListaRot* listaR,char* operadora); // Imprime a quantidade de roteadores cadastrados de uma operadora

void ImprimeListaRot(ListaRot* listaR);// Printa a lista de roteadores

void LiberaListaRot(ListaRot* listaR);// Destroi a lista de roteadores


#endif
