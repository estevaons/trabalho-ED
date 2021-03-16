#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "roteador.h"
#include "listaRoteadores.h"

struct roteador{
    int id;
    char* nome;
    char* operadora;
    ListaRot* listaEnlaces;
};
