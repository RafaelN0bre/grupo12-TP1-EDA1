#include <stdio.h>
#include <stdlib.h>
#include "libs/leitura/leitura.c"
#include "libs/vocabulario/vocab.c"
// #include "libs/basics/basics.c"

int main(){

    char str[100];
    printf("Escreva o direto'rio do arquivo a ser lido : ");
    scanf("%[^\n]s",str);

    leitura(str);
    char **Vet_palavras = vocab(str);
    printf("%s", Vet_palavras[0]);
    return 0;
}
