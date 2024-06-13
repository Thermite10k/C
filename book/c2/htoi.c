#include <stdio.h>

 /* 
    0xffff\0
 */

long htoi(char s[]);
int power(int base, int p);
int main(void){

    printf("%ld", htoi("0xf000"));

    return 0;
}

int power(int base, int p){
    int i = 0, result = 1;
    for(i; i<p; i++){
        result = result * base;
    }
    return result;
}

long htoi(char s[]){
    long value = 0;
    int charVal=0;
    int i=1;
    int len = 0;
    while(s[len+1] != '\0')
        len++;

    
    while (len >= 0 ){
        if(s[len] == 'x' || s[len] == 'X' ){
            break;
        }
        charVal = s[len];
        if(charVal >= '0' && charVal <= '9'){
        
            value = value  + (s[len--] - '0') * i ;
        }else if(charVal >= 'a' && charVal <= 'f'){
            value = value  + (s[len--] - 'a' + 10) * i ;

        }else if (charVal >= 'A' && charVal <= 'F'){
            value = value  + (s[len--] - 'A' + 10) * i ;

        }
        i *= 16;

    }
    return value;
}