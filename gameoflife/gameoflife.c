#include <stdio.h>
#include <stdlib.h>
#define ROW 40
#define COL 100
#define DEAD 128 //47
#define ALIVE 255 // 220
#define MOD(a,  b) (((a%b))+b) % b
// arr[row][col]

char graphics[2] = {46,219};

void cleararray(char arr[ROW][COL]);
void initialize(char arr[ROW][COL]);
void display(char arr[ROW][COL]);
int getneighbor(char arr[ROW][COL], int x, int y);
void eval(char front[ROW][COL], char back[ROW][COL]); // we read back and update front
void swaparrays(char (*arr1)[], char (*arr2)[] );

int main(int argc, char *argv[]){
    char front[ROW][COL];
    char back[ROW][COL];
    cleararray(front);
    cleararray(back);
    initialize(front);




    while(1){
        system("cls") ;   
        display(front);
        eval(back, front);
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
            printf("%c","-#"[(arr[y][x])]);
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
            neighbors = getneighbor(back,x,y);
            front[y][x] = 0;
            if(back[y][x]){
                if(neighbors == 2 || neighbors == 3 ){
                    front[y][x] = 1;
                }
            }else if (neighbors == 3){
                front[y][x] = 1;
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