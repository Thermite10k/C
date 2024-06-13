#include <stdio.h>
#include "alloc.h"


int main(void){
    char *myspace = alloc(10);
    int i;
    *myspace = 0;
    for(i=0; i <10; i++){
        // *myspace = 2 * i;
        // myspace++;
        // the two lines above do the same thing as the line below
        *(myspace + i) = i;
        // value (*) of alloc + i(myspace[i])
    }
    i--;
    for(i; i >= 0; i--){
        printf("%c", (*myspace + i)+'0');
    }
    return 0;
}