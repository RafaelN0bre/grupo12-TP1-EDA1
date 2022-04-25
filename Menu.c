// Importando libs locais
#include "avl/avl.c"
#include "libs/gerarAbp/gerarAbp.c"

// Importando libs padrao
#include <stdio.h>
#include <stdlib.h>


int main(void){
    int estado = 0;
    char str[100];
    while(estado == 0){
        int op;
        int balanceamentoFoiCalculado;

        // Criando ponteiro para file que lera os dados
        FILE *file;        
        
        
        struct No *root;

        printf("Escolha uma das opcoes: \n\n");
        printf("1 - Gerar ABP\n");
        printf("2 - Calcular Fator de Balanceamento\n");
        printf("3 - Imprime ABP\n");
        printf("4 - Sair\n");
        scanf("%d", &op);
        printf("\n");
        if(op != 1 && op != 2 && op != 3 && op != 4){
            printf("opcao invalida\n\n");
            fflush(stdin);
            estado = 0;
        }else{
            switch (op)
            {
            case 1:
                fflush(stdin);
                printf("Escreva o direto'rio do arquivo a ser lido : ");
                scanf("%[^\n]s",str);
                file = fopen(str, "r");
                int tam = contarLinhas(file);
                fclose(file);
                printf("O arquivo possui %d registros !!\n", tam);
                file = fopen(str, "r");
                root = gerarAbp(tam, file);
                estado = 0;
                break;
            case 2:
                calculaFatBal(root);
                printf("Fator de balanceamento calculado !!\n\n");
                estado = 0;
                balanceamentoFoiCalculado = 1;
                break;
            case 3:
                // printPreOrder(root);
                if((root->pEsq != NULL || root->pDir != NULL) && balanceamentoFoiCalculado == 1){
                    printf("|\tChave\t|\tFatBal\t|\n");
                    printf("---------------------------------\n");
                    imprimirOrdemCresc(root);
                    estado = 0;
                    break;
                }else{
                    if(balanceamentoFoiCalculado != 1)
                        printf("Calcule o fator de balanceamento antes de imprimir a arvore !!!\n\n");
                    else
                        printf("A arvore esta  vazia !! Gere a ABP antes . . .\n\n");
                    break;
                }
            case 4:
                estado = 1;
                desalocar(root);
                printf("Arvore desalocada !! Encerrando sistema . . .");
                fclose(file);
                break;
            
            default:
                break;
            }
        }
    }    
}