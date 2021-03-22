#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaRoteadores.h"


struct celula_r{ // Celula da lista de roteadores
    Celula_R* prox;
    Roteador* rot;
};


struct ListaDeRoteadores{// Sentinela da lista de roteadores
    Celula_R* prim;
    Celula_R* ult;
    int tamanho;
};


ListaRot* CriaListaRot(){
    ListaRot* lista = (ListaRot*)malloc(sizeof(ListaRot));

    lista->prim = NULL;
    lista->ult = NULL;

    lista->tamanho = 0;

    return lista;
}


ListaRot* CadastraRoteador(ListaRot* lista,int* idRot,char* nomeRot,char* nomeOperadora){
    Celula_R* nova = (Celula_R*)malloc(sizeof(Celula_R));

    nova->rot = CriaRoteador(&idRot,nomeRot,nomeOperadora);

    nova->prox = NULL;
    lista->ult->prox = nova;
    lista->ult = nova;

    if(lista->prim==NULL){
        lista->prim = nova;
    }

    lista->tamanho = lista->tamanho + 1;

    return lista;
}

int verificaRoteador(Celula_R* cel,ListaRot* lista){
    int existe = 0;
    Roteador* rot = retornaRot(cel);
    Celula_R* p;
    char* nome = retornaNomeRot(rot);

    char* nome2;
    Roteador* rot2;

    for(p=lista->prim;p!=NULL;p=p->prox){
        rot2 = retornaRot(p);
        nome2 = retornaNomeRot(rot2);
        if(strcmp(nome,nome2)==0){
            existe = 1;
        }
    }

    return existe;
}


Celula_R* buscaCelRot(char* nomeRot,ListaRot* lista, FILE* log){
    Celula_R* p;
    int existeRot = 0;
    int listaVazia = 1;

    for(p=lista->prim;p!=NULL;p=p->prox){
        listaVazia = 0;
        if(strcmp(retornaNomeRot(p->rot),nomeRot)==0){
            return p;
            existeRot = 1;
        }
    }
    if(existeRot==0 && listaVazia == 0){
        fprintf(log,"ERRO: Roteador %s inexistente no NetMap!\n",nomeRot);              
    }

    else if(listaVazia == 1){
        fprintf(log,"O NetMap não contém roteadores.\n");       
    }
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

Roteador* retornaRot(Celula_R* cel){
    return cel->rot;
}


void ConectaRoteadoresEnlaces(Celula_R* cel1,Celula_R* cel2){  
    Celula_E* nova1 = (Celula_E*)malloc(sizeof(tamanhoCelE()));
    Roteador* rot1 = retornaRotEnlaces(nova1);
    rot1 = retornaRot(cel1);  

    Celula_E* nova2 = (Celula_E*)malloc(sizeof(tamanhoCelE()));
    Roteador* rot2 = retornaRotEnlaces(nova2);
    rot2 = retornaRot(cel2);


    Enlaces* listaEnlaces1 = retornaEnlaces(retornaRot(cel1));
    Enlaces* listaEnlaces2 = retornaEnlaces(retornaRot(cel2));

    listaEnlaces1 = CadastraRoteadorEnlaces(listaEnlaces1, nova2);

    listaEnlaces2 = CadastraRoteadorEnlaces(listaEnlaces2, nova1);
   
}


void RemoveRoteador(Celula_R* cel,ListaRot* listaR){
    Celula_R* p = listaR->prim;
    Celula_R* ant = NULL;

    while(p!=NULL && retornaIdRot(p->rot)!=retornaIdRot(retornaRot(cel))){
        ant = p;
        p = p->prox;
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

    Celula_E* celE;
    Roteador* rot = retornaRot(cel);
    Roteador* rotCel_E = retornaRotEnlaces(celE);
    rotCel_E = rot;

    Enlaces* listaEnlaces = retornaEnlaces(rot);
    Enlaces* listaEnlacesP;

    Celula_E* q;

    for(q=retornaPrimEnlaces(listaEnlaces);q!=NULL;q = retornaProxEnlaces(q)){
        listaEnlacesP = retornaEnlaces(retornaRotEnlaces(q));
        RemoveRoteadorEnlaces(celE,listaEnlacesP);
    }

    LiberaListaEnlaces(p);
    free(p);

}

void FrequenciaOperadora(ListaRot* listaR,char* operadora, FILE* saida){ // Imprime a quantidade de roteadores cadastrados de uma operadora
    int cont = 0;
    Celula_R* p = listaR->prim;

    while(p!=NULL){
        if(strcmp(retornaOperadoraRot(p->rot),operadora)==0){
            cont++;
        }
        p = p->prox;
    }

    fprintf(saida,"FREQUENCIAOPERADORA %s: %d\n",operadora,cont);

}

void ImprimeListaRot(ListaRot* listaR){ // Printa a lista de roteadores *******ANALISAR DNV temos que imprimir de tras pra frente
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
