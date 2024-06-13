#include <stdio.h>

int invert(int x, int p, int y);
int rightrot(int x, int n);
int nbits(int x);
int nbits2(int x);
int main(void){

    printf("%d", rightrot(57, 2));

    return 0;

}

int invert(int x, int p, int n){
    int mask, mask2;

    mask = ~0 << p+1;
    mask2 = ~(~0 << p+1-n);
    mask = ~(mask | mask2);
    return x ^ mask;

}

int rightrot(int x, int n){

    int numberofbits = nbits2(x);
    int lost = x & ~(~0 << n);
    x = x >> n;
    x = x | lost << (numberofbits - n);
    return x;


}

int nbits(int x){

    int i = 1;

    for(i; (x = x / 2) > 0; i++ ){

        ;
    }

    return i;
}

int nbits2(int x){
    int i = 1;
    
    for(i; (x >>= 1) != 0 ; i++){
        ;
    }
    return i;
}