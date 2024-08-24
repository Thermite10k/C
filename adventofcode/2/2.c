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
    int defn;
};
struct color {
    char *color;
    int value;
};
struct color colors[] = {
    {"red", 0},
    {"green", 1},
    {"blue", 2},
    {"game", -1}
};

static struct nlist *hashtab[HASHSIZE];

struct nlist *lookup(char *name);
unsigned hash(char *name);
struct nlist *install(char *name, int defn);

void addkeys(int nkeys, struct color *);

int getword(int limit, char *word, FILE *fp);
char getfilechar(FILE *fp);
void ungetfilechar(char c);
unsigned hash(char *word);
void wordprocessor(char *word);

int main(void){
    FILE *fp;
    char word[MAXWORD];
    addkeys(NKEYS, colors);
    fp = fopen("key.txt", "r");
    while( getword(MAXWORD, word, fp) != EOF){
        printf("%s\n", word);
    }
    printf("\n%d", lookup("green")->defn  );
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

void wordprocessor(char *word){
    static int red = 0;
    static int green = 0;
    static int blue = 0;

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
struct nlist *install(char *name, int defn){
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
    np->defn = defn;
    return np;
}
void addkeys(int nkeys, struct color *colors){
    int i = 0;
    
    for(i; i<nkeys; i++){
        printf("adding %s , %d", colors[i].color, colors[i].value);
        if((install(colors[i].color, colors[i].value)) == NULL){
            printf("Could not add colors\n");
        }
    }
}