#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
#include "vocab.h"

char ** vocab(char diretorio_arquivo[100]){
    FILE *file;
    // char *diretorio_arquivo;
    // diretorio_arquivo = "..\\..\\data\\tripadvisor_hotel_reviews.csv";
    
    char temp_palavra[100];    
    int qtd = 1;
    // char * Vet_palavras[500000];
    char **Vet_palavras;
    Vet_palavras = (char**) malloc (sizeof(char[100]) * qtd);   
    
    file = fopen(diretorio_arquivo, "r");

    int linha = 1;
    char ch;
    int posiCh = 0;
    int cont = 0;
    int l = 0;

    while(ch != EOF){
        
        posiCh = 0;
        do{
            ch = fgetc(file);
            if(ch == EOF){
                printf("Chegamos ao fim \n");
            }else{

                if(ch != '\"' && ch != '*' && ch != ',' && ch != '.' && ch != '\'' && ch != ' ' && ch != '\n' && !isdigit(ch) && ch != '/' && ch != '-' && ch != '_'){
                    temp_palavra[posiCh] = ch;
                    posiCh++;
                } 
                if(ch == '\n'){
                    if(linha % 100 == 0){
                        printf("Linha %d \n", linha);
                    }
                    linha ++;
                }

            }
        }while(ch != ' ' && ch != '\n' && ch != EOF);
        
        if(ch == EOF){
            printf("Vocabulário completo");
        }else{

            if(posiCh > 3){
                if(procuraPalavraEmVetor(temp_palavra, Vet_palavras,cont) == 0){
                    // Vet_palavras[cont] = palavra[cont];
                    l = strlen(temp_palavra);
                    qtd++;
                    Vet_palavras = realloc(Vet_palavras, qtd * sizeof(char[100]));
                    Vet_palavras[cont] = (char *)malloc(sizeof(char)*(l+1));
                    strcpy(Vet_palavras[cont], temp_palavra);
                    // printf("%s\n", Vet_palavras[cont]);
                    cont++;
                    // printf("%s \n", temp_palavra);
                    memset(temp_palavra,0,strlen(temp_palavra));
                }
            }
        }
       
    }
    
    fclose(file);
    return Vet_palavras;   

    
}