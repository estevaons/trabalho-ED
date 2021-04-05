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

Roteador* retornaRot(Celula_R* cel){
    return cel->rot;
}

Celula_R* retornaPrimRot(ListaRot* lista){
    return lista->prim;
}

void LiberaListaEnlaces(ListaRot * lista){ 
    Celula_R* p = lista->prim;
    
    while(p !=NULL){
        Enlaces* listaEnlaces = retornaEnlaces(p->rot);

        Celula_E* q = retornaPrimEnlaces(listaEnlaces);
        Celula_E* t;

        while(q != NULL){       
            t = retornaProxEnlaces(q);
            free(q);
            q = t;  
        }
        free(listaEnlaces);

        p = p->prox;
    }
}

ListaRot* CriaListaRot(){
    ListaRot* lista = (ListaRot*)malloc(sizeof(ListaRot));

    lista->prim = NULL;
    lista->ult = NULL;

    lista->tamanho = 0;

    return lista;
}


int verificaRoteador(Celula_R* cel,ListaRot* lista){
    Celula_R* p;
    int existe = 0;
    Roteador* rotProcurado = retornaRot(cel);
    char* nomeProcurado = retornaNomeRot(rotProcurado);

    for(p=lista->prim;p!=NULL;p=p->prox){
        Roteador* rotP = retornaRot(p);
        char* nomeP = retornaNomeRot(rotP);
        if(strcmp(nomeProcurado,nomeP)==0){
            existe = 1;
        }
    }

    return existe;
}



void CadastraRoteador(ListaRot* lista,int idRot,char* nomeRot,char* nomeOperadora){ // CERTO
   
    Celula_R* nova = (Celula_R*)malloc(sizeof(Celula_R));
    

    nova->rot = CriaRoteador(idRot,nomeRot,nomeOperadora);
    

    nova->prox = NULL;
    
    if(lista->prim != NULL){
        lista->ult->prox= nova; 
        lista->ult = nova;     
    }
    else{
        lista->prim = nova;   
        lista->ult = nova; 
    }
    
  

    lista->tamanho = lista->tamanho + 1;

}



size_t retornaSizeOfCelR(){
    return sizeof(Celula_R);
}


void DesconectaRoteadoresEnlaces(Celula_R* cel1,Celula_R* cel2,FILE* log){

    Roteador* rot1 = retornaRot(cel1);
    Roteador* rot2 = retornaRot(cel2);

    Enlaces* listaEnlaces1 = retornaEnlaces(rot1);
    Enlaces* listaEnlaces2 = retornaEnlaces(rot2);


    Celula_E* cel_E_Rot2 = buscaRoteadorEnlaces(rot2,listaEnlaces1,log,rot1);

    Celula_E* cel_E_Rot1 = buscaRoteadorEnlaces(rot1,listaEnlaces2,log,rot2);



    if(cel_E_Rot1 != NULL && cel_E_Rot2 != NULL){
        RemoveRoteadorEnlaces(cel_E_Rot2,listaEnlaces1); // remover uma celula_E de uma lista de enlaces de um roteador
        RemoveRoteadorEnlaces(cel_E_Rot1,listaEnlaces2); 
    } 



    
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
        return NULL;            
    }

    else if(listaVazia == 1){
        fprintf(log,"O NetMap não contém roteadores.\n"); 
        return NULL;   
    }
}
void RemoveRoteador(Celula_R* cel,ListaRot* listaR){
    Celula_R* p = listaR->prim;
    Celula_R* ant = NULL;
    int existeEnlaces = 0;

    int idP = retornaIdRot(p->rot);

    Roteador* rotCel = retornaRot(cel); 
    int idCel = retornaIdRot(rotCel);
    Enlaces* enlacesCelR = retornaEnlaces(rotCel);

    while(p->prox!=NULL && idP != idCel){
        ant = p;
        p = p->prox;
        idP = retornaIdRot(p->rot);
    } 


    if(p == listaR->prim && p == listaR->ult){ // unica celula
        listaR->prim = NULL;
        listaR->ult = NULL;
    }

    else if(p == listaR->prim){ // se for a primeira celula
        listaR->prim = p->prox;
    }

    else if(p == listaR->ult){ // se for a ultima celula    
        listaR->ult = ant;
        listaR->ult->prox = NULL;
    } 

    else if(p != listaR->prim && p != listaR->ult){ // caso comum
        ant->prox = p->prox;            
    } 

    /*printf("LISTA ENLACES ANTES DO ROT %s:\n",retornaNomeRot(rotCel)); // TESTE
    ImprimeListaEnlaces(enlacesCelR);
    printf("-------------------------------------------------------------------\n");  */

    // removendo o roteador removido da lista principal dos enlaces dos outros roteadores

    Celula_R* andaListaRot;
    for(andaListaRot=listaR->prim;andaListaRot!=NULL;andaListaRot=andaListaRot->prox){ // ANDA NA LISTA DE ROTEADORES
        Roteador* rot1 = retornaRot(andaListaRot); // PEGA O ROTEADOR DA CELULA R ANALISADA
        Enlaces* listaEnlaces = retornaEnlaces(rot1);

        Celula_E* celE = verificaListaEnlaces(rotCel,listaEnlaces); // BUSCA O ROTEADOR REMOVIDO NA LISTA DE ENLACES DO ROTEADOR ANALISADO
        
        if(celE!=NULL){ // SE O ROTEADOR FOR ENCONTRADO NA LISTA DE ENLACES
            RemoveRoteadorEnlaces(celE,listaEnlaces); // REMOVE A CELULA E DA LISTA DE ENLACES DO ROTEADOR ANALISADO
        } 

    }

    free(enlacesCelR);

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



void ImprimeListaRotDOT(ListaRot* listaR, FILE*dot){ // Printa a lista de roteadores 
    Celula_R* p;
    for(p=listaR->prim;p != NULL;p = p->prox){
        ImprimeListaEnlacesDOT(retornaEnlaces(p->rot),dot,p->rot);
    }
    fprintf(dot,"}\n");
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
