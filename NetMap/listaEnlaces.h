#ifndef listaEnlaces_h
#define listaEnlaces_h


#include "roteador.h"

typedef struct enlaces Enlaces;

typedef struct celula_e Celula_E;

Enlaces* criaListaEnlaces();

Celula_E* retornaPrimEnlaces(Enlaces* enlaces);

Roteador* retornaRotEnlaces(Celula_E* cel); // ERRO !

//Roteador* retornaUltEnlaces(Enlaces* enlaces);

int* retornaTamanhoEnlaces(Enlaces* enlaces);

Celula_E* retornaProxEnlaces(Celula_E* cel);

Enlaces* CadastraRoteadorEnlaces(Enlaces* listaEnlaces,Celula_E* cel);

size_t tamanhoCelE();

void RemoveRoteadorEnlaces(Celula_E* cel,Enlaces* lista);

Celula_E* buscaRoteadorEnlaces(Roteador* rot, Enlaces* lista, FILE* log,Roteador* rot2);

void ImprimeListaEnlaces(Enlaces* lista);

void LiberaListaEnlaces(Enlaces* lista);



#endif