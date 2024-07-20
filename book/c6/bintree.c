#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100

struct tnode {
    struct tnode *right;
    struct tnode *left;
    int count;
    char *word;
};

struct tnode *talloc();
struct tnode *addtree(char *word, struct tnode *node);
void treeprint(struct tnode *);
int getword(char *word, int limit);
char getch(void);
void ungetch(char c);
char *strdupp(char *str);
/* Word Frequency Count*/
int main(){

    struct tnode *root;
    char word[MAXWORD];

    root = NULL;

    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0])){
            root = addtree(word, root);
        }
    }
    treeprint(root);


    return 0;
}

struct tnode *addtree(char *word, struct tnode *p){

    int cond;

    if(p == NULL){
        p = talloc();
        p->word = strdupp(word);
        p->count = 1;
        p->right = p->left = NULL;
    }else if((cond = (strcmp(word, p->word))) == 0){
        ++p->count;
    }else if(cond > 0){
        p->right = addtree(word, p->right);
    }else{
        p->left = addtree(word, p->left);
    }

    return p;

}

void treeprint(struct tnode *p){

    if(p != NULL){
        treeprint(p->left);
        printf("%s: %4d\n", p->word, p-> count);
        treeprint(p->right);
    }
}
char *strdupp(char *str){

    char *p;

    p = (char *) malloc(strlen(str)+1);// +1 is for /0
    if(p != NULL){
        strcpy(p, str);
    }

    return p;
}
struct tnode *talloc(){
    return((struct tnode *) malloc(sizeof(struct tnode)));
}

#define BUFFSIZE 100

char buffer[BUFFSIZE];
int bufferindex = 0;

int getword(char *word, int limit){
    char c;

    while(isspace((c = getch()))){
        ;
    }
    char *w = word;

    if(c != EOF){ /* to handle ctrl-z*/
        *w++ = c;
    }
    if(!isalnum(c)){
        *w = '\0';
        return c;
    }
    for(; --limit; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

char getch(void){
    if(bufferindex > 0){
        return buffer[--bufferindex];
    }
    return getchar();
}

void ungetch(char c){
    if(bufferindex < BUFFSIZE){
        buffer[bufferindex++] = c;
    }else{
        printf("error: ungetch: buffer is full");
    }
}