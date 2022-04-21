#include <stdio.h>
#include <stdlib.h>

#ifndef GERARABP_H  
#define GERARABP_H

int lerChave(FILE *file);
struct No *gerarAbp(int tam, FILE *file);

#endif