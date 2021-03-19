#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "listaRoteadores.h"

typedef struct roteador Roteador;

Roteador* CriaRoteador(int id,char* nome,char* operadora); // Cria um roteador novo

Roteador* retornaRot(Celula_R* cel);

int retornaIdRot(Roteador* rot);// retorna o id do roteador

char* retornaNomeRot(Roteador* rot);// retorna o nome do roteador

char* retornaOperadoraRot(Roteador* rot);// retorna a operadora do roteador

ListaRot* retornaEnlaces(Roteador* rot); // retorna a lista dos enlaces do roteador

void ConectaRoteadores(Celula_R* cel1,Celula_R* cel2,ListaRot* listaRot1,ListaRot* listaRot2); // Cria um enlace entre o rot1 e o rot2

void DesconectaRoteadores(Celula_R* cel1,Celula_R* cel2);// Desfaz um enlace entre o rot1 e o rot2

void ImprimeRoteador(Roteador* rot);// imprime o roteador

void LiberaRoteador(Roteador* rot);// libera o roteador



#endif