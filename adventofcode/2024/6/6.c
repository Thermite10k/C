#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 150
#define MAX_LINE_BUFFER 150
#define CHAR_BUFF_SIZE 20
#define KEY "key.txt"

char get_f_char(FILE *fp);
void unget_f_char(uint8_t c);
uint32_t get_f_line(FILE *fp, uint32_t limit, char *line);

int main(){

    char line[MAX_LINE];
    FILE *fp = fopen(KEY, "r");
    char **lines = calloc(MAX_LINE_BUFFER, sizeof(char *));

    uint32_t linesCount = 0;
    uint32_t lineLength = 0;
    
    while ((lineLength = get_f_line(fp, MAX_LINE, line))){
        lines[linesCount] = calloc(lineLength, sizeof(char));
        memcpy(lines[linesCount], line, lineLength+1); // +1 to also copy '\0'
        linesCount++;
    }

    for(int i = 0; i < linesCount; i++){
        printf("%s\n", lines[i]);
    }
    

    return 0;
}

char charBuffer[CHAR_BUFF_SIZE];
uint32_t charBufferPointer = 0;

char get_f_char(FILE *fp){
    if(charBufferPointer > 0){
        return(charBuffer[--charBufferPointer]);
    }else{
        return(getc(fp));
    }
}
void unget_f_char(uint8_t c){
    if(charBufferPointer < CHAR_BUFF_SIZE){
        charBuffer[charBufferPointer++] = c;
    }else{
        fprintf(stderr, "error: unget_f_char: Buffer is full.");
    }
}
uint32_t get_f_line(FILE *fp, uint32_t limit, char *line){
    char c = 0;
    char *l = line;
    uint32_t length = 0;

    while ((c = get_f_char(fp)) == ' ')
    {
        ;    
    }
    if(c == EOF){
        l[length] = '\0';
        return length;
    }
    l[length++] = c;

    while (--limit-1 && (l[length] = get_f_char(fp)) != '\n' && l[length] != EOF){
        length++;
    }
    l[length] = '\0';
    return length;
    
    
}

