#include <stdio.h>

#define MAX_LINE 150
#define CHAR_BUFFER_SIZE 100
#define KEY "key.txt"

int get_f_line(int limit, char* line, FILE* fp);
int get_f_char(FILE* fp);
void unget_f_char(char c);

int main(){
    char lines[MAX_LINE][MAX_LINE];
    FILE* fp = fopen(KEY, "r");
    int lineCount = 0;
    int charInLine = 0;

    while((charInLine = get_f_line(MAX_LINE, lines[lineCount++], fp)) > 0){
        printf("Line: %.3d\tChars: %.4d\n", lineCount, charInLine);
    }
    return 0;
}
int get_f_line(int limit, char* line, FILE* fp){
    int c;
    char* l = line;
    int charCount = 0;

    while(--limit > 0 && (c = get_f_char(fp)) != EOF && c != '\n'){
        *l++ = c;
        charCount++;
    }

    if(c == EOF || c == '\n'){
        *l++ = c;
    }

    *l = '\0';
    return charCount;
}

int charBuffer[CHAR_BUFFER_SIZE];
int charBufferIndex = 0;


int get_f_char(FILE* fp){
    if(charBufferIndex > 0){
        return charBuffer[--charBufferIndex];
    }else{
        return getc(fp);
    }
}
void unget_f_char(char c){
    if(charBufferIndex < CHAR_BUFFER_SIZE){
        charBuffer[charBufferIndex++] = c;
    }else{
        fprintf(stderr, "Error: unget_f_char: Buffer is full");
    }
}