#include <stdio.h>
// 122 = z, 65 = A 
int main(){
    int chars[58];
    for(int i = 0; i<58; i++){
        chars[i] = 0;
    }
    int c;
    while((c = getchar()) != EOF){
        if(c != ' ' && c != '\n' && c != '\t'){
            chars[c - 'A']++;
        }
    }
    for(int i = 0; i<58; i++){
        printf("%c : %d \n", 65 + i, chars[i]);
    }
    return 0;
}