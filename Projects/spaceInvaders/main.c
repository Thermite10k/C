#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define ROWS 15
#define COLS 40
/*
    NAMING CONVENTION
    ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
    DEFINE
    a_function()
    myVariable - exception for two char vars such as dx, Vy, etc
    ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
*/
/*
    These are the characters that represent game objects
    O: enemy, lvl 1
    M: enemy, lvl 2
    X: enemy, lvl 0 - will die next time it's printed
    ASCII 30: Player bullet
    A: player ship
    ASCII 254: player bullet
    |: enemy bullet
*/

enum env{
    ENEMY_1 = 'O', ENEMY_2 = 'M', ENEMY_0 = 'X', ENEMY_BULLET = '|', // enemy
    PLAYER_BULLET = 30, PLAYER_SHIP = 'A', // player
    ENV_BRICK_HALF = 254, ENV_BRICK_FULL = 219 // making the envirenment
};

void display(char (*array)[COLS], int rows, int cols);

// initializes the array to either ' ' or whatever char is given as the second arg
void initialize_char_pointer_array(char (*array)[COLS], int rows, int cols, ...);

// setsup the frontBuffer to start the game
void setup_front_buffer(char (*array)[COLS], int rows, int cols);

// reads the fron buffer and puts the new instance in backbuffer
void update_game_state(char (*arrayBack)[COLS], char (*arrayFront)[COLS], int rows, int cols);

// returns 1 if it's hitting a wall, returns 2 if it's hitting the bottom
// if y == 1 || y == rows  OR x == 1 || cols, we have a collision
int check_for_collision(int y, int x, int rows, int cols);

int main(){

    // we use a two buffer approach
    char frontBuffer[ROWS][COLS];
    char backBuffer[ROWS][COLS];
    
    


    initialize_char_pointer_array(frontBuffer, ROWS, COLS);
    initialize_char_pointer_array(backBuffer, ROWS, COLS);
    setup_front_buffer(frontBuffer, ROWS, COLS);

    while(1){
        printf("\033[%dA\033[%dD", ROWS, COLS);
        display(frontBuffer, ROWS, COLS);
        update_game_state(backBuffer, frontBuffer, ROWS, COLS);
        memcpy(frontBuffer, backBuffer, sizeof(backBuffer));
    }

    return 0;
}
void display(char (*array)[COLS], int rows, int cols){
    int y = 0, x = 0;
    for(y = 0; y < rows; y++){
        for(x = 0; x < cols; x++){
            putchar(array[y][x]);
        }
        putchar('\n');
    }
}
void initialize_char_pointer_array(char (*array)[COLS], int rows, int cols, ...){

    va_list ap;
    char initializeTo;
    int y = 0, x = 0;
    va_start(ap, cols);
    if(!(initializeTo = va_arg(ap, int))){
        initializeTo = ' ';
    }
    for(y = 0; y < rows; y++){
        for(x = 0; x < cols; x++){
            array[y][x] = initializeTo;
        }
    }

    va_end(ap);

}
void setup_front_buffer(char (*array)[COLS], int rows, int cols){    

    int y = 0, x = 0;

    for(y = 0; y < rows; y++){
        array[y][0] = array[y][cols-1] = ENV_BRICK_FULL;
        if(y == 0 || y == rows-1){
            for(x = 0; x < cols; x++){
                array[y][x] = ENV_BRICK_FULL;
            }
        }
    }

    int middle = cols / 2;
    int firstThird = middle / 2;
    int secondThird = firstThird + middle;

    array[3][middle] = ENEMY_2;          array[3][middle + 1] = ENEMY_2;          array[3][middle - 1] = ENEMY_2;
    array[4][middle] = ENEMY_1;          array[4][middle + 1] = ENEMY_1;          array[4][middle - 1] = ENEMY_1;
                                         array[4][middle + 2] = ENEMY_1;          array[4][middle - 2] = ENEMY_1;
    
    array[4][firstThird] = ENEMY_2;      array[4][firstThird + 1] = ENEMY_2;      array[4][firstThird - 1] = ENEMY_2;
    array[5][firstThird] = ENEMY_1;      array[5][firstThird + 1] = ENEMY_1;      array[5][firstThird - 1] = ENEMY_1;
                                         array[5][firstThird + 2] = ENEMY_1;      array[5][firstThird - 2] = ENEMY_1;

    array[4][secondThird] = ENEMY_2;     array[4][secondThird + 1] = ENEMY_2;     array[4][secondThird - 1] = ENEMY_2;
    array[5][secondThird] = ENEMY_1;     array[5][secondThird + 1] = ENEMY_1;     array[5][secondThird - 1] = ENEMY_1;
                                         array[5][secondThird + 2] = ENEMY_1;     array[5][secondThird - 2] = ENEMY_1;                                     

    array[rows-2][middle] = PLAYER_SHIP;
}

void update_game_state(char (*backBuffer)[COLS], char (*frontBuffer)[COLS], int rows, int cols){

    enum collisions {WALL = 1, TOP_BOTTOM = 2};
    static int Vx = 1;
    char currentSelection;
    int x = 0, y = 0;
    //initialize_char_pointer_array(backBuffer, ROWS, COLS, '#');
    /*
        read front -> update back.
    */
    for(y = 0; y < rows; y++){
        for(x = 0; x < cols; x++){
            currentSelection = frontBuffer[y][x];
            switch(currentSelection){
                case ENEMY_2:
                //printf("CS : %c ", currentSelection);
                    if(check_for_collision(y, x, rows, cols - 1) == WALL){
                        Vx = -1 * Vx;
                    }
                    backBuffer[y][x+Vx] = currentSelection;
                   
                    break;

                case ENEMY_1:
                    if(check_for_collision(y, x, rows, cols - 1) == WALL){
                        Vx *= -1;
                    }
                    backBuffer[y][x+Vx] = currentSelection;
                    break;

                default:
                    backBuffer[y][x] = currentSelection;
                    break;
            }
        }
    }
    

}
/*
    Note: this function fails if it's hitting a corner, use conditions to fix it
          if corners become a thing, for now, this will work.
*/
int check_for_collision(int y, int x, int rows, int cols){
    if(y == 1 || y == rows){
        return(2);
    }
    if(x == 1 || x == cols){
        return(1);
    }
    return(0);
}