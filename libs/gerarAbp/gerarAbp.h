#include <stdio.h>
#include <stdlib.h>

#ifndef GERARABP_H  
#define GERARABP_H

int readKey(FILE *file);
struct Node *gerarAbp(int tam, FILE *file);

#endif