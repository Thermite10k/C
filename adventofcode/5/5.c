#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define CHARBUFFSIZE 100
#define KEYFILE "key.txt"
#define MAXLINE 1000
#define MAXSEEDS 100

char getfilechar(FILE *fp);
void ungetfilechar(char c);
int getfileline(FILE *fp, int limit, char *line);
int getlineword(char **line, char *word, int limit);
 long long myatoi(char *word);
 long long updatesrc( long long src,   long long from,   long long to,   long long range);

int main(int argc, char *argv[]){
    int wordstatus, linestatus, i;
     long long dest = 0;
    FILE *fp = fopen(KEYFILE, "r");
    char line[MAXLINE];
    char *lineptr;
    char word[MAXLINE];
     long long src[MAXSEEDS];
     long long updatedsrc[MAXSEEDS];
    int srcindex = 0;
    char *newmap = "%[^-]-to-%[^ ] map:";
    char *map = "%lld%lld%lld";
    char *from[MAXLINE], *to[MAXLINE];
    long long int rangeto, rangefrom, range;
    /* First line contains the seeds */
    getfileline(fp, MAXLINE, line); // storing the seeds in line
    lineptr = line;
    while(getlineword(&lineptr, word, MAXLINE) != '\0'){
        if(srcindex < MAXSEEDS && isdigit(*word)){
            printf("%lld ", (src[srcindex++] = myatoi(word)));
            updatedsrc[i] = 0;
        }
    }
    printf("\n");



    while((linestatus = getfileline(fp, MAXLINE, line)) != EOF){
        lineptr = line;
        int scanstatus = 0;
        //printf("%s", line);
        if((scanstatus = sscanf(line, newmap, from, to)) == 2){
            //printf("%s to %s\n", from, to);
        }else if ((scanstatus = sscanf(line, map, &rangeto, &rangefrom, &range)) == 3){
            printf("Going from %lld to %lld with range: %lld\n", rangefrom, rangeto, range);
            // while((wordstatus = getlineword(&lineptr, word, MAXLINE)) != EOF && wordstatus !='\0'){         
            // }
            for(i=0; (i < srcindex); i++){
                if(src[i]){ // if src has not been updated, (we set it to zero if it's updated)
                    dest = updatesrc(src[i], rangefrom, rangeto, range);
                    if(dest){ // if it has a value within range
                        printf("%lld goes to %lld\n", src[i], dest);
                        updatedsrc[i] = dest;
                        src[i] = 0; // if we have an updated value, do not check src[i] again.
                    }

                }
            }
            
        }
        /*
            Now we check the updatedsrc and src, if src has not been mapped to a new one, we keep it, and replace the updated ones with new values.
        */
        if(linestatus == '\n'){
            for(i=0; i < srcindex; i++){
                if(!src[i]){
                    src[i] = updatedsrc[i];
                    updatedsrc[i] = 0;
                }
            }
        }
    }
    /* 
        Findinding the final answer.
     */
    long long min = src[0];
    for(i = 0; i<srcindex; i++){
        min = src[i] < min ? src[i] : min;
    }

    printf("\n\t%lld", min);
    

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
/*
    Check whether or not an src is in range.
*/
long long updatesrc( long long src,  long long from,  long long to,  long long range){
    long long step = to - from;

    if(src >= from && src < (from + range)){
        return (src + step);
    }else{
        return 0;
    }
}
 long long myatoi(char *word){
     long long number = 0;
    while(*word){
        number = 10 * number + *word - '0';
        word++;
    }

    return number;
}