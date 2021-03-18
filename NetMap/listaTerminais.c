#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaTerminais.h"

typedef struct celula_t Celula_T;

struct celula_t{ // Celula da lista de terminais
    Celula_T* prox;
    Terminal* term;
};


struct ListaDeTerminais{// Sentinela da lista de terminais
    Celula_T* prim;
    Celula_T* ult;
};

ListaTerm* CriaListaTerm(){
    ListaTerm* listaT = (ListaTerm*)malloc(sizeof(ListaTerm));

    listaT->prim = NULL;
    listaT->ult = NULL;

    return listaT;
}

ListaTerm* CadastraTerminal(Terminal* term,ListaTerm* lista){
    Celula_T* nova = (Celula_T*)malloc(sizeof(Celula_T));

    nova->term = term;
    nova->prox = NULL;
    lista->ult->prox = nova;
    lista->ult = nova;

    if(lista->prim==NULL){
        lista->prim = nova;
    }

    return lista;
}

void RemoveTerminal(Terminal* term,ListaTerm* listaT){
    Celula_T* p = listaT->prim;
    Celula_T* ant = NULL;
    int listaVazia = 1;

    while(p!=NULL && retornaIdTerm(p->term)!=retornaIdTerm(term)){
        ant = p;
        p = p->prox;
        listaVazia = 0;
    }

    if(p==NULL && listaVazia==0){ // não encontrou o terminal na lista
        printf("Não existe o terminal especificado no NetMap.");
        return 0;
    }

    if(p==NULL && listaVazia==1){ // lista vazia
        printf("O NetMap não contém terminais.");
        return 0;
    }

    if(p == listaT->prim && p == listaT->ult){ // unica celula
        listaT->prim = listaT->ult = NULL;
    }

    else if(p == listaT->prim){ // se for a primeira celula
        listaT->prim = p->prox;
    }

    else if(p == listaT->ult){ // se for a ultima celula
        listaT->ult = ant;
        listaT->ult->prox = NULL;
    } 

    else{ // caso comum
        ant->prox = p->prox;
    }

    free(p);
}

void FrequenciaTerminal(ListaTerm* listaT , char* loc){
    int cont = 0;
    Celula_T* p = listaT->prim;

    while(p!=NULL){
        if(strcmp(retornaLocTerm(p->term),loc)){
            cont++;
        }
    }

    printf("Existem %d terminais cadastrados em %s.",cont,loc);
}

char* EnviaPacotesDados(Terminal* term1, Terminal* term2){
    Roteador* rot1 = retornaRotTerm(term1);
    Roteador* rot2 = retornaRotTerm(term2);



    ListaRot* listaROT1 = retornaEnlaces(rot1);


    Celula_R* p;


    for(p = retornaPrim_R(listaROT1) ;p!=NULL;p = retornaProx_R(p)){

    }

    


}

void ImprimeListaTerm(ListaTerm* listaT){
    Celula_T* p;
    for(p=listaT->prim;p != NULL;p = p->prox){
        ImprimeTerminal(p->term);
    }
}

void LiberaListaTerm(ListaTerm* listaT){
    Celula_T* p = listaT->prim;
    Celula_T* t;
    

    while(p!= NULL){
        t = p->prox;
        LiberaTerminal(p->term);
        free(p);
        p = t;
    }

    free(listaT);
}
