#include <stdio.h>
#define HASHSIZE 101
#include <string.h>
#include <stdlib.h>

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *name);
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
        if(strcmp(np->name, s) == 0){
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

void undef(char *name){
    struct nlist *np, *prev;
    unsigned hashval = hash(name);

    np = hashtab[hashval];
    
    for(np; np != NULL; np = np->next){
        if(strcmp(name, np->name) == 0){
            if(prev == NULL){
                hashtab[hashval] = np->next;
            }else{

                prev->next = np->next;
            }
            free(np->name);
            free(np->defn);
            free(np);
        }
        prev = np;
    }
}