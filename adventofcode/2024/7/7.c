#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#define CHAR_BUFFER_SIZE 10
#define KEY_TEST "key.txt"
#define KEY_MAIN "key2.txt"
#define MAX_NUMBERS 30

char get_f_c(FILE *fp);
void unget_f_c(char C);
int64_t get_f_number(FILE *fp, int32_t limit, int64_t *number);
int32_t can_be_solved(int64_t acc, int32_t index, int64_t answer, int64_t *numbers);
int main(){

    int64_t numbersArray[MAX_NUMBERS];
    int32_t numbersArrayIndex = 0;
    int64_t temp = 0;
    int32_t status = 0;
    uint64_t answer = 0;
    
    FILE *fp = fopen(KEY_MAIN, "r");

    while ((status = get_f_number(fp, MAX_NUMBERS, &temp)) != EOF){
        numbersArrayIndex = 0;
        numbersArray[numbersArrayIndex++] = temp;
        while ((status = get_f_number(fp, MAX_NUMBERS, &temp)) != EOF){
            numbersArray[numbersArrayIndex++] = temp;
            if(status == '\n'){
            numbersArray[numbersArrayIndex] = -1; // this will marl the end of the current set.
            for(uint32_t i = 0; i < numbersArrayIndex; i++){
               // printf("%lld ", numbersArray[i]);
            }
            if(can_be_solved(0, 1, numbersArray[0], numbersArray)){
                //printf("\t\t%lld can be achieved.", numbersArray[0]);
                answer += (uint64_t)numbersArray[0];
            }
             //putchar('\n');
             break;
            }
        }     
    }

    printf("%lld\n", answer);
    return 0;

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
int64_t get_f_number(FILE *fp, int32_t limit, int64_t *number){

    int32_t c = 0; 
    int64_t value = 0;

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
            // unget_f_c(c);
            break;
        }
        value = value * 10 + c - '0';
    }

    *number = value;
    return c;
    
}

int32_t can_be_solved(int64_t acc, int32_t index, int64_t answer, int64_t *numbers){
    if(numbers[index] == -1){
        if(acc == answer){
            return 1;
        }
        return 0;
    }
    index++;
    if(can_be_solved(acc + numbers[index-1], index, answer, numbers)){
        return 1;
    }
    return can_be_solved(acc * numbers[index-1], index, answer, numbers);
}