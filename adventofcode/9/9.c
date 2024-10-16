#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY "key.txt"
#define MAX_WORD 100
#define MAX_LINE 1000
#define CHAR_BUFF_SIZE 100

int get_f_word(int limit, char* word, FILE* fp);
int get_l_number(int limit, char* word, char **line);
int get_f_line(int limit, char *line, FILE* fp);
int get_f_char(FILE* fp);
void unget_f_char(int c);
int get_next_val(int* dataArray, int length);
int get_first_val(int* dataArray, int length);
int* get_difference(int* dataArray, int length);
int has_non_zero(int* numbers, int length);

int main(){

    char word[MAX_WORD];
    char line[MAX_LINE];
    char* linePTR = line;
    FILE* fp = fopen(KEY, "r");
    int lineNumbers[100]; // we expect to have 100 numbers for each line at most.
    int i = 0; // the index used for lineNumbers
    int ans = 0;

    while(get_f_line(MAX_LINE, line, fp) != EOF){
        linePTR = line;
        i = 0;
        while(get_l_number(MAX_WORD, word, &linePTR) != '\0'){
            lineNumbers[i++] = atoi(word);
        }
        
        ans += get_first_val(lineNumbers, i-1);

    }
    printf("%d", ans);

    return 0;
}

int get_f_word(int limit, char *word, FILE* fp){
    
    char *w = word;
    int c;

    while(((c = get_f_char(fp)) == ' ')){
        ;
    }
    if(c != EOF){
        *w++ = c;
    }
    if(c == EOF || c == '\n' || !isalnum(c)){
        *w = '\0';
        return c;
    }
    for(; --limit > 0; w++){
        if(!isalnum((*w = get_f_char(fp)))){
            unget_f_char(*w);
            break;
        }
    }

    *w = '\0';
    return *word;
    
}
int get_l_number(int limit, char* word, char **line){
    int c;
    char* w = word;
    while((c = *(*line)++) == ' '){
        ;
    }
    if(c != EOF){
        *w++ = c;
    }
    if(c == '\0' || c == '\n'){ // adding !isalnum(c) to the conditions prevents us to get the negative numbers
        *w = '\0';
        return c;
    }
    for(; --limit > 0; (*line)++, w++){
        if(!isalnum((*w = **line))){
            break;
        }
    }
    *w = '\0';
    return word[0];
}

int get_f_line(int limit, char *line, FILE* fp){
    int c = 0;
    char* l = line;

    while((--limit > 0) && (c = get_f_char(fp)) != EOF && c != '\n'){
        *l++ = c;
    }
    if( c == '\n' || c == EOF){
        *l++ = c;
    }
    *l = '\0';

    return line[0];

}

int charBuff[CHAR_BUFF_SIZE];
int charBuffPtr = 0;

int get_f_char(FILE* fp){
    if(charBuffPtr > 0){
        return charBuff[--charBuffPtr];
    }else{
        return getc(fp);
    }
}
void unget_f_char(int c){
    if(charBuffPtr < CHAR_BUFF_SIZE){
        charBuff[charBuffPtr++] = c;
    }else{
        fprintf(stderr, "Error: unget_f_char: can not unget %c, buffer is full.\n", c);
    }
}

int get_next_val(int dataArray[], int length){
    if(length <= 1){
        return 0;
    }
    int ans = 0;
    int* diffArray;
    diffArray = get_difference(dataArray, length);


    if(has_non_zero(diffArray, length-1)){
        ans += get_next_val(diffArray, length-1);
    }
    free(diffArray);
    return ans + dataArray[length - 1];
    
}

int get_first_val(int dataArray[], int length){
    if(length <= 1){
        return 0;
    }
    int ans = 0;
    int *diffArray;
    diffArray = get_difference(dataArray, length - 1);

    if(has_non_zero(diffArray, length-1)){
        ans -= get_first_val(diffArray, length-1);
    }
    free(diffArray);
    return ans + dataArray[0];
}

int* get_difference(int* dataArray, int length){
    if(length <= 1){
        return NULL;
    }
    int* diffArray = calloc(length - 1, sizeof(int));
    int i = 0;
    for(i = 0; i < length - 1; i++){
        diffArray[i] = dataArray[i+1] - dataArray[i];
    }
    /*
        Why did I even use this pointer approach?
    */
    // int* first = (dataArray + 0);
    // int* second = (dataArray + 1);
    // int* diffPTR = (diffArray + 0);

    // while(second < (dataArray + length)){
    //     *diffPTR++ = *second++ - *first++;
    // }
    return diffArray;
}

int has_non_zero(int* numbers, int length){
    int i = 0;
    for(i = 0; i < length; i++){
        if(numbers[i] != 0){
            return 1;
        }
    }
    return 0;
}