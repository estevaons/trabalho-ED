#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "listaTerminais.h"
#include "listaRoteadores.h"





void le_e_executaComando(FILE* entrada, ListaRot* listaROT, ListaTerm* listaTERM,FILE* log, int* idRot,int* idTerm,FILE* saida){
    char instrucao[100];
    char nomeRot[100],nomeRot1[100],nomeRot2[100];
    char nomeOperadora[100];
    char nomeLoc[100];
    char nomeTerm[100];

    char pacoteDados;

    char nomeTerm1[100];
    char nomeTerm2[100];
    

    fscanf(entrada,"%s",instrucao);
    if(strcmp(instrucao,"CADASTRAROTEADOR")==0){
        fscanf(entrada,"%s",nomeRot);
        fscanf(entrada,"%s",nomeOperadora);  

        //cria roteador
        Roteador* novoRot = CriaRoteador(*idRot,nomeRot,nomeOperadora);
        *idRot++;
        // executar cadastra roteador

        listaROT = CadastraRoteador(novoRot, listaROT);
    
    }
    if(strcmp(instrucao,"REMOVEROTEADOR")==0){
        fscanf(entrada,"%s",nomeRot);
    
        listaROT = RemoveRoteador(buscaRoteador(nomeRot,listaROT,log),listaROT);     // executar remove roteador
      
    }

    if(strcmp(instrucao,"CONECTAROTEADORES")==0){
        fscanf(entrada,"%s",nomeRot1);
        fscanf(entrada,"%s",nomeRot2);

        // executar conecta roteadores

        ConectaRoteadores(buscaRoteador(nomeRot1,listaROT,log), buscaRoteador(nomeRot2,listaROT,log));


    }

    if(strcmp(instrucao,"IMPRIMENETMAP")==0){

        // executar imprime netmap
    }

    if(strcmp(instrucao,"DESCONECTAROTEADORES")==0){
        fscanf(entrada,"%s",nomeRot1);
        fscanf(entrada,"%s",nomeRot2);

        // executar desconecta roteadores

        DesconectaRoteadores(buscaRoteador(nomeRot1,listaROT,log), buscaRoteador(nomeRot2,listaROT,log));
    }

    if(strcmp(instrucao,"DESCONECTATERMINAL")==0){
        fscanf(entrada,"%s",nomeTerm);

        // executar desconecta terminal

        DesconectaTerminal(buscaTerminal(nomeTerm,listaTERM,log));
    }
    
    if(strcmp(instrucao,"FREQUENCIAOPERADORA")==0){
        fscanf(entrada,"%s",nomeOperadora);

        // executar frequencia operadora

        FrequenciaOperadora(listaROT,nomeOperadora,saida);
    }

    if(strcmp(instrucao,"FREQUENCIATERMINAL")==0){
        fscanf(entrada,"%s",nomeLoc);

        // executar frequencia terminal
        FrequenciaTerminal(listaTERM,nomeLoc,saida);
    }
  

    if(strcmp(instrucao,"REMOVETERMINAL")==0){
        fscanf(entrada,"%s",nomeTerm);

        // executar remove terminal
        RemoveTerminal(buscaTerminal(nomeTerm,listaTERM,log),listaTERM,log);
    }

    if(strcmp(instrucao,"CONECTATERMINAL")==0){
        fscanf(entrada,"%s",nomeTerm1);
        fscanf(entrada,"%s",nomeRot);
        
        // executar conecta terminal
        ConectaTerminal(buscaTerminal(nomeTerm1,listaTERM,log), buscaRoteador(nomeRot,listaROT,log));
    }

    if(strcmp(instrucao,"ENVIARPACOTESDADOS")==0){
        fscanf(entrada,"%s",nomeTerm1);
        fscanf(entrada,"%s",nomeTerm2);

        // executar enviar pacotes dados

        EnviaPacotesDados(buscaTerminal(nomeTerm1,listaTERM,log),buscaTerminal(nomeTerm2,listaTERM,log),listaROT,saida);
    }


    if(strcmp(instrucao,"FIM")==0){
        printf("PROGRAMA TERMINANDO !!!\n");

        //termina o programa
        exit(0);
    }

}

int main(){
    FILE* entrada;
    FILE* log;
    FILE* saida;
    int idRot = 0; 
    int idTerm = 0;

    //abrindo arquivo
    log = fopen("log.txt","w");
    saida = fopen("saida.txt","w");
    entrada = fopen("entrada.txt","r");

    if(entrada==NULL){
        fprintf(log,"ERRO: entrada.txt não encontrado");
    }

    ListaRot* listaRot = CriaListaRot();
    ListaTerm* listaTerm = CriaListaTerm();
    



    while(!feof(entrada)){

        le_e_executaComando(entrada,listaRot,listaTerm,log,&idRot,&idTerm,saida);
        

    }




    //fechando arquivo
    fclose(entrada);

    return 0;
}