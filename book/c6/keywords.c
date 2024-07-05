#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NKEYS  (sizeof keytab / sizeof keytab[0])
/*
    #define NKEYS (sizeof keytab / sizeof(struct key))

    sizeof object && sizeof(type)
*/
#define MAXWORD 100
struct key {
    char *name;
    int count;
};

struct key keytab[] = {
    {"break", 0},
    {"char", 0},
    {"int", 0},
    {"return", 0},
    {"void", 0},
};
/* 

could've been declated like this too:

struct key {...} keytab[NKEYS] // to add values// = {"name1", 0, name2, 0,...};

*/
int getch(void);
void ungetch(int c);
int binsearch(char *, struct key *, int); // get a char ptr, a ptr to a struct of key and an int
int getword(char *word, int limit);

// counts keywords

int main(int argc, char* argv[]){

    int n = 0;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF){
        if(isalpha(word[0])){

            if((n = binsearch(word, keytab, NKEYS)) >= 0){
                keytab[n].count++;
            }

        }
    }
    for(n = 0; n < NKEYS; n++){
        if(keytab[n].count){
            printf("Occurances of %s: %d\n",keytab[n].name, keytab[n].count);
        }
    }

    return 0;
}

int binsearch(char *word, struct key tab[], int n){
    int cond, low, mid, high;
    
    low = 0;
    high = n-1;

    while(low <= high){
        mid = (low + high)/ 2;
        if((cond = strcmp(word, tab[mid].name)) < 0){
            high = mid - 1;
        }   
        else if (cond > 0){
            low = mid + 1;
        }else{
            return mid;
        }
        }
    
    return -1;
}

int getword(char *word, int lim){
    int c;
    
    char *w = word;

    while(isspace(c = getch())){
        ;
    }
    if(c != EOF){
        *w++ = c;
    }
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for( ; --lim > 0; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';

    return word[0];
}

#define CHBUFF 10

int charbuffer[CHBUFF];
int charbufferpointer = 0;

int getch(void){
    if(charbufferpointer > 0){
        return charbuffer[--charbufferpointer];
    }
    return getchar();

}

void ungetch(int c){

    if(charbufferpointer < CHBUFF){
        charbuffer[charbufferpointer++] = c;
    }else{
        printf("error: Char buffer is full");
    }
}