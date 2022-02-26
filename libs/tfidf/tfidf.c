#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../basics/basics.c"
#include "tfidf.h"

int ** ContaTodasP(int maxp, char *Vet_palavras){
    int count = 0;
    char PVet;
    char palavras;
    int *VetTotalPalavra;
    VetTotalPalavra = (int*) malloc (sizeof(int)*maxp);

    FILE *file;
    file = fopen("../../data/tripdvisor_hotel_reviews.csv", "r");


    for(int i=0; i<= maxp; i++){
        PVet = Vet_palavras[i];
        do{
            palavras = fgetc(file);
            if(palavras == PVet){
                count++;
            }
        }while(palavras != EOF);

        VetTotalPalavra[i] = count;
    }
    fclose(file);
    return VetTotalPalavra;
}

int ** ContaNotaP(int maxp, char *Vet_palavras, int indice){
    int count = 0;
    char PVet;
    char palavras;
    int *VetNotaPalavras;
    VetNotaPalavras = (int*) malloc (sizeof(int)*maxp);

    switch (indice)
    {
    case 1:
        FILE *nota1;
        nota1 = fopen("../../notas/nota1", "r");
        for(int i=0; i<= maxp; i++){
            PVet = Vet_palavras[i];
            do{
                palavras = fgetc(nota1);
                if(palavras == PVet){
                    count++;
                }
            }while(palavras != EOF);

            VetNotaPalavras[i] = count;
        }    
        break;
    case 2:
        FILE *nota2;
        nota2 = fopen("../../notas/nota2", "r");
        for(int i=0; i<= maxp; i++){
            PVet = Vet_palavras[i];
            do{
                palavras = fgetc(nota2);
                if(palavras == PVet){
                    count++;
                }
            }while(palavras != EOF);

            VetNotaPalavras[i] = count;
        }         
        break;
    case 3:
        FILE *nota3;
        nota3 = fopen("../../notas/nota3", "r");
        for(int i=0; i<= maxp; i++){
            PVet = Vet_palavras[i];
            do{
                palavras = fgetc(nota3);
                if(palavras == PVet){
                    count++;
                }
            }while(palavras != EOF);

            VetNotaPalavras[i] = count;
        } 
        break;
    case 4:
        FILE *nota4;
        nota4 = fopen("../../notas/nota4", "r");
        for(int i=0; i<= maxp; i++){
            PVet = Vet_palavras[i];
            do{
                palavras = fgetc(nota4);
                if(palavras == PVet){
                    count++;
                }
            }while(palavras != EOF);

            VetNotaPalavras[i] = count;
        }         
        break;
    case 5:
        FILE *nota5;
        nota5 = fopen("../../notas/nota5", "r");
        for(int i=0; i<= maxp; i++){
            PVet = Vet_palavras[i];
            do{
                palavras = fgetc(nota5);
                if(palavras == PVet){
                    count++;
                }
            }while(palavras != EOF);

            VetNotaPalavras[i] = count;
        }         
        break;
    
    default:
        break;

    fclose(nota1);
    fclose(nota2);
    fclose(nota3);
    fclose(nota4);
    fclose(nota5);
    }

    return VetNotaPalavras;
}

float ** CalculaTF(int *VetNotaPalavras, int *VetTotalPalavra, int maxp){
    float *VetTf;
    VetTf = (float*) malloc (sizeof(float)*maxp);
    for(int i = 0; i <= maxp; i++){
        VetTf[i] = VetNotaPalavras[i]/VetTotalPalavra[i];
    }
    free(VetTf);
    return VetTf;
}

float ** CalculaIDF(int maxp, char *Vet_palavras){
    int TotalDoc = 5;
    int TotalDocsTermo = 0;
    int *VetDocsTermo;
    float ResultadoIDF;
    float *VetIDF;
    int n = 0;
    
    //alocando memória dos vetores
    VetIDF = (float*) malloc (sizeof(float)*maxp);
    VetDocsTermo = (int*) malloc (sizeof(int)*5);

    FILE *nota1;
    nota1 = fopen("../../notas/nota", "r");
    FILE *nota2;
    nota2 = fopen("../../notas/nota2", "r");
    FILE *nota3;
    nota3 = fopen("../../notas/nota3", "r");
    FILE *nota4;
    nota4 = fopen("../../notas/nota4", "r");
    FILE *nota5;
    nota5 = fopen("../../notas/nota5", "r");

    do{
        for(int i = 0; i <= maxp; i++){

            if(strstr(nota1, Vet_palavras[i])){
                TotalDocsTermo ++;
            }else if(strstr(nota2, Vet_palavras[i])){
                TotalDocsTermo ++;
            }else if(strstr(nota3, Vet_palavras[i])){
                TotalDocsTermo ++;
            }else if(strstr(nota4, Vet_palavras[i])){
                TotalDocsTermo ++;
            }else if(strstr(nota5, Vet_palavras[i])){
                TotalDocsTermo ++;
            }
            
            VetDocsTermo[i] = TotalDocsTermo;
        }
    }while(n<=5);

    
    for(int i = 0; i <= maxp; i++){
        ResultadoIDF = log10(1 + (5/VetDocsTermo[i]));
         VetIDF[i] = ResultadoIDF;
    }

    return VetIDF;   
}

float ** CalculoTFIDF(int maxp, float *VetTF, float *VetIDF){
    float *VetResultado;
    VetIDF = (float*) malloc (sizeof(float)*maxp);
    float Resultado;

    for(int i = 0; i <= maxp; i++){
        Resultado = VetTF[i]*VetIDF[i];
        VetResultado[i] = Resultado;
    }

    return VetResultado;
}

