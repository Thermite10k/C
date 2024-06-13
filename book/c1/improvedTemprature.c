# include <stdio.h>

#define UPPER 1000
#define LOWER 0
#define STEP 20
void main(){
    float fahr = LOWER;
    for(fahr; fahr<=UPPER; fahr = fahr + STEP){
        printf("%6.1f : %6.2f\n", fahr, ((5.0/9.0)*(fahr-32)));
    }
    while(1){
        char c = getchar();
        // putchar(c);
        printf("%c",c);
    }
    
}