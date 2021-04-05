#ifndef roteador_h
#define roteador_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct roteador Roteador;

typedef struct enlaces Enlaces;


typedef struct celula_e Celula_E;




void adicionaRotCelE(Celula_E* cel, Roteador* roteador);

Enlaces* criaListaEnlaces(); // cria a lista de enlaces de um roteador

Celula_E* retornaPrimEnlaces(Enlaces* enlaces); // retorna a primeira celula da lista de enlaces de um roteador

Roteador* retornaRotEnlaces(Celula_E* cel); // retorna o roteador de uma celula de uma lista de enlaces

Celula_E* retornaUltEnlaces(Enlaces* enlaces); // retorna a ultima celula da lista de enlaces de um roteador

int* retornaTamanhoEnlaces(Enlaces* enlaces); // retorna o tamanho da lista de enlaces de um roteador

Celula_E* retornaProxEnlaces(Celula_E* cel); // retorna a proxima celula de uma lista de enlaces de um roteador

Enlaces* CadastraRoteadorEnlaces(Enlaces* listaEnlaces,Celula_E* cel); // cadastra um roteador em uma lista de enlaces de outro roteador

size_t tamanhoCelE(); // retorna o tamanho da celula E

void setarListaEnlaces(Enlaces* lista1,Enlaces* lista2);

Celula_E* verificaListaEnlaces(Roteador* rot,Enlaces* lista);

void RemoveRoteadorEnlaces(Celula_E* cel,Enlaces* lista); // remove um roteador de uma lista de enlaces de outro roteador

Celula_E* buscaRoteadorEnlaces(Roteador* rot, Enlaces* lista, FILE* log, Roteador* rot2); // busca um roteador na lista de enlaces de outro roteador

void ImprimeListaEnlaces(Enlaces* lista); // imprime a lista de enlaces de um roteador

Roteador* CriaRoteador(int id,char* nome,char* operadora); // Cria um roteador novo

Enlaces* retornaEnlaces(Roteador* rot); // retorna a lista dos enlaces do roteador

void ConectaRoteadoresEnlaces(Roteador* rot1,Roteador* rot2);

int retornaIdRot(Roteador* rot);// retorna o id do roteador

char* retornaNomeRot(Roteador* rot);// retorna o nome do roteador

char* retornaOperadoraRot(Roteador* rot);// retorna a operadora do roteador

void ImprimeRoteador(Roteador* rot);// imprime o roteador

void LiberaRoteador(Roteador* rot);// libera o roteador

void adicionaProxCelE(Celula_E* cel1, Celula_E* cel2);

void adicionaPrimEnlaces(Celula_E* cel,Enlaces* lista);

void adicionaUltEnlaces(Celula_E* cel,Enlaces* lista);

void ImprimeRoteadorDOT(Roteador* rot,FILE* dot);

void ImprimeListaEnlacesDOT(Enlaces* lista,FILE* dot,Roteador* rot);

void EnviaPacotesDados(Roteador* rot1,Roteador* rot2,FILE*saida, char* nomeTerm1, char* nomeTerm2);

int analisaListaEnlaces(Roteador* rot, Enlaces* lista);

int verificaVetorID(int id,int* vet, int* tam);

void LiberaRoteadorEnlaces(Roteador* rot);

#endif