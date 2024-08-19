#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define HASHSIZE 101
#define MAXWORD 100
#define BUFFSIZE 100
struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};
static struct nlist *hashtab[HASHSIZE];

char getch(void);
void ungetch(char c);
struct nlist *lookup(char *name);
unsigned hash(char *name);
struct nlist *install(char *name, char *defn);
int getword(char *word, int limit);

int main(int argc, char *argv[]){

    return 0;
}

int bufferindex = 0;
char buffer[BUFFSIZE];

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
struct nlist *lookup(char *name){
    struct nlist *np;
    unsigned hashval = hash(name);
    for(np = hashtab[hashval]; np != NULL; np = np->next){
        if(strcmp(name, np->name) == 0){
            return np;
        }
    }
    return NULL;
}
unsigned hash(char *name){
    unsigned hashval;

    for(hashval = 0; *name != '\0'; name++){
        hashval = *name + 32 * hashval;
    }

    return hashval % HASHSIZE;
}
struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval = 0;
    if((np = lookup(name)) == NULL){
        np = (struct nlist *) malloc(sizeof(struct nlist));
        if(np == NULL || (np->name = strdup(name)) == NULL){
            return NULL;
        }
        hashval = hash(name);
        hashtab[hashval] = np;
    }else{
        free( (void *) np->defn);
    }
    if((np->defn = strdup(defn)) == NULL){
        return NULL;
    }
    return np;
}
int getword(char *word, int limit){
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
    for(; --limit > 0; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

