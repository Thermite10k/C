#include <stdio.h>
#include <time.h>

int onescount(long unsigned x);
int onescountfast(long unsigned x);

int main(void){

    long unsigned int x = 41841687684153; // 1101
    clock_t start = clock();
    printf("%d\n", onescount(x));
    clock_t end = clock();
    printf("Time to execute: %f0.20", (double)(end - start));

    start = clock();
    printf("%d\n", onescountfast(x));
    end = clock();
    printf("Time to execute: %f0.20", (double) (end - start));
    return 0;
}

int onescount(long unsigned x){

    int ones = 0;

    for (ones; x != 0; x >>= 1){
        if(x & 01){
            ones ++;
        }
    }

    return ones;
}

int onescountfast(long unsigned x){

  

    int ones = (x == 0) ? 0 : 1;
    
    while(x &= x-1){
        ones++;
    }

    return ones;
}