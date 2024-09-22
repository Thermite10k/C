#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int ROW = 120;
int COL = 450;
#define DEAD 128 //47
#define ALIVE 255 // 220
#define MOD(a,  b) (((a%b))+b) % b
// arr[row][col]

/*
    Command line arguments : -ry, -cx where y is the number of rows and x is the number of columns
*/

char graphics[2] = {176,219};

void cleararray(char (*arr)[]);
void initialize(char (*arr)[]);
void display(char (*arr)[]);
int getneighbor(char (*arr)[], int x, int y);
void eval(char (*front)[], char (*back)[]); 
void swaparrays(char (*arr1)[], char (*arr2)[] );

int main(int argc, char *argv[]){

    int *row,*col;
    row = &ROW;
    col = &COL;
    *row = 0;
    *col = 0;
    int c;
    if(argc > 1){
        while(--argc && (*++argv)[0] == '-'){
            while(c = *++argv[0]){
                switch(c){
                    case 'r':
                        
                        while(isdigit(*++argv[0])){
           
                            *row = *row * 10 + *argv[0] - '0';
                        }
                        break;
                    case 'c':
                        while(isdigit(*++argv[0])){
                            *col = *col * 10 + *argv[0] - '0';
                        }
                        break;
                }
            }
            
        }
    }

    *row = *row ? *row : 40;
    *col = *col ? *col : 60;

    char front[ROW][COL];
    char back[ROW][COL];
    cleararray(front);
    cleararray(back);
    initialize(front);
//



    while(1){
        //system("cls") ;   
        display(front);
        eval(front, back);
        printf("\033[%dA\033[%dD",ROW, COL);
        /*
            \033 : ASCII code 27, start signals the start of a scape sequence
            [ : begining of control sequence
            A : move cursor up by ROW
            D : move cursor left by COL
        */
        //memmove(front, back, sizeof(front));
        //memcpy(front, back, sizeof(front));
        swaparrays(front, back);
        // for(double j=0; j < 10; j = j+0.16){

        // }
    }
 
    return 0;  
}

void cleararray(char arr[ROW][COL]){

    int y=0, x=0;

    for(y=0; y< ROW; y++){
        for(x=0; x<COL; x++){
            arr[y][x] = 0;
        }
    }

};
void initialize(char arr[ROW][COL]){
    arr[10][6] = 1;
    arr[11][6] = 1;
    arr[11][5] = 1;
    arr[12][6] = 1;
    arr[12][7] = 1;
    //arr[13][4] = 1;
    //arr[13][5] = 1;
}
void display(char arr[ROW][COL]){
    int x = 0, y = 0;

    for(y=0; y<ROW; y++){
  
        for(x=0; x< COL; x++){
            printf("%c",graphics[(arr[y][x])]);
        }
        printf("\n");
    }

}
int getneighbor(char arr[ROW][COL], int x, int y){
    int neighbors = 0;
    int dx,dy;
    for(dy = -1; dy<= 1; dy++){
        for(dx = -1; dx<= 1; dx++){
            if((arr[MOD( (y + dy) ,ROW)][MOD((x + dx) , COL)])){
                neighbors++;
            }
        }
    }
    if(arr[y][x]){
        neighbors--;
    }
    return neighbors;
}
void eval(char front[ROW][COL], char back[ROW][COL]){
    int neighbors = 0; 
    int x,y;
    for(y=0; y<ROW; y++){
        for(x=0; x<COL; x++){
            neighbors = getneighbor(front,x,y);
            back[y][x] = 0;
            if(front[y][x]){
                if(neighbors == 2 || neighbors == 3 ){
                    back[y][x] = 1;
                }
            }else if (neighbors == 3){
                back[y][x] = 1;
            }
                
            
        }
     
    }
}
void swaparrays(char front[ROW][COL], char back[ROW][COL]){
    int x, y;
    for(y=0;y< ROW; y++){
        for(x=0;x<COL;x++){
            front[y][x] = back[y][x];
        }
    }

}
