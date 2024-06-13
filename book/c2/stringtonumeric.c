#include <stdio.h>

int stoi(char s[]);
int lower(int c);
int upper(int c);

int main(void){

    char stringofchars[] = "256";
    printf("%d\n", stoi(stringofchars));
    printf("%c", lower(upper('f')));
    return 0;
}

int stoi(char s[]){

    int n=0, i=0;

    for(i=0; s[i] >= '0' && s[i] <= '9'; i++){

        n = 10 * n + (s[i] - '0');
    }
    return n;

}

int lower(int c){

    if(c >= 'A' && c <= 'Z'){
        return c + 'a' - 'A'; // in ASCI, the 'a' - 'A' returns the distance of upper case letter from it's lower case counterpart. A...Z, a...Z
        // that is, upper + a constant = lower.
    }else {
        return c;
    }
}

int upper(int c){
    if(c >= 'a' && c <= 'z'){
        return 'A' + c - 'a'; //'A' + distance of c from 'a'
    }else{
        return c;
    }
}