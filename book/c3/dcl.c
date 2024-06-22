#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.h"

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void directdcl(void);

int gettoken(void);
int tokentype;
char token[MAXTOKEN]; // type of last token
char name[MAXTOKEN]; // last token string
char datatype[MAXTOKEN]; // char, int, etc.
char out[MAXTOKEN];

int main(){

    while(gettoken() != EOF){
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if(tokentype != '\n'){
            printf("Syntax error\n");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;

}
/*
    Token is a name, pair of parentheses, a pair of brackets perhaps includeing a number, or any other single character
*/

void dcl(void){

    int ns;

    for(ns=0; gettoken() == '*';){ // counting *'s
        ns++;
    }
    directdcl();
    while(ns-- > 0){
        strcat(out, " pointer to");
    }

}

void directdcl(void){
    int type;

    if(tokentype == '('){ // it's a declatarot, dcl
        dcl();
        if(tokentype != ')'){
            printf("error: missing )\n");
        }

    }else if(tokentype == NAME){
        strcpy(out, token);
    }else{
        printf("error: expected (dcl) or name.\n");
    }
    while((type = gettoken()) == PARENS || type == BRACKETS){
        if (type == PARENS){
            strcat(out, " function returning");
        }else{
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

int gettoken(void){
    int c;
 

    char *p = token;

    while((c = getch()) == ' '|| c == '\t'){
        ;
    }
    if(c == '('){
        if((c = getch()) == ')'){
            strcpy(token, "()");
            return tokentype = PARENS;
        }else{
            ungetch(c);
            return tokentype = '(';
        }
    }else if (c == '['){
        for(*p++ = c; (*p++ = getch()) != ']' ;){
            ;
        }
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)){
        for(*p++ = c;isalnum(c = getch());){
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }else{
        return tokentype = c;
    }

}
