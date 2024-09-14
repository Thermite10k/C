#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *in, FILE *out);

int main(int argc, char *argv[]){
    FILE *fp;
    char *prog = argv[0]; /* this is the program name for error handling */

    if(argc == 1){
        filecopy(stdin, stdout);
    }else{
        while(--argc > 0){
            if((fp = fopen(*++argv, "rb")) == NULL){
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    if(ferror(stdout)){ // ferror (*stream) returns non zero if error occures on the stream.
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}
void filecopy(FILE *in, FILE *out){
    int c;
    while((c = getc(in)) != EOF){
        fprintf(out, " %d ", c);
        //putc(c - 0, out);
    }
}