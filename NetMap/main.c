#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "comandos.h"

int main(){   
    FILE* entrada;
    FILE* log;
    FILE* saida;
    FILE* dot;
    int idRot = 1; 
    int idTerm = 1;

    //abrindo arquivos
 
    log = fopen("log.txt","w");
    saida = fopen("saida.txt","w");
    dot = fopen("dot.txt","w");
    entrada = fopen("entrada.txt","r");

    if(entrada==NULL){
        fprintf(log,"ERRO: entrada.txt não encontrado");
    }

    ListaRot* listaRot = CriaListaRot();
    ListaTerm* listaTerm = CriaListaTerm();

    while(!feof(entrada)){
        le_e_executaComando(entrada,listaRot,listaTerm,log,&idRot,&idTerm,saida,dot);     
    }

    //fechando arquivos
    fclose(entrada);
    fclose(saida);
    fclose(dot);
    fclose(log);

    return 0;
}

