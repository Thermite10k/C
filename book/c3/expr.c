#include <stdio.h>
#include <ctype.h>

#define NUMBER 5
#define LINELIM 1000

int getline(char line[], int limit);
int getop(char s[]);

#define STACKLIMIT 1000

char *stack[STACKLIMIT];
int sp = 0;

void push(char *n);
char *pop();



int main(int argc, char *argv[]){
    char s[LINELIM];
  
    int mode;
    while((mode = getop(s)) != EOF){

        printf("got: \"%s\"\n", s);
   
        switch(mode){

            case NUMBER:
                
                push(&s[0]);
                break;
            case '\n':
                printf("here.");
                printf("%s", pop());
                putchar('A');
                printf("%s", pop());
                break;
            default:
                printf("Yup, someething is wrong.\n");
                break;
        }
    }


    return 0;
}

void push(char *n){
    if(sp < STACKLIMIT){
        *(stack + sp++) = n;
    }else{
        printf("error: stack is full.\n");
    }
}

char *pop(){
    if(sp > 0){
        return(*(stack + --sp));
    }else{
        printf("error: stack is empty.\n");
        return 0;
    }
}
int k=0;
char line[LINELIM];
int getop(char s[]){
    
    int j = 0, c ;
    
    if(k == 0 || line[k] == '\0'){
        getline(line, LINELIM);
        k=0;
    }
    
    
    while((s[0] = c = line[k++]) == ' ' || c == '\t'){
        ;
    }
    s[1] = '\0';

    if(!isdigit(c) && (c != '-' && c!= '.')){
        printf("R1, K is %d",k);
        return c;
    }
    if(c == '-'){
        if(!isdigit(line[k])){
        printf("R2");

            return c;
        }
        s[++j] = c = line[k++];
        
        
    }

    if(isdigit(c)){

        while(isdigit(s[++j] = c = line[k++])){
            ;
        }
    }

    if(c == '.'){
        while(isdigit(s[++j] = c = line[k++])){ 
          ;
        }
     
    
    }
    if(c != EOF){
        k--;
    }
    
    s[j] = '\0';

    return NUMBER;
}

int getline(char *line, int limit){

    int c;
    int i = 0;
    while(--limit > 0 && (c = getchar()) != EOF && c != '\n'){
        *(line+(i++)) = c;
    }
    
    if(c == '\n'){
        *(line+(i++)) = c;
    }
    
    *(line + i) = '\0';

    return i;

}