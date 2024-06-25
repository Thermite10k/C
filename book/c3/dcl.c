#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.h"
// complile with getch.c


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


int main(int argc, char *argv[]){

    int c, type, mode = 0; // mode 0 = DCL = -d , 1 = undcl = -u. default is DCL
    char temp[MAXTOKEN];
    if(argc > 1){
        while(--argc && (*++argv)[0] == '-'){
            while((c = *++argv[0])){
                switch(c){
                    case 'u':
                        mode = 1;
                        break;
                    case 'd':
                        mode = 0;
                        break;

                }
            }
        }
    }
    printf("Mode if %d\n", mode);
    switch(mode){
        case 0:
            while(gettoken() != EOF){
            strcpy(datatype, token);
            out[0] = '\0';
            dcl();
            if(tokentype != '\n'){
                printf("Syntax error\n");
            }
            printf("%s: %s %s\n", name, out, datatype);
            break;
        }
        case 1:
            while(gettoken() != EOF){
                strcpy(out, token);
                while((type = gettoken()) != '\n'){
                    if(type == PARENS || type == BRACKETS){
                        strcpy(out, token);
                    } else if (type == '*'){
                        sprintf(temp, "(*%s), out");
                        strcpy(out, temp);
                    }else if (type == NAME){
                        sprintf(temp, "%s %s", token, out);
                        strcpy(out, temp);
                    }else{
                        printf("Invalid input at %s\n", token);
                    }
                    
                    
                }
                    printf("%s\n", out);
            }

 
    }
        

    
    return 0;

}
/*
    Token is a name, pair of parentheses, a pair of brackets perhaps includeing a number, or any other single character
*/

/*
    Token is a name, pair of parentheses, a pair of brackets perhaps includeing a number, or any other single character
*/

/*
    DCL:
        optional *'s + direct-dcl

    direct-dcl:
        NAME
        (DCL)
        direct-dcl()
        direct-dcl[optional-number]

    something like (*PFA[])() would be parsed as: (remember [] binds tighter than *)
    PFA -> NAME ->direct-dcl -> [] -> direct-dcl -> * -> DCL -> (DCL) ->direct-dcl -> direct-dcl() -> dcl.

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
