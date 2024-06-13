#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void){
    char s1[] = "this will be quite interesting";
    char s2[] = "intervals are the distance between notes";
    

    squeeze(s1, s2);
    printf("%s", s1);
    return 0;
}

void squeeze(char s1[], char s2[]){
    int i = 0, j = 0;
    while(s1[i++] != '\0') /* Finds the length of s1*/
        ;
    char news1[i];

    int k = 0;
    i = j = 0;
    int copy = 1;

    while(s1[i] != '\0'){
        copy = 1;
        for(j = 0; s2[j] != '\0'; j++){
            if(s1[i] == s2[j]){
                copy = 0;
                break;
            }
        }
        if(copy){
            news1[k++] = s1[i];
        }
        i++;
    }
    news1[k] = '\0';
    for(j = 0; (s1[j] = news1[j]) != '\0'; j++)
        ;
    s1[j] = '\0';

}