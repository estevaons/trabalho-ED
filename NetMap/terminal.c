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
    term->nome = strdup(nome); // lembrar de dar free
    term->loc = strdup(loc); // lembrar de dar free

    //Celula_R* rot = (Celula_R*)malloc(sizeof(retornaSizeOfCelR()));
    
    term->rot = NULL;

    return term;

}

void setCelR_TERMINAL(Terminal* terminal, Celula_R* celr){
    
    
    terminal->rot = celr;

    Celula_R* celRTERM = retornaCelRTerm(terminal);


    // ImprimeRoteador(retornaRot (celRTERM));

    setCelR_ROTEADOR(terminal->rot,celr);
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

    nome = retornaNomeRot(retornaRot(term->rot));

    if(retornaCelRTerm(term)==NULL){
        printf("Terminal sem roteador\n");
        printf("Nome do terminal: %s\nId do terminal: %d\nLocalização do terminal: %s\nRoteador conectado: TERMINAL SEM ROTEADOR\n",term->nome,term->id,term->loc);
    }
    else{
        printf("Nome do terminal: %s\nId do terminal: %d\nLocalização do terminal: %s\nRoteador conectado: %s\n",term->nome,term->id,term->loc,nome); 
    }

    // rot = retornaRot(term->rot); // CELULA R SENDO NULL

    // nome = retornaNomeRot(rot);


    //ImprimeRoteador(rot);



    // Celula_R* celR = term->rot;
    
    //  if(celR != NULL){
    //     //rot = retornaRot(term->rot);
    //     //nome = retornaNomeRot(rot);
        
    // }else{
    //     nome = "NULO";
    // } 
    

    // //printf("Nome do terminal : %s\nId do terminal: %d\nLocalização do terminal: %s\nRoteador conectado: %s\n",term->nome,term->id,term->loc,nome);
}

void LiberaTerminal(Terminal* term){
    free(term->nome);
    free(term->loc);
    free(term);
}
