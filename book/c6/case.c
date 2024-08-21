#include <stdio.h>
#include <ctype.h>

struct {
    unsigned upper : 1;
    unsigned lower : 1;
} flags;

int main(int argc, char *argv[]){
    int mode = 0, c;
    flags.lower = 0;
    flags.upper = 0;
    while(--argc > 0 && **++argv == '-'){
        while((c = *++*argv)){
            switch(c){
                case 'u':
                    flags.upper = 1;
                    break;
                case 'l':
                    flags.lower = 1;
                    break;
            }
        }
    }
    while((c = getchar()) != EOF){
        flags.lower && putchar(tolower(c));
        flags.upper && putchar(toupper(c));
        !(flags.upper | flags.lower) && putchar(c);
    }
    return 0;
}