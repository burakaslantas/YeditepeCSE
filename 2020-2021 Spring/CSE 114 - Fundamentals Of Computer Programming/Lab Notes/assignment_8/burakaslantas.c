#include <stdio.h>

int recSearch(int array[], int x, int length){
    int *r = array + length - 1;
    int *l = array;
    if(*r == x){
        return r-l;
    }
    if(r == l){
        if(*r == x) return 0;
        else if(*r != x) return -1;
    }
    return recSearch(array, x, length-1);
}

int main(){
    int array[5] = {1, 1, 4, 2, 1};
    int x = 4;
    int result;

    result = recSearch(array, x, 5);

    printf("Result: %d", result);
}

