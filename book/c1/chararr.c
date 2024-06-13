#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void){
    int len; /* current line length */
    int max; /* maximum line length */

    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while((len = getline(line, MAXLINE)) > 0){
        if (len > max){
            max = len;
            copy(longest, line);
        }
    }

    if(max > 0){
        printf("%s", longest);
    }

    return 0;
}

int getline(char line[], int maxline){
    int c, i; 

    for(i = 0; i<maxline && (c = getchar()) != EOF && c != '\n'; i++){
        line[i] = c;
    }
    if (c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i = 0;
    // while(from[i] != '\0'){
    //     to[i] = from[i];
    //     ++i;
    // }

    for(i; (to[i] = from[i] )!= '\0'; i++)
        ;
}