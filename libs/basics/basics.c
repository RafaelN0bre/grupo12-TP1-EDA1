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

int procuraPalavraEmArquivo(FILE * arquivo, char palavra[100]){

    char ch;
    int posiCh = 0;

    char temp_palavra[100];

    while(ch != EOF){
        
        posiCh = 0;

        do{
            ch = fgetc(arquivo);
            if(ch != '\"' && ch != '*' && ch != ',' && ch != '.' && ch != '\'' && ch != ' ' && ch != '\n' && !isdigit(ch) && ch != '/' && ch != '-' && ch != '_'){
                    temp_palavra[posiCh] = ch;
                    posiCh++;
            } 
        }while(ch != '\n' && ch != ' ' && ch != EOF);
        // printf("%s \n", temp_palavra);
        if(strcmp(palavra, temp_palavra) == 0){
            memset(temp_palavra,0,strlen(temp_palavra));
            return 1;
        }
        memset(temp_palavra,0,strlen(temp_palavra));
        
    }
    fclose(arquivo);
    return 0;
}

typedef struct{
        char **Vet_palavras;
        int qtd;
}conjunto;
