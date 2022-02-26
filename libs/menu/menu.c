#include <stdio.h>
#include <stdlib.h>
#include "menu.h"



int menu(){
    printf("Selecione a opcao:\n");
    printf("1 - Ler o dataset\n");
    printf("2 - Gerar vocabulario\n");
    printf("3 - Exibir TF-IDFs\n");
    printf("4 - Exibir TF-IDF de uma Nota\n");
    printf("5 - Sair\n");
    int opcao_selecionada;
    scanf("%d", &opcao_selecionada);

    return opcao_selecionada;

}

