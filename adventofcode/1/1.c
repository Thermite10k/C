#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int getline(char *line, int limit, FILE *fp);

int main(void){

    char line[MAXLINE];
    char *lptr, numberOfDigits = 2, position = 0;
    long int lineIntVal = 0, answer = 0;
    int len;
    FILE *fp;
    fp = fopen("key.txt", "r");

    while((len = getline(line, MAXLINE, fp)) != '\0'){
        len--; // to skip the \0
        lptr = line;
        lineIntVal = 0;
        while(!isdigit(*lptr)){
            lptr++;
        }
        lineIntVal = 10 * lineIntVal + *lptr - '0';
        lptr = line + len;
        while(!isdigit(*lptr)){
            lptr--;
        }
        lineIntVal = 10 * lineIntVal + *lptr - '0';
        printf("%d\n", lineIntVal);
        answer += lineIntVal;
    }

    printf("%ld", answer);
    
}
int getline(char *line, int limit, FILE *fp){

    int c = 0, i;

    for(i=0; (i < limit-1) && (c = getc(fp)) != '\n' && c != EOF; i++){
        line[i] = c;
    }
    if(c == '\n'){
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}