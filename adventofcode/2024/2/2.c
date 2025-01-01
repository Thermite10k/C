#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
    We must check the overall trend and the difference of two consecutive numbers
*/
#define CHAR_BUFF_SIZE 100
#define MAX_LINE 100
#define KEY "key.txt"
#define KEY_2 "key2.txt"
#define MAX_NUMBERS 15 // We expect 15 unmbers at most for each line of data.

char get_f_char(FILE* fp);
void unget_f_char(char c);

int get_f_line(int limit, char* line, FILE* fp);
int get_l_word(int limit, char* word, char** line);

int check_for_safety(int* numbers, int count);
int is_safe_entry(int numbers[], int count);

int main(){

    FILE* fp = fopen(KEY, "r");

    char line[MAX_LINE];
    char word[MAX_LINE];

    char* linePtr = line;
    int lineNumbers[MAX_NUMBERS];
    int i = 0;
    int safeCount = 0;

    while(get_f_line(MAX_LINE, line, fp) != 0){

            linePtr = line;
            i = 0;
            while(i < MAX_NUMBERS && get_l_word(MAX_LINE, word, &linePtr) != '\0'){
                lineNumbers[i++] = atoi(word);
            }
            // printf("Entry: %s is %d\n", line, check_for_safety(lineNumbers, i));
            safeCount += check_for_safety(lineNumbers, i);
        }
 
    printf("Safe entries: %d\n", safeCount);
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
int check_for_safety(int* numbers, int count){
    int lastRate = 0;
    // rates[0] = decreasing. rates[1] = increasing
    int rates[] = {0, 0};
    int rate = 0;
    int i = 0;
    int number1 = 0, number2 = 0;
    int dampner = 0; // this is our error flag, we can stand up to one error
    int difference = 0;
        if(count < 3){
            fprintf(stderr, "Can not check safety if count is < 3, count: %s\n", count);
            return 0;
        }
    for(i=0; i < count-1; i++){
        number1 = numbers[i];
        number2 = numbers[i+1];
        (number2 - number1) > 0 ? rates[1]++ : rates[0]++;

    }

    lastRate = rates[1] > rates[0] ? 1 : -1;
    //lastRate = (numbers[count-1] - numbers[0]) > 0 ? 1 : -1; // rate is either positive or negative.
    int firstMethod = 0, secondMethod = 0;
    for(i=0; i < count-1; i++){
        // 1 2 7 8 9
        number1 = numbers[i];
        number2 = numbers[i+1];
        if(i == 0 && number1 == number2){
            // if the first two data points are equal, ignore them but set dampner to 1.
            printf("Will remove %d\n", numbers[i+1]);
            dampner = 1;
            continue;
        }
        if(i == count-2 && number1 == number2){ // last two numbers
            /*
                If the last two numbers are equal and dampner (previous errors) is zero, 
                it's a safe set, else it's not.
            */
            if(dampner){
                return 0;
            }else{
                return 1;
            }
        }
        
        difference = number2 - number1;
        difference = difference > 0 ? difference : -1 * difference; // getting abs(difference)
        rate = (number2 - number1) > 0 ? 1 : -1;
        if((rate != lastRate || difference > 3 || difference < 1)){ // rate can't change and diff must be between 1 and 3, INCLUDING 1 and 3
           // compare i-1 and i+1, if error, return 0 else set i to i+1
            if(dampner){
                return 0;
            }
            if(i == count - 2){
                number1 = numbers[i-1];
                number2 = numbers[i+1];
                difference = number2 - number1;
                difference = difference > 0 ? difference : -1 * difference;
                if(difference > 3 || difference < 1){
                    return 0;
                }
            }
            
            number2 = numbers[i+1];
            number1 = numbers[i-1];
            difference = number2 - number1;
            difference = difference > 0 ? difference : -1 * difference; // getting abs(difference)
            rate = (number2 - number1) > 0 ? 1 : -1;         
            if(rate != lastRate || difference > 3 || difference < 1){
                
                number2 = numbers[i+2];
                number1 = numbers[i];
                
                difference = number2 - number1;
                difference = difference > 0 ? difference : -1 * difference; // getting abs(difference)
                rate = (number2 - number1) > 0 ? 1 : -1;
      
                if(rate != lastRate || difference > 3 || difference <1){
                    
                        return 0;
                    
                }else{
                    i++;
                }
            }
                
            
            dampner = 1;
            printf("Will remove %d\n", numbers[i]);
        }
           
           
           
            
        
    }
    // 624 is too high
    // 58x is too low
    return 1;
}

int is_safe_entry(int numbers[], int count){
    
    struct stat {
        int increasing;
        int decreasing;
        int differenceViolation;
    };

    struct stat set_stats = {.increasing = 0, .decreasing = 0, .differenceViolation = 0};


}