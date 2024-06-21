#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SPRINT(str) printf(#str" is %s\n", str)
#define DPRINT(d) printf(#d" is %d\n", d)
#define MAXLINES 5000
#define MAXLINELEN 200
char *linepter[MAXLINES];
int numeric = 0, reverse = 0, fold = 0, fieldmode = 0, directory = 0 ;

int readlines(char *lineptr[], int nlines);
void writelines(char *linepter[], int nline, int reverse);

int validdirectorymode(char *s);
char mytolower(char c);
void qsort(char *lineptr[], int left, int right, int (*comp)(char *, char *));
void swap(char *v[], int i, int j);
int numcp(char *, char *);
int strcmp2(char *s1, char *s2);
double atof(char *);
int getline(char *line, int limit);
char *alloc(int size);
void afree(char *p);
void strcp(char *s1, char *s2);
int main(int argc, char *argv[]){
    int nlines = 0;
    int c;
    if(argc > 1){
        while(--argc && (*++argv)[0]== '-'){
            while( c = *++argv[0] ){
                switch(c){
                    case 'n':
                        numeric = 1;
                        break;
                    case 'r':
                        reverse = 1;
                        break;
                    case 'f':
                        fold = 1;
                        break;
                    case 'd':
                        if(*(1+argv[0]) == 'f'){
                            fieldmode = 1;
                            break;
                        }
                        directory = 1;
                        break;
                    

                }
            }
        }
    }
    if(((nlines = readlines(linepter, nlines)) >=0)){

        
        qsort(linepter, 0, nlines-1, (int(*)(char *, char *))(numeric ? numcp : strcmp2));
        
        writelines(linepter, nlines, reverse);
        
        return 0;
    }else{
        printf("input too big to sort\n");
        return 1;
    }
}

void qsort(char *v[], int left, int right, int (*comp)(char *, char *)){
    int i, last;
    
    if(left >= right){
        return;
    }
    swap(v, left, (right + left) / 2);
    last = left;
    for(i = left+1; i<= right; i++){
        if((*comp)(v[i], v[left]) < 0){
            swap(v, ++last, i);
        }
    }
    swap(v, last, left);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);


}
void swap(char *v[], int i, int j){
    char *temp = v[i];
    v[i]  = v[j];
    v[j] = temp;
}
int numcp(char *s1, char *s2){
   double v1, v2;

   v1 = atof(s1);
   v2 = atof(s2);

   if(v1 < v2){
    return -1;
   }else if (v1 > v2){
    return 1;
   }
   return 0;
}
char mytolower(char c){
    return((c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c);
}
int validdirectorymode(char *s){
    return(((isdigit(*s)) || (*(s+1) == '\0')) ? 1 : 0);
}
int strcmp2(char *s1, char *s2){

    if(directory && (!validdirectorymode(s1) || !validdirectorymode(s2))){
        return 0;
    }
    

    while (*s1 == *s2 || (fold &&( mytolower(*s1) == mytolower (*s2)))){
        s1++;
        s2++;
        
    }
    if(*s1 == '\0')
        return 0;

    return(*s1 < *s2 ||( fold && (mytolower(*s1) < mytolower(*s2)))) ? -1 : 1;
}
double atof(char *s){
    double val = 0, power = 1;
    int hasdecimal = 0, sign = 1;
    if(*s == '-'){
        sign = -1;
        s++;
    }
    while(*s){
 
        if(*s == '.'){
            hasdecimal = 1;
            s++;
            power = 10 * power;
            continue;
        }
        val = 10 * val + *s - '0';
        if(hasdecimal){
            power *= 10;
        }
        s++;
    }

    return val/power*sign;

}
int getline(char *line, int limit){
    int c, i =0;
    while(--limit > 0 && (c = getchar()) != EOF && c!='\n'){
        
        *(line+i++) = c;
    }
    if(c=='\n')
        *(line+i++) = c;

    *(line+i) = '\0';

    return i;
}

static int memsize = 1000000;
char memory[1000000];
char *sp = memory;

char *alloc(int size){
    if(size < 0){
        return NULL;
    }
    if((memory + memsize - sp) >= size){
        sp += size;
        return sp-size;
    }
    printf("error: memory is full\n");
    return NULL;
}
void afree(char *p){
    sp = p;
}
void strcp(char *s1, char *s2){
    while(*s1++ = *s2++){
        ;
    }
}
int readlines(char *lineptr[], int nlines){
    char line[MAXLINELEN], *p;
    int len, nline = 0;
    while((len = getline(line, MAXLINELEN)) > 0){
        if(len > MAXLINELEN){
            printf("Line length is more than %d\n", MAXLINELEN);
        }else{

        p = alloc(len);
        if(p != NULL){
            line[len-1] = '\0';
            strcp(p, line);

            linepter[nline++] = p;
        }else{
            printf("error: could not allocate memory\n");
        }
        }
    }
    
    return nline;
}
void writelines(char *linepter[], int nline, int reverse){
    int i = 0;
    if (reverse){
        i = nline -1;    
    }
    for(i; (reverse ? i>=0 : i < nline);(reverse ? i-- : i++)){
        printf("%s\n", linepter[i]);
    }
}