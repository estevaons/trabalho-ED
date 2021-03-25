#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "terminal.h"

struct terminal{
    int id;
    char* nome;
    char* loc;
    Celula_R* rot;
};

Terminal* CriaTerminal(int id,char* nome,char* loc){
    Terminal* term = (Terminal*)malloc(sizeof(Terminal));

    term->id = id;
    term->nome = strdup(nome);
    term->loc = strdup(loc);
    
    term->rot = NULL;

    return term;

}


int retornaIdTerm(Terminal* term){
    return term->id;
}

Celula_R* retornaCelRTerm(Terminal* term){
    return term->rot;
}

char* retornaNomeTerm(Terminal* term){
    return term->nome;
}

char* retornaLocTerm(Terminal* term){
    return term->loc;
}




void ImprimeTerminal(Terminal* term){ 
    char* nome;
    
    Roteador* rot;
    
    if(term->rot != NULL){
        rot = retornaRot(term->rot);
        nome = retornaNomeRot(rot);
    }else{
        nome = "NULO";
    }
    

    printf("Nome do terminal : %s\nId do terminal: %d\nLocalização do terminal: %s\nRoteador conectado: %s\n",term->nome,term->id,term->loc,nome);
}

void LiberaTerminal(Terminal* term){
    free(term->nome);
    free(term->loc);
    free(term);
}
