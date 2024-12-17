#include <stdio.h>
#include <ctype.h>

#define CHAR_BUFF_SIZE 100
#define MAX_LINE 100
#define KEY "key.txt"

char get_f_char(FILE* fp);
void unget_f_char(char c);

int get_f_line(int limit, char* line, FILE* fp);
int get_l_word(int limit, char* word, char** line);

int main(){

    FILE* fp = fopen(KEY, "r");

    char line[MAX_LINE];
    char word[MAX_LINE];

    char* linePtr = line;

while(get_f_line(MAX_LINE, line, fp) != 0){
        printf("%s\n", line);
        linePtr = line;
        while(get_l_word(MAX_LINE, word, &linePtr) != '\0'){
            printf("%s\n", word);
        }
    }

    return 0;
}

char charBuffer[CHAR_BUFF_SIZE];
int charBuffPtr = 0;

char get_f_char(FILE* fp){
    if(charBuffPtr > 0){
        return(charBuffer[--charBuffPtr]);
    }else{
        return getc(fp);
    }
}
void unget_f_char(char c){
    if(charBuffPtr < CHAR_BUFF_SIZE){
        charBuffer[charBuffPtr++] = c;
    }else{
        fprintf(stderr, "error: unget_f_c: buffer is full.\n");
    }
}

int get_f_line(int limit, char* line, FILE* fp){
 
    char c;
    int i = 0;
    char* l = line;
    while(--limit > 0 && (c = get_f_char(fp)) != EOF && c != '\n'){
        l[i++] = c;
    }

    // if(c == '\n'){
    //     *l++ = c;
    // }

    l[i] = '\0';
    return i;
}
int get_l_word(int limit, char* word, char** line){

    
    char* w = word;
    int c;

    while((c = *(*line)++) == ' '){
        ;
    }

    if(c != EOF){
        *w++ = c;
    }

    if(c == '\0'){
        *w = '\0';
        return c;
    }

    for(;--limit > 0; w++, (*line)++){
        if(!isalnum((*w = **line))){
            //unget_f_char(*w);
            break;
        }
    }

    *w = '\0';

    return word[0];


}
