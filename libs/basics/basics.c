#include <stdio.h>
#include <stdlib.h>
#include "basics.h"

FILE *criaArquivo(char *diretorio){
    
    FILE *file;
    file = fopen(diretorio, "w");

    return file;
}

void escreveEmArquivo(FILE *arquivo, char caractere){
    fputc(caractere, arquivo);
}