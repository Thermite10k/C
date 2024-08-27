#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORD 100
#define CHARBUFF 10
#define MAXLINE 1000

//int getword(int limit, char *word, FILE *fp);
//char getfilechar(FILE *fp);
//void ungetfilechar(char c);
int evaluate(char (*)[], int x, int y);
int getfileline(int limit, FILE *fp, char *line);

int main(void){
    char *line = (char *)malloc(MAXLINE); // char line[maxline] is also valid.
    int length = 0;
    FILE *fp;
    fp = fopen("key.txt", "r");
    while((length = getfileline(MAXLINE, fp, line))){
        printf("Line: \t%sLine: \t%d\n", line, length);
    }
    return 0;
}
//int getword(int limit, char *word);
//char getfilechar(FILE *fp);
//void ungetfilechar(char c);
int evaluate(char (*)[], int x, int y){
    return 0;
}
int getfileline(int limit, FILE *fp, char *line){ // char *line[] is an array of lines, not what we need.
    int i, c;
    for(i=0; (i < limit - 1) && (c = getc(fp)) != '\n' && c != EOF; i++){
        line[i] = c;
    }
    if(c == '\n'){
        line[i++] = c;
    }
    line[i] = '\0';


    return i;
}