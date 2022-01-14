#include<stdio.h>
 
/* Recursive function to search x in arr[l..r] */
int recSearch(int arr[], int l, int r, int x)
{
     if (r < l)
        return -1;
     if (arr[l] == x)
        return l;
     if (arr[r] == x)
        return r;
     return recSearch(arr, l+1, r-1, x);
}
 
int main()
{
    int arr[] = {1, 1, 4, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 4;
    int index = recSearch(arr, 0, n-1, x);
   
    if (index != -1)
       printf("%d is present at index %d\n", x, index);
    else
        printf("%d is not present\n", x);
   

    return 0;
}