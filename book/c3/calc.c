#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define SIN 20
#define COS 30
#define EXP 40
#define ANS 50

int getop(char []);
extern void push(double);
double pop(void);
double peek(void);
void duplicate(void);
void swap(void);
int optype(char []);
int getline(char s[], int lim);

int main(void){
    int type;
    double op2;
    char s[MAXOP];
    double ans = 0.0;

    while((type = getop(s)) != EOF){
        //printf("got %s\n", s);
        switch(type){
            case NUMBER:
       
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - (op2));
                break;
            case '/':
                op2 = pop();
                if(op2 != 0){
                    push(pop() / op2);

                }else{
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                push(((int)(pop())) % ((int)op2));
                break;
            case SIN:
                push(sin(pop()));
                break;
            case COS:
                push(cos(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case ANS:
                printf("\t%.8g\n", ans);
                break;
            case '\n':
                ans = pop();
                printf("\t%.8g\n", ans);
                break;
            case 'p':
                printf("%f\n", peek());
                break;
            case 'd':
                duplicate();
                break;
            case 's':
                swap();
                break;
            default:
                printf("error: unknown command => %s\n", s);
                break;
        }
    }
}


#define MAXVAL 100
int sp = 0;

double val[MAXVAL];

void push(double f){
    if(sp < MAXVAL){
        val[sp++] = f;
    }else{
        printf("error: stack is full\n");
    }
}

double pop(void){
    if(sp > 0){
        return val[--sp];
    }else{
        printf("error: stack is empty\n");
        return 0.0;
    }
}

// thus, we an kjdhfoehfoh;fjpejdd`
double peek(void){
    if(sp > 0 ){
        return val[(sp - 1)];
    }else{
        printf("error: stak is empty\n");
        return 0.0;
}
}
void swap(void){
    double f,s;
    if(sp >= 2){
        s = pop();
        f = pop();
        push(s);
        push(f);
    }
}

void duplicate(void){
    if(sp > 0){
        push(peek());
    }
}



#include <ctype.h>
char input[MAXOP];
int j = 0;
int getch(void);
int ungetch(int);
void ungets(char s[]);
int getop(char s[]){
    
    int i=0, c,m, type;
    if(j == 0 || input[j] == '\0'){ /* if the input is empty, get a new input array */
    getline(input, MAXOP);
    j = 0;
    }
    while((s[0] = c = input[j++]) == ' ' || c == '\t'){ // skipping whitespaces
							
        ;
    }

    s[1] = '\0';
    i=0;
    m = c; // m is used to decide if - is operator or sign.
    if(isalpha(c)){ // used to get stuff like sin, cos, ans etc
       
        while(isalpha(s[++i] = c = input[j++])){
            ;
        }
      
        
        s[i] = '\0';
        type = optype(s);
        if(c != EOF && type != ANS){ // if type is ANS, we want to get rid of the \n so it does not clear the ANS after showing it as \n triggers an ANS update and a pop().
            j--; // same as ungetch;
        }
            
        return type;
        

    }
    if(c == '-' && (isdigit(c = s[++i] = input[j++]))){ // this is just a stupid if that get's the next char if c == '-' to see if - is a sign or an operator.

    }
    if(m == '-' && (c =='\n' || c == ' ')){ // '-' is an operator if it's followed by \n or ' '. here, 'm' is the n-1 getch.
        s[i] = '\0';
        j--;
        return m;
 
    }
    if((!isdigit(c) && c != '.' )){
      
        return c;
       
       
    }
    

    if(isdigit(c)){
        while(isdigit(s[++i] = c = input[j++])){
            ;
        }
    }
    if(c == '.'){
        while(isdigit(s[++i] = c = input[j++])){
            ;
        }
    }
    s[i] = '\0';
  
    if(c != EOF){
        
        j--;
    }

    return NUMBER;
}

/*
this version does not need an externar variable input[] and index j but it's more difficult to parse complex structures this way.
since getch() is analogous to input[j++] and ungetch() to j--, it's very easy to switch between the two.
int getop(char s[]){
    
    int i=0, c,m, type;

    while((s[0] = c = getch()) == ' ' || c == '\t'){ // skipping whitespaces
        ;
    }

    s[1] = '\0';
    i=0;
    m = c; // m is used to decide it - is operator or sign.
    if(isalpha(c)){ // used to get stuff like sin, cos, ans etc
       
        while(isalpha(s[++i] = c = getch())){
            ;
        }
      
        
        s[i] = '\0';
        type = optype(s);
        if(c != EOF && type != ANS){ // if type is ANS, we want to get rid of the \n so it does not clear the ANS after showing it.
            ungetch(c);
        }
            
        return type;
        

    }
    if(c == '-' && (isdigit(c = s[++i] = getch()))){ // this is just a stupid if that get's the next char if c == '-' to see if - is a sign or an operator.

    }
    if(m == '-' && (c =='\n' || c == ' ')){ // '-' is an operator if it's followed by \n or ' '. here, 'm' is the n-1 getch.
        s[i] = '\0';
        ungetch(c);
        return m;
 
    }
    if((!isdigit(c) && c != '.' )){
      
        return c;
       
       
    }
    

    if(isdigit(c)){
        while(isdigit(s[++i] = c = getch())){
            ;
        }
    }
    if(c == '.'){
        while(isdigit(s[++i] = c = getch())){
            ;
        }
    }
    s[i] = '\0';
  
    if(c != EOF){
        
        ungetch(c);
    }

    return NUMBER;
}
*/

int optype(char s[]){
     
    /*
    to add a new operator: 1- define it, 2- increment numop, 3- define it as a string,
    4- add it to operations[], 5- add it to definitions, 6, add it to the loop while taking notice of it's lenght

    this looks like the least efficient way to do it but it is what it is.
    */
    /*
        the decision making is still ambiguous if len of input is more than som of the elements 
        such as input = "sin", case1: "sin", case2: "sindeg". in this case, since the first 3 elements of the case1 and case 2 are identical, the state is never updated
        and both are true. if the are ordered in ascending lenghts, then it would be ok, and we will do this but what if the input is:
        input = "sindeg", again, both will be true and sin will be returned which is not correct. one way to solve it is by checking the lengths too, that is, add an else if in the while loop and
        if (i > len) where len: len of each operator (hardcoded), then it's false. this would work and all but i'm looking for a better and more concise solution. we are not interested in subsets.
    */
    int numop = 4;
    char sin[] = "sin";
    char cos[] = "cos";
    char pow[] = "exp";
    char ans[] = "ans";
    int operations[] = {1, 1, 1, 1}; // eventually, 
    int definitions[] = {SIN , COS, EXP, ANS};
    int i = 0;
    while(s[i] != '\0'){
        if(operations[0] && i<3 &&(s[i] != sin[i])){
            operations[0] = 0;
        }
        if(operations[1] && i<3 &&(s[i] != cos[i])){
            operations[1] = 0;
        }
        if(operations[2] && i<3 &&(s[i] != pow[i])){
            operations[2]  = 0;
        }
        if(operations[3] && i<3 &&(s[i] != ans[i])){
            operations[3]  = 0;
        }
        i++;
    }
    for(i=0; i < numop; i++){
        if(operations[i]){
            return definitions[i];
        }
    }

    
}

int getline(char s[], int lim){
    int i = 0, c;
    
    while(lim-- > 0 && (c = getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }
    if(c == '\n'){
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0; // next free buffer position;

int getch(void){

    if(bufp > 0){
        return buf[--bufp];
    }else{
        return getchar();
    }
    
    
}

int ungetch(int ch){
    if (bufp >= BUFFSIZE){
        printf("ungetch: too many characters\n");
        return(0);
    }else{


    buf[bufp++] = ch;
    }
    return(1);
}

void ungets(char s[]){

    /*
        since it's using ungetch(), it does not have to know about the buffer size as the getch, ungetch() are well-defined and take care of it.
    */
    int i = 0, state = 1;
    
    while(state && s[i] != '\0'){
        state = ungetch(s[i++]);
    }
    if(state && s[i] == '\0'){
        ungetch(s[i]);
    }
}
