#include <stdio.h>
#include <stdlib.h>
#include "../basics/basics.c"
#include "leitura.h"



void leitura(char *diretorio_arquivo){
    FILE *file;

    FILE *nota1;
    nota1 = criaArquivo("notas/nota1.txt");
    FILE *nota2;
    nota2 = criaArquivo("notas/nota2.txt");
    FILE *nota3;
    nota3 = criaArquivo("notas/nota3.txt");
    FILE *nota4;
    nota4 = criaArquivo("notas/nota4.txt");
    FILE *nota5;
    nota5 = criaArquivo("notas/nota5.txt");


    char *VetReg = (char*) malloc (15000*sizeof(char));

    file = fopen(diretorio_arquivo, "r");

    char ch;
    char nota;
    int linha = 1;
    int posiCh = 0;

    // Temos 20492 linhas no total
    while(linha <= 20492){
        // printf("======= LINHA %d =========\n", linha);
        posiCh = 0;
        do{
            
            ch = fgetc(file);
            // printf("%c", ch);
            VetReg[posiCh] = ch;
            
            posiCh++;

            if(ch == '\n'){    
                linha++;
                // printf("NOTA - %c\n", nota);
            }else{
                nota = ch;
            }

        }while(ch != '\n');

        // printf("Numero de caracteres -> %d\n", posiCh);

        
        switch(nota){
            case '1': {
                for(int i = 0; i< posiCh; i++){
                    escreveEmArquivo(nota1, VetReg[i]);
                }
            }
            break;
            case '2': {
                for(int i =0; i< posiCh; i++){
                    escreveEmArquivo(nota2, VetReg[i]);
                }
            }
            break;
            case '3': {
                for(int i =0; i< posiCh; i++){
                    escreveEmArquivo(nota3, VetReg[i]);
                }
            }
            break;
            case '4': {
                for(int i = 0; i < posiCh; i++){
                    escreveEmArquivo(nota4, VetReg[i]);
                }
            }
            break;
            case '5': {
                for(int i =0; i< posiCh; i++){
                    escreveEmArquivo(nota5, VetReg[i]);
                }
            }
            break;
        }
    }

    printf("===== Leitura conclui'da =====\n");
    free(VetReg);
    fclose(file);
    fclose(nota1);
    fclose(nota2);
    fclose(nota3);
    fclose(nota4);
    fclose(nota5);
}

