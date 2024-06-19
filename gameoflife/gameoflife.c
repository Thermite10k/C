#include <stdio.h>
#define ROW 32
#define COL 32
// arr[row][col]

void cleararray(char arr[][]);

int main(int argc, char *argv[]){
    char front[ROW][COL];
    char back[ROW][COL];
    
    printf("%c", 28);

    return 0;  
}

void cleararray(char arr[][]){

    int y=0, x=0;

    for(y; y< COL; y++){
        for(x; j<ROW; x++){
            arr[y][x] = 28;
        }
    }

}