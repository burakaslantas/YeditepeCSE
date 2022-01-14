// Program that returns greater value of two numbers
#include <stdio.h>

int* larger(int*, int*);

int main()
{
    int a = 15;
    int b = 92;
    int *p;
    p = larger(&a, &b);
    printf("%d is larger",*p);
}

int * larger(int *x, int *y)
{
    if(*x > *y)
        return x;
    else
        return y;
}
