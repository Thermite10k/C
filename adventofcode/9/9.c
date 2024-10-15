#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY "key.txt"
#define MAX_WORD 100
#define MAX_LINE 1000
#define CHAR_BUFF_SIZE 100

int get_f_word(int limit, int* word, FILE* fp);
int get_l_word(int limit, int* word, char **line);
int get_f_line(int limit, char *line, FILE* fp);
int get_f_char(FILE* fp);
void unget_f_char(int c);
int get_next_val(int* dataArray, int length);
int* get_difference(int* dataArray, int length);

int main(){

    int word[MAX_WORD];
    char line[MAX_LINE];
    FILE* fp = fopen(KEY, "r");
    printf("%c", get_f_char(fp));
    while(get_f_line(MAX_LINE, line, fp) != EOF){
        printf("%s", line);
    }

    int numbers[] = {0, 3, 6, 9, 12, 15};
    int numbers2[] = {1, 1, 1, 1};
    printf("\n%d", get_next_val(numbers, 6));

    // int* differenceOfNumbers = get_difference(numbers, 4);
    // putchar('\n');
    // for(int i = 0; i < 3; i++){
    //     printf("%d - ",*(differenceOfNumbers + i));
    // }

    



    

    return 0;
}

int get_f_word(int limit, int *word, FILE* fp){
    
    int *w = word;
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
int get_l_word(int limit, int* word, char **line){
    // I'll add this tomorrow...
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

    if(*(diffArray) != 0){
        ans += get_next_val(diffArray, length-1);
    }
    free(diffArray);
    return ans + dataArray[length - 1];
    
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