#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TEST_INPUT "key.txt"
#define MAX_WORD 100
#define CARDS 13
/*
    NAMING CONVENTION
    ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
    DEFINE_SOMETHING
    a_function()
    myVariable - exception for two char vars such as dx, Vy, etc
    ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
*/

/*
    CARDS:
        A-K-Q-J-T-9,8,7,6,5,4,3,2
        H                       L

    TYPES:
        -Five of a kind  -> AAAAA - 7
        -Four of a kind  -> AA2AA - 6
        -Full house      -> 33444 - 5
        -Three of a kind -> QQQA2 - 4
        -Two pair        -> QQKK3 - 3
        -One pair        -> 4437A - 2
        -High card       -> 45678 - 1
*/
struct tNode {

    char *hand;
    int rank;

    struct tNode *right;
    struct tNode *left;
};

int get_card_index(char card);
int get_hand_type(char *hand);
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
        printf("deck is: %s\n", word);
        get_hand_type(word);
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

int get_card_index(char card){
    
    if(isdigit(card)){
        return card - '0'; // return the integer of digit
    }else{
        switch(card){
            case 'A':
                return 14;
                break;
            case 'K':
                return 13;
                break;
            case 'Q':
                return 12;
                break;
            case 'J':
                return 11;
            case 'T':
                return 10;
                break;
        }
    }

    return 0;

}

int get_hand_type(char *hand){
    struct cardInfo {
        char card;
        int count;
    };
    struct cardInfo **table = calloc(CARDS+10, sizeof(struct cardInfo *));
    char c;
    int cardIndex = 0;
    int i = 0;




    while((c = *hand)){
        struct cardInfo *thisCard;
        cardIndex = get_card_index(c);
        
        if((table[cardIndex]) == NULL){
            
            thisCard = (struct cardInfo *) malloc(sizeof(struct cardInfo));
            thisCard->card = c;
            thisCard->count = 1;
            table[cardIndex] = thisCard;
        }else{
            thisCard = table[cardIndex];
            thisCard->count = thisCard->count + 1;
        }
        hand++;
    }
    /*
        DON'T FORGET TO FREE THE MEMORY BEFOER RETURNING
    */
    for(i = 0; i < CARDS+10; i++){
        struct cardInfo *myCard = table[i];
        if(myCard != NULL){
            printf("card: %c, count: %d\n", myCard->card, myCard->count);
        }
    }
    
}