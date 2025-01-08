#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_BUFF_SIZE 100
#define MAX_WORD 100
#define KEY "key.txt"
#define KEY_2 "key2.txt"
#define READ_MODE "r"
#define MAX_LINES 10

int get_f_char(FILE* fp);
void unget_f_char(char c);
void unget_f_word(char *w);
int get_f_word(FILE* fp, int limit, char* word);

int str_in_str(char* s1, char* s2); // s1 in s2 ? 1 : 0;
int str_end_in_str(char* s1, char* s2); // s1 ends in s2 ? 1 : 0;



int main(){
    
    char word[MAX_WORD] ;

    FILE* fp;
    fp = fopen(KEY_2, READ_MODE);
    int i = 0, max_prams = 5;
    char prams[100][100];
    int pram = 0;
    char mulPattern[] = "(%d,%d)";
    int j = 0; // the counter for mulPattern
    char c; // used instead of mulPattern[j]
    int patternLength = strlen(mulPattern);

    long long answer = 0;
    long long tempAnswer = 0;
    long long totalAnswers[MAX_LINES];

    for(int i2 = 0; i2 < MAX_LINES; i2++){
        totalAnswers[i2] = 0;
    }

    int status = 0;
    int isValidMul = 0;
    int lines = 0;

    //printf("Len is%d\n", patternLength);
    while((status = get_f_word(fp, MAX_WORD, word)) != EOF){
        isValidMul = 0;
        //printf("%s\n", word);
        if(status == '\n'){
            lines++;
            printf("___________________________________________________________\n");
            continue;
        }
        i = 0;
        if(str_in_str("mul", word)){
            //printf("\t%s\n", word);
            // if you see a mul, get max_prams next inputs
            while(i < max_prams && (status = get_f_word(fp, MAX_WORD, word)) != EOF){
                strcpy(prams[i++], word);
            }
 
            if(i == max_prams){
                tempAnswer = 1;
                i = 0;
                j = 0;
                while((c = mulPattern[j]) != '\0'){
                    if(c == '%'){
                        c = mulPattern[++j];
                        switch(c){
                            case 'd':
                                pram = atoi(prams[i++]);
                                if(!(pram / 1000) && pram != 0){
                                    tempAnswer *= pram;
                                }else{
                                    tempAnswer = 0;
                                    fprintf(stderr, "Invalid prameter of mul instruction: %d\n", pram);
                                }
                                break;
                            default:
                                fprintf(stderr, "Unknown pattern: %c\n", c);
                                break;
                        }
                    }else if(mulPattern[j] == *prams[i]){
                            i++;
                    }else{
                        // for(int i3 = 0; i3 < max_prams; i3++){
                        //     printf("Ungetting %s\n", prams[i3]);
                        //         unget_f_word(prams[i3]);
                        //     }
                            break;
                        }
                    
                    j++;
                }
                if(j == patternLength){// && i == max_prams : -> else -> unget_str...
                    printf("mul");
                    for(int k = 0; k < i; k++){
                        printf("%s", prams[k]);
                    }
                    printf(" = %lld in line %d\n", tempAnswer, lines);
                    totalAnswers[lines] += tempAnswer;
                    answer += tempAnswer;
                    isValidMul = 1;
                }
            }
        }
           
        if(!isValidMul){
        }
        if(status == EOF){
            break;
        }

    }
    printf("%lld\nin %d lines\n", answer, lines);

    for(int l = 0; l < lines; l++){
        if(totalAnswers[l]){
            printf("%lld\n", totalAnswers[l]);
        }
    }

    //printf("dose m!ul have mul? %d", str_in_str("mul", "m!ul"));
    
    return 0;
}

char charBuff[CHAR_BUFF_SIZE];
int charBuffPtr = 0;

int get_f_char(FILE* fp){
    if(charBuffPtr > 0){
        return charBuff[--charBuffPtr];
    }else{
        return getc(fp);
    }
}
void unget_f_char(char c){
    if(charBuffPtr < CHAR_BUFF_SIZE){
        charBuff[charBuffPtr++] = c;
    }else{
        fprintf(stderr, "error: unget_f_char: Buffer is full!\n");
    }
}
void unget_f_word(char *w){
    char* word = w;
    while(*word){
        unget_f_char(*word++);
    }
}

int get_f_word(FILE* fp, int limit, char* word){
    char* w = word;
    int c;

    c = get_f_char(fp);

    if(c != EOF && c != '\n'){
        *w++ = c;
    }
    if(!isalnum(c) || c == EOF){
        *w = '\0';
        return c;
    }

    for(; --limit > 0; w++){
        if(!isalnum((*w = get_f_char(fp)))){
            unget_f_char(*w);
            break;
        }
    }

    *w = '\0';

    return *word;
}

int str_in_str(char* s1, char* s2){ // s1 in s2 ? 1 : 0;

    char* str1 = s1;
    char* str2 = s2;

    int i = 0, j = 0;
    if(*str1 == '\0' || *str2 == '\0'){
        fprintf(stderr, "error: str_in_str: s1 or s2 has length of 0\n");
    }

    if(strlen(s1) > strlen(s2)){
        return 0;
    }

    while(str2[i] != '\0'){
        if(str1[j] == str2[i]){
            j++;
        }else{
            j = 0;
        }
        if(str1[j] == '\0'){
            return 1;
        }
        i++;
    }

    return 0;

}

int str_end_in_str(char* s1, char* s2){ // s2 ends in s1 ? 1 : 0;

    char* str1 = s1;
    char* str2 = s2;

    int i = 0, j = 0;
    int lenOfS1 = 0;

    while(str2[i]){
        i++;
    }
    while(str1[j]){
        j++;
    }
    if(i == 0 || j == 0){
        fprintf(stderr, "error: str_end_in_str: s1 or s2 has length of 0\n");
    }
    if(j > i){
        return 0;
    }
    j--;
    i--; // to skip the '\0'
    lenOfS1 = j;
    while(i >= 0 ){
        if(str2[i] == str1[j]){
            if(j == 0){
                return 1;
            }
            j--;
        }else{
            j = lenOfS1;
        }
        i--;
    }
    return 0;
}