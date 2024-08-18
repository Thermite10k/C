#include <stdio.h>
#define HASHSIZE 101
#include <string.h>
#include <stdlib.h>

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};
int main(void){

    return 0;
}
static struct nlist *hashtab[HASHSIZE]; // array of nlist pointer.


unsigned hash(char *s){
    unsigned hashval = 0;

    for(hashval; *s != '\0'; s++){
        hashval += *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
    struct nlist *np;

    for(np = hashtab[hash(s)]; np != NULL; np = np -> next){
        if(strcmp(np->name, s)){
            return np;
        }
    }

    return NULL;
}
struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL){// not found 
        np = (struct nlist *) malloc(sizeof(*np));
        if(np == NULL || (np->name = strdup(name)) == NULL){
            return NULL; // if no space is available.
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;

    } else { // already there
        free((void *) np->defn);

    }
    if((np->defn = strdup(defn)) == NULL){
        return NULL;
    }
    return np;
}
