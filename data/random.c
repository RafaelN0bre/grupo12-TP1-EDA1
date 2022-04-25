#include <stdio.h>
#include <time.h>
#include <string.h>

int main(){
   /*this is the seed that is created based on how much 
  time has passed since the start of unix time. 
  In this way the seed will always vary every time the program is opened*/
  srand(time(NULL));
  	
    FILE *fp;
    fp = fopen("data.csv", "w"); 
      
    int max = 40000;
  	int min = 1;
    int n;
    char text[6];
  	for (int i = 0; i < 300; i++){
        n = rand() % ((max - min + 1) + min);
        sprintf(text, "%d", n);
        for (int i = 0; i< strlen(text); i++){
            fputc(text[i], fp);
        }
        if(i != 299){
            fputc('\n', fp);
        }
    }
    fclose(fp);
  	return 0;
}