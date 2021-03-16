#ifndef ROTEADOR_H
#define ROTEADOR_H

typedef struct roteador Roteador;

Roteador* CriaRoteador(int id,char* nome,char* operadora); // Cria um roteador novo

int retornaIdRot(Roteador* rot);// retorna o id do roteador

char* retornaNomeRot(Roteador* rot);// retorna o nome do roteador

char* retornaOperadoraRot(Roteador* rot);// retorna a operadora do roteador

Roteador* ConectaRoteadores(Roteador* rot1,Roteador* rot2); // Cria um enlace entre o rot1 e o rot2

Roteador* DesconectaRoteadores(Roteador* rot1,Roteador* rot2);// Desfaz um enlace entre o rot1 e o rot2

void ImprimeRoteador(Roteador* rot);// imprime o roteador

void LiberaRoteador(Roteador* rot);// libera o roteador



#endif