#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

double atof(char src[]);
int getline(char line[], int lim);
int main(void){

    char line[MAXLINE];
    while(getline(line, MAXLINE) > 0){
        printf("%f\n", atof(line));
    }

    return 0;
}

int getline(char line[], int lim){

    int i = 0, c;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n' ){
        line[i++] = c;
    }

    if(c == '\n'){
        line[i++] = c;
    }
    line[i] = '\0';

    return i;

}

double atof(char src[]){
    int i, sign, expsign, expval = 0, exppower = 1, isexp = 0;
    double val, power;

    for(i=0; isspace(src[i]); i++){ 
        ;
    }
    sign = src[i] == '-' ? -1 : 1; 
    if(src[i] == '-' || src[i] == '+'){

        i++;
    }
    for(val = 0.0; isdigit(src[i]); i++){
        val = 10.0 * val + (src[i] - '0');
    }
    if(src[i] == '.'){
        i++;
    }
    for(power = 1.0; isdigit(src[i]); i++){
        val = 10.0 * val + (src[i] - '0');
        power *= 10.0;
    }
    if(src[i] == 'e' || src[i] == 'E'){
        isexp = 1;
        i++;
        expsign = src[i] == '-' ? -1 : 1;
        if(src[i] == '-' || src[i] == '+'){
            i++;
        }
        for(expval=0.0;isdigit(src[i]); i++){
            expval = expval * 10.0 + (src[i] - '0');
        }
        while(expval > 0){
            exppower = exppower * 10;
            expval--;
        }
    }
    val = sign * val / power;
    if(isexp){
        if(expsign == 1){
            return val * exppower;
        }
        return val / exppower;
    }
    return val;
}