#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 100
#define PATTERN_LENGTH 500
#define TABLE_SIZE 300
#define KEY "key.txt"

struct tableMember {
    char* current;
    char* R;
    char* L;
    struct tableMember* next;
};
struct tableMember* hashTable[TABLE_SIZE];

struct tableMember* lookup(char* current);
struct tableMember* install(char* current, char* L, char* R);
unsigned hash(char* current);
int get_f_line(int limit, char* line, FILE* fp);
// check whether all <count> positions end with Z, if yes, ret 1 :
int all_at_dest(char** positions, int count);


int main(){

    FILE* fp = fopen(KEY, "r");
    char line[MAX_LINE];
    char leftRightPattern[PATTERN_LENGTH];
    int patternLength;
    int lineLen = 0;
    int matches = 0;
    char from[MAX_LINE];
    char right[MAX_LINE];
    char left[MAX_LINE];

    int stratWithACount = 0;
    char** positionsArray = (char **)calloc(10, sizeof(char *));

    //BBB = (DDD, EEE)
    /*
        %[^X]X => anything until X, excluding X.
    */
    char* mapPattern = "%[^ ] = (%[^,], %[^)])";
    patternLength = get_f_line(PATTERN_LENGTH, leftRightPattern, fp) - 1; // -1 because we don't count the \0
    printf("%s\n", leftRightPattern);
    while((lineLen = get_f_line(MAX_LINE, line, fp)) != 0){
        //printf("%s\t%d", line, lineLen-1);
        matches = sscanf(line, mapPattern, from, left, right);
        if(matches == 3){
            install(from, left, right);
            if(from[2] == 'A'){
                positionsArray[stratWithACount++] = strdup(from);
            }
        }
    }
    printf("End with A: %d\tptr len: %d\n", stratWithACount,patternLength);
    
    for(int index = 0; index < stratWithACount; index++){
        printf("%s\n", positionsArray[index]);
    }

    char direction;
    struct tableMember* currentPosition = lookup("AAA");
    int i = 0;
    long long steps = 0;
    int positions = 0;
    char currentlyAt[4];
    /*
        While we are not at dest (ZZZ), update the currentPosition according to direction[i++]
        where i++ is always in range of the patternLength using the % operator.
    */

    int loop = 1;
    while(loop){
        loop = 0;
        direction = leftRightPattern[i++];
        
        for(int posIndex = 0; posIndex < stratWithACount; posIndex++){
            strcpy(currentlyAt, positionsArray[posIndex]);
            free(positionsArray[posIndex]);
            if(direction == 'L'){
                positionsArray[posIndex] = strdup(lookup(currentlyAt)->L);
            }else if(direction == 'R'){
                positionsArray[posIndex] = strdup(lookup(currentlyAt)->R);
            }
            if(positionsArray[posIndex][2] != 'Z'){
                loop = 1;
            }
        }

        // printf("%c\n", direction);
        // for(int index = 0; index < stratWithACount; index++){
        //     printf("%s\n", positionsArray[index]);
        //  }

        //  putchar('\n');

  
        steps++;
        i = i%patternLength;
   
    }
    printf("Steps: %lld\n", steps);
    return 0;
}

struct tableMember* lookup(char* current){

    unsigned hashVal = hash(current);

    struct tableMember* tableItem;
    tableItem = hashTable[hashVal];

    for(tableItem; tableItem != NULL; tableItem = tableItem->next){
        if(strcmp(current, tableItem->current) == 0){
            return tableItem;
        }
    }

    return NULL;
}
struct tableMember* install(char* current, char* L, char* R){
    unsigned hashVal = hash(current);
    struct tableMember* tableItem = lookup(current);

    if(tableItem == NULL){
        tableItem = (struct tableMember *)malloc(sizeof(struct tableMember));
        if(tableItem == NULL){
            return NULL;
        }
        tableItem->current = strdup(current);
        tableItem->R = strdup(R);
        tableItem->L = strdup(L);
        tableItem->next = hashTable[hashVal];
        hashTable[hashVal] = tableItem;
        
    }
    return tableItem;
}
unsigned hash(char* current){
    unsigned hashVal = 0;
    int i = 4; // just a random number.
    while(*current){
        hashVal += i * *current++;
        i = *(current-1)+1;
    }
    return hashVal % TABLE_SIZE;
    
}
int get_f_line(int limit, char* line, FILE* fp){
    char c;
    char* w = line;
    int i = 0;
    
    for(;--limit > 0 && (c = getc(fp)) != EOF && c != '\n'; i++){
        *(w + i) = c;
    }
    if(c == '\n'){
        *(w + i++) = c;
    }
    *(w + i)= '\0';

    return i;
}

// check whether all <count> positions end with Z, if yes, ret 1 :
int all_at_dest(char** positions, int count){

    while(count--){
        // gets the third character of each position and compares it with Z
        if(*(*(positions + count) + 2) != 'Z'){
            return 0;
        }
    }

    return 1;

}