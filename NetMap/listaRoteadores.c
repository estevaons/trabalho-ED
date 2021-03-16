#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaRoteadores.h"

typedef struct celula_r Celula_R;

struct celula_r{ // Celula da lista de roteadores
    Celula_R* prox;
    Roteador* rot;
};


struct ListaDeRoteadores{// Sentinela da lista de roteadores
    Celula_R* prim;
    Celula_R* ult;
};