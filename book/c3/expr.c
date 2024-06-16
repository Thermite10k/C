#include <stdio.h>
#include <ctype.h>

#define NUMBER 5
#define LINELIM 1000

int getline(char line[], int limit);
int getop(char s[], int *len);

#define STACKLIMIT 1000

char *stack[STACKLIMIT];
int sp = 0;

void push(char *n);
char *pop();

char *alloc(int size);
void afree(char *p);

void strconcat(char *s1, char *dest);

void strcp(char *s1, char *s2); // copy s2 to s1
int getlen(char *s);
int main(int argc, char *argv[]){
    char s[LINELIM];
    char *p;
    // char *s1 = "14";
    // char *s2 = "15";
    // p = alloc(8);
    // strconcat(s1, p);
    // strconcat(" + ", p+2);
    // strconcat(s2, p+5);
    // strconcat("", p+7);
    // printf("%s", p);
    // printf("length of 14 \\0 is: %d", getlen("14"));

    int mode, *len;
    while((mode = getop(s, len)) != EOF){

        switch(mode){

            case NUMBER:
                p = alloc((*len) + 1) ;
                strcp(p, s);
                push(p);
                break;
            case '+':
         
                char *second = pop();
                char *filler = " + ";
                int length = getlen(second);
                afree(second);
                char *first = pop();
                length += getlen(first);
                length += getlen(filler);
                afree(first);
       
                p = alloc(length+1); // one for \0
                strconcat(first, p);
                strconcat(filler, p);
                strconcat(second, p);
                strconcat("", p);
                push(p);


                break;
            case '\n':
                char *pop1;
                pop1 = pop();
                afree(pop1);
                printf("%s", pop1);
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
int getop(char s[], int *len){
    
    
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
        return c;
    }
    if(c == '-'){
        if(!isdigit(line[k])){

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
    *len = j;    
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

#define STORAEG 1000

char storage[STORAEG];
char *storagepointer = storage;


char *alloc(int size){
    if((storage + STORAEG - storagepointer ) >= size){
        storagepointer = storagepointer + size;
        return storagepointer-size;
    }else{
        printf("error: memory is full");
        return 0;
    }
}

void afree(char *p){
    storagepointer = p;
}

void strcp(char *s1, char *s2){

    while(*s1++ = *s2++)
        ;
}

int getlen(char *s){
    int len;
    while(*s++){
        len++;
    }
    return len;
}

void strconcat(char *s1, char *dest){

    while(*s1){
        *dest = *s1;
        s1++;
        dest++;
    
    }
    


}