#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define KEY "key.txt"
#define KEY_2 "key2.txt"
#define MAX_LINE 150
#define CHAR_BUFF_SIZE 10
#define ROWS 150
#define COLS 150

int get_f_line(FILE* fp, char* line, int limit);
int get_f_char(FILE* fp);
void unget_f_char(char c);

int look_for_pattern(char lines[ROWS][COLS], char* pattern, int y, int x);
int look_for_X_pattern(char lines[ROWS][COLS], int y, int x);

int main(){

    FILE* fp = fopen(KEY_2, "r");
    char line[MAX_LINE];
    char lines[ROWS][COLS];
    int row = 0;
    int lineLength = 0;
    int answer = 0;
    while(row < ROWS && (lineLength = get_f_line(fp, line, MAX_LINE))){
        strcpy(lines[row++], line);
    }
    lineLength = strlen(lines[0]);

    int x = 0;
    int y = 0;

    for(y = 0; y < row; y++){
        for(x = 0; x < lineLength; x++){
            if(lines[y][x] == 'A'){
                answer += look_for_X_pattern(lines, y, x);
            }
        }
    }

    printf("%d", answer);

    return 0;
}


int get_f_line(FILE* fp, char* line, int limit){
    int c;
    char* l = line;
    int i = 0;

    

    while(isspace((c = get_f_char(fp)))){
        ;
    }
    if(c == EOF){
        return i;
    }else{
        l[i++] = c;
    }

    while(i < limit-1 && (l[i] = get_f_char(fp)) != EOF && l[i] != '\n'){
        i++;
    }
    l[i] = '\0';
    return i;

}

int charBuff[CHAR_BUFF_SIZE];
int charBuffPtr = 0;

int get_f_char(FILE* fp){
    if(charBuffPtr > 0){
        return(charBuff[--charBuffPtr]);
    }else{
        return getc(fp);
    }
}
void unget_f_char(char c){
    if(charBuffPtr < CHAR_BUFF_SIZE){
        charBuff[charBuffPtr++] = c;
    }else{
        fprintf(stderr, "error: unget_f_char: buffer is full.");
    }
}

int look_for_X_pattern(char lines[ROWS][COLS], int y, int x){

    int dy = -1, dx = -1;
    int matches = 0;
    int c1 = 0, c2 = 0;
    for(dy = -1; dy < 0; dy ++){ // setting dy < 0 improves the speed as we check for the opposite sides in the logic. the first row is enough
        if(y+dy < ROWS && y+dy >= 0){
            for(dx = -1; dx < 2; dx++){
                
                if(x+dx < COLS && x+dx >= 0){
                    if(fabs(dy*dx)){ // this only checks the diagonal characters
                        /*
                            c1 and c2 are the opposite sides 

                            c1  .   .
                            .   A   .
                            .   .   c2

                            or any other valid combo


                        */
                        c1 = lines[y+dy][x+dx];
                        c2 = lines[y-dy][x-dx];
                        if(c1 != c2 &&(c1 == 'M' || c1 == 'S') && (c2 == 'M' || c2 == 'S')){
                            matches ++;
                        }
                    }
                }
            }
        }
    }

    if(matches == 2){ // set it to 4 if dy < 2
        return 1;
    }
    return 0;

}

int look_for_pattern(char lines[ROWS][COLS], char* pattern ,int y, int x){

    int patternLength = strlen(pattern);
    int dx = 0, dy = 0;

    int j = 0;
    int patternCount = 0;
    // checking right x -> x + len-1
    if(x+patternLength-1 < COLS && lines[y][x+1] == pattern[1]){
        for(j = 2; j < patternLength; j++){

            if(lines[y][x+j] != pattern[j]){
                break;
            }
        }
        if(j == patternLength){
            patternCount++;
        }
    }
    // checking bottom right y -> y + len-1 && x -> x + len-1
    if((y+patternLength-1 < ROWS && x+patternLength-1 < COLS) && lines[y+1][x+1] == pattern[1]){
        for(j = 2; j < patternLength; j++){
            if(lines[y+j][x+j] != pattern[j]){
                break;
            }
        }
        if(j == patternLength){
            patternCount++;
        }
    }

    // checking bottom y -> y + len-1
    if(y + patternLength-1 < ROWS && lines[y+1][x] == pattern[1]){
        for(j = 2; j < patternLength; j++){
            if(lines[y+j][x] != pattern[j]){
                break;
            }
        }
        if(j == patternLength){
            patternCount++;
        }
    }

    // checking bottom left y -> y + len-1 && x -> x - len+1

    if(x - patternLength+1 >= 0 && y + patternLength-1 < ROWS && lines[y+1][x-1] == pattern[1]){
        for(j = 2; j < patternLength; j++){
            if(lines[y+j][x-j] != pattern[j]){
                break;
            }
        }
        if(j == patternLength){
            patternCount++;
        }
    }

    // checking left x -> x - len+1
    if(x-patternLength+1 >= 0 && lines[y][x-1] == pattern[1]){
        for(j = 2; j < patternLength; j++){
            if(lines[y][x-j] != pattern[j]){
                break;
            }
        }
        if(j == patternLength){
            patternCount++;
        }
    }

    // checking top left y -> y - len+1 && x -> x - len+1

    if(x - patternLength+1 >= 0 && y - patternLength+1 >= 0 && lines[y-1][x-1] == pattern[1]){
        for(j = 2; j < patternLength; j++){
            if(lines[y-j][x-j] != pattern[j]){
                break;
            }
        }
        if(j == patternLength){
            patternCount++;
        }
    }

    // checking top y -> y - len+1
    if(y - patternLength+1 >= 0 && lines[y-1][x] == pattern[1]){
        for(j = 2; j < patternLength; j++){
            if(lines[y-j][x] != pattern[j]){
                break;
            }
        }
        if(j == patternLength){
            patternCount++;
        }
    }

    // checking top right y -> y + len-1 && x -> x + len-1
    if(y + patternLength-1 < ROWS && x + patternLength-1 < COLS &&  lines[y-1][x+1] == pattern[1]){
        for(j = 2; j < patternLength; j++){
            if(lines[y-j][x+j] != pattern[j]){
                break;
            }
        }
        if(j == patternLength){
            patternCount++;
        }
    }

    return patternCount;

}