#include <stdio.h>
/*
    Write a program entab that replaces strings of blanks by the
    minimum number of tabs and blanks to achieve the same spacing. Use the
    same tab stops as for detab. When either a tab or a single blank would suffice
    to reach a tab stop, which should be given preference? 
*/
#define MAXLINE 1000

int getline(char line[], int maxline);
void entab(char line[], int maxline);
int main(void){
    char line[MAXLINE];
    int len;
    while((len = getline(line, MAXLINE)) != 0){
        entab(line, len);
        printf("%s", line);
    }
    
    return 0;
}

void entab(char line[], int maxline){
    char newline[MAXLINE];
    int i,c, blanks =0, k = 0;

    for(i=0; (newline[i] = line[i]) != '\0'; i++)
        ;
    newline[i] = '\0';
    
    
    for(i=0; (c = newline[i]) != '\0'; i++){

        if(c == ' '){
            blanks++;
            if(blanks == 8){
                line[k++] = '\t';
                blanks = 0;
            }
        }else{
            while(blanks > 0){
                line[k++] = ' ';
                blanks--;
            }
            line[k++] = c;
        }       
    }
    line[k] = '\0';

}

int getline(char line[], int maxline){
    int i,c;

    for(i; i<maxline -1 && (c=getchar()) != EOF && c != '\n';i++){
        line[i] = c;
    }
    if(c == '\n'){
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;

}