#include <stdio.h>

int main(){
    // blanks, tabs, newlines

    int blanks = 0, tabs = 0, newlines =0, c;
    

    while(((c = getchar()) != 'A')){
        if(c == ' '){
            ++blanks;
        }
        if(c == '\t'){
            ++tabs;
        }
        if(c == '\n'){
            ++newlines;
        }
    }
    printf("Blanks: %d \t Tabs: %d \t newLines: %d", blanks, tabs, newlines);
    return 0;
}