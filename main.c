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
    conjunto vocabulario = vocab(str);
    printf("%s", vocabulario.Vet_palavras[3]);
    printf("%s", vocabulario.Vet_palavras[279]);

    return 0;
}
