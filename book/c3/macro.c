#include <stdio.h>
#define dprint(exp) printf(#exp " = %d", exp)
#define concat(a, b) a ## b
#define swap(a,b) a = a^b;\
                  b= a^b;\
                  a=a^b;
int main(void){

    dprint(12*8);
    int a = 1,  b =2;
    swap(a, b);
    dprint(a);
    dprint(b);
    return 0;
}