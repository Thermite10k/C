#include <stdio.h>

void filecopy(FILE *, FILE *);

int main(int argc, char *argv[]){
    FILE *fp;
    if(argc == 1){
        filecopy(stdin, stdout);
    }else{
        while(--argc > 0){
            if((fp = fopen(*++argv, "r")) == NULL){
                printf("showfile: can't open %s\n", *argv);
                return 1;
            }else{
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    return 0;
}
void filecopy(FILE *inputfile, FILE *outputfile){
    int c;
    while((c = getc(inputfile)) != EOF){
        putc(c, outputfile);
    }
}