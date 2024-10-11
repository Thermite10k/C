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
        A-K-Q-T-9,8,7,6,5,4,3,2,J
        H                       L

    TYPES:
        |Name:            | e.g. |index| Features:
        _____________________________________________________
        -Five of a kind  -> AAAAA - 6 - max: 5 - n_unique = 1
        -Four of a kind  -> AA2AA - 5 - max: 4 - n_unique = 2
        -Full house      -> 33444 - 4 - max: 3 - n_unique = 2
        -Three of a kind -> QQQA2 - 3 - max: 3 - n_unique = 3
        -Two pair        -> QQKK3 - 2 - max: 2 - n_unique = 3
        -One pair        -> 4437A - 1 - max: 2 - n_unique = 4
        -High card       -> 45678 - 0 - max: 1 - n_unique = 5
        _____________________________________________________
*/
struct tNode {

    char *hand;
    int rank;
    int type;
    int bid;

    struct tNode *right;
    struct tNode *left;
};

int get_card_index(char card);
int get_hand_type(char *hand);
// hand1 > hand2 ? 1 : -1
int compare_same_type(const char *hand1, const char *hand2);
char get_f_char(FILE *fp);
void unget_f_char(char c);

char get_f_word(int size, char *word, FILE *fp);

struct tNode *t_alloc();
struct tNode *add_tree(char *hand, int type, int bid, struct tNode *node);
// prints the tree and returns rank * bide
int tree_print(struct tNode *node, long *sum_winners);
void add_rank_to_tree(struct tNode *node, int *count);


int main(){
    
    char hand[MAX_WORD];
    char bid[MAX_WORD];
    int type = 0;
    FILE *fp = fopen(TEST_INPUT, "r");
    int count = 0;
    long sum_winners = 0;
    struct tNode *root = NULL;

    while(get_f_word(MAX_WORD, hand, fp) != EOF){
        type = get_hand_type(hand);
        get_f_word(MAX_WORD, bid, fp);
        root = add_tree(hand, type, atoi(bid), root);
        count++;
    }
    if(root == NULL){
        printf("\n ROOT IS NULL !\n");
    }
    add_rank_to_tree(root, &count);
    printf("Hand\trank\tbid\ttype\trank*bid\n\n");
    tree_print(root, &sum_winners);
    printf("\t\t\t\tsum:\t%ld\n", sum_winners);

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
struct tNode *add_tree(char *hand, int type, int bid, struct tNode *node){
    int cond = 0;
    if(node == NULL){
        node = t_alloc();
        node->hand = strdup(hand);
        node->rank = 0;
        node->type = type;
        node->bid = bid;
        node->right = NULL;
        node->left = NULL;
    }else if(type == node->type){
        if((cond = compare_same_type(hand, node->hand)) == 1){ // if hand > node-> hand
            node->right = add_tree(hand, type, bid, node->right);
        }else if (cond == -1){
            node->left = add_tree(hand, type, bid, node->left);
        }
    }else if(type > node->type){
        node->right = add_tree(hand, type, bid, node->right);
    }else{
        node->left = add_tree(hand, type, bid, node->left);
    }
  

    return node;

}

int tree_print(struct tNode *node, long *sum_winners){
    int winning = 0;
    if (node != NULL){
        tree_print(node->right, sum_winners);
        winning = node->rank * node->bid;
        printf("%s\t%d\t%d\t%d\t%d\n", node->hand, node->rank, node->bid, node->type, winning);
        *sum_winners += winning;
        tree_print(node->left, sum_winners);

    }
    return winning;
}
void add_rank_to_tree(struct tNode *node, int *count){
    if(node != NULL){

        add_rank_to_tree(node->right, count);
        node->rank = (*count)--;
        add_rank_to_tree(node->left, count);
    }
}
int get_card_index(char card){
    // 0 1 2 3 4 5 6 7 8 9 10 11 12
    // J 2 3 4 5 6 7 8 9 T Q  K  A
    if(isdigit(card)){
        return card - '0' - 1; // return the index, 2 is 0, 3 is 1, 9 is 7 etc
    }else{
        switch(card){
            case 'A':
                return 12;
                break;
            case 'K':
                return 11;
                break;
            case 'Q':
                return 10;
                break;
            case 'J':
                return 0;
                break;
            case 'T':
                return 9;
                break;
            default:
                fprintf(stderr, "Invalid card: %c\n", card);
                return -1;
                break;

        }
    }


}

int get_hand_type(char *hand){

    /*
    
        This 2D array takes [max][nUnique] and returns a number between 0-6 based on the hand type.
    
    */

    static int cardTypeArr[][6] = {
//   max: 0   1   2   3   4   5| nUnique 
        {-1, -1, -1, -1, -1, -1},// 0
        {-1, -1, -1, -1, -1,  0},// 1 
        {-1, -1, -1,  2,  1, -1},// 2
        {-1, -1,  4,  3, -1, -1},// 3
        {-1, -1,  5, -1, -1, -1},// 4
        {-1,  6, -1, -1, -1, -1},// 5
    };

    struct cardInfo {
        char card;
        int count;
    };
    struct cardInfo **table = calloc(CARDS, sizeof(struct cardInfo *));
    char c;
    char* handptr = hand;
    int cardIndex = 0;
    int i = 0, secondMax = 0;
    int max = 0, nUnique = 0;




    struct cardInfo *thisCard;
    while((c = *handptr)){
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
        handptr++;
    }
    /*
        DON'T FORGET TO FREE THE MEMORY BEFOER RETURNING
    */
    for(i = 1; i < CARDS; i++){ // start from 1 since we want to know the max except for the joker
        struct cardInfo *thisHand = table[i];
        if(thisHand != NULL){
            nUnique ++;
            if(thisHand->count > max){
              
                max = thisHand->count;
            }
            //max = thisHand->count > max ? thisHand->count : max;
        }
    }
    if(table[0] != NULL){// if hand had joker
        nUnique++; // this is because we don't increment nUnique for the joker(i starts at 1), so we do it now.
        if(nUnique >= 2){ // if there is an other type other than joker
            
            max = max + table[0]->count;
            
            nUnique--;
            
        }else if(nUnique == 1){ // JJJJJ case
            max = 5;
        }
    }
    //printf("got %s, max: %d,  n_unique: %d, secondMax: %d\n", hand, max, nUnique, secondMax);
    return(cardTypeArr[max][nUnique]);
    
}

// hand1 > hand2 ? 1 : -1
int compare_same_type(const char *hand1, const char *hand2){
    
    while(*hand1 == *hand2){
        hand1++;
        hand2++;
    }
    if(*hand1 == '\0'){
        return 1;
    }
    int index1 = get_card_index(*hand1);
    int index2 = get_card_index(*hand2);


    
    return index1 > index2 ? 1 : -1; 
}