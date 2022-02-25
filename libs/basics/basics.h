#include <stdio.h>
#include <stdbool.h>

#ifndef BASICS_H
#define BASICS_H

FILE *criaArquivo(char *diretorio);
void escreveEmArquivo(FILE *arquivo, char caractere);
int procuraPalavraEmVetor(char palavra[100], char ** Vetor, int tamanho);

#endif