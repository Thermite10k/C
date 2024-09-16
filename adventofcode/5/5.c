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
long updatesrc(long src, long from, long to, long range);

int main(int argc, char *argv[]){
    int wordstatus, linestatus;
    FILE *fp = fopen(KEYFILE, "r");
    char line[MAXLINE];
    char *lineptr;
    char word[MAXLINE];
    long src[MAXSEEDS];
    long updatedsrc[MAXSEEDS];
    int srcindex = 0;
    char *newmap = "%[^-]-to-%[^ ] map:";
    char *map = "%d%d%d";
    char *from[MAXLINE], *to[MAXLINE];
    long rangeto, rangefrom, range;
    /* First line contains the seeds */
    getfileline(fp, MAXLINE, line); // storing the seeds in line
    lineptr = line;
    while(getlineword(&lineptr, word, MAXLINE) != '\0'){
        if(srcindex < MAXSEEDS && isdigit(*word)){
            src[srcindex++] = atoi(word);
        }
    }

    for(int i = 0; i<srcindex; i++){
        printf("%d ", src[i]);
    }


    while((linestatus = getfileline(fp, MAXLINE, line)) != EOF){
        lineptr = line;
        int scanstatus = 0;
        //printf("%s", line);
        if((scanstatus = sscanf(line, newmap, from, to)) == 2){
            printf("%s to %s\n", from, to);
        }else if ((scanstatus = sscanf(line, map, &rangeto, &rangefrom, &range)) == 3){
            printf("Going from %d to %d with range: %d\n", rangefrom, rangeto, range);
            // while((wordstatus = getlineword(&lineptr, word, MAXLINE)) != EOF && wordstatus !='\0'){         
            // }
            
        }
        if(linestatus == '\n'){
            printf("END OF MAP\n");

        }
    }
    // src from to range

    printf("\n%d", updatesrc(79, 50, 52, 48));

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
long updatesrc(long src, long from, long to, long range){
    long step = to - from;

    if(src >= from && src <= from + range){
        return (src + step);
    }else{
        return src;
    }
}