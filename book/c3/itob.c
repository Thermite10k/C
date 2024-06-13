#include <stdio.h>

void itob(int n, char s[], int b);

int main(void){
    char s[32];
    int n = 1849;
    itob(n, s, 16);
    printf("%s\n", s);
    itob(n, s, 8);
    printf("%s\n", s);
    itob(n, s, 2);
    printf("%s\n", s);
    return 0;
}

void itob(int n, char s[], int b){

    char hexa[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char octa[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
    int i = 0;
 

    while(n>0){
        switch(b){
            case 16:
            s[i++] = hexa[n%16];
            n /= 16;
            break;
            case 8:
            s[i++] = octa[n%8];
            n /= 8;
            break;
            case 2:
            s[i++] = n%2 + '0'; // n%2 is 0 or 1 and is an int, we want the ascii code as s will be treated as a string not an int.
            n /= 2;
            break;
        }
    }
    s[i--] = '\0';

    
        

    for(int k=0; k<i; ){
        int temp = s[i];
        s[i] = s[k];
        s[k] = temp;
        k++;
        i--;
    }
    
    

}