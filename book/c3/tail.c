#include <stdio.h>
#include <ctype.h>
#define MAXLINES 200
#define LIMIT 100
/*
    This program utilizes dynamic storage and prints the last n (default 10) lines of input to output.
*/

char *alloc(int size);
void afree(char *p);

void strcp(char *s1, char *s2);
int getline(char *line, int limit);
int readlines(char *lines[], int maxlinelen);
int getn(int argc, char *argv[]);

int main(int argc, char *argv[]){
    int nval;
    nval = (nval = getn(argc, argv)) ? nval : 10;

    printf("%d\n", nval);

    char *lines[MAXLINES];
    int nlines;
    if((nlines = readlines(lines, LIMIT))){
        int i = nval;
        if(nlines >= i){
            i =  nlines - i;
            nlines = nlines - i;
            while(nlines--){
                printf("%s\n",*(lines+i++));
            }
        }
    }

    return 0;
}

int getline(char *line, int limit){

    int c, i=0;

    while(--limit > 0 && (c = getchar()) != EOF && c != '\n'){
        *(line + i++) = c;
    }
    if(c=='\n'){
        *(line + i++) = c;
    }
    
    *(line + i) = '\0';

    return i;
}

int memsize = 20000; // 100*200
char memory[20000];
char *memp = memory;

char *alloc(int size){
    if(size < 0){
        return NULL;
    }
    if((memory + memsize - memp) > size){
        memp += size;
        return memp - size;
    }else{
        printf("error: memory is full.");
        return NULL;
    }

}

void afree(char *p){
    memp = p;
}

void strcp(char *s1, char *s2){
    while(*s1++ = *s2++){
        ;
    }
        
}

int readlines(char *lines[], int maxlinelen){
    int nlines = 0, len;
    char line[maxlinelen];
    char *p;
    while((len = getline(line, maxlinelen)) > 0  ){
        if(len > maxlinelen){
            printf("error: length of line out of bound");
        }
        p = alloc(len);
        if(p  != 0){
            
        

            line[len - 1] = '\0';
            strcp(p, line);

            lines[nlines++] = p;
        }
    }
    return nlines;
}
int getn(int argc, char *argv[]){
    char c;
    int nval = 0;
    while(--argc && (*++argv)[0] == '-'){ // *++argv points to a string, [0] gets the first char.
           while( c = *++argv[0]){// [] binds tighter than * and ++ so argv is not changed.
            if(isdigit(c)){
                nval = nval * 10 + c - '0';
            }
           }
    }
    return nval;
}