#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXWORD 100
#define CHARBUFFERSIZE 100
#define MAXNUMBERS 100
#define MAXCARDS 300
void initializearray(int *arr, int size, int setto);
void addwinners(int *arr, int form,int count, int mult);
char getfilechar(FILE *fp);
void ungetfilechar(char c);

int getfileword(int limit, char *word, FILE *fp);

int main(void){
    int index = 0;
    int winnerarray[MAXNUMBERS];
    int mycards[MAXCARDS];
    initializearray(mycards, MAXCARDS, 0);
    initializearray(winnerarray, MAXNUMBERS ,0);
    FILE *fp = fopen("key.txt", "r");
    struct flag {
        int is_winning_number : 1;
        int is_own_number : 1;
        int is_index : 1;
    };
    char word[MAXWORD];
    struct flag flags = {
        0,
        0,
        0
    };
    int c, cardIndex = 0, winnerCount = 0, score = 0, totalScore = 0;
    while((c = getfileword(MAXWORD, word, fp)) != EOF){
        if(strcmp("Card", word) == 0){
            winnerCount = 0;
            // next input is the index, we will track it
            getfileword(MAXWORD, word, fp);
            cardIndex = atoi(word);
            
            // next is ':', we will skip it.
            getfileword(MAXWORD, word, fp);
            initializearray(winnerarray, MAXNUMBERS, 0);
            flags.is_winning_number = 1;
            flags.is_own_number = 0;
        }else if((c == EOF || c == '\n') ){
            if((index == 0 || mycards[index] > 0)){
                printf("processing card %d\n", cardIndex);
                //score = pow(2, winnerCount -1);
                //totalScore += score;
                //printf("Card %d has %d winnwes so %d points.\n", cardIndex, winnerCount, score);
                //printf("\t for %d instances of card have %d matching numbers, so you win")
                addwinners(mycards, index+1, winnerCount, mycards[index] + 1);
                //printf("We have %d of card %d\n", mycards[index] + 1, index+1);
                totalScore +=mycards[index++] + 1; // we add the once because we have one original copy
                
            }else{
                totalScore++;
            }
            
        }else if(flags.is_winning_number){
            if(c == '|'){
                flags.is_winning_number = 0;
                flags.is_own_number = 1;
            }else{
                winnerarray[atoi(word)] = 1;
            }
        }else if(flags.is_own_number){
            if(winnerarray[atoi(word)]){
                winnerCount++;
            }
        }
    }
    printf("Total score: %d\n", totalScore);
    return 0;
}

char charbuffer[CHARBUFFERSIZE];
int charbufferpointer = 0;

char getfilechar(FILE *fp){
    if(charbufferpointer > 0){
        return charbuffer[--charbufferpointer];
    }else{
        return getc(fp);
    }
}

void ungetfilechar(char c){
    if(charbufferpointer < CHARBUFFERSIZE){
        charbuffer[charbufferpointer++] = c;
    }else{
        printf("error ungetflechar: buffer is full.\n");
    }

}


int getfileword(int limit, char *word, FILE *fp){
    int c;
    char *w = word;
    while(isspace((c = getfilechar(fp))) && c!= '\n'){
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
    *w ='\0';
    return word[0];
}
void initializearray(int *arr, int size, int setto){
    int i;
    for(i=0; i<size; i++){
        *(arr + i) = setto;
    }
}
void addwinners(int *arr, int from ,int count, int mult){

    int i = from;
    //printf("For card %d\n", from);
    for(i; i <= (from + count - 1); i++){// so if  card 2 (index = 1) and 3 winnders, we want 3-4-5 or index 2, 3, 4
        printf("\tadding %d to card %d\n", mult, i+1);
        arr[i] += mult;
    }

}