#include <stdio.h>
#include <ctype.h>

int strend(char *str1, char *str2);
int winstr(char *s, char *w);


int main(void){
    char str1[] = "This is a test strinG";
    char str2[] = "This is a strinG";
    char w[] = "a";

    printf("%d\n", strend(str1, str2));
    printf("%d\n", winstr(str1, w));
    return 0;
}


int strend(char *str1, char *str2){

    int  len1 = 0, len2 = 0;
    
    while(*str1++){
        len1++;
    }
        
    while(*str2++){
        len2++;
    }
    if(len2 > len1){
        return -1;
    }
        
    
    while(*str1-- == *str2-- && len2-- > 0 && *str1 != ' '){
        ;
    }
    if(*str1++ == ' '){
        return 1;
    }
    return 0;
}

int winstr(char *s, char *w){

    int inword = 0;
    char *wbp = w;
    while(isspace(*s))
        s++;

    while(*s){
     
        while((*s == *w) && *w != '\0'){
            s++;
            w++;
        }
        if (*w == '\0'){
            return 1;
        }
        w = wbp;


        s++;
        
    }
    return 0;

}