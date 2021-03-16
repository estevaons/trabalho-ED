#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "terminal.h"

struct terminal{
    int id;
    char* nome;
    char* loc;
    Roteador* rot;
};