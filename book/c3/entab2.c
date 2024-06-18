#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000
#define ENTABMODE 0
#define DETABMODE 1


int getline(char *line, int limit);
void detab(char *line, char *out);
void entab(char *line, char *out);



int  mval = 0, nval = 4;
// starting at -m, every +n.

int main(int argc, char *argv[]){
    int c, mode=0;
    while(--argc > 0){
        ++argv;
        if(*argv[0] == '-'){
            while(*++argv[0]){
                if(isdigit(*(argv[0]))){
                    mval = 0;
                    mval = 10 * mval + *(argv[0]) - '0';
                }
                else if(isalpha(*(argv[0]))){
                    mode = *(argv[0]) == 'd' ? 1 : 0;
                }
            }
        }
        if(*argv[0] == '+'){
            while(*++(*(argv + 0))){
                nval = 0;
                nval = 10 * nval + *(argv[0]) - '0';
            }
        }
        
    }

    // tab stops every n columns, starting at m.
    
    printf("use -d for detab mode, leave empty for entab mode.\n");
    printf("each tab is: %d\n", nval);
    printf("Begining from column: %d\n", mval);
    
    char line[MAXLINE];
    char out[MAXLINE];
     while(getline(line, MAXLINE) != 0){
        switch(mode){
            case ENTABMODE:
                entab(line, out);
                break;
            case DETABMODE:
                detab(line, out);
                break; 
        }
                printf("%s", out);  
     }
}
void detab(char *line, char *out){

    int c, i=0, j=0, nspace=0;

    while(c = line[i++]){
        if(c == '\t' && i-1 >= mval){
            nspace += nval;
            continue;
        }
        if(nspace){
            while(nspace-- > 0){
                out[j++] = ' ';
            }
        }
        out[j++] = c;
    }

    out[j] = '\0';
}
void entab(char *line, char *out){

    int c, i=0, j=0, k=0, nspace = 0;
    
    while (c = line[i++]){
        if (c == ' ' && i-1 >= mval){
            nspace++;
            continue;
        }
        while(nspace >= nval){
            nspace -= nval;
            out[j++] = '\t' ;
        }
        if(nspace){

        while(nspace-- > 0){
            out[j++] = ' ';
        }
        }
        out[j++] = c;

    }
    out[j] = '\0';

}

int getline(char *line, int limit){
    int c, i = 0;
    
    while(--limit > 0 && (c = getchar()) != EOF && c != '\n'){
        *(line+ i++) = c;

    }
    if(c == '\n'){
        *(line+ i++) = c;
    }

    *(line + i) = '\0';

    return i; 
}