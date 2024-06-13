#include <stdio.h>

int atod(int n);

int main(void){
    
    atod(-4858);

    return 0;
}

int atod(int n){

    if(n < 0){
        putchar('-');
        n *= -1;
    }
    if (n / 10){
        atod(n/10);

    }
    putchar((n % 10) + '0') ;
}