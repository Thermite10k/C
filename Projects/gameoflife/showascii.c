#include <stdio.h>

int main(){

    int i = 0;

    for(i; i<256;i++){
        printf("%d => %c \t", i, i);
        if((i%10) == 0){
            printf("\n");
        }
    }

    return 0;
}