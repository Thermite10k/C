#include <stdio.h>

#define MAXLINE 2000

int getline(char line[], int maxlen);
void decoment(char line[], int maxlen);
int main(void){

    int c, len;
    char line[MAXLINE];
    
    while((len = getline(line, MAXLINE)) != 0){
        decoment(line, MAXLINE);
        printf("%s", line);
    }

    return 0;
}
/* some stupid shit*/
// some stupid shit
void decoment(char line[], int maxlen){
    char newline[maxlen];
    int i = 0, c, k = 0, incomment=0, inquote=0;
    for(i;(newline[i] = line[i]) != '\0'; i++)
        ;
    newline[i] = '\0';
    for(i = 0; (c = newline[i]) != '\b'; i++){
        if(c == '\"'){
            inquote = !inquote;
        }
        if(!inquote){
            
            if(c == '/'){
                if(newline[i+1] != '\b' && newline[i+1] == '*'){
                    incomment = 1;
                }
            }
            if(incomment == 1 && c == '*'){
                if(newline[i+1] != '\b' && newline[i+1] == '/'){
                    incomment = 0;
                    if(i+2 < maxlen){
                        i +=2;
                        c = newline[i];
                    }
                }
            }
        }
        if(!incomment){
            line[k++] = c;
        }
    }
    line[k] = '\b';
}
int getline(char line[], int maxlen){

    int i, c;

    for(i=0; i < maxlen-1 && (c=getchar()) != EOF && c != '\n'; i++){
        line[i] = c;
    }

    if(c == '\n'){
        line[i++] = '\n';
    }
    line[i] = '\0';
    return i;
}