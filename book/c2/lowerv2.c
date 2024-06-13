#include <stdio.h>

void lower(char s[]);

int main(void){

    char s[] = "This WiLL be A TEsT!";
    lower(s);
    printf("%s\n", s);

    return 0;
}

void lower(char s[]){

   
    char c;
    int i = 0;
    while((c = s[i]) != '\0'){
        s[i] = (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
        i++;
    }
}