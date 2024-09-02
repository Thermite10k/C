#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define TABLESIZE 100
#define MAXWORD 100
#define CHARBUFFERSIZE 100

struct tablemember {
    int value;
    struct tablemember *next;
};

struct tablemember *hashtable[TABLESIZE];
// struct tablemember *hashtable = (struct tablemember *)malloc(TABLESIZE * sizeof(struct tablemember))

char getfilechar(FILE *fp);
void ungetfilechar(char c);
int getfileword(int limit, char *word, FILE *fp);

unsigned hash(char *word);
struct tablemember *lookup(char *word);
struct tablemember *install(char *word);
void refreshTable();
void freemembers(struct tablemember *member);

int main(){

    struct flag {
        unsigned int is_winning_number : 1;
        unsigned int is_own_number : 1;
        unsigned int is_index : 1;
    };

    struct flag flags = {
        0,
        0,
        0
    };
    
    char word[MAXWORD];
    FILE *fp = fopen("key.txt", "r");
    int c;
    int cardIndex , winnerCount = -1; // winner count is set to -1 because we use 2^winnerCount.
    long int totalScore = 0, currentScore;
    while((c = getfileword(MAXWORD, word, fp)) != EOF){

        if(strcmp(word, "Card") == 0){
            if(winnerCount >=0){
                currentScore = pow(2, winnerCount);
                printf("card %d has %d winners so %ld points\n", cardIndex, winnerCount, currentScore);
                totalScore += currentScore;
            }
            winnerCount = -1;
            flags.is_own_number = 0;
            flags.is_winning_number = 1;
            getfileword(MAXWORD, word, fp); // go to index
            cardIndex = atoi(word);
            getfileword(MAXWORD, word, fp); // skip the ':'
            refreshTable(); // we only care about the current winning numbers.
        }else if(flags.is_winning_number){
            if(c == '|'){
                flags.is_winning_number = 0;
                flags.is_own_number = 1;
              
              
            }else{
                install(word);
            }
        }else if(flags.is_own_number){
   
            if(lookup(word)){
                winnerCount++;
                printf("%d is a winning number in card %d\n", atoi(word), cardIndex);
            }
        }
    }
    printf("%ld", totalScore);
    return 0;
}

char CHARBUFF[CHARBUFFERSIZE];
int charbufferpointer = 0;

char getfilechar(FILE *fp){
    if(charbufferpointer > 0){
        return CHARBUFF[--charbufferpointer];
    }else{
        return getc(fp);
    }
}

void ungetfilechar(char c){
    if(charbufferpointer < CHARBUFFERSIZE){
        CHARBUFF[charbufferpointer++] = c;
    }else{
        printf("error: ungetfilechar: buffer is full.\n");
    }
}

int getfileword(int limit, char *word, FILE *fp){
    int c;
    char *w = word;

    while(isspace(c = getfilechar(fp)) && c!= '\n'){
        ;
    }
    if(c != EOF){
        *w++ = c;
    }
    
    if(!isalnum(c)){
        *w = '\0';
        return c;
    }

    for(; --limit > 0; w++){
        if(!isalnum((*w = getfilechar(fp)))){
            ungetfilechar(*w);
            break;
        }
    }
    *w = '\0';

    return word[0];
}
unsigned hash(char *word){
    int value = atoi(word);
    unsigned hashval = 0;
    int v1 = 3; // just a random numbers.

    for(value; value > 0; value /= 10){
        hashval += (value % 10) * v1++;
    }
    
    return hashval % TABLESIZE;
}
struct tablemember *lookup(char *word){
    unsigned hashval = hash(word);
    struct tablemember *memberPtr;

    memberPtr = hashtable[hashval];
    
    for(memberPtr; memberPtr != NULL; memberPtr = memberPtr->next){

        if(atoi(word) == memberPtr->value){
            return memberPtr;
        }
    }

    return NULL;

}
struct tablemember *install(char *word){

    
    struct tablemember *memberPtr = lookup(word);
    unsigned hashval = hash(word);
    if(memberPtr == NULL){
        memberPtr = (struct tablemember *)malloc(sizeof(struct tablemember));
        if(memberPtr == NULL ){
            return NULL;
        }
        hashtable[hashval] = memberPtr;
        memberPtr->value = atoi(word);
        memberPtr->next = NULL;
    }

    return memberPtr;


}
void refreshTable(){
    int i = 0;

    for(i=0; i<TABLESIZE; i++){
        if(hashtable[i] != NULL){

            freemembers(hashtable[i]->next);
            hashtable[i] = NULL;
        }
    }
    

}
void freemembers(struct tablemember *member){

    if(member != NULL){
        freemembers(member->next);
        free(member);
    }
    return;
    
}