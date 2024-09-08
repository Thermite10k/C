#include <stdio.h>
#include <stdarg.h>

/*
    Mini print: minimal printf with variable argument list
*/
void miniprintf(char *fmt, ...);

int main(){
    miniprintf("This %d works%s", 123, " aight!");
    return 0;
}
void miniprintf(char *fmt, ...){
    va_list ap; /* Points to each unnamed arg in turn */
    /* different conversion characters */
    char *p, *sval;
    int ival;
    double dval; 

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for(p = fmt; *p; p++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }
        switch(*++p){
            case 'd':
                ival = va_arg(ap, int); // we nust specify the type to push ap forward enough
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for(sval = va_arg(ap, char *); *sval; sval++){
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
        va_end(ap); 
    }
}