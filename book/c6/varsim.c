#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

int getword(char *word, int limit);
char getch(void);
void ungetch(char c);

int main(int argc, char *argv[]){
    // [*, *, ..., *]
    int c;
    int val = 0;
    
    while(--argc > 0 && **++argv == '-'){
        while((c = *++*argv)){
            switch(c){
                case 'l':
                    
                    while(isdigit((c = *++*argv))){
                        val = 10 * val + c - '0';
                    }
                    break;
                default:
                    printf("\"%s\" is not a valid argument.\n");
            }

        }
    }

    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF){
        printf("%s\n", word);
    }

    printf("Val is: %d\n", val);

    return 0;
}

int getword(char *word, int limit){

    int c;
    
    while(isspace(c = getch())){
        ;
    }
    char *w = word;
    if(c != EOF){
        *w++ = c; 
    }
    if(!isalnum(c)){
        *w = '\0';
        return c;
    }
    for(; --limit; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];

}

#define BUFFSIZE 100

char buffer[BUFFSIZE];
int bufferindex = 0;

char getch(void){
    if(bufferindex > 0){
        return buffer[--bufferindex];
    }else{
        return getchar();
    }
}
void ungetch(char c){
    if(bufferindex < BUFFSIZE){
        buffer[bufferindex++] = c;
    }else{
        printf("error: ungetch: buffer is full.");
    }
}

