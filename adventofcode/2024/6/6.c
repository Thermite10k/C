#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX_LINE 150
#define MAX_LINE_BUFFER 150
#define CHAR_BUFF_SIZE 20
#define KEY "key2.txt"

struct vector{ // can be used for any (x, y) pair.
    int32_t x;
    int32_t y;
};

char get_f_char(FILE *fp);
void unget_f_char(uint8_t c);
int32_t get_f_line(FILE *fp, int32_t limit, char *line);
void warp_to_obstacle(uint32_t **floor, int32_t columns, int32_t rows);
struct vector *find_guard(uint32_t **floor, int32_t columns, int32_t rows);
int32_t look(uint32_t **floor, int32_t columns, int32_t row, struct vector *guard, struct vector *heading, int32_t *steps);
void rotateVector(struct vector *vector, int32_t angle);
void showMap(uint32_t **floor, int32_t columns, int32_t rows);
void swap(uint32_t **floor, int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void memcpyCharToInt(uint32_t *dest, char *src, int32_t length);
int32_t turn_n_hit_old_obstacle(uint32_t **floor, int32_t coulmns, int32_t rows,  struct vector *guard,  struct vector *heading); // turn right, if you hit '#' and are not on '.', return 1 : 0

uint32_t floorCpy[200][200];

int main(){
    for(uint32_t i = 0; i < 200; i++)    {
        for(uint32_t j = 0; j < 200; j++){
            floorCpy[i][j] = 0;
        }
    }
    char line[MAX_LINE];
    FILE *fp = fopen(KEY, "r");
    uint32_t **lines = calloc(MAX_LINE_BUFFER, sizeof(uint32_t *));

    int32_t linesCount = 0; // same as rows
    int32_t lineLength = 0; 
    int32_t numberOfColumns = 0;

    while ((lineLength = get_f_line(fp, MAX_LINE, line))){
        lines[linesCount] = calloc(lineLength, sizeof(uint32_t));
        for(int32_t i = 0; i < lineLength; i++){
            lines[linesCount][i] = (uint32_t) line[i];
        }
        //memcpy(lines[linesCount], line, lineLength+1); // +1 to also copy '\0'
        linesCount++;
        numberOfColumns = lineLength;
    }
    //printf("Copied %d lines successfuly.\n", linesCount);
    //showMap(lines, numberOfColumns, linesCount);
    
    
    warp_to_obstacle(lines, numberOfColumns, linesCount);
    uint32_t ans = 0;
    for(uint32_t i = 0; i < 200; i++)    {
        for(uint32_t j = 0; j < 200; j++){
            floorCpy[i][j] && ans++;
        }
    }

    printf("obstacles: %d\n", ans);

    return 0;
}

char charBuffer[CHAR_BUFF_SIZE];
int32_t charBufferPointer = 0;

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
int32_t get_f_line(FILE *fp, int32_t limit, char *line){
    char c = 0;
    char *l = line;
    int32_t length = 0;

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


void warp_to_obstacle(uint32_t **floor, int32_t columns, int32_t rows){
    
    struct vector *guard = find_guard(floor, columns, rows);
    floor[guard->y][guard->x] = '.';
    struct vector heading = {.x = 0, .y = -1}; // initially, the guard is '^' which is looking up, x=0, y=-1;
    int32_t steps = 0;
    
    while(look(floor, columns, rows, guard, &heading, &steps)){
        rotateVector(&heading, -90);
        // printf("guard exits at x: %d y: %d  with heading x: %d y: %d and has walked %d steps\n", guard->x, guard->y, heading.x, heading.y, steps);
    }
    steps = steps+1; // the algorithm does not take the last step.
    //showMap(floor, columns, rows);
    printf("guard exits at x: %d y: %d  with heading x: %d y: %d and has walked %d steps\n", guard->x, guard->y, heading.x, heading.y, steps);
       
    
}

struct vector *find_guard(uint32_t **floor, int32_t columns, int32_t rows){
    struct vector *guard = malloc(sizeof(struct vector *));
    for(int32_t y = 0; y < rows; y++){
        for(int32_t x = 0; x < columns; x++){
            if(floor[y][x] == '^'){
                guard->x = x;
                guard->y = y;
            }
        }
    }

    return guard;
}


int32_t look(uint32_t **floor, int32_t columns, int32_t rows, struct vector *guard, struct vector *heading, int32_t *steps){
    if(heading->x == 0 && heading->y == 0){
        printf("where exactly is the guard looking at?\n");
    }

    // the following x, y pair is one 'block' ahead of guard in the direction of heading, where it will "look"
    static int32_t obstacleCount = 0; // we start at 300 to avoid ASCII characters.
    int32_t x = guard->x + heading->x;
    int32_t y = guard->y + heading->y;
    int32_t blockAhead = 0;
    while(x < columns && y < rows  && x >=0 && y >= 0){
        guard->x = x - heading->x;
        guard->y = y - heading->y;
        floor[guard->y][guard->x] = '!'; // mark where you stand
        blockAhead = floor[y][x];

        if(blockAhead != '#'){ // if you can take a step
            if(blockAhead != '!' && !floorCpy[y][x] && turn_n_hit_old_obstacle(floor, columns, rows, guard, heading)){
                floorCpy[y][x] = 1;
                obstacleCount++;
            };
            if(blockAhead == '.'){ // if you've never been there, add to unique steps
                *steps = *steps + 1;
            }
            
        
        }
        if(blockAhead == '#'){ // if the obstacle is ahead
            break;
        }
        x += heading->x;
        y += heading->y;
    }
    //floor[guard->y][guard->x] = 'f'; // mark where you stand

    //printf("Possible obstacles: %d\n", obstacleCount);
    // we subtract the heading because guard+heading is the block ahead, not the guard itself.
    guard->x = x - heading->x;
    guard->y = y - heading->y;
    if(x >= columns || y >= rows || x < 0 || y < 0){// if block ahead is out of bounds
        return 0;
    }
    return 1;
}

void rotateVector(struct vector *vector, int32_t angle){
    // sine and cosine are floats but in our case, they will always be integers
    //double_t radians = angle * 3.1415926 / 180;
    /*
        I will not use sin(radians) and cos(radians) as we really don't need it here, we're working with integeres and our angle never changes.
        Unnecessary complexity.
    */
    int32_t sine = -1;
    int32_t cosine = 0;
    int32_t x = vector->x;
    int32_t y = vector->y;
    /*
        I flipped the sign of y.sine and x.sine becasue the y axis is flipped in our case
    */
    vector->x = (x * cosine) + (y * sine);
    vector->y = -(x * sine) + (y * cosine);
}
void showMap(uint32_t **floor, int32_t columns, int32_t rows){
    for(int32_t y = 0; y < rows; y++){
        for(int32_t x = 0; x < columns; x++){
            putchar(floor[y][x]%CHAR_MAX); // we're working with integers and putchar expects a char. This does not fully represent the floor as characters loop every CHAR_MAX while they are actually unique
        }
        putchar('\n');
    }

}
void swap(uint32_t **floor, int32_t x1, int32_t y1, int32_t x2, int32_t y2){
    char temp = floor[y1][x1];
    floor[y1][x1] = floor[y2][x2];
    floor[y2][x2] = temp;
}
void memcpyCharToInt(uint32_t *dest, char *src, int32_t length){
    
    for(uint32_t i = 0; i < length; i++){    
        dest[i] = (uint32_t)src[i];
    }
}


int32_t turn_n_hit_old_obstacle( uint32_t **floor,int32_t columns, int32_t rows,   struct vector *guard,  struct vector *heading){


    struct vector guardCpy = {.x = guard->x, .y = guard->y};
    struct vector headingCpy = {.x = heading->x, .y = heading->y};

    uint32_t x = guardCpy.x + headingCpy.x;
    uint32_t y = guardCpy.y + headingCpy.y;
    
    uint32_t *obstacle = &floor[y][x];
    uint32_t obstacleCpy = *obstacle;
    *obstacle = '#';
        
    rotateVector(&headingCpy, -90);

    x = guard->x + headingCpy.x;
    y = guard->y + headingCpy.y;

    uint32_t maxSteps = columns * rows;
    uint32_t steps = 0;
    
//    printf("looking for loop at x:%d, y:%d\n", guard->x, guard->y);
    while (steps < maxSteps && x >= 0 && y >= 0 && x < columns && y < rows){    
        guardCpy.x = x - headingCpy.x;
        guardCpy.y = y - headingCpy.y;
        if(steps > 1 && guard->x == guardCpy.x && guard->y == guardCpy.y && heading->y == headingCpy.y && heading->x == headingCpy.x){
            *obstacle = obstacleCpy;
            //printf("Guard is at x: %0.2d y: %0.2d, looking at x: %0.2d y: %0.2d which is a %c\n", guardCpy.x, guardCpy.y, x, y, floor[y][x]);
            //printf("fast exit\n");
            return 1;
        }
        if(floor[y][x] == '#'){
            rotateVector(&headingCpy, -90);
            x = guardCpy.x + headingCpy.x;
            y = guardCpy.y + headingCpy.y;
        }else{
            // if(guard->x == guardCpy.x && guard->y == guardCpy.y && heading->y == headingCpy.y && heading->x == headingCpy.x){
            //     *obstacle = obstacleCpy;
            //     return 1;
            // }
            y += headingCpy.y;
            x += headingCpy.x;
        }
        
        steps++;
        
    }
    if(steps == maxSteps){
        *obstacle = obstacleCpy;
       // printf("steps exit\n");
        return 1;
    }

    *obstacle = obstacleCpy;
    return 0;

}

/*

    It's 03/03/25 @ 4:12 AM, too late to think clearly and implement my solution, what you should do is 
    on each step, turn right, if you hit a valid obstable, keep turning and moving until you reach whe-
    -re you started from and return 1. I don't know what the base condition should be but it's either 
    a loop, and we return 1, or we get out of bounds and return 0

*/