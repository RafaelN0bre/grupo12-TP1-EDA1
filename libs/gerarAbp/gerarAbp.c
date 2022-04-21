#include "gerarAbp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lerChave(FILE *file){

    char text[5];
    int counter;
    char ch;
    while (ch != '\n' && ch != EOF){
        ch = fgetc(file);
        text[counter] = ch;
        counter++;
    }
    int chave = atoi(text);
    return chave;
}

struct No *gerarAbp(int tam, FILE *file){
    int chave;
    struct No *final_root = NULL;
    printf("Gerando abp...");
    printf("\n");
    for (int i = 0; i< tam;i++){
        chave = lerChave(file);
        final_root = inserirNo(final_root, chave);
    }
    fclose(file);
    printf("ABP gerada com sucesso!!\n\n");
    return final_root;
}