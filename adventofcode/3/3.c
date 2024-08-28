#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100
#define CHARBUFF 10
#define MAXLINE 1000
#define MAXWORD 100
#define MAX(a,b) ((a > b) ? a : b)

//int getword(int limit, char *word, FILE *fp);
//char getfilechar(FILE *fp);
//void ungetfilechar(char c);
int evaluate(char (*)[], int x, int y);
int iteratepuzzle(char **puzzle, int rows, int cols);
int getfileline(int limit, FILE *fp, char *line);
int getwordfromline(char *line, char *word, int limit);
int main(void){
    char *line = (char *)malloc(MAXLINE); // char line[maxline] is also valid.
    int length = 0; // columns
    int *ROWS = malloc(sizeof(int));
    int *COLS = malloc(sizeof(int));
    *COLS = 0;
    *ROWS = 0;
    char **puzzle = (char **)malloc(MAXLINE);
    char **pp = puzzle;
    FILE *fp;
    fp = fopen("key.txt", "r");
    while((length = getfileline(MAXLINE, fp, line))){
        //printf("Line: \t%sLine: \t%d\n", line, length);
        *pp = (char *)malloc(length); //puzzle pointer
        memcpy(*pp, line, length);
        *pp++;
        (*ROWS)++;
        *COLS = MAX(*COLS, length-1);
    }
    printf("%d rows.\n", *ROWS);
    printf("%d cols.\n", *COLS);
    char *myline = "This is a test...*string";
    char *lineptr = myline;
    char word[MAXWORD];
    while(*lineptr != '\0'){

        if(getwordfromline(lineptr, word, MAXWORD)){
            printf("%s\n", word);
            lineptr += strlen(word);
            while(isspace(*lineptr)){
                lineptr++;
            }
        }
    }

    //iteratepuzzle(puzzle, *ROWS, *COLS);

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

int iteratepuzzle(char **puzzle, int rows, int cols){
    int x = 0, y = 0;
    char word[MAXWORD];
    for(y=0; y<rows; y++){
        // for(x=0; x<=cols; x++){
        //     //printf("%c", puzzle[y][x]);
        //     printf("%c", *(*(puzzle + y) + x));
        // }
        while(getwordfromline(*(puzzle + y), word, MAXWORD)){
        printf("%s", word);
            
        }
    }
}
int getwordfromline(char *line, char *word, int limit){

    int c;
    char *w = word;
    while(isspace((c = *line++))){
        ;
    }
    if(c != EOF){
        *w++ = c;
    }
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for(; --limit > 0; line++, w++){
        
        if(!isalnum((*w = *line))){
            line--;
            break;
        }
    }

    *w = '\0';
    return word[0];

}