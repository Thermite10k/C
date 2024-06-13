#include <stdio.h>

int main(){
    int c;

    while((c = getchar()) != 'A'){
        
        if(c == ' '){
            putchar(c);
            while((c = getchar()) == ' ')
                ;
        }
        putchar(c);
        
        



    }
    return 0;
}