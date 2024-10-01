#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TEST_INPUT "key.txt"
#define MAX_WORD 100
/*
    NAMING CONVENTION
    ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
    DEFINE_SOMETHING
    a_function()
    myVariable - exception for two char vars such as dx, Vy, etc
    ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
*/
struct tNode {

    char *hand;
    int rank;

    struct tNode *right;
    struct tNode *left;
};

char get_f_char(FILE *fp);
void unget_f_char(char c);

char get_f_word(int size, char *word, FILE *fp);

struct tNode *t_alloc();
struct tNode *add_tree(char *hand, struct tNode *node);


int main(){
    
    char word[MAX_WORD];
    FILE *fp = fopen(TEST_INPUT, "r");

    struct tNode *root = NULL;

    while(get_f_word(MAX_WORD, word, fp) != EOF){
        printf("deck is: %s ", word);
        get_f_word(MAX_WORD, word, fp);
        printf("bid is %d\n", atoi(word));
    }
    return 0;
}

char charBuffer[MAX_WORD];
int charBufferPointer = 0;

char get_f_char(FILE *fp){
    if(charBufferPointer > 0){
        return(charBuffer[--charBufferPointer]);
    }else{
        return(getc(fp));
    }
}
void unget_f_char(char c){
    if(charBufferPointer < MAX_WORD){
        charBuffer[charBufferPointer++] = c;
    }else{
        fprintf(stderr, "error: unget_f_char: Buffer is full\n");
    }
}

char get_f_word(int size, char *word, FILE *fp){

    char *w = word;
    int c;

    while(isspace((c = get_f_char(fp)))){
        ;
    }

    if(c != EOF){
        *w++ = c; 
    }
    if(!isalnum(c)){
        *w = '\0';
        return c;
    }

    for(; --size > 0; *w++){
        if(!isalnum(*w = get_f_char(fp))){
            unget_f_char(*w);
            break;
        }
    }

    *w = '\0';
    return *word;

}

struct tNode *t_alloc(){
    return (struct tNode *) malloc(sizeof(struct tNode));
}
struct tNode *add_tree(char *hand, struct tNode *node){

    if(node == NULL){
        node = t_alloc();
        node->hand = strdup(hand);
        node->rank = 0;
        node->right = node-> left = NULL;
    }
    // add card checking algorithms...

    return NULL;

}

