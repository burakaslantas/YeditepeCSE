 /*
  C program to find the number of occurrences of a given number in a
 list */
 
#include <stdio.h>
 
int rCountArray(int array[], int n, int a)
{
    int found = 0;
    if (n < 0) 
        return 0;

    if (array[n] == a)
        found++;

    return (found + rCountArray(array, n - 1, a));
}

int main()
{
    int arr[] = {1, 1, 4, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]); 
    // 5*4= 20 / 4 = 5

    int c = rCountArray(arr, n-1, 1);
    printf("%d\n",c );
    return 0;
}
 

