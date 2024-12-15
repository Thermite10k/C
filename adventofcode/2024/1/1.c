#include <stdio.h>
#include <ctype.h>

#define KEY "key.txt"
#define MAX_WORD 100
#define CHAR_BUFF_SIZE 100

char get_f_char(FILE* fp);
void unget_f_char(char c);

int get_f_word(int limit, char* word, FILE* fp);



int main(int argc, char* argv){

    char word[MAX_WORD];
    FILE *fp = fopen(KEY, "r");

    while(get_f_word(MAX_WORD, word, fp) != EOF){
        printf("%s", word);
    }

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

    while(((c = get_f_char(fp))) == ' '){ // use isalnum() to eliminate '\n' as well.
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