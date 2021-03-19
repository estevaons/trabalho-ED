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


Celula_R* retornaCelRTerm(Terminal* term){
    return term->rot;
}

int retornaIdTerm(Terminal* term){
    return term->id;
}

char* retornaNomeTerm(Terminal* term){
    return term->nome;
}

char* retornaLocTerm(Terminal* term){
    return term->loc;
}

Roteador* retornaRotTerm(Terminal* term){
    return term->rot;
}

void DesconectaTerminal(Terminal* term){
    term->rot = NULL;
}

void ImprimeTerminal(Terminal* term){ 
    printf("Nome do terminal : %s\nId do terminal: %d\nLocalização do terminal: %s\nRoteador conectado: %s",term->nome,term->id,term->loc,retornaNomeRot(term->rot));
}

void LiberaTerminal(Terminal* term){
    free(term->nome);
    free(term->loc);
    free(term);
}
