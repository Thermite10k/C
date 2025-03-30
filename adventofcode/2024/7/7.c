#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#define CHAR_BUFFER_SIZE 10
#define KEY_TEST "key.txt"
#define KEY_MAIN "key2.txt"
#define MAX_NUMBERS 30

char get_f_c(FILE *fp);
void unget_f_c(char C);
int32_t get_f_number(FILE *fp, int32_t limit, int32_t *number);

int main(){

    int32_t numbersArray[MAX_NUMBERS];
    int32_t numbersArrayIndex = 0;
    int32_t temp = 0;
    int32_t status = 0;
    
    FILE *fp = fopen(KEY_TEST, "r");

    while ((status = get_f_number(fp, MAX_NUMBERS, &temp)) != EOF){

            fprintf(stdout, "%d: ", temp);
   
        while ((status = get_f_number(fp, MAX_NUMBERS, &temp)) != EOF){
            printf("%d ", temp);
            if(status == '\n'){
             putchar('\n');
             break;
            }
        }
       
        
        
     
    }
    

}

char charBuffer[CHAR_BUFFER_SIZE];
int32_t charBufferPointer = 0;

char get_f_c(FILE *fp){
    if(charBufferPointer > 0){
        return(charBuffer[--charBufferPointer]);
    }else{
        return getc(fp);
    }
}
void unget_f_c(char c){
    if(charBufferPointer < CHAR_BUFFER_SIZE){
        charBuffer[charBufferPointer++] = c;
    }else{
        fprintf(stderr, "Error: unfet_f_c: Buffer is full.\n");
    }
}
int32_t get_f_number(FILE *fp, int32_t limit, int32_t *number){

    int32_t c = 0; 
    int32_t value = 0;

    while ((c = get_f_c(fp)) == ' '){
        ;
    }
    if(c == EOF || c == '\n'){
        return c;
    }
    if(isdigit(c)){
        value = value * 10 + c - '0';
    }

    while(--limit ){
        if(!isdigit((c = get_f_c(fp)))){
            //unget_f_c(c);
            break;
        }
        value = value * 10 + c - '0';
    }

    *number = value;
    return c;
    
}
