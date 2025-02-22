#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define UPDATES_LEN 30
#define MAX_PRINTED_LIST_LEN 100
#define MAX_NEXT_PAGES
#define NEXT_PAGES_MAP_LEN 100
#define CHAR_BUFF_SIZE 100
#define MAX_WORD 10
#define MAX_LINE 100

#define UPDATES_PATH "updates2.txt"
#define ORDERS_PATH "order2.txt"

int get_f_word(FILE* fp, int limit, char *word);
int get_f_line(FILE* fp, int limit, char *line);
int get_f_char(FILE* fp);
void unget_f_char(char c);


int main(){

    int rules[NEXT_PAGES_MAP_LEN][NEXT_PAGES_MAP_LEN];
    for(int i = 0; i < NEXT_PAGES_MAP_LEN; i++){
        for(int j = 0; j < NEXT_PAGES_MAP_LEN; j++){
            rules[i][j] = 0;
        }
    }

    FILE *fp = fopen(ORDERS_PATH, "r");
    char word[MAX_WORD];
    char line[MAX_LINE];
    char X[MAX_WORD];
    char Y[MAX_WORD];
    char *patternPattern = "%[^|]|%[^ ]";
    while(get_f_line(fp, MAX_LINE, line) != 0){
        //printf("%s\n", line);
        if(sscanf(line,patternPattern, X, Y) == 2){
            rules[atoi(X)][atoi(Y)] = 1;
            rules[atoi(X)][0] = 1; // indicates that X is in the rules        
        }
        
    }

    fclose(fp);
    fp = fopen(UPDATES_PATH, "r");
    int status = 0;

    int* updatedList = calloc(NEXT_PAGES_MAP_LEN, sizeof(int));
    int currentPageForUpdate = 0;
    int currentSet[NEXT_PAGES_MAP_LEN];
    int currentSetIndex = 0;
    int isLegalSet = 1;
    int sumAnswers = 0;
    int i = 0;
    int j = 0;
    int pageNumber = 0;
    int temp = 0;
    int wasIllegal = 0;
    while((status = get_f_word(fp, MAX_WORD, word)) != EOF){
        wasIllegal = 0;
        if((pageNumber = atoi(word))){ // ignoring '.'
            currentSet[currentSetIndex++] = pageNumber;
        }
        if(status == '\n'){
            for(i = 0; i < currentSetIndex; i++){
                currentPageForUpdate = currentSet[i];
                updatedList[currentPageForUpdate] = 1;
                if(rules[currentPageForUpdate][0]){ // rulex[x][0] is 1 if the page is in rules. if thre is a page that the curren page must precede
                    for(int l = 0; l <= i; l++){// we will only check until the current selection, i
                        if(updatedList[currentSet[l]] && rules[currentPageForUpdate][currentSet[l]]){// if the added page must precede L and L already exists -> if 97, 13, (75) and 75 | 13
                            //printf("Illegal page: %d|%d has been violated.\n", currentPageForUpdate,currentSet[l]);
                            for(j = 0; currentSet[j] != currentSet[l]; j++){
                                ;
                            }
                            //printf("Swapping current set i = %d, j = %d\t%d and \t%d\n", i,j, currentSet[i], currentSet[j]);
                            temp = currentSet[j];
                            currentSet[j] = currentSet[i];
                            currentSet[i] = temp;
                            i=0;
                            wasIllegal = 1;
                            break;
                            
                        }
                    }
                    
                }
            }
            
            
            
            //printf("new line...\n");
            free(updatedList);
            updatedList = calloc(NEXT_PAGES_MAP_LEN, sizeof(int));
            if(wasIllegal){ // not this statement will be the answer to part I. so !wasIllegal
                // for(int k = 0; k < currentSetIndex ; k++){
                //     //printf("%d ", currentSet[k]);
                // }
                sumAnswers += currentSet[currentSetIndex/2];
                //printf("will add: %d\n", currentSet[currentSetIndex/2]);
            }
            currentSetIndex = 0;
            
        }

        
    }
    
    printf("Answer: %d", sumAnswers);    
    

    return 0;
}

int get_f_word(FILE* fp, int limit, char *word){
    int c;
    char* w = word;

    while((c = get_f_char(fp)) == ' '){
        ;
    }
    if(c != EOF && c != '\n'){
        *w++ = c;
    }
    if(!isalnum(c) || c == EOF){
        *w = '\0';
        return c;
    }

    while(--limit){
        if(!isalnum((*w = get_f_char(fp)))){
            unget_f_char(*w);
            break;
        }
        *w++;
    }
    *w = '\0';

    return word[0];

}

int get_f_line(FILE* fp, int limit, char *line){

    int c;
    char *l = line;
    int i = 0;
    while ((c = get_f_char(fp)) == ' ')
    {
        ;
    }
    
    

    if(c == EOF){
        l[i] == '\0';
        return i;
    }

    l[i++] = c;
   

    while (--limit && (l[i] = get_f_char(fp)) != '\n' && l[i] != EOF)
    {
        i++;
    }
    l[i] = '\0';
    return i;


}
int charBuff[CHAR_BUFF_SIZE];
int charBuffPointer = 0;

int get_f_char(FILE* fp){
    if(charBuffPointer > 0){
        return charBuff[--charBuffPointer];
    }
    return getc(fp);
}
void unget_f_char(char c){
    if(charBuffPointer < CHAR_BUFF_SIZE){
        charBuff[charBuffPointer++] = c;
    }else{
        fprintf(stderr, "error: unget_f_char: buffer is full.\n");
    }
}

