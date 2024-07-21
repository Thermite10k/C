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

    printf("Val is: %d\n", val);

    return 0;
}