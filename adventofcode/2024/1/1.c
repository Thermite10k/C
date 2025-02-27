#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define KEY "key.txt"
#define MAX_WORD 100
#define CHAR_BUFF_SIZE 100
#define TABLE_SIZE 1000

struct tableMember {
    int value;
    int count;

    struct tableMember* next;
};

struct tNode {
    struct tNode* right;
    struct tNode* left;

    int value;
};

struct tableMember* hashTable[TABLE_SIZE];

struct tableMember* lookup(int value);
struct tableMember* install(int value);


char get_f_char(FILE* fp);
void unget_f_char(char c);

int get_f_word(int limit, char* word, FILE* fp);
int my_atoi(char* word);

struct tNode* t_alloc();
struct tNode* add_to_tree(int value, struct tNode* node);
void tree_print(struct tNode* root);

void add_tree_to_array(struct tNode* root, int* array, int* index);


int main(int argc, char* argv){

    char word[MAX_WORD];
    FILE *fp = fopen(KEY, "r");

    int size = 0;

    struct tNode* firstTree = NULL;
    struct tNode* secondTree = NULL;
    int secondValue = 0;

    while(get_f_word(MAX_WORD, word, fp) != EOF){
        size++;        
        firstTree = add_to_tree(my_atoi(word), firstTree);
        get_f_word(MAX_WORD, word, fp);
        secondValue = my_atoi(word);
        install(secondValue);
        secondTree = add_to_tree(secondValue, secondTree);
    }
    printf("size is: %d\n", size);
    int firstArr[size];
    int secondArr[size];
    int index = 0;
    int* firstArrayPtr = firstArr;

    
    // tree_print(firstTree);
    // tree_print(firstTree);
    // putc('\n', stdout);
    // tree_print(secondTree);
    add_tree_to_array(firstTree, firstArr, &index);
    index = 0;
    int sumDifference = 0;
    int secondAnswer = 0;
    int similarityScore = 0;
    struct tableMember* similarityScoreItem;
    add_tree_to_array(secondTree, secondArr, &index);
     for(int i = 0; i < size; i++){
        sumDifference += (firstArr[i] - secondArr[i]) >= 0 ? firstArr[i] - secondArr[i] : secondArr[i] - firstArr[i];
        similarityScoreItem = lookup(firstArr[i]);
        if(similarityScoreItem){
            similarityScore = lookup(firstArr[i])->count;
            secondAnswer = secondAnswer + firstArr[i] * (similarityScore);
        }
        
    }

    printf("answer to part I:\t%09d\n", sumDifference);
    printf("answer to part II:\t%09d", secondAnswer);

    return 0;
}

char charBuff[CHAR_BUFF_SIZE];
int charBuffPtr = 0;

char get_f_char(FILE* fp){
    if(charBuffPtr > 0){
        return charBuff[--charBuffPtr];
    }else{
        return getc(fp);
    }
}
void unget_f_char(char c){
    if(charBuffPtr < CHAR_BUFF_SIZE){
        charBuff[charBuffPtr++] = c;
    }else{
        fprintf(stderr, "Error: unget_f_char: Buffer is full!");
    }
}

int get_f_word(int limit, char* word, FILE* fp){
    int c;
    char* w = word;

    while(isspace((c = get_f_char(fp)))){ // use c == ' ' to include the '\n' as well
        ;
    }
    if(c != EOF){
        *w++ = c;
    }
    if(!isalnum(c) || c == '\n'){
        *w = '\0';
        return c;
    }
    while(--limit > 0){
        if(!isalnum((*w = get_f_char(fp)))){
            unget_f_char(*w);
            break;
        }
        w++;
       
    }

    *w = '\0';
    return word[0];
}
struct tNode* t_alloc(){
    return (struct tNode*) malloc(sizeof(struct tNode));
}
struct tNode* add_to_tree(int value, struct tNode* node){
    if(node == NULL){
        node = t_alloc();
        node->value = value;
        node->right = NULL;
        node->left = NULL;
    }else if(node->value >= value){
        node->left = add_to_tree(value, node->left);
    }else if(node->value < value){
        node->right = add_to_tree(value, node->right);
    }else{
        fprintf(stderr, "Can't add %d to tree", value);
    }

    return node;
}
void tree_print(struct tNode* node){
    if(node != NULL){
        tree_print(node->left);
        printf("%d", node->value);
        tree_print(node->right);
    }
}
int my_atoi(char* word){
    char* w = word;
    int returnValue = 0;
    int exponent = 1;
    int sign = 1;

    while(*w == ' '){
        w++;
    }
    if(*w == '-'){
        sign = -1;
        w++;
    }

    while(*w && isdigit(*w)){
        returnValue = 10 * returnValue + *w - '0';
        w++;
    }
    // if(*w == '.'){ THIS IS NOT IN atoi()
    //     w++;
    //     while(*w && isdigit(*w)){
    //         returnValue = 10 * returnValue + *w - '0';
    //         exponent = exponent * 10;
    //         w++;
    //     }
    // }

    return ((returnValue * sign));

}


void add_tree_to_array(struct tNode* root, int* array, int* index){
    if(root != NULL){
        
        add_tree_to_array(root->left, array, index);
        array[*index] = root->value;
        (*index)++;
        add_tree_to_array(root->right, array, index);
    }
}
struct tableMember* install(int value){
   
    int hashVal = value%TABLE_SIZE;
    struct tableMember* tableItem;
    tableItem = lookup(value);

    if(tableItem == NULL){
        tableItem = (struct tableMember *) malloc(sizeof(*tableItem));
        if(tableItem == NULL){
            return NULL;
        }
        tableItem->value = value;
        tableItem->count = 1;
        tableItem->next = hashTable[hashVal];
        hashTable[hashVal] = tableItem;
    }else{
        tableItem->count++;
    }

    return tableItem;
}
struct tableMember* lookup(int value){
    
    struct tableMember* tableItem;
    tableItem = hashTable[value%TABLE_SIZE];

    for(tableItem; tableItem != NULL; tableItem = tableItem->next){
        if(tableItem->value == value){
            return tableItem;
        }
    }

    return NULL;
}
