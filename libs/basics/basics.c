#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "basics.h"
#include <ctype.h>
#include <string.h> 

FILE *criaArquivo(char *diretorio){
    
    FILE *file;
    file = fopen(diretorio, "w");

    return file;
}

void escreveEmArquivo(FILE *arquivo, char caractere){
    fputc(caractere, arquivo);
}

int procuraPalavraEmVetor(char palavra[100], char ** Vetor, int tamanho){
    int posicao = 0;
    int encontrado = 0;
    
    while(posicao < tamanho && encontrado == false){
        if(strcmp(palavra, Vetor[posicao]) == 0){
            return 1;      
        }else{
            posicao++;
        }
    }
    return 0;
}
