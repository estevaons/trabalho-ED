#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "listaRoteadores.h"
#include "listaEnlaces.h"

typedef struct roteador Roteador;

typedef struct enlaces Enlaces;

Roteador* CriaRoteador(int id,char* nome,char* operadora); // Cria um roteador novo

Roteador* retornaRot(Celula_R* cel);

int retornaIdRot(Roteador* rot);// retorna o id do roteador

char* retornaNomeRot(Roteador* rot);// retorna o nome do roteador

char* retornaOperadoraRot(Roteador* rot);// retorna a operadora do roteador

Enlaces* retornaEnlaces(Roteador* rot); // retorna a lista dos enlaces do roteador


void ImprimeRoteador(Roteador* rot);// imprime o roteador

void LiberaRoteador(Roteador* rot);// libera o roteador



#endif