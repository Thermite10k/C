# include <stdio.h>

/*
    Write a program to print a histogram of the lengths of words in its input ( bonus if it's vertical )
*/

int main(){

    int c, nc;

    nc = 0;
  
    while((c = getchar()) != EOF){
          
        if(c != ' ' && c != '\t' && c != '\n'){
            putchar(c);
            nc++;
            
        }else{

            
            printf("\t");

            for(int i = 0; i< nc; i++){
                printf("_");
            }
            printf("\n");
            nc = 0;
        }
        
            
        
    }
    return 0;
}