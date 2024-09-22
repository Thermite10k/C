#include <stdio.h>
#include <stdarg.h>

#define ROWS 15
#define COLS 40
/*
    NAMING CONVENTION
    ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
    DEFINE
    a_function()
    myVariable
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
void initializeCharPointerArray(char (*array)[COLS], int rows, int cols, ...);

// setsup the frontBuffer to start the game
void setupFrontBuffer(char (*array)[COLS], int rows, int cols);


int main(){

    // we use a two buffer approach
    char frontBuffer[ROWS][COLS];
    char backBuffer[ROWS][COLS];
    initializeCharPointerArray(frontBuffer, ROWS, COLS);
    initializeCharPointerArray(backBuffer, ROWS, COLS);
    setupFrontBuffer(frontBuffer, ROWS, COLS);
    display(frontBuffer, ROWS, COLS);

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
void initializeCharPointerArray(char (*array)[COLS], int rows, int cols, ...){

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
void setupFrontBuffer(char (*array)[COLS], int rows, int cols){    

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