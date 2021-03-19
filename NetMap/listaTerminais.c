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

void RemoveTerminal(Terminal* term,ListaTerm* listaT,FILE* log){
    Celula_T* p = listaT->prim;
    Celula_T* ant = NULL;
    int listaVazia = 1;

    while(p!=NULL && retornaIdTerm(p->term)!=retornaIdTerm(term)){
        ant = p;
        p = p->prox;
        listaVazia = 0;
    }

    if(p==NULL && listaVazia==0){ // não encontrou o terminal na lista
        fprintf(log,"ERRO: Terminal %s inexistente no NetMap!\n",retornaNomeTerm(term));
        return 0;
    }

    if(p==NULL && listaVazia==1){ // lista vazia
        fprintf(log,"O NetMap não contém terminais.\n");
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

void FrequenciaTerminal(ListaTerm* listaT , char* loc,FILE* saida){
    int cont = 0;
    Celula_T* p = listaT->prim;

    while(p!=NULL){
        if(strcmp(retornaLocTerm(p->term),loc)){
            cont++;
        }
    }
 
    fprintf(saida,"FREQUENCIATERMINAL %s: %d\n",loc,cont);

}



void ImprimeListaTerm(ListaTerm* listaT){
    Celula_T* p;
    for(p=listaT->prim;p != NULL;p = p->prox){
        ImprimeTerminal(p->term);
    }
}



Terminal* buscaTerminal(char* nomeTerm,ListaTerm* lista, FILE* log){
    Celula_T* p;
    int existeTerm = 0;
    int listaVaziaT = 1;

    for(p=lista->prim; p!=NULL; p=p->prox){
        listaVaziaT = 0;
        if(strcmp(retornaNomeTerm(p->term),nomeTerm)==0){
            return p->term;
            existeTerm =1;
        }
    }
    if(existeTerm==0 && listaVaziaT== 0){
        fprintf(log,"ERRO: Terminal %s inexistente no NetMap!\n",nomeTerm);              
    }

    else if(listaVaziaT == 1){
        fprintf(log,"O NetMap não contém terminais.\n");       
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
