#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "roteador.h"
#include "listaRoteadores.h"
#include "listaEnlaces.h"

struct celula_e{
    Celula_E* prox;
    Roteador* rot;
};

struct enlaces{
    Celula_E* prim;
    Celula_E* ult;
    int *tamanho;
};


Celula_E* retornaPrimEnlaces(Enlaces* enlaces){
    return enlaces->prim;
}

Roteador* retornaUltEnlaces(Enlaces* enlaces){
    return enlaces->ult;
}

int retornaTamanhoEnlaces(Enlaces* enlaces){
    return enlaces->tamanho;
}

Celula_E* retornaProxEnlaces(Celula_E* cel){
    return cel->prox;
}

Roteador* retornaRotEnlaces(Celula_E* cel){
    return cel->rot;
}

Enlaces* criaListaEnlaces(){
    Enlaces* listaEnlaces = (Enlaces*)malloc(sizeof(Enlaces));

    listaEnlaces->prim = NULL;
    listaEnlaces->ult = NULL;

    listaEnlaces->tamanho = 0;

    return listaEnlaces;
}

Enlaces* CadastraRoteadorEnlaces(Enlaces* listaEnlaces,Celula_E* cel){
    cel->prox = NULL;
    listaEnlaces->ult->prox = cel;
    listaEnlaces->ult = cel;

    if(listaEnlaces->prim==NULL){
        listaEnlaces->prim = cel;
    }

    listaEnlaces->tamanho = *(listaEnlaces->tamanho) + 1;

    return listaEnlaces;
}

void ConectaRoteadoresEnlaces(Celula_R* cel1,Celula_R* cel2){  
    Celula_E* nova1 = (Celula_E*)malloc(sizeof(Celula_E));
    nova1->rot = retornaRot(cel1);  

    Celula_E* nova2 = (Celula_E*)malloc(sizeof(Celula_E));
    nova2->rot = retornaRot(cel2);


    Enlaces* listaEnlaces1 = retornaEnlaces(retornaRot(cel1));
    Enlaces* listaEnlaces2 = retornaEnlaces(retornaRot(cel2));

    listaEnlaces1 = CadastraRoteadorEnlaces(listaEnlaces1, nova2);

    listaEnlaces2 = CadastraRoteadorEnlaces(listaEnlaces2, nova1);
   
}

Celula_E* buscaRoteadorEnlaces(Roteador* rot, Enlaces* lista, FILE* log,Roteador* rot2){
    int idRot = retornaIdRot(rot);

    Celula_E* p;
    int existeRot = 0;
    int listaVazia = 1;
    Roteador* rotP;

    for(p=lista->prim;p!=NULL;p=p->prox){
        listaVazia = 0;
        rotP = p->rot;
        if(retornaIdRot(p->rot)==idRot){
            return p;
            existeRot = 1;      
        }
    }
    if(existeRot==0 && listaVazia == 0){
        fprintf(log,"ERRO: O roteador %s nao esta conectado com o roteador %s.\n",retornaNomeRot(rot),retornaNomeRot(rot2));   
        return NULL;           
     }

    else if(listaVazia == 1){
        fprintf(log,"O roteador %s nao possui conexoes.\n",retornaNomeRot(rot2)); 
        return NULL;      
     }
}
    


void RemoveRoteadorEnlaces(Celula_E* cel,Enlaces* lista){
    Celula_E* p = lista->prim;
    Celula_E* ant = NULL;

    while(p!=NULL && retornaIdRot(p->rot)!=retornaIdRot(retornaRot(cel))){
        ant = p;
        p = p->prox;
    }

    if(p == lista->prim && p == lista->ult){ // unica celula
        lista->prim = lista->ult = NULL;
    }

    else if(p == lista->prim){ // se for a primeira celula
        lista->prim = p->prox;
    }

    else if(p == lista->ult){ // se for a ultima celula
        lista->ult = ant;
        lista->ult->prox = NULL;
    } 

    else{ // caso comum
        ant->prox = p->prox;
    }

    free(p);

}

void DesconectaRoteadoresEnlaces(Celula_R* cel1,Celula_R* cel2,FILE* log){

    Roteador* rot1 = retornaRot(cel1);
    Roteador* rot2 = retornaRot(cel2);

    Enlaces* listaEnlaces1 = retornaEnlaces(rot1);
    Enlaces* listaEnlaces2 = retornaEnlaces(rot2);

    Celula_E* cel_E_lista1 = buscaRoteadorEnlaces(rot2,listaEnlaces1,log,rot1);
    
    Celula_E* cel_E_lista2 = buscaRoteadorEnlaces(rot1,listaEnlaces2,log,rot2);


    RemoveRoteadorEnlaces(cel_E_lista1,listaEnlaces2); // remover uma celula_E de uma lista de enlaces de um roteador
    RemoveRoteadorEnlaces(cel_E_lista2,listaEnlaces1); 
    
}

void ImprimeListaEnlaces(Enlaces* lista){ // Printa a lista de enlaces *******ANALISAR DNV temos que imprimir de tras pra frente
    Celula_E* p;
    for(p=lista->prim;p != NULL;p = p->prox){
        ImprimeRoteador(p->rot);
    }
}

void LiberaListaEnlaces(Enlaces* lista){ // Destroi a lista de roteadores
    Celula_E* p = lista->prim;
    Celula_E* t;

    while(p!= NULL){
        t = p->prox;
        LiberaRoteador(p->rot);
        free(p);
        p = t;
    }

    free(lista);
}



