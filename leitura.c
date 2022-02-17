# include <stdio.h>
# include <stdlib.h>


int main(){
    FILE *file;
    file =fopen("data/tripadvisor_hotel_reviews.csv", "r");

    int linha = 1;
    char ch;
    char last_ch;
    
    int maxCh = 0;
    int cont;
    int i= 0;

    while(linha < 20492){
        printf("======= LINHA %d =========\n", linha);
        int cont = 0;
        do{
            ch = fgetc(file);
            printf("%c", ch);
            cont++;
            if(ch == '\n'){    
                linha++;
                printf("NOTA - %c\n", last_ch);
            }else{
                last_ch = ch;
            }
        }while(ch != '\n');

        if(cont > maxCh){
                maxCh = cont;
        };

        i++;
    }

    printf("O comentário com mais caracteres tem %d caracteres", maxCh);

    return 0;
}