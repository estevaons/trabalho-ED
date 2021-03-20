#ifndef LISTAENLACES_H
#define LISTAENLACES_H

#include "roteador.h"
#include "listaRoteadores.h"
#include "listaEnlaces.h"

typedef struct enlaces Enlaces;

typedef struct celula_e Celula_E;


Enlaces* criaListaEnlaces();

Celula_E* retornaPrimEnlaces(Enlaces* enlaces);

Roteador* retornaUltEnlaces(Enlaces* enlaces);

int retornaTamanhoEnlaces(Enlaces* enlaces);

Celula_E* retornaProxEnlaces(Celula_E* cel);

Roteador* retornaRotEnlaces(Celula_E* cel);

Enlaces* CadastraRoteadorEnlaces(Enlaces* listaEnlaces,Celula_E* cel);

void ConectaRoteadoresEnlaces(Celula_R* cel1,Celula_R* cel2);

void DesconectaRoteadoresEnlaces(Celula_R* cel1,Celula_R* cel2);// Desfaz um enlace entre o rot1 e o rot2

void RemoveRoteadorEnlaces(Celula_E* cel,Enlaces* lista);

Celula_E* buscaRoteadorEnlaces(Roteador* rot, Enlaces* lista, FILE* log,Roteador* rot2);

void ImprimeListaEnlaces(Enlaces* lista);

void LiberaListaEnlaces(Enlaces* lista);






#endif