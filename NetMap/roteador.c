#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "roteador.h"
#include "listaRoteadores.h"
#include "listaEnlaces.h"



struct roteador{
    int id;
    char* nome;
    char* operadora;
    Enlaces* listaEnlaces;
};


Roteador* CriaRoteador(int id,char* nome,char* operadora){
    Roteador* rot = (Roteador*)malloc(sizeof(Roteador));

    rot->id = id;
    rot->nome = strdup(nome);
    rot->operadora = strdup(operadora);

    rot->listaEnlaces = criaListaEnlaces();

    return rot;
}

int retornaIdRot(Roteador* rot){
    return rot->id;
}

char* retornaNomeRot(Roteador* rot){
    return rot->nome;
}

char* retornaOperadoraRot(Roteador* rot){
    return rot->operadora;
}

Enlaces* retornaEnlaces(Roteador* rot){
    return rot->listaEnlaces;
}

void ConectaRoteadores(Celula_R* cel1,Celula_R* cel2,ListaRot* listaRot1,ListaRot* listaRot2){ // ******************************************************
    listaRot1 = CadastraRoteador(listaRot1,retornaIdRot(retornaRot(cel2)),retornaNomeRot(retornaRot(cel2)),retornaOperadoraRot(retornaRot(cel2)));
    listaRot2 = CadastraRoteador(listaRot2,retornaIdRot(retornaRot(cel1)),retornaNomeRot(retornaRot(cel1)),retornaOperadoraRot(retornaRot(cel1)));
}

void DesconectaRoteadores(Celula_R* cel1,Celula_R* cel2){
    RemoveRoteador(retornaRot(cel1),retornaEnlaces(retornaRot(cel2)));
    RemoveRoteador(retornaRot(cel2),retornaEnlaces(retornaRot(cel1)));
}

void ImprimeRoteador(Roteador* rot){
    printf("Nome do roteador: %s\nId do roteador: %d\nOperadora do roteador: %s\n",rot->nome,rot->id,rot->operadora);
}

void LiberaRoteador(Roteador* rot){
    free(rot->nome);
    free(rot->operadora);
    free(rot);
}
