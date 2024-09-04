#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLINE 1000

struct trieNode {
    struct trieNode *child[26];
    int isEndOfWord;
    int value;
};

struct trieNode *getNode(void);
void insert(struct trieNode *root, const char *key, int value);
int search(struct trieNode *root, const char *key);
struct trieNode *seek(struct trieNode *root, char *key);
int getline(int limit, char *line, FILE *fp);

void getDigits(int *fd, int *sd, struct trieNode *root, char *line);


int main(void){
    int numbersCount = 0, i = 0;
    int count = 0;
    int *fd, *ld, len = 0;
    unsigned  long int answer = 0;
    char *numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    struct trieNode *root = getNode();
    FILE *fp;
    char line[MAXLINE];
    fp = fopen("key.txt", "r");

    numbersCount = sizeof numbers / sizeof numbers[0];

    fd = (int *)malloc(sizeof(int));
    ld = (int *)malloc(sizeof(int));

    if(fd == NULL || ld == NULL){
        printf("Memory allocation failed.");
        return 1;
    }

    *fd = -1;
    *ld = -1;

    for(i=0; i<numbersCount; i++){
        insert(root, numbers[i], i+1);
    }
    //5rxbkctnsfeightxpbllldgjxqdrd3dmt
    //xoneight2five3fqmc6zrgcbzbzghpvbzt
//    char *testStr = {"5rxbkctnsfeightxpbllldgjxqdrd3dmt"};
    while((len = getline(MAXLINE, line, fp)) > 0){
        count++;
        *fd = -1;
        *ld = -1;
        //printf("%s\n", line);
        getDigits(fd, ld, root, line);
        //printf("%d, %d\n", *fd, *ld);
        answer += (10 * (*fd) )+ *ld;
        }
    // getDigits(fd, ld, root, testStr);
    
   printf("%ld", answer);
   printf("\n %d: lines", count);

    


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


void getDigits(int *fd, int *sd, struct trieNode *root, char *line){
    char *testStr = line;
    char *charpt = line;
    struct trieNode *curr;
    while(*testStr){

        curr = root;
        charpt = testStr;
  
        if(isdigit(*testStr)){
            if(*fd == -1){
                *fd = *testStr - '0';
            }else{
                *sd = *testStr - '0';
            }
            
        }else{        
            while(*charpt && (curr = seek(curr, charpt)) != NULL){ // can the char be the begining of a digit? if yes, then go until it isn't. if digit, print it.
                if(curr->isEndOfWord){
                    if(*fd == -1){
                        *fd = curr->value;
                    }else{
                        *sd = curr->value;
                    }
                    testStr = charpt-1;
                    break;
                }
                charpt++;
            }
        }
        testStr++;
    }

    if(*sd == -1){
        *sd = *fd;
    }   

}
int getline(int limit, char *line, FILE *fp){
    int c, i;
    for(i=0; (i < limit - 1) && (c = getc(fp)) != EOF && c != '\n'; i++){
        line[i] = c;
    }
    if(c == '\n'){
        line[i++] = c;
    }
    line[i] = '\0';

    return i;
}