#include <stdio.h>
#include <stdlib.h>
#include "libs/leitura/leitura.c"
#include "libs/vocabulario/vocab.c"
// #include "libs/basics/basics.c"
#include "libs/menu/menu.c"

int main(){
    conjunto vocabulario;
    char str[100];
    int opcao_selecionada;

    while(opcao_selecionada != 5){
        opcao_selecionada = menu();
        switch (opcao_selecionada)
        {
        case 1:
            printf("Escreva o direto'rio do arquivo a ser lido : ");
            scanf("%[^\n]s",str);
            leitura(str);
            menu();
            break;
        case 2:
            vocabulario = vocab(str);
            menu();
        default:
            break;
        }
    }
    
    free(vocabulario.Vet_palavras);
    for(int i = 0; i< vocabulario.qtd; i++){
        free(vocabulario.Vet_palavras[i]);
    }

    return 0;
}
