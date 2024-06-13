#include <stdio.h>

/*
    Write a program *detab* that replaces tabs in the input with the proper number of blanks
    to space to the next tab stop. assume a fixed set of tab stops, sat every n columns. 
    should n be a variable or a symbolic parameter?
    
*/
#define MAXLINE 1000

int getline(char line[], int maxline);
void detab(char line[]);

int main(void){

    char line[MAXLINE];
    int len;

    while((len = getline(line, MAXLINE)) != 0){
        detab(line);
        printf("%s", line);
    }
    return 0;
}

void detab(char line[]){

    char newline[MAXLINE];
    int c, i, j = 0;
    for(i = 0; (newline[i] = line[i]) != '\0'; i++)
        ;
    newline[i] = '\0';
    

    for(i=0; (c = newline[i]) != '\0'; i++){
        if(c != '\t'){
            line[j] = newline[i];
            j++;
        }
        else if(c == '\t' && i != 0){
            for(int k = j; k < j+4; k++){
                line[k] = ' ';
            }
            j += 4;
        }else if(c == '\t' && i == 0){
            for(int k = j; k<j+8; k++){
                line[k] = ' ';
            }
            j +=8;
        }

    }
    line[j] = '\0';




}


int getline(char line[], int maxline){

    int i, c;

    for(i=0; (i< maxline-1) && (c = getchar()) != EOF && c != '\n'; i++ ){
        line[i] = c;
    }

    if(c == '\n'){
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i; // i is length.

}
