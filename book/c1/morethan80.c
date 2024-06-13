#include <stdio.h>
#define MINLEN 10
#define MAXLINE 1000

int getline(char line[], int maxline);

int main(){
   
    char line[MAXLINE];
    int len = 0;

    while((len = getline(line, MAXLINE)) > 0){
        if(len > MINLEN){

            printf("%s", line);
        }
    }



    return 0;
}

int getline(char line[], int maxline){
    int c;
    int i = 0;
    for(i; i<maxline && (c = getchar()) != EOF && c != '\n'; i++){
        line[i] = c;
    }
    if(c == '\n' && i < maxline){
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    printf("%d", i);
    return i;

}
