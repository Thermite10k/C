#include <stdio.h>

void main(){
    float f,c;
    int min, max, step;

    min = 0;
    max = 300;
    step = 20;

    for(min; min<=max; min+=step){
        f=min;
        c = (5.0/9.0) * (f-32);
        printf("%3.2f %6.2f\n", f,c);
    }
    while(1){

    }
}
