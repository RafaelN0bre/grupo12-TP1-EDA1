#include "gerarAbp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readKey(FILE *file){

    char text[5];
    int counter;
    char ch;
    while (ch != '\n' && ch != EOF){
        ch = fgetc(file);
        text[counter] = ch;
        counter++;
    }
    int key = atoi(text);
    return key;
}

struct Node *gerarAbp(int tam, FILE *file){
    int key;
    struct Node *final_root = NULL;
    printf("gerando abp...");
    printf("\n");
    for (int i = 0; i< tam;i++){
        key = readKey(file);
        final_root = insertNode(final_root, key);
    }
    fclose(file);
    return final_root;
}