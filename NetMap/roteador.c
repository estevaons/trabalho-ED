#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "roteador.h"


struct roteador{
    int id;
    char* nome;
    char* operadora;
    ListaRot* listaEnlaces;
};

Roteador* CriaRoteador(int id,char* nome,char* operadora){
    Roteador* rot = (Roteador*)malloc(sizeof(Roteador));

    rot->id = id;
    rot->nome = strdup(nome);
    rot->operadora = strdup(operadora);

    rot->listaEnlaces = CriaListaRot();

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

ListaRot* retornaEnlaces(Roteador* rot){
    return rot->listaEnlaces;
}

void ConectaRoteadores(Roteador* rot1,Roteador* rot2){ 
    rot1->listaEnlaces = CadastraRoteador(rot2,rot1->listaEnlaces);
    rot2->listaEnlaces = CadastraRoteador(rot1,rot2->listaEnlaces);
}

void DesconectaRoteadores(Roteador* rot1,Roteador* rot2){
    RemoveRoteador(rot1,rot2->listaEnlaces);
    RemoveRoteador(rot2,rot1->listaEnlaces);
}

void ImprimeRoteador(Roteador* rot){
    printf("Nome do roteador: %s\nId do roteador: %d\nOperadora do roteador: %s\n",rot->nome,rot->id,rot->operadora);
}

void LiberaRoteador(Roteador* rot){
    free(rot->nome);
    free(rot->operadora);
    free(rot);
}
