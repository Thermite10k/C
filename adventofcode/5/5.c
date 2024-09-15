#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define CHARBUFFSIZE 100
#define KEYFILE "key.txt"
#define MAXLINE 100
#define MAXSEEDS 100

char getfilechar(FILE *fp);
void ungetfilechar(char c);
int getfileline(FILE *fp, int limit, char *line);
int getlineword(char **line, char *word, int limit);

int main(int argc, char *argv[]){
    int linestatus;
    FILE *fp = fopen(KEYFILE, "r");
    char line[MAXLINE];
    char *lineptr;
    char word[MAXLINE];
    int seeds[MAXSEEDS];
    int seedindex = 0;
    char *newmap = "%[^-]-to-%[^ ] map:";
    char *from[MAXLINE], *to[MAXLINE];

    /* First line contains the seeds */
    getfileline(fp, MAXLINE, line); // storing the seeds in line
    lineptr = line;
    while(getlineword(&lineptr, word, MAXLINE) != '\0'){
        if(seedindex < MAXSEEDS && isdigit(*word)){
            seeds[seedindex++] = atoi(word);
        }
    }

    // for(int i = 0; i<seedindex; i++){
    //     printf("%d ", seeds[i]);
    // }


    while(getfileline(fp, MAXLINE, line) != EOF){
        lineptr = line;
        int scanstatus = 0;
        //printf("%s", line);
        if((scanstatus = sscanf(line, newmap, from, to)) == 2){
            printf("%s to %s\n", from, to);
        }
        // while((linestatus = getlineword(&lineptr, word, MAXLINE)) != EOF && linestatus !='\0'){
        //     printf("%s\n", word);
        // }
    }

    return 0;
}

char charbuffer[CHARBUFFSIZE];
int charbufferptr = 0;
char getfilechar(FILE *fp){
    char c;
    if(charbufferptr > 0){
        return charbuffer[--charbufferptr];
    }else{
        return getc(fp);
        
    }
}
void ungetfilechar(char c){
    if(charbufferptr < CHARBUFFSIZE){
        charbuffer[charbufferptr++] = c;
    }else{
        fprintf(stderr, "ungetfilechar: buffer is full.");
    }
}
int getfileline(FILE *fp, int limit, char *line){
    
    int c;
    char *w = line;

    while(--limit > 0 && (c = getfilechar(fp)) != EOF && c != '\n'){
        *w++ = c;
    }
    if(c == '\n' || c == EOF){
        *w++ = c;
    }
    *w = '\0';

    return line[0];
    
}

int getlineword(char **line, char *word, int limit){
    int c;
    char *w = word;

    while(isspace((c = *(*line)++))){
        ;
    }
    if(c != EOF){
        *w++ = c;
    }
    if(c == '\0' || !isalnum(c)){
        *w = '\0';
        return c;
    }

    for(; --limit > 0; (*line)++, w++){
        if(!isalnum(*w = **line)){
            break;
        }
    }

    *w = '\0';
    return word[0];
}