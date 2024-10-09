#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

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
    X: enemy, lvl 0 - will die next time it's evaluated
    ASCII 30: Player bullet
    ASCII 202 ╩: player ship
    ASCII 194 ┬: player bullet
    |: enemy bullet
*/

enum env{
    ENEMY_1 = 'O', ENEMY_2 = 'M', ENEMY_0 = 'X', ENEMY_BULLET = '|', // enemy
    PLAYER_BULLET = 197, PLAYER_SHIP = 202, // player
    ENV_BRICK_HALF = 254, ENV_BRICK_FULL = 219, // envirenment
    PLAYER_MODE = 1, GAME_MODE = 2, // PLAYER_MODE: move the ship and bullet only. GAME_MODE: update everything
    MAX_BULLETS = 5, // maximum bullets on the screen
    ENV_DESCENT_RATE = 300, // the higher it is, the slower they fall
};
enum keys{
        RIGHT = 'M',
        LEFT = 'K',
        FIRE = ' ',
    };
struct gameState {
        int score;
        int userInput;
        int frame;
        int mode;
    };
void display(int (*array)[TOTAL_COLS], int rows, int cols);

// initializes the array to either ' ' or whatever char is given as the second arg
void initialize_char_pointer_array(int (*array)[TOTAL_COLS], int rows, int cols, ...);

// setsup the frontBuffer to start the game
void setup_front_buffer(int (*array)[TOTAL_COLS], int rows, int cols);

// reads the fron buffer and puts the new instance in backbuffer
void update_game_state(int (*arrayBack)[TOTAL_COLS], int (*arrayFront)[TOTAL_COLS], int rows, int cols, struct gameState* state);

// swaps the arrays, int cols MUST BE TOTAL_COLS to swap the velocity vector too.
void swaparrays(int (*arrayTo)[TOTAL_COLS], int (*arrayFrom)[TOTAL_COLS], int rows, int cols);

int main(){

    // we use a two buffer approach
    // total cols is cols+1 to save the direction of each col too, 1 is right, two is left
    int frontBuffer[ROWS][TOTAL_COLS];
    int backBuffer[ROWS][TOTAL_COLS];
    

    struct gameState myState = {
    .score = 0,
    .userInput = 0,
    .frame = 0,
    .mode = GAME_MODE
    };
    /*
    
        To hide the cursor: printf("\e[?25l");

        To re-enable the cursor: printf("\e[?25h");

    */
    printf("\e[?25l");
    PlaySound(TEXT("./tada.wav"), NULL, SND_ASYNC);
    

    initialize_char_pointer_array(frontBuffer, ROWS, COLS);
    initialize_char_pointer_array(backBuffer, ROWS, COLS);
    setup_front_buffer(frontBuffer, ROWS, COLS);
    long frames = 10000000;
    long framesindex = 0;
    

    while(1){
        myState.userInput = 0;
        myState.frame = framesindex;
        printf("Score: %d\n", myState.score);
        display(frontBuffer, ROWS, COLS);
        if(kbhit()){
           myState.userInput =  getch();
        }
        if((framesindex % 8) == 0){
            myState.mode = GAME_MODE;
        }else{
            myState.mode = PLAYER_MODE;
        }
        update_game_state(backBuffer, frontBuffer, ROWS, COLS, &myState);
        printf("\033[%dA\033[%dD", ROWS+1, TOTAL_COLS); // ROWS+1 to account for the "score:" line.
        
        // I use this function do have more flexibility than memcpy
        swaparrays(frontBuffer, backBuffer, ROWS, TOTAL_COLS);
        
        framesindex = (framesindex + 1) % frames;
    }

    return 0;
}
void display(int (*array)[TOTAL_COLS], int rows, int cols){
    int y = 0, x = 0;
    for(y = 0; y < rows; y++){
        for(x = 0; x <= cols; x++){
            putchar(array[y][x]);
        }
        putchar('\n');
    }
}
void initialize_char_pointer_array(int (*array)[TOTAL_COLS], int rows, int cols, ...){

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
void setup_front_buffer(int (*array)[TOTAL_COLS], int rows, int cols){    

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

void update_game_state(int (*backBuffer)[TOTAL_COLS], int (*frontBuffer)[TOTAL_COLS], int rows, int cols, struct gameState* state){

    enum collisions {WALL = 1, TOP_BOTTOM = 2};
    char Vx = '1';
    int dx = 1; // direction 1=r, -1=l
    int dy = 0;
    int currentSelection;
    int x = 0, y = 0;
    int bulletCount = 0;
    int kbEvent = state->userInput;
    dy = state->frame % ENV_DESCENT_RATE ? 0 : 1;

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
        if(state->mode == PLAYER_MODE){
            dx = 0;
        }
        backBuffer[y][cols] = Vx;
        for(x = 0; x < cols; x++){
            currentSelection = frontBuffer[y][x];
            switch(currentSelection){
                case ENEMY_2:
                    if(frontBuffer[y+1][x] == PLAYER_BULLET){
                        currentSelection = ENEMY_1;
                        state->score += y;
                        frontBuffer[y+1][x] = ' ';
                    }
                    backBuffer[y + dy][x + dx] = currentSelection;
                    break;
                case ENEMY_1:
                    if(frontBuffer[y+1][x] == PLAYER_BULLET){
                        state->score += y/2;
                        currentSelection = ENEMY_0;
                        frontBuffer[y+1][x] = ' ';
                    }
                    backBuffer[y + dy][x + dx] = currentSelection;
                
                    break;
                case ENEMY_0:
                    backBuffer[y][x] = ' ';
                    break;
                
                case PLAYER_SHIP:
                    if(kbEvent == RIGHT){
                  
                        if(x < COLS - 2){ // m cols, m-1 is the wall, m-2 is the last valid space
                            backBuffer[y][x+1] = currentSelection;
                        }else{
                        backBuffer[y][x] = currentSelection;
                    }

                    }else if(kbEvent == LEFT){
                        if(x > 1){
                            backBuffer[y][x-1] = currentSelection;
                        }else{
                        backBuffer[y][x] = currentSelection;
                    }

                    }else{
                        backBuffer[y][x] = currentSelection;
                    }
                    if(kbEvent == FIRE && bulletCount < MAX_BULLETS){
                        PlaySound(TEXT("./chord.wav"), NULL, SND_ASYNC);
                        backBuffer[y-1][x] = PLAYER_BULLET;
                    }
                    break;
                case PLAYER_BULLET:
                    bulletCount++;
                    if(y > 1){
                        backBuffer[y-1][x] = PLAYER_BULLET;
                        backBuffer[y][x] = ' ';
                    }
                    break;
                default:
                    if(backBuffer[y][x] == ' '){
                        backBuffer[y][x] = currentSelection;
                    }
            }   
        }
    }
 
}

void swaparrays(int (*arrayTo)[TOTAL_COLS],int (*arrayFrom)[TOTAL_COLS], int rows, int cols){
    int x = 0, y = 0;

    for(y = 0; y < rows; y++){
        for(x = 0; x < cols; x++){
            arrayTo[y][x] = arrayFrom[y][x];
        }
    }
}