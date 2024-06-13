#include <stdio.h>
#define MAXLINE 1000

void reverse(char line[], int len);
int getline(char line[], int maxline);
int main(){

    char line[MAXLINE];
    int len;
    while(((len = getline(line, MAXLINE)) > 0)){
        reverse(line, len);
   

        printf("%s", line);
    }

    return 0;
}

int getline(char line[], int maxline){


    int c, i = 0;
    
    for(i; i < maxline &&(c = getchar()) != EOF && c != '\n'; i++){
        line[i] = c;
    }

    if(c == '\n'){
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';


    return i;
}

void reverse(char line[], int len){
    // int j = len;

    // char reverse[len];
    // reverse[j] = '\0';
    // j--;
    // reverse[j] = '\n';
    // j--;

    // for(int i = 0; i<len-1;i++){
    //     reverse[j] = line[i];
    //     j--;
    // }
    // printf("Len is: %d\n", len);

    
    // for(int i = 0; i<len;i++){
    //     line[i] = reverse[i];
    // }

    char temp;
    int start = 0;
    int end = len-1;
    while(start < end){
        temp = line[start];
        line[start] = line[end];
        line[end] = temp;
        start++;
        end--;
    }

}