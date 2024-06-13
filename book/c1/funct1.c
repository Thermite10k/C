#include <stdio.h>

#define STEP 20.0
float celi(float fahr);

int main(void){
    float fahr, step;
    step = STEP;

    for(fahr; fahr<=300; fahr += STEP){
        printf("%3.0f %6.2f\n", fahr, celi(fahr));
    }

    return 0;
}

float celi(float fahr){
    return((5.0/9.0) * (fahr-32.0));
}