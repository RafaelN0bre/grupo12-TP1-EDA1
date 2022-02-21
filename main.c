#include <stdio.h>
#include <stdlib.h>
#include "libs/leitura/leitura.c"

int main(){
    char str[100];
    printf("Escreva o direto'rio do arquivo a ser lido : ");
    scanf("%[^\n]s",str);

    leitura(str);

    return 0;
}