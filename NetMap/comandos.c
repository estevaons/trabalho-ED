#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include"comandos.h"

void le_e_executaComando(FILE* entrada, ListaRot* listaROT, ListaTerm* listaTERM,FILE* log, int* idRot,int* idTerm,FILE* saida, FILE* dot){
    char instrucao[100];
    char nomeRot[100],nomeRot1[100],nomeRot2[100];
    char nomeOperadora[100];
    char nomeLoc[100];
    char nomeTerm[100];
    char locTerm[100];
    int idROT,idTERM;

    char pacoteDados;

    char nomeTerm1[100];
    char nomeTerm2[100];
    

    fscanf(entrada,"%s",instrucao);
    if(strcmp(instrucao,"CADASTRAROTEADOR")==0){ 
        fscanf(entrada,"%s",nomeRot);
        fscanf(entrada,"%s",nomeOperadora);  
        
       
        // executa cadastra roteador
        idROT = *idRot;
        CadastraRoteador(listaROT,idROT,nomeRot,nomeOperadora);
        
        *idRot = *idRot+1;
       
    
    }

    if(strcmp(instrucao,"REMOVEROTEADOR")==0){ 
        fscanf(entrada,"%s",nomeRot); 

        Celula_R* celR = buscaCelRot(nomeRot,listaROT,log); // Procura a celula R do roteador a ser removido

        if (celR !=NULL){
            // executa remove roteador   
            RemoveRoteador(celR,listaROT);  
          
        }
    }

    if(strcmp(instrucao,"CADASTRATERMINAL")==0){ 
        fscanf(entrada,"%s",nomeTerm);
        fscanf(entrada,"%s",locTerm);
        
        idTERM = *idTerm;
        // executa cadastra terminal
        CadastraTerminal(idTERM,nomeTerm,locTerm,listaTERM);
        *idTerm = *idTerm +1;

    }

    if(strcmp(instrucao,"REMOVETERMINAL")==0){ 
        fscanf(entrada,"%s",nomeTerm);

        // executa remove terminal
        RemoveTerminal(buscaCelTerminal(nomeTerm,listaTERM,log),listaTERM,log);
    }

    if(strcmp(instrucao,"CONECTAROTEADORES")==0){ 
        fscanf(entrada,"%s",nomeRot1);
        fscanf(entrada,"%s",nomeRot2);

        Celula_R* cel1;
        Celula_R* cel2;

        cel1 = buscaCelRot(nomeRot1,listaROT,log); // Procura a celula R do roteador1
        cel2 = buscaCelRot(nomeRot2,listaROT,log); // Procura a celula R do roteador2

        //executa conecta roteadoresElaces

        if(cel1 != NULL && cel2 != NULL){
            Roteador* rot1 = retornaRot(cel1);
            Roteador* rot2 = retornaRot(cel2);
            ConectaRoteadoresEnlaces(rot1,rot2);
        }
    }

    if(strcmp(instrucao,"CONECTATERMINAL")==0){ 
        fscanf(entrada,"%s",nomeTerm1);
        fscanf(entrada,"%s",nomeRot);
        
        
        Celula_T* celT = buscaCelTerminal(nomeTerm1,listaTERM,log); // Procura a celula T do terminal

        Celula_R* celR = buscaCelRot(nomeRot,listaROT,log); // Procura a celula R do roteador

        if(celT != NULL && celR != NULL){  
            // executa conecta terminal
            ConectaTerminal(celT,celR);
        }
    }

    if(strcmp(instrucao,"IMPRIMENETMAP")==0){ 

        // executa imprime netmap
        ImprimeListaTermDOT(listaTERM,dot);
        ImprimeListaRotDOT(listaROT,dot);
        
    }

    if(strcmp(instrucao,"DESCONECTAROTEADORES")==0){ 
        fscanf(entrada,"%s",nomeRot1);
        fscanf(entrada,"%s",nomeRot2);

        Celula_R* cel1;
        Celula_R* cel2;


        cel1 = buscaCelRot(nomeRot1,listaROT,log); 
        cel2 = buscaCelRot(nomeRot2,listaROT,log);

     

        if(cel1 != NULL && cel2 != NULL){
            // executa desconecta roteadores
            DesconectaRoteadoresEnlaces(cel1,cel2,log);
        }

       
    }

    if(strcmp(instrucao,"DESCONECTATERMINAL")==0){ 
        fscanf(entrada,"%s",nomeTerm);

        // executa desconecta terminal

        DesconectaTerminal(buscaCelTerminal(nomeTerm,listaTERM,log));

    }
    
    if(strcmp(instrucao,"FREQUENCIAOPERADORA")==0){ 
        fscanf(entrada,"%s",nomeOperadora);

        // executa frequencia operadora

        FrequenciaOperadora(listaROT,nomeOperadora,saida);
    }

    if(strcmp(instrucao,"FREQUENCIATERMINAL")==0){ 
        fscanf(entrada,"%s",nomeLoc);

        // executa frequencia terminal
        FrequenciaTerminal(listaTERM,nomeLoc,saida);
    }


    if(strcmp(instrucao,"ENVIARPACOTESDADOS")==0){
        fscanf(entrada,"%s",nomeTerm1);
        fscanf(entrada,"%s",nomeTerm2);

        Celula_T* celT1 = buscaCelTerminal(nomeTerm1,listaTERM,log);
        Celula_T* celT2 = buscaCelTerminal(nomeTerm2,listaTERM,log);

        Celula_R* celR_rot1;
        Celula_R* celR_rot2;

        if(celT1 != NULL && celT2 != NULL){
            Terminal* t1 = retornaTerm(celT1);
            Terminal* t2 = retornaTerm(celT2);

            celR_rot1 = retornaCelRTerm(t1);
            celR_rot2 = retornaCelRTerm(t2);

            // executa enviar pacotes dados
            EnviaPacotesDados(retornaRot(celR_rot1),retornaRot(celR_rot2),saida,nomeTerm1,nomeTerm2);
        }   
    }


    if(strcmp(instrucao,"FIM")==0){      
        //termina o programa e da free em tudo
        
        //LiberaListaTerm(listaTERM);

        //LiberaTodosEnlaces(listaROT);

        //LiberaListaRot(listaROT); 

    }

}