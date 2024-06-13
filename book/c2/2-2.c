include <stdio.h>

int main(void){
    int i,c, lim = 10;

    // for(i;i<lim;i++){
    //     c = getchar();
    //     if(c != '\n'){
    //         if(c != EOF){
    //             return 1;
    //         }
    //     }
    // }
    while(i<lim-1){
        c = getchar();
        if (c =='\n')
            break;
        if(c == EOF){
            break;
        }
        i++;
    }
    return 0;
}