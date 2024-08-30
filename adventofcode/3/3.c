#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 1000
#define CHARBUFF 10
#define MAXLINE 1000

#define MAX(a,b) ((a > b) ? a : b)


int evaluate(char (*)[], int x, int y);
int iteratepuzzle(char **puzzle, int rows, int cols);
int getfileline(int limit, FILE *fp, char *line);
int getwordfromline(char **line, char *word, int limit);
int myatoi(char *str);
int check(char **puzzle, int x, int y, int rows, int cols, int length);
int isvalidsymbol(char value);
int getneighbordigit(char **puzzle, int x, int y, int rows, int cols);
int getneighbornumber(char **puzzle, int x, int y);

int main(void){
    char *line = (char *)malloc(MAXLINE); // char line[maxline] is also valid.
    int length = 0; // columns
    int answer = 0;
    int *ROWS = malloc(sizeof(int));
    int *COLS = malloc(sizeof(int));
    *COLS = 0;
    *ROWS = 0;
    char **puzzle = (char **)malloc(MAXLINE * sizeof(char *)); // a 2-D array
    char **pp = puzzle;
    FILE *fp;
    fp = fopen("key.txt", "r");
    while((length = getfileline(MAXLINE, fp, line))){
        //printf("Line: \t%sLine: \t%d\n", line, length);
        *pp = (char *)malloc(length+1); //puzzle pointer allocates space for storing the n-th line.
        memcpy(*pp, line, length+1);
        *pp++;
        (*ROWS)++;
       
        *COLS = MAX(*COLS, length-1);
    }


    
    answer = iteratepuzzle(puzzle, *ROWS, *COLS);

    printf("Answer: %d\n", answer);



    return 0;
}

int evaluate(char (*)[], int x, int y){
    return 0;
}
int getfileline(int limit, FILE *fp, char *line){ // char *line[] is an array of lines, not what we need.
    int i=0, c;
    for(i=0; (i < limit - 1) && (c = getc(fp)) != '\n' && c != EOF; i++){
        line[i] = c;
    }
    if(c == '\n'){
        line[i++] = c;
    }
    line[i] = '\0';


    return i;
}

int iteratepuzzle(char **puzzle, int rows, int cols){
    int x = 0, y = 0, length = 0, isvalid = 0, gearRatio = 0;
    int answer = 0;
    char word[MAXWORD];
    char *lineptr;
    for(y=0; y<rows; y++){
        // for(x=0; x<=cols; x++){
        //     //printf("%c", puzzle[y][x]);
        //     printf("%c", *(*(puzzle + y) + x));
        // }
        lineptr = *(puzzle + y);
        //printf("sending %s", lineptr);
            while(getwordfromline(&((lineptr)), word, MAXWORD)){
                length = strlen(word);
                x += length;
                isvalid = 0;
                if(myatoi(word)){
                    //printf("%s\tfor%d to %d at y = %d \n", word, x-length, x-1, y); // x-1 because index starts at 0          

                    isvalid = check(puzzle, x, y, rows, cols, length); 
                    if(!isvalid && ((y-1) >=0) ){
                        isvalid = check(puzzle, x, y-1, rows, cols, length);
                    }
                    if(!isvalid && (y+1 < rows)){ // if we have 10 rows, index is from 0 to 9.
                        isvalid = check(puzzle, x, y+1, rows, cols, length);
                    }

                    if(isvalid){
                        answer += myatoi(word);
                    }
                }
                if(*word == '*'){
                    gearRatio += getneighbordigit(puzzle, x-length, y, rows, cols);
                }
        
            }
        x = 0;
    }
    printf("Gear Ratio: %d\n", gearRatio);
    return answer;
}
int getwordfromline(char **line, char *word, int limit){

    int c;
    char *w = word;
  
    while(isspace((c = *(*line)++))){
        ;
    }
    if(c != EOF){

        *w++ = c;
    }
    if(c == '\0' || !isalnum(c)){
        *w = '\0';
        return c;
    }


    for(; --limit > 0; (*line)++, w++){
        if(!isalnum(*w = **line)){
            break;
        }
    }

    *w = '\0';
    
    return word[0];

}
int myatoi(char *str){
    int value = 0;
    while(*str){
        if((*str - '0') >= 0 && (*str - '0') <= 9){
            value = 10 * value + *str - '0';
        }
        str++;
    }
    return value;
}
int check(char **puzzle, int x, int y, int rows, int cols, int length){
    //    x-length-1 zzzzzzzzzzz  x  : z is a digit
    //    ____^_____              ^
    //     char before number --  x is the first char after our number.
    int isvalid = 0;
    int i = 0;
    if((x-length-1) >= 0){ // if x is not out of bounds, check left
        isvalid = isvalidsymbol(puzzle[y][x-length-1]);
    }
    if(!isvalid && (x < cols)){ // if x is not out of bounds, check right
        isvalid = isvalidsymbol(puzzle[y][x]);
    }
    if(!isvalid){ // check the characters of the word, useful for when y+1 or y-1
        for(i = x-length; (i < x) && !isvalid; i++){
            isvalid = isvalidsymbol(puzzle[y][i]);
            if(isvalid){
            }
        }
    }

    return(isvalid);
}
int isvalidsymbol(char value){
                //printf("Checking %c\n", value);
   // anything is a valid symbol as long as it's not alnum and it's not a period 
    return(!isalnum(value) && value != '.');
}
int getneighbordigit(char **puzzle, int x, int y, int rows, int cols){
    int firstNumber = 1, secondNumber = 1, checkNumber = 1;
    /*
          23779   | Get a digiti and see what number it belongs too, get the number and save it.
            *     | Get the second digit, if any, and store it in the second var. if you come across
            46    | a new digit, get its number and if it's not the same as the second number, terminate.
    */
    if((x-1) >= 0){ // if anyhting is to the left (x-1), check it.
        if(isdigit(puzzle[y][x-1])){
            if(firstNumber == 1){
                firstNumber = getneighbornumber(puzzle, x-1, y);
              
            }else{
                checkNumber = getneighbornumber(puzzle, x-1, y);
                if(secondNumber == 1){
                    secondNumber = checkNumber;
                }else if(secondNumber != checkNumber){
                    return 0;
                }
            }
        }
    }
    if(isdigit(puzzle[y][x])){// for upper and lower rows
        if(firstNumber == 1){
            firstNumber = getneighbornumber(puzzle, x, y);
        }else{
            checkNumber = getneighbornumber(puzzle, x, y);
            if(secondNumber == 1){
                secondNumber = checkNumber;
            }else if(secondNumber != checkNumber){
                return 0;
            }
        }
    }
    if((x+1) < cols){// checking the right side.
        if(isdigit(puzzle[y][x+1])){
            if(firstNumber == 1){
                firstNumber = getneighbornumber(puzzle, x+1, y);
            }else{
                checkNumber = getneighbornumber(puzzle, x+1, y);
                if(secondNumber == 1){
                    secondNumber = checkNumber;
                }else if(secondNumber != checkNumber){
                    return 0;
                }

            }
        }
    }
    
    return firstNumber * secondNumber;
}
int getneighbornumber(char **puzzle, int x, int y){
    int number = 0;
    char *line = *(puzzle + y);
    char *n_ptr = line+x; // number pointer

    while(isdigit(*n_ptr)){// go to the begining of the number.
        n_ptr--;
    }
    n_ptr++; // now set the pointer to the first digit of the number
    while(isdigit(*n_ptr)){
        number = 10 * number + *n_ptr++ - '0';
    }
    return number;
}