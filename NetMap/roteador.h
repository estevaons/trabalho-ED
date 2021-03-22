#ifndef roteador_h
#define roteador_h

#include "listaEnlaces.h"

typedef struct roteador Roteador;


Roteador* CriaRoteador(int** id,char* nome,char* operadora); // Cria um roteador novo

Enlaces* retornaEnlaces(Roteador* rot); // retorna a lista dos enlaces do roteador

int retornaIdRot(Roteador* rot);// retorna o id do roteador

char* retornaNomeRot(Roteador* rot);// retorna o nome do roteador

char* retornaOperadoraRot(Roteador* rot);// retorna a operadora do roteador

void ImprimeRoteador(Roteador* rot);// imprime o roteador

void LiberaRoteador(Roteador* rot);// libera o roteador



#endif