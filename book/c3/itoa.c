#include <stdio.h>

void itoa(int n, char s[], int width);

int main(void){
    int n = -145, width = 6;
    char s[32];
    itoa(n, s, width);
    printf("%s", s);
    return 0;
}

void itoa(int n, char s[], int width){

    int i=0, sign, len, padding;

    if((sign = n) < 0){
        n = -n;
    }
    while(n > 0){
        s[i++] = (n%10) + '0';
        n /= 10;
    }
    if(sign < 0){
        s[i++] = '-';
    }
    padding = width - i;
    while(padding > 0){
        s[i++] = ' ';
        padding--;
    }
    s[i--] = '\0';
    for(int k = 0; k<i; i--, k++){
        int temp  = s[i];
        s[i] = s[k];
        s[k] = temp;
    }


}