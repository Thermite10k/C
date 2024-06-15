#include <stdio.h>
#include <ctype.h>

#define NUMBER 0
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
        switch(mode){
            case NUMBER:
                push(s);
                break;
            case '\n':
                printf("%s", pop());
                printf("%s", pop());
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
int i=0;
char line[LINELIM];
int getop(char s[]){

    if(i == 0 || line[i] == '\0'){
        getline(line, LINELIM);
    }
    
    int j = 0;
    while(isspace(line[i])){
        i++;
    }
    if(!isdigit(line[i]) && line[i] != '-'){
        return line[i];
    }
    if(line[i] == '-'){
        if(!isdigit(line[i+1])){
            return line[i];
        }
        s[j] = line[i++];
        
        
    }
    while(isdigit(line[i])){
        s[j++] = line[i++];
    }
    if(line[i] == '.'){
        s[j++] = line[i++];
        while(isdigit(line[i])){ 
          s[j++] = line[i++];
        }
    
    }
    line[j] = '\0';
    return NUMBER;
}

int getline(char *line, int limit){

    char c;
    int i = 0;
    while((c = getchar()) != EOF && c != '\n'){
        *(line+i++) = c;
    }
    
    if(c == '\n'){
        *(line+i++) = c;
    }
    
    *(line + i) = '\0';

    return i;

}