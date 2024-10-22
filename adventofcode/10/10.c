#include <stdio.h>

#define MAX_LINE 140
#define CHAR_BUFFER_SIZE 100
#define KEY "key.txt"
#define TEST_KEY "key2.txt"


int get_f_line(int limit, char* line, FILE* fp);
int get_f_char(FILE* fp);
void unget_f_char(char c);
int has_start(char* line, int lineLength);
int traverse_loop(char (*tunnele)[MAX_LINE], int startingX, int startingY);
int initiate_loop(char (*tunnel)[MAX_LINE], int x, int y, int* Vx, int* Vy);
int main(){
    char lines[MAX_LINE][MAX_LINE];
    FILE* fp = fopen(KEY, "r");
    int lineCount = 0;
    int charInLineCount = 0;
    int YofS = -1;
    int XofS = -1;
    int steps = 0;
//                                                              max_line+2 to account for \n etc
    while(lineCount < MAX_LINE && (charInLineCount = get_f_line(MAX_LINE+2, lines[lineCount++], fp)) > 0){
        if(YofS == -1 && (XofS = has_start(lines[lineCount-1], charInLineCount))){   
            YofS = lineCount - 1;
        }
    }
    printf("X: %d\nY: %d\n", XofS, YofS);
    steps = traverse_loop(lines, XofS, YofS);
    printf("Farthest point: %d\n", steps/2);
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
int has_start(char* line, int lineLength){
    int x = 0;

    for(x = 0; x < lineLength; x++){

        if(line[x] == 'S'){
            return x;
        }
    }

    return 0;

}
int traverse_loop(char (*tunnel)[MAX_LINE], int startingX, int startingY){
    int steps = 0;
    int currentX = startingX;
    int currentY = startingY;
    int Vx = 0;
    int Vy = 0;
    char currentSelection = 0;
    while((currentSelection = tunnel[currentY][currentX]) != 'S' || steps == 0){
        printf("going to x: %.4d, y: %.4d\n", currentX, currentY);
        steps++;
        switch(currentSelection){
            case 'S':
                initiate_loop(tunnel, startingX, startingY, &Vx, &Vy);
                currentY += Vy;
                currentX += Vx;
                break;
            case '|':
                currentY += Vy;
                break;
            case '-':
                currentX += Vx;
                break;
            case 'L':
                if(Vx == -1){// enter from right
                    Vx = 0;
                    Vy = -1;
                }else if(Vy == 1){// enter from top
                    Vx = 1;
                    Vy = 0;
                }
                currentY += Vy;
                currentX += Vx;
                break;
            case 'J':
                if(Vx == 1){// enter from left
                    Vx = 0;
                    Vy = -1;
                }else if(Vy == 1){// enter from top
                    Vy = 0;
                    Vx = -1;
                }
                currentY += Vy;
                currentX += Vx;
                break;
            case 'F':
                if(Vx == -1){// enter from right
                    Vx = 0;
                    Vy = 1;
                }else if(Vy == -1){// enter from bottom
                    Vx = 1;
                    Vy = 0;
                }
                currentY += Vy;
                currentX += Vx;
                break;
            case '7':
                if(Vx == 1){// enter from right
                    Vx = 0;
                    Vy = 1;
                }else if(Vy == -1){// enter from bottom
                    Vx = -1;
                    Vy = 0;
                }
                currentY += Vy;
                currentX += Vx;
                break;
            
            default:
                printf("Got an unexpected character -%c-\n", currentSelection);
                break;


        }
    }
    return steps;
}
int initiate_loop(char(*tunnel)[MAX_LINE], int x, int y, int* Vx, int* Vy){
    int dy = -1;
    int dx = -1;
    char current = 0;
    for(dy = -1; dy < 2; dy++){
        for(dx = -1; dx < 2; dx++){
            current = tunnel[y+dy][x+dx];
            if(!(dx*dy)){ // if it's a valid block: above, below, left, right
                if(dy == -1 || dy == 1){ // if we're checking the top or bottom
                    if(current == '|' || current == 'F' || current == '7'){
                        *Vy = dy;
                        return 0;
                    }
                }
                if(dy == 0 && dx == -1){
                    if(current == '-' || current == 'L'){
                        *Vx = dx;
                        return 0;
                    }
                }else if(dy == 0 && dx == 1){
                    if(current == 'J' || current == '7'){
                        *Vx = dx;
                        return 0;
                    }
                }
            }
        }
    }
    printf("Can not star moving from S!\n");
    return -1;
}