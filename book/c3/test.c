#include <stdio.h>

int main(void){
    int c;
    while( (c = getchar()) != EOF || c != '\n'){
        printf("%d ", c);
    }

    return 0;
}