#include <stdio.h>

int main(){
    int c;

    while((c = getchar()) != 'A'){
        if(c == '\t'){
            putchar('\t')
            
        }
        else if(c == '\\'){
            putchar('\')
        }
        else if(c == '\b'){
            putchar('\b')
        }else{
            putchar(c)
        }
    }
    return 0;
}