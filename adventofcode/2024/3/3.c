#include <stdio.h>
#include <ctype.h>

#define CHAR_BUFF_SIZE 10
#define MAX_WORD 100
#define KEY "key.txt"
#define READ_MODE "r"

int get_f_char(FILE* fp);
void unget_f_char(char c);

int get_f_word(FILE* fp, int limit, char* word);

int main(){
    
    char word[MAX_WORD] ;

    FILE* fp;
    fp = fopen(KEY, READ_MODE);

    while(get_f_word(fp, MAX_WORD, word) != EOF){
        printf("%s\n", word);
    }

    return 0;
}

char charBuff[CHAR_BUFF_SIZE];
int charBuffPtr = 0;

int get_f_char(FILE* fp){
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
        fprintf(stderr, "error: unget_f_char: Buffer is full!\n");
    }
}

int get_f_word(FILE* fp, int limit, char* word){
    char* w = word;
    int c;

    c = get_f_char(fp);
    if(c != EOF){
        *w++ = c;
    }
    if(!isalnum(c) || c == EOF){
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