#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct trieNode {
    struct trieNode *child[26];
    int isEndOfWord;
    int value;
};

struct trieNode *getNode(void);
void insert(struct trieNode *root, const char *key, int value);
int search(struct trieNode *root, const char *key);
struct trieNode *seek(struct trieNode *root, char *key);

int main(void){

    int numbersCount = 0, i = 0;

    char *numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    numbersCount = sizeof numbers / sizeof numbers[0];
    struct trieNode *root = getNode();

    for(i=0; i<numbersCount; i++){
        insert(root, numbers[i], i+1);
    }
    char *testStr = {"Thi8sixStrfone"};
    //printf("%d", search(root, "three"));
    char *charpt = testStr;
    struct trieNode *curr;
    while(*testStr){
        curr = root;
        charpt = testStr;
        while((curr = seek(curr, charpt)) != NULL){
            if(curr->isEndOfWord){
                printf("%d", curr->value);
                testStr = charpt;
                break;
            }
            charpt++;
        }
        testStr++;
    }

    return 0;
}
struct trieNode *getNode(void){
    struct trieNode *node = (struct trieNode *) malloc(sizeof(struct trieNode));
    node->isEndOfWord = 0;
    node->value = -1;
    for(int i = 0; i < 26; i++){
        node->child[i] = NULL;
    }
    return node;
}
void insert(struct trieNode *root, const char *key, int value){
    struct trieNode *curr = root;
    int index;
    while(*key){
        index = *key - 'a';
        if(!curr->child[index]){
            curr->child[index] = getNode();
        }
        curr = curr->child[index];
        key++;
    }
    curr->isEndOfWord = 1;
    curr->value = value;
}
int search(struct trieNode *root, const char *key){
    struct trieNode *curr = root;
    int index = 0;
    while(*key){
        index = *key - 'a';
        if(!curr->child[index]){
            return -1;
        }
        curr = curr->child[index];
        key++;
    }
    return ((curr != NULL && curr->isEndOfWord) ? curr->value : -1);
}
struct trieNode *seek(struct trieNode *root, char *key){
    
    struct trieNode *curr = root;
    int index = *key - 'a';
    if(curr->child[index]){
        curr = curr->child[index];
        return curr;

    }
    return NULL;
}