#include <stdio.h>
#define MAXLEN 1000


int getline(char *line, int limit);
char *haspattern(char *src, char *pat);

int main (int argc, char *argv[]){

    char line[MAXLEN];
    long lineno=0;
    int len, except = 0, number = 0, found = 0, c;
    while(--argc  > 0 && (*++argv)[0] == '-'){ // (*++argv)[0] will get the first character of the next pointer.
        while(c = *++argv[0]){ // *++argv[0] will increment the internal pointer of the pointer that the argv points to.
            
            switch (c){
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("illegal option: -%c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }

    if(argc != 1){
        printf("usage: Find -x -n pattern.\n");
    }


    while((len = getline(line, MAXLEN)) > 0){
        lineno++;
        if((haspattern(line, *(argv)) != NULL ) != except){ // if true != true so if we get false != true which is true, print it
            if(number){
                printf("%ld:", lineno);
            }
            printf("%s", line);
            found++;
        }
    }
    
    return 0;
}

char *haspattern(char *src, char *pat){

    char *s, *p;
    

    while(*src++ != '\0'){
        s = src - 1;
        p = pat;
        if(*s == *p){
            while(*s++ == *p++){
                ;
            }
            if(*(p-1) == '\0'){
            
            return s;
        }
        }
        
    }
    return NULL;
}

int getline(char *line, int limit){

    int i = 0, c;

    while(--limit && (c = getchar()) != EOF && c != '\n'){
        *(line + i++) = c;
    }
    if(c == '\n'){
        *(line + i++) = c;
    }
    *(line + i) = '\0';

    return i;

}