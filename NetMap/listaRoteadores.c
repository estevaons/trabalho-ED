#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaRoteadores.h"

typedef struct celula_r Celula_R;

struct celula_r{ // Celula da lista de roteadores
    Celula_R* prox;
    Roteador* rot;
};


struct ListaDeRoteadores{// Sentinela da lista de roteadores
    Celula_R* prim;
    Celula_R* ult;
};

ListaRot* CriaListaRot(){
    ListaRot* lista = (ListaRot*)malloc(sizeof(ListaRot));

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

ListaRot* CadastraRoteador(Roteador* rot,ListaRot* lista){
    Celula_R* nova = (Celula_R*)malloc(sizeof(Celula_R));

    nova->rot = rot;
    nova->prox = NULL;
    lista->ult->prox = nova;
    lista->ult = nova;

    if(lista->prim==NULL){
        lista->prim = nova;
    }

    return lista;
}

void RemoveRoteador(Roteador* rot,ListaRot* listaR){
    Celula_R* p = listaR->prim;
    Celula_R* ant = NULL;
    int listaVazia = 1;

    while(p!=NULL && retornaIdRot(p->rot)!=retornaIdRot(rot)){
        ant = p;
        p = p->prox;
        listaVazia = 0;
    }

    if(p==NULL && listaVazia==0){ // não encontrou o roteador na lista
        printf("Não existe o roteador especificado no NetMap.");
        return 0;
    }

    if(p==NULL && listaVazia==1){ // lista vazia
        printf("O NetMap não contém roteadores.");
        return 0;
    }

    if(p == listaR->prim && p == listaR->ult){ // unica celula
        listaR->prim = listaR->ult = NULL;
    }

    else if(p == listaR->prim){ // se for a primeira celula
        listaR->prim = p->prox;
    }

    else if(p == listaR->ult){ // se for a ultima celula
        listaR->ult = ant;
        listaR->ult->prox = NULL;
    } 

    else{ // caso comum
        ant->prox = p->prox;
    }

    free(p);

}

void FrequenciaOperadora(ListaRot* listaR,char* operadora){ // Imprime a quantidade de roteadores cadastrados de uma operadora
    int cont = 0;
    Celula_R* p = listaR->prim;

    while(p!=NULL){
        if(strcmp(retornaOperadoraRot(p->rot),operadora)){
            cont++;
        }
    }

    printf("Existem %d roteadores cadastrados da operadora %s.",cont,operadora);
}

void ImprimeListaRot(ListaRot* listaR){ // Printa a lista de roteadores
    Celula_R* p;
    for(p=listaR->prim;p != NULL;p = p->prox){
        ImprimeRoteador(p->rot);
    }
}

void LiberaListaRot(ListaRot* listaR){ // Destroi a lista de roteadores
    Celula_R* p = listaR->prim;
    Celula_R* t;

    while(p!= NULL){
        t = p->prox;
        LiberaRoteador(p->rot);
        free(p);
        p = t;
    }

    free(listaR);
}
