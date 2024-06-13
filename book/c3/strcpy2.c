#include <stdio.h>

void strcpy2(char *s, char *t);
int strcmp2(char *s, char *t);
int main(void){
    char arr1[] = "This is an array to test something";
    char arr2[100];
    strcpy2(arr2, arr1);
    printf("%s\n", arr2);
    printf("%d\n", strcmp2(&arr2[4], arr1));

    return 0;
}

void strcpy2(char *s, char *t){
    while(*s++ = *t++) /* int he end , the assignment will return '\0 which terminates the loop. the *p++ does not increment the value that the pointer refers to but it increments the address 
    stored in the pointer.*/
        ;
}

int strcmp2(char *s, char *t){

    for(; *s == *t ; s++, t++){
        if(*s == '\0'){
            return 0;
        }
    }
    return *s - *t;

}