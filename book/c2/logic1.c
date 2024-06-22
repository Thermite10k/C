#include <stdio.h>

int setbits(int x, int p, int n, int y);
int setbits2(int x, int p, int n, int y);

/*Return x with the n bits that begin at position p  set to the rightmost n bits of y, leaving the rest of the bits unchanged*/

int main(void){
    int x = 4736, y = 110, p = 11 , n = 5;
    printf("%d \n", setbits(x,p,n,y));
    printf("%d \n", setbits2(x,p,n,y));
    return 0;
}

int setbits(int x, int p, int n, int y){

    int oldx = x; // 1101 0011

    x = x >> (p+1-n); // 1101 0011 => (p=3,n=2) =>  x>>2 => 1101 00
    y = y & ~(~0 << n); // 1111 1111 => 1111 1111 & ~(1111 1100) => 0000 0011
    x = x & ~0 << n; // clear the old bits from x 1101 00 => 1101 00 (they were alrady 0)
    x = x | y; // 11 0100 | 0000 0011 => 110111
    x = x<<(p+1-n); // 110111 => 1101 1100
    oldx = oldx & ~(~0 << p+1-n);
    x = x | oldx; // 1101 1100 | 1101 0011 => 1101 1111
    
    return x;
}

int setbits2(int x, int p, int n, int y){

    x = x &( ~(~0 << (p+1-n)) | ~0 << p+1 );
    y = (y & ~(~0 << n))<< (p+1-n);
    return x | y;

}