#include <stdio.h>

void list_4bit_colors(void);
void list_8bit_colors(void);
void list_all_SGR(void);

int main(int argc , char* argv[]){

    list_4bit_colors();
    list_all_SGR();
    list_8bit_colors();
    return 0;
}
void list_4bit_colors(void){
     int fg = 30, bg = 40;

    for(fg = 30; fg < 38; fg++){
        for(bg = 40; bg < 48; bg++){
            printf("\033[%d;%dmbg: %d, fg: %d\033[m\t", bg,fg,bg,fg);
        }
        putchar('\n');
    }
    putchar('\n');
}
void list_8bit_colors(void){
    int i = 0, j = 0, k = 0;

    for(i = 0, j = 0; i < 256; i++){
        
        printf("\033[38;5;%dm%3d: TEST\033[0m", i, i);
        printf("\033[48;5;%dm     \t\033[0m", i);
        
        j++;
        if(j % 5 == 0){
            putchar('\n');
        }
    }
   
    putchar('\n');
}
void list_all_SGR(void){
    
    int i = 0, j = 0;

    for(i = 0; i < 108; i++){
        printf("\033[%dm%3d: TEST\t\033[0m", i, i);
        j++;
        if(i == 75){
            i = 89; // will be incremented to 90 at the end of the loop. 
        }        
        if(j % 5 == 0){
            putchar('\n');
        }
    }

    putchar('\n');
}