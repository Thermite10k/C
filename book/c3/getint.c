#include <stdio.h>

int getch();
void ungetch(int c);
int getint(int *);
int getfloat(double *);
int main(void){

    int arrsize = 100, i;
    double array[arrsize];

    for(i=0; i<arrsize && getfloat(&array[i]) != EOF;i++){
        ;
    }
    i--;
    for(i; i >=0; i--){
        printf("%f\n", array[i]);

    }

    return 0;
}


/* get int: get the next integer from input to *pn */
#include <ctype.h>

int getint(int *pn){

    int c, sign;

    while(isspace(c = getch())){
        ;
    }
    if(!isdigit(c) && c!= EOF && c != '+' && c!= '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ?  -1 : 1;
    int m;
    if(c == '-' || c == '+'){
        while(isspace(c = getch())){
            ;
        }
    }
    *pn = 0;
    while(isdigit(c)){
        *pn = 10 * *pn + (c - '0');
        c = getch();
    }
    *pn *= sign;
    if(c != EOF){
        ungetch(c);
    }
    return c;

}

int getfloat(double *pn){

    int c, sign, power;

    while(isspace(c = getch())){
        ;
    }
    if(!isdigit(c) && c!= EOF && c != '-' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    *pn = 0.0;
    if(c == '-' || c == '+'){

        while(isspace(c = getch())){
            ;
        }
    }
    for(*pn; isdigit(c); c = getch()){
        *pn = 10.0 * *pn + (c - '0');
    }
    if(c == '.'){
        c = getch();
    }
    for(power = 1.0; isdigit(c); c = getch()){
        power *= 10.0;
        *pn = *pn * 10.0 + (c - '0');
    }
    *pn /= power;
    *pn *= sign;
    if(c != EOF) {
        ungetch(c);
    }
    return c;
}






#define MAXBUF 100

int buffer[MAXBUF];
int bp = 0; /* current empty buffer position */

int getch(){
    return (bp > 0) ? buffer[--bp] : getchar();
}

void ungetch(int c){
    if(bp < MAXBUF){
        buffer[bp++] = c;
    }else{
        printf("error: buffer is full.");
    }
}