#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD 100
#define CHARBUFF 10
#define HASHSIZE 100
#define MAX(a, b) ((a > b) ? a : b)
#define NKEYS (sizeof colors / sizeof (struct color))

struct nlist {
    struct nlist *next;
    char *name;
    int value;
    int maxVal;
};
struct color {
    char *color;
    int value;
    int maxVal;
};

struct color colors[] = {
    {"red", 0, 12},
    {"green", 0, 13},
    {"blue", 0, 14},

};

static struct nlist *hashtab[HASHSIZE];

struct nlist *lookup(char *name);
unsigned hash(char *name);
struct nlist *install(char *name, int value, int maxVal);

void addkeys(int nkeys, struct color *);


int getword(int limit, char *word, FILE *fp);
char getfilechar(FILE *fp);
void ungetfilechar(char c);
unsigned hash(char *word);
int wordprocessor(char *word, unsigned *powerset);

int main(void){
    FILE *fp;
    int answer = 0;
    unsigned *powerset = (unsigned *) malloc(sizeof(unsigned));
    *powerset = 0;
    char word[MAXWORD];
    addkeys(NKEYS, colors);
    fp = fopen("key.txt", "r");
    while( getword(MAXWORD, word, fp) != EOF){
        answer += wordprocessor(word, powerset);
        
    }
 
    printf("%d\n", answer);
    printf("%d\n", *powerset);

    return 0;
}


int getword(int limit, char *word, FILE *fp){

    int c;
    char *w = word;
    while(isspace((c = getfilechar(fp)))){
        ;
    }
    if(c != EOF){
        *w++ = c;
    }
    if(!isalnum(c)){
        *w = '\0';
        return c;
    }
    while((--limit > 0)){
        if(isalnum((c = getfilechar(fp)))){
            *w++ = c;
        }else{
            ungetfilechar(c);
            break;
        }
    }
    *w = '\0';
    return word[0];
}


int charbuffer[CHARBUFF];
int charbufferpointer = 0;

char getfilechar(FILE *fp){
    if(charbufferpointer > 0){
        return charbuffer[--charbufferpointer];
    }else{
        return getc(fp);
    }
}

void ungetfilechar(char c){
    if(charbufferpointer < CHARBUFF){
        charbuffer[charbufferpointer++] = c;
    }else{
        printf("error: ungetflechar: buffer is full, chek input.");
    }
}

int wordprocessor(char *word, unsigned *powerset){
    struct nlist *np;
    static int value = 0;
    static int isIndex = 0;
    static int index = 0;
    int isValidRound = 1, i = 0;
    unsigned localset = 1;
    
    if(atoi(word)){
        if(isIndex){
            isIndex = 0;
            index = atoi(word);
        }else{
            value = atoi(word);
        }
        return 0;
    }
    if(strcmp(word, "Game") == 0){
        if(value > 0){
            // if one game is over, calculate the results.
            for(i=0; i<NKEYS; i++){
                np = lookup(colors[i].color);
                printf("Game %d: %s, %d out of %d\n",index,np->name, np->value, np->maxVal );
                localset *= np->value;
                if(np->value > np->maxVal){
                    isValidRound = 0;
                }
                np->value = 0;
            }
            
            *powerset += localset;
            if(isValidRound){
                localset = 1;
                isIndex = 1;
                return(index);

            }

            
        }
        isIndex = 1;
        return 0;
    }
    
    if(strlen(word) > 1 && (np = lookup(word)) != NULL){

        install(word, MAX(np->value , value), np->maxVal);
                
    }


    return 0;

}

struct nlist *lookup(char *name){
    struct nlist *np;

    unsigned hashcode = hash(name);
    for(np = hashtab[hashcode]; np != NULL; np = np->next){
        if(strcmp(name, np->name) == 0){
            return np;
        }
    }

    return NULL;
}
unsigned hash(char *name){
    unsigned hashval = 0;
    while(*name){
        hashval = hashval * *name++ +22;
    }

    return hashval % HASHSIZE;
}
struct nlist *install(char *name, int value, int maxVal){
    struct nlist *np;
    unsigned hashval = 0;
    if((np = lookup(name)) == NULL){

        np = (struct nlist *) malloc(sizeof(struct nlist));
        if(np == NULL || (np->name = strdup(name)) == NULL){
            return NULL;
        }
        hashval = hash(name);
        hashtab[hashval] = np;
    }
    np->value = value;
    np->maxVal = maxVal;
    return np;
}
void addkeys(int nkeys, struct color *colors){
    int i = 0;
    
    for(i; i<nkeys; i++){
 
        if((install(colors[i].color, colors[i].value, colors[i].maxVal)) == NULL){
         
        }
    }
}