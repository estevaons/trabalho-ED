#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaTerminais.h"

typedef struct celula_t Celula_T;

struct celula_t{ // Celula da lista de terminais
    Celula_T* prox;
    Terminal* rot;
};


struct ListaDeTerminais{// Sentinela da lista de terminais
    Celula_T* prim;
    Celula_T* ult;
};