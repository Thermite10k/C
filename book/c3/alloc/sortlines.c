#include "alloc.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>

#define MAXLINES  5000
#define STORAGELEN 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
int readlineslocal(char *lineptr[], int nlines, char lines[], int storagelim);
void writelines(char *lineptr[],  int nlines);

void qsort(char *lineptr[], int left, int right);

int main(void){

    int nlines;
    char lines[STORAGELEN];

    if((nlines = readlineslocal(lineptr, MAXLINES, lines, STORAGELEN)) >=0){
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }else{
        printf("Error: too many lines!\n");
        return 1;
    }

}

#define MAXLEN 1000
int getline(char *c, int limit);
char *alloc(int size);

int getline(char *arr, int limit){

    int len = 0, c, i = 0;
    while(limit-- && (c = getchar()) != EOF && c != '\n'){
        arr[i++] = c;
        
    }
    if(c == '\n'){
        arr[i++] = c;
        
    }
    *(arr+i) = '\0';
    return i;

}
int readlineslocal(char *lineptr[], int maxlines, char lines[], int storagelim){
    int len, nlines;
    char *p, line[MAXLEN];
    
    nlines = 0;
    p = lines;
    while((len = getline(line, MAXLEN)) > 0){
        if(nlines > maxlines || p + len> (lines + storagelim) ){
            return -1;
        }else{
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}
int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;

    while((len = getline(line, MAXLEN)) > 0){
        if(nlines > maxlines || ((p = alloc(len)) == 0)){
            return -1;
        }else{
            line[len - 1] = '\0'; // getting rid of \n
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines){
    // int i = 0;
    // for(i; i < nline; i++){
    //     printf("%s\n", lineptr[i]);
    // }
    while(nlines-- > 0){
        printf("%s\n", *lineptr++);
    }
}
void swap(char *arr[], int i , int j);
void swap(char *arr[], int i, int j){
    char *temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}
void qsort(char *v[], int left, int right){
    if(left >= right){
        return;
    }
    int last, i;
    swap(v, left, (left+right / 2));
    last = left;
    for(i = left+1; i <= right; i++){
        if(strcmp(v[i], v[left]) < 0){
            swap(v, ++last, i);
        }
    }
    swap(v, last, left);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}