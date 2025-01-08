#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define CHAR_BUFF_SIZE 10

#define KEY "key2.txt"

int get_f_char(FILE* fp);
void unget_f_char(char c);

int main(){

    char pattern[] = "mul(%d,%d)";
    int patternLength = strlen(pattern);
    int c, i = 0;
    long tempAnswer = 1;
    long answer = 0;
    int number = 0;

    FILE* fp = fopen(KEY, "r");

    while((c = get_f_char(fp)) != EOF){

        if(c == '\n'){
            continue;
        }

        if(c == pattern[i]){
            i++;
        }else if(pattern[i] == '%'){
            i++;
            
            switch(pattern[i++]){
                case 'd':
                    number = 0;

                    if(isdigit(c)){
                        number = number * 10 + c - '0';
                        while(isdigit((c = get_f_char(fp)))){
                            
                            number = number * 10 + c - '0';
                        }
                        if(c != EOF){
                            unget_f_char(c);
                        }
                    }
                    
                    //printf("%d\n", number);
                    tempAnswer *= number;
                    break;
                default:
                    break;
            }
            
        }else{
            i = 0;
            tempAnswer = 1;
        }
        
        if(i == patternLength){
            //printf("Adding %d\n", tempAnswer);
            answer += tempAnswer;
            tempAnswer = 1;
            i = 0;
        }

    }

    printf("%ld\n", answer);
   
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
        fprintf(stderr, "error: unget_f_char: buffer is full.\n");
    }
}