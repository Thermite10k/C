#include <stdio.h>

int strlen(char *c);

int main(void){

    char arr[] = "1234 678";
    char str[] = {'T', 'h', 'i', 's', '\0'};

    printf("%d\n",strlen(arr)); // *p = nameofarray
    printf("%d\n",strlen(&arr[0])); // *p = &a[0] address of the 0th element of a
    printf("%d\n",strlen(str));// str is an array, str holds the address of 0th element.
    printf("%d\n",strlen(&str[0]));// str is an array, str holds the address of 0th element.
    printf("%d\n",strlen(&str[2]));// str is an array, str holds the address of 0th element., &str[2] is like sending str + 2
    printf("%d\n",strlen(str + 2));// str is an array, str holds the address of 0th element., &str[2] is like sending str + 2
    

    return 0;
}

int strlen(char *c){
    int n;
    for(n = 0; *c != '\0'; n++, c++){
        ;
    }

    return n;
}