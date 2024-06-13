# include <stdio.h>
# define MAXLEN 1000

/*
    Program to remove trailing white-spaces and tabs
    while line:
        get each char, if i = 0 && c = '\t' || c = ' ', do not add it and dont i++
        else, add them and i++
*/

int getnospaceline(char line[], int maxline);

int main(){

    char line[MAXLEN];
    int len;
    while((len = getnospaceline(line, MAXLEN)) > 0){
        printf("%s \n", line);
    }


    return 0;
}

int getnospaceline(char line[], int maxline){

    int i, c = 0;

    for(i=0; i <maxline-1 && (c = getchar()) != EOF && c != '\n'; ){
        if(i == 0 && ( c == ' ' || c == '\t'))
            ;
        else{
            line[i] = c;
            ++i;
        }
        
    }
    if(c == '\n'){
  
        line[i] = '\n';
        i++;
        

    }
    line[i] = '\0';
    
    return i;
    

}