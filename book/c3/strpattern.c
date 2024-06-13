#include <stdio.h>
#define MAXLINE 1000

int getline(char saveto[], int limit);
int strindex(char source[], char pattern[]);
int strindexrtl(char source[], char pattern[]);
void addpadding(char result[], int lim);

int main(void){
    char input[MAXLINE];
    long unsigned long position = 0;
    char outoutindicator[MAXLINE];
    char pattern[] = "st";
    int instances = 0;
    while(getline(input, MAXLINE) > 0){
        if((position = strindexrtl(input, pattern)) >= 0){
            instances ++;
            addpadding(outoutindicator, position);
            printf("%s%s\n", input, outoutindicator);
        }
    }

    return instances;
}

void addpadding(char result[], int lim){
    int i = 0;
    for(i; i<lim;i++){
        result[i] = ' ';
    }
    result[i++] = '^';
    result[i] = '\0';
}

int strindex(char src[], char pattern[]){

    int i,j,k;

    for(i=0; src[i] != '\0'; i++){
        for(k=i, j=0; pattern[j] != '\0' && src[k] == pattern[j]; k++, j++){
            ;
        }
        if (j>0 && pattern[j]=='\0'){
            return i;
        }

    }
    return -1;
}

int strindexrtl(char src[], char pattern[]){

    int position = -1, i, j, k;

    for(i=0; src[i] != '\0'; i++){
        for(j=i, k=0; pattern[k] != '\0' && src[j] == pattern[k]; k++, j++){
            ;
        }
        if(k > 0 && pattern[k] == '\0' ){
            position = i;
        }
    }
    return position;

}



int getline(char line[], int lim){

    int i = 0, c;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n'){
        line[i++] = c;
    }
    if(c=='\n'){
        line[i++] = c;
    }
    line[i] = '\0';

    return i;
}