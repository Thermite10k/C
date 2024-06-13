/*
Write a function expand(s1 ,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in
s2. Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-zO-9 and -a-z. Arrange that a leading or trailing - is
taken literally. D
*/

#include <stdio.h>
#define MAXLEN 1000

void expand(char s1[], char s2[]);
int main(void){

    char s1[] = {"a-b-c-d"};
    char s2[200];
    

    expand(s1,s2);
    printf("\n%s", s2);
    return 0;
}

void expand(char s1[], char s2[]){

    int c1, c2, i=0, j=0, lower, upper, k=0;

    while(s1[j] != '\0'){
        for(i; s1[i] == '-' ; i++)
            if(j==0){
                s2[k++] = '-';
            }
        for(j=i+1; s1[j] == '-'; j++)
            ;
        c1 = s1[i];
        c2 = s1[j];
        printf("%d\t%d\n", i,j);
        
        

        i=++j;


        if((c1 - '0' >= 0)&&(c2 - '9' <= 9)){
            while(c1 <= c2){
                s2[k++] = c1++;
            }
        }
        if((c1 - 'a' >= 0)&&(c2-'z' <= 'z')){
            while(c1 <= c2){
                s2[k++] = c1++;
            }
        }
        if((c1-'A' >= 0)&&(c2 - 'Z' < 'Z')){
            while(c1 <= c2){
                s2[k++] = c1++;
            }
        }
  
    }
    s2[k] = '\0';
     

    

    

}