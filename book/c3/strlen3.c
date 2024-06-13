#include <stdio.h>

size_t strlen3(char *s);

int main(void){
    char arr1[] = "The missile knows where it is.";
    printf("%d\t\n", strlen3(arr1));

    return 0;
}

size_t strlen3(char *s){
    char *e = s;

    while(*e != '\0'){
        e++;
    }

    return e - s;
}