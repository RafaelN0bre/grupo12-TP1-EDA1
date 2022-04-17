// Importando libs locais
#include "avl/avl.c"
#include "libs/gerarAbp/gerarAbp.c"

// Importando libs padrao
#include <stdio.h>
#include <stdlib.h>


int main(void){
    int estado = 0;
    while(estado == 0){
        int op;

        // Criando ponteiro para file que lera os dados
        FILE *file;        
        file = fopen("data/data.csv", "r");
        
        struct Node *root;

        printf("Escolha uma das opcoes: \n\n");
        printf("1 - Gerar ABP\n");
        printf("2 - Calcular Fator de Balanceamento\n");
        printf("3 - Imprime ABP\n");
        printf("4 - Sair\n");
        scanf("%d", &op);
        printf("\n");
        if(op != 1 && op != 2 && op != 3 && op != 4){
            printf("opcao invalida\n\n");
            estado = 0;
        }else{
            switch (op)
            {
            case 1:
                root = gerarAbp(100, file);
                estado = 0;
                break;
            case 2:
                /* code */
                estado = 0;
                break;
            case 3:
                printPreOrder(root);
                estado = 0;
                break;
            case 4:
                estado = 1;
                desalocar(root);
                printf("Arvore desalocada !! Encerrando sistema . . .");
                fclose(file);
                free(root);
                break;
            
            default:
                break;
            }
        }
    }


    
    
}