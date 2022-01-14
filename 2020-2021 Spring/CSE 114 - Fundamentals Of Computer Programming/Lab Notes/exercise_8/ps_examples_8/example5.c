#include <stdio.h>
/*
	Input : arr[] = {2, 4}
	Output: 0 2 4 6

	Input : arr[] = {2, 4, 5}
	Output : 0 2 4 5 6 7 9 11
*/

// Prints sums of all subsets of arr[l..r]
void subsetSums(int arr[], int l, int r, int sum)
{
    // Print current subset
    if (l > r)
    {
        printf("%d ",sum );;
        return;
    }
 
    // Subset including arr[l]
    subsetSums(arr, l+1, r, sum+arr[l]);
    // Subset excluding arr[l]
    subsetSums(arr, l+1, r, sum);
        //printf("**");

}
 
int main()
{
    int arr[] = {2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    subsetSums(arr, 0, n-1,sum);
    return 0;
}