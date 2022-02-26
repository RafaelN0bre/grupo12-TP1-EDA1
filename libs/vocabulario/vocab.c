#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
#include "vocab.h"
// #include "../basics/basics.c"

conjunto vocab(char diretorio_arquivo[100]){
    FILE *file;
    // char *diretorio_arquivo;
    // diretorio_arquivo = "..\\..\\data\\tripadvisor_hotel_reviews.csv";
    
    FILE *vocabtxt = criaArquivo("vocab.txt");

    char temp_palavra[100];    
    // char * Vet_palavras[500000];
    conjunto conj;

    int qtd = 1;
    conj.Vet_palavras = (char**) malloc (sizeof(char[100]) * qtd);   
    conj.qtd;
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

                if(ch != '\"' && ch != '*' && ch != ',' && ch != '.' && ch != '\'' && ch != ' ' && ch != '\n' && !isdigit(ch) && ch != '/' && ch != '-' && ch != '_' && ch != '+'){
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
                if(procuraPalavraEmVetor(temp_palavra, conj.Vet_palavras,cont) == 0){
                    for(int j = 0;j < posiCh;j ++){
                        escreveEmArquivo(vocabtxt, temp_palavra[j]);
                    }
                    escreveEmArquivo(vocabtxt, '\n');
                    // Vet_palavras[cont] = palavra[cont];
                    l = strlen(temp_palavra);
                    qtd++;
                    conj.Vet_palavras = realloc(conj.Vet_palavras, qtd * sizeof(char[100]));
                    conj.Vet_palavras[cont] = (char *)malloc(sizeof(char)*(l+1));
                    strcpy(conj.Vet_palavras[cont], temp_palavra);
                    // printf("%s\n", conj.Vet_palavras[cont]);
                    cont++;
                }
            }
            memset(temp_palavra,0,strlen(temp_palavra));
        }
       
    }
    conj.qtd = cont;
    fclose(file);
    return conj;    
}