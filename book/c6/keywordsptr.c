#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define NKEYS (sizeof keytab / sizeof (struct key))
#define MAXWORD 100
int getword(char *, int limit);
int getch(void);
void ungetch(int c);
struct key *binsearch(char *name, struct key *keytab, int len);


struct key {
    char *name;
    int count;
};
// the keytab has to be sorted
struct key keytab[] = {
    {"char", 0},
    {"DEFINE", 0},
    {"int", 0},
};

int main(void){
    
    char word[MAXWORD];
    struct key *p;
    while(getword(word, MAXWORD) > 0){
        printf("%d\n", NKEYS);
        if((p = binsearch(word, keytab, NKEYS)) != NULL){
            p->count++; // ++p->count
        }
    }
    for(p = keytab; p <  keytab + NKEYS; p++){
        if(p->count > 0){
            printf("Count of %s: %d\n", p->name, p->count);
        }
    }

    return 0;
}

struct key *binsearch(char *name, struct key *tab, int len){
    int cond = 0;
    struct key *low = &tab[0];
    struct key *high = &tab[len];
    struct key *mid;

    while(low <= high){
        mid = low + (high - low) / 2;

        if((cond = strcmp(mid->name, name)) < 0){
            high = mid;
        }else if (cond > 0){
            low = mid + 1;
        }else{
            return mid;
        }
    }

    return NULL;

}

int getword(char *word, int limit){
    int c;
    while(isspace(c = getch())){
        ;
    }
    char *w = word;

    if(c != EOF)
        *w++ = c;
    if(!isalnum(c)){
        *w = '\0';
    }
    for(; --limit > 0 ; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    
    return word[0];

}

#define CHBUFF 100
int chbuffer[CHBUFF];
int chbuffpointer = 0;

int getch(void){
    if(chbuffpointer > 0){
        return chbuffer[--chbuffpointer];
    }
    return getchar();
}

void ungetch(int c){
    if(chbuffpointer < CHBUFF){
        chbuffer[chbuffpointer++] = c;
    }else{
        printf("error: char buffer is full");
    }
}