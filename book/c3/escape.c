#include <stdio.h>

void escape(char s[], char t[]);
void deescape(char s[], char t[]);
int getline(char s[]);

int main(void){

    char s[100] ;
    char m[100] ;
    getline(s);
    char t[100];
    escape(s,t);
    printf("%s\n", t);
    deescape(t, m);
    printf("%s", m);

    return 0;
}

void escape(char s[], char t[]){
        
    int c, i=0, j=0;
    
    while((c = s[i++]) != '\0'){
        switch(c){
            case '\n': t[j++] ='\\'; t[j++] = 'n'; break;
            case '\t': t[j++] = '\\'; t[j++] = 't';break;
            default: t[j++] = c; 
        }
    }
    t[j] = '\0';
}
void deescape(char s[], char t[]){
    int c, i=0, j=0;

 

    while((c = s[i++]) != '\0'){
        if(c == '\\'){
            if(s[i] == 'n'){
                t[j++] = '\n';
                i++;
            }else if(s[i] == 't'){
                t[j++] = '\t';
                i++;
                
            }else{
                t[j++] = c;
            }
        }else{
            t[j++] = c;

        }
    } 
    t[j] = '\0';
}
int getline(char s[]){

    int c, i=0;
    while((c = getchar()) != 'X'){
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}