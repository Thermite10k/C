#include "alloc.h"
#define MAXMEM 10000


static char memory[MAXMEM];
static char *allocp = memory;
 

char *alloc(int size){
    
    if(memory + MAXMEM - allocp >= size){ // if memory (mem + maxmem) 
                                        // - used memory (allocp) is more then size
        allocp += size;
        return allocp - size;

    }else{
        
        return 0;
    }


}

void afree(char *p){
    if(p >= memory && p< memory + MAXMEM){
        // if p is valid and it's within the range:
        allocp = p;
    }
}