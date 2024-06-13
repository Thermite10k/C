#include <stdio.h>
#define swap(a,b,v) v[(a)] = v[(a)] ^ v[(b)];\
                    v[(b)] = v[(a)] ^ v[(b)];\
                    v[(a)] = v[(a)] ^ v[(b)];
void qsort(int low, int high, int v[]);
void magicswap(int first, int second, int v[]);

int main(void){
    int v[] = {2,3, 6, 75,2,7,623,8,5,7,68,24,8,7};
    qsort(0 , 13,v);
    for(int i = 0; i<14; i++){
        printf("%d\t", v[i]);
    }
    printf("\n%d",7/2 );
    return 0;
}

void magicswap(int first, int second, int v[]){

    // v[first] = v[first] ^ v[second];
    // v[second] = v[first] ^ v[second];
    // v[first] = v[first] ^ v[second];
    int temp = v[first];
    v[first] = v[second];
    v[second] = temp;
}

void qsort(int low, int high, int v[]){
    int i, last;
    if(low >= high){
        return;
    }
 
    magicswap(low, ((low + high) / 2), v);
    last = low;
    for (i = low + 1; i <= high; i++){
        if (v[i] < v[low]) {
            magicswap(i, ++last, v);
        }
    }
    magicswap(low, last, v);
    qsort(low, last-1, v);
    qsort(last + 1, high, v);


}