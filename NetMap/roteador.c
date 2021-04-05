#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "roteador.h"


struct celula_e{
    Celula_E* prox;
    Roteador* rot;
};

struct enlaces{
    Celula_E* prim;
    Celula_E* ult;
    int *tamanho;
};

struct roteador{
    int id;
    char* nome;
    char* operadora;
    Enlaces* listaEnlaces;
};



Enlaces* retornaEnlaces(Roteador* rot){
    return rot->listaEnlaces;

}

void setarListaEnlaces(Enlaces* lista1,Enlaces* lista2){
    lista1 = lista2;
}

void ConectaRoteadoresEnlaces(Roteador* rot1,Roteador* rot2){

    Enlaces* listaEnlaces1 = retornaEnlaces(rot1);
    Enlaces* listaEnlaces2 = retornaEnlaces(rot2);

    Celula_E* nova1 = (Celula_E*)malloc(sizeof(Celula_E));
    Celula_E* nova2 = (Celula_E*)malloc(sizeof(Celula_E));

    adicionaRotCelE(nova1,rot1);
    adicionaRotCelE(nova2,rot2);


    adicionaProxCelE(nova1,NULL); // nova1->prox = NULL; 
    
    Celula_E* prim1 = retornaPrimEnlaces(listaEnlaces1);

    
    adicionaProxCelE(nova2,NULL); // nova2->prox = NULL; 

    Celula_E* prim2 = retornaPrimEnlaces(listaEnlaces2);


    // alocando a celula nova 1 na lista de enlaces 2
    
    if(prim2 != NULL){
        
        adicionaProxCelE(retornaUltEnlaces(listaEnlaces2),nova1); // listaEnlaces2 -> ult -> prox = nova1;
       
        adicionaUltEnlaces(nova1,listaEnlaces2); // listaEnlaces2 -> ult = nova1; 
            
    }
    else{
        
        adicionaPrimEnlaces(nova1,listaEnlaces2); // listaEnlaces2->prim = nova1;
        adicionaUltEnlaces(nova1,listaEnlaces2); //listaEnlaces2->ult = nova1; 
    }

        // alocando celula nova 2 na lista de enlaces 1

    if(prim1 != NULL){
        adicionaProxCelE(retornaUltEnlaces(listaEnlaces1),nova2); // listaEnlaces1 -> ult -> prox = nova2;
       
        adicionaUltEnlaces(nova2,listaEnlaces1); // listaEnlaces1 -> ult = nova2; 
            
    }
    else{
        adicionaPrimEnlaces(nova2,listaEnlaces1); // listaEnlaces1->prim = nova2;
        adicionaUltEnlaces(nova2,listaEnlaces1); //listaEnlaces1->ult = nova2; 
    }

}


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


void adicionaProxCelE(Celula_E* cel1, Celula_E* cel2){
    cel1->prox = cel2;
}

void adicionaPrimEnlaces(Celula_E* cel,Enlaces* lista){
    lista->prim = cel;
}

void adicionaUltEnlaces(Celula_E* cel,Enlaces* lista){
    lista->ult = cel;
}


void ImprimeRoteadorDOT(Roteador* rot,FILE* dot){    
   printf("Nome do roteador: %s\nId do roteador: %d\nOperadora do roteador: %s\n",rot->nome,rot->id,rot->operadora);  
}


void ImprimeRoteador(Roteador* rot){    
    printf("Nome do roteador: %s\nId do roteador: %d\nOperadora do roteador: %s\n",rot->nome,rot->id,rot->operadora);
}

void LiberaRoteador(Roteador* rot){

    free(rot->nome);
    free(rot->operadora);
    free(rot);
}

void adicionaRotCelE(Celula_E* cel, Roteador* roteador){
    cel->rot = roteador;
}

Celula_E* retornaPrimEnlaces(Enlaces* enlaces){
    return enlaces->prim;
}

Celula_E* retornaUltEnlaces(Enlaces* enlaces){
   return enlaces->ult;
}

int* retornaTamanhoEnlaces(Enlaces* enlaces){
    return enlaces->tamanho;
}

Celula_E* retornaProxEnlaces(Celula_E* cel){
    return cel->prox;
}

int analisaListaEnlaces(Roteador* rot, Enlaces* lista){
     Celula_E* p;  

    for(p=lista->prim;p!=NULL;p=p->prox){
        if(p->rot->id==rot->id){
            return 1;
        }
    }

    return 0;

}

Celula_E* verificaListaEnlaces(Roteador* rot,Enlaces* lista){
    Celula_E* p;  

    for(p=lista->prim;p!=NULL;p=p->prox){
        if(p->rot->id==rot->id){
            return p;
        }
    }

    return NULL;

}

Celula_E* buscaRoteadorEnlaces(Roteador* rot, Enlaces* lista, FILE* log,Roteador* rot2){
    int idRot = retornaIdRot(rot);

    Celula_E* p;
    int existeRot = 0;
    int listaVazia = 1;
    Roteador* rotP;

    for(p=retornaPrimEnlaces(lista);p!=NULL;p=retornaProxEnlaces(p)){
        listaVazia = 0;
        rotP = retornaRotEnlaces(p);
        if(retornaIdRot(retornaRotEnlaces(p))==idRot){
            return p;
            existeRot = 1;      
        }
    }
    if(existeRot==0 && listaVazia == 0){
        //fprintf(log,"ERRO: O roteador %s nao esta conectado com o roteador %s.\n",retornaNomeRot(rot),retornaNomeRot(rot2));   
        return NULL;           
     }

    else if(listaVazia == 1){
        //fprintf(log,"O roteador %s nao possui conexoes.\n",retornaNomeRot(rot2)); 
        return NULL;      
     }
}

Enlaces* criaListaEnlaces(){
    Enlaces* listaEnlaces = (Enlaces*)malloc(sizeof(Enlaces));

    listaEnlaces->prim = NULL;
    listaEnlaces->ult = NULL;

    listaEnlaces->tamanho = 0;

    return listaEnlaces;
}

Roteador* retornaRotEnlaces(Celula_E* cel){
    return cel->rot;
}

Enlaces* CadastraRoteadorEnlaces(Enlaces* listaEnlaces,Celula_E* cel){
    cel->prox = NULL;


    if(listaEnlaces->prim != NULL){
        listaEnlaces->ult->prox = cel;
        listaEnlaces->ult = cel;
    }
    else{
        
        listaEnlaces->prim = cel;
        listaEnlaces->ult = cel;
    }

    listaEnlaces->tamanho = (listaEnlaces->tamanho) + 1;

    return listaEnlaces;
}




void RemoveRoteadorEnlaces(Celula_E* cel,Enlaces* lista){
    Celula_E* p = lista->prim;
    Celula_E* ant = NULL;

    while(p!=NULL && retornaIdRot(p->rot)!=retornaIdRot(cel->rot)){
        ant = p;
        p = p->prox;
    }

    if(p == lista->prim && p == lista->ult){ // unica celula
        lista->prim = NULL;
        lista->ult = NULL;
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



void ImprimeListaEnlacesDOT(Enlaces* lista,FILE* dot,Roteador* rot){ // Printa a lista de enlaces *******ANALISAR DNV temos que imprimir de tras pra frente
    Celula_E* p;
    for(p=lista->prim;p != NULL;p = p->prox){
        if(p->prox == NULL){
            fprintf(dot,"    %s -- %s;\n",rot->nome,p->rot->nome);
            break;
        }
        fprintf(dot,"    %s -- %s;\n",rot->nome,p->rot->nome);
    }
}


void ImprimeListaEnlaces(Enlaces* lista){ // Printa a lista de enlaces *******ANALISAR DNV temos que imprimir de tras pra frente
    Celula_E* p;
    for(p=lista->prim;p != NULL;p = p->prox){
        ImprimeRoteador(p->rot);
    }
}

size_t tamanhoCelE(){
    return sizeof(Celula_E);
}

int verificaVetorID(int id,int* vet, int *tam){
    for(int i=0;i<*tam;i++){
        if(vet[i] == id){
            return 1;
        }
    }
    return 0;
}

int verificaConexaoEnlaces(Roteador* rot1,Roteador* rot2,int* vetID,int* cont){
    // entra lista de enlaces do roteador 1
    Enlaces* enlacesAnalisado = rot1 -> listaEnlaces; // Pega a lista de enlaces do roteador 1
    
    if(analisaListaEnlaces(rot2,enlacesAnalisado)){ // verifica se o roteador 5 esta nos enlaces do roteador 1
        return 1;
    }

    else{
        Celula_E* p;
       
        for(p=retornaPrimEnlaces(enlacesAnalisado);p!=NULL;p=p->prox){ // andando na lista de enlaces do roteador anterior
            Roteador* rotP = p->rot; //pega o roteador 

            if(verificaVetorID(rotP->id,vetID,cont)==0){ // verifica se o roteador ja foi analisado
                *cont = *cont+1;


                vetID = (int*)realloc(vetID, (*cont) * sizeof(int));


                vetID[*cont-1] = rot1->id; // grava o id do roteador 1
                
                   

                if(verificaConexaoEnlaces(rotP,rot2,vetID,cont)){ // recursão
                    return 1;
                }

            }
        }

       
        return 0;
    }
}
void EnviaPacotesDados(Roteador* rot1,Roteador* rot2,FILE*saida, char* nomeTerm1, char* nomeTerm2){
    int tam = 2;
    int* cont= &tam;
    
    int* vetID =(int*)calloc(tam,sizeof(int));


    int idProcurado = rot2->id;

 
    if(verificaConexaoEnlaces(rot1,rot2,vetID,cont)){
        fprintf(saida,"ENVIARPACOTESDADOS %s %s: SIM\n",nomeTerm1,nomeTerm2);
    }else{
        fprintf(saida,"ENVIARPACOTESDADOS %s %s: NAO\n",nomeTerm1,nomeTerm2);
    }  

    free(vetID);


} 