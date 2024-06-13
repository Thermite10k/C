#include <stdio.h>

#define IN 1 /* Inside of a word */
#define OUT 0 /* Outside of a word */

// count the number of lines, words, and characters

int main(){
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nc = nw = 0;

    while((c = getchar()) != 'A'){
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' '|| c == '\n' || c== '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        }
    }
    printf("Words: %d lines: %d letters: %d", nw, nl, nc);
    return 0;
}

