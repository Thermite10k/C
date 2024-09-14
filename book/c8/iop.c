#include "windows.h"
#include <stdio.h>
#define BUFSIZE 100
int main(){

    char buf[BUFSIZE];
    DWORD n;
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    if(hInput == INVALID_HANDLE_VALUE || hOutput == INVALID_HANDLE_VALUE){
        fprintf(stderr, "Error getting std handles\n");
        return 1;
    }

    while(ReadFile(hInput, buf, BUFSIZE, &n, NULL) &&  n > 0){
        DWORD written;
        if(!WriteFile(hOutput, buf, n, &written, NULL)){
            fprintf(stderr, "Error writing to output\n");
            return 1;

        }
        
    }

    return 0;
}