#ifndef comandos_h
#define comandos_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "listaTerminais.h"
#include "listaRoteadores.h"


void le_e_executaComando(FILE* entrada, ListaRot* listaROT, ListaTerm* listaTERM,FILE* log, int* idRot,int* idTerm,FILE* saida, FILE* dot);


#endif