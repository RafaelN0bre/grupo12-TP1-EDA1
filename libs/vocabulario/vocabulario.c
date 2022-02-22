#include <stdio.h>
#include <stdlib.h>


int leitura_das_palavras(){

    typedef struct // Cria uma STRUCT para armazenar palavras e dados referentes
    {
    int nota1, nota2, nota3, nota4, nota5;
    char palavra[];
    } palavras_por_arquivo;

    char file_name[30];
    int na_palavra = 0;
    char guarda_palavra[50];
    char ch;

    FILE *fp;

    palavras_por_arquivo palavras[66666666];

    for(int i = 1; i < 6; i++){

        int char_cont = 0, palavra_cont = 0;

        file_name = "notas/nota"+'i'+".txt";  // isso funciona?
        fp = fopen(file_name, "r");

        if(fp == NULL) {
            printf("nao foi possivel abrir o arquivo %s\n", file_name);
            return 1;
        }

        while ((ch = fgetc(fp)) != EOF) {   //EOF = fim do arquivo
            char_cont++;
            int j;

            if(ch == ' ' || ch == '\t' || ch == '\0' || ch == '\n') {
                if (na_palavra) {
                    j = 0;
                    na_palavra = 0;
                    palavra_cont++;
                                        // pensar em alguma maneira de introduzir o guarda palavra no struct
                                        // fazer um switch case para somar a palavra no arquivo certo 
                                        // filtrar palavras nao validas   
                }


            } else {
                na_palavra = 1;
                j++;
                guarda_palavra[j] = ch;
            }
        }



    }





}