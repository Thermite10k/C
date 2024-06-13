#include <stdio.h>

void main(){
    int c;
    //printf("%i",EOF);
    
    // while((c = getchar()) != EOF){
    //     putchar(c);
    //     c = getchar();
    // }
    //  while(c = (getchar() != EOF)){
    //     putchar(c);
    //     c = getchar();
    // }
    // while(1){

    //     printf("%d", getchar() != EOF);
    // }
    // long nc;

    // nc = 0;
    // while(getchar() != EOF){
    //     ++nc;
    //     printf("%ld", nc);
    // }
    double nc;
    for (nc = 0; getchar() != '1'; nc++)
        ;
    printf("%.0f", nc);
    while(1)
        ;
}