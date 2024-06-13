#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(void){
    
    int my_int = 4294967295ul;
    int second = 0x1f;
    char bell = '\xdf'; 
    char my_str[] = "This is a test.";

    printf("%d\n", strlen(my_str));
    printf("%ul \n", second);
    printf("%c \a", bell);

    return 0;
}