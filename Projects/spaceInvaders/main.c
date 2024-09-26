#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <windows.h>

#define ROWS 15
#define COLS 80
#define TOTAL_COLS (COLS + 1)
/*
    NAMING CONVENTION
    ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
    DEFINE_SOMETHING
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

void display(char (*array)[TOTAL_COLS], int rows, int cols);

// initializes the array to either ' ' or whatever char is given as the second arg
void initialize_char_pointer_array(char (*array)[TOTAL_COLS], int rows, int cols, ...);

// setsup the frontBuffer to start the game
void setup_front_buffer(char (*array)[TOTAL_COLS], int rows, int cols);

// reads the fron buffer and puts the new instance in backbuffer
void update_game_state(char (*arrayBack)[TOTAL_COLS], char (*arrayFront)[TOTAL_COLS], int rows, int cols);

// swaps the arrays, int cols MUST BE TOTAL_COLS to swap the velocity vector too.
void swaparrays(char (*arrayTo)[TOTAL_COLS], char (*arrayFrom)[TOTAL_COLS], int rows, int cols);

int main(){

    // we use a two buffer approach
    // total cols is cols+1 to save the direction of each col too, 1 is right, two is left
    char frontBuffer[ROWS][TOTAL_COLS];
    char backBuffer[ROWS][TOTAL_COLS];
    
    


    initialize_char_pointer_array(frontBuffer, ROWS, COLS);
    initialize_char_pointer_array(backBuffer, ROWS, COLS);
    setup_front_buffer(frontBuffer, ROWS, COLS);
    int frames = 10000000;
    int framesindex = 0;

    while(1){
        display(frontBuffer, ROWS, COLS);
        if(!(framesindex % 100000)){

        update_game_state(backBuffer, frontBuffer, ROWS, COLS);
        printf("\033[%dA\033[%dD", ROWS, TOTAL_COLS);
        }
        swaparrays(frontBuffer, backBuffer, ROWS, TOTAL_COLS);
        //Sleep(40);

        framesindex = (framesindex++ % frames);
    }

    return 0;
}
void display(char (*array)[TOTAL_COLS], int rows, int cols){
    int y = 0, x = 0;
    for(y = 0; y < rows; y++){
        for(x = 0; x <= cols; x++){
            putchar(array[y][x]);
        }
        putchar('\n');
    }
}
void initialize_char_pointer_array(char (*array)[TOTAL_COLS], int rows, int cols, ...){

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
        array[y][cols] = '1'; // sets the inital directoin to 1
    }

    va_end(ap);

}
void setup_front_buffer(char (*array)[TOTAL_COLS], int rows, int cols){    

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
    array[2][2] = ENEMY_2;

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

void update_game_state(char (*backBuffer)[TOTAL_COLS], char (*frontBuffer)[TOTAL_COLS], int rows, int cols){

    enum collisions {WALL = 1, TOP_BOTTOM = 2};
    char Vx = '1';
    int dx = 1; // direction 1=r, -1=l
    int currentSelection;
    int x = 0, y = 0;

    // this must be changed to not update the velocity vector.
    //initialize_char_pointer_array(backBuffer, rows, cols, ' ');
    for(y = 0; y < rows; y++){
        for(x = 0; x < cols; x++){
            backBuffer[y][x] = ' ';
        }
    }
    
    
    /*
        read front -> update back.
        --vx--char--dir--
            |1      |Right
            |2      |Left

    */
    for(y = 0; y < rows; y++){
        Vx = frontBuffer[y][cols]; // the velocity vector
        
        if(Vx == '1' && frontBuffer[y][cols - 2] != ' '){
            Vx = '2';
        }else if(Vx == '2' && frontBuffer[y][1] != ' '){
            Vx = '1';
        }
        dx = (Vx == '1' ? 1 : Vx == '2' ? -1 : 0);
        backBuffer[y][cols] = Vx;


        for(x = 0; x < cols; x++){
            currentSelection = frontBuffer[y][x];
            if(currentSelection == ENEMY_2 || currentSelection == ENEMY_1){
                    backBuffer[y][x + dx] = currentSelection;                
            }else{
                if(backBuffer[y][x] == ' '){
                    backBuffer[y][x] = currentSelection;
                }
            }
        }
    }
 
}

void swaparrays(char (*arrayTo)[TOTAL_COLS],char (*arrayFrom)[TOTAL_COLS], int rows, int cols){
    int x = 0, y = 0;

    for(y = 0; y < rows; y++){
        for(x = 0; x < cols; x++){
            arrayTo[y][x] = arrayFrom[y][x];
        }
    }
}