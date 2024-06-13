#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main(void){
    
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d\n", binsearch(6, v, 9));
    printf("%d\n", binsearch(0, v, 9));
    printf("%d\n", binsearch2(6, v, 9));
    printf("%d\n", binsearch2(0, v, 9));

    return 0;
}
/*
    Write a version of binsearch where only one test is performed in the loop, at the price of more tests outside.
*/
int binsearch(int x, int v[], int n){
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(x < v[mid]){
            high = mid-1;
        }else if (x > v[mid]){
            low = mid+1;
        }else{
            return mid;
        }

    }
    return -1;
}

int binsearch2(int x, int v[], int n){
    int low = 0, high = n - 1, mid;
    if(x == v[n / 2]){
        return n/2;
    }
    while(low <= high){
        mid = (low + high) / 2;
        if(x < v[mid]){
            high = mid - 1;
        }else{
            low = mid + 1 ;
        }

    }
    
    if (x == v[mid]){
        return mid;
    }else{
        return -1;
    }
}