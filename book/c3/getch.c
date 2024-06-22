#include <stdio.h>
#include "getch.h"
#define MAXBUFF 100


static char buffer[MAXBUFF];
static int bufferpointer = 0;



int getch(void){
    if(bufferpointer > 0){
        return buffer[--bufferpointer];
    }else{
        return getchar();
    }
}

void ungetch(int c){
    if (bufferpointer < MAXBUFF){

        buffer[bufferpointer++] = c;
    } else{
        printf("getch.h\nerror: buffer is full.\n");
    }
}

