#include <stdio.h>
#define MSIZE 2

void  print(int arr[], int size)
{
    int i;
	for(i=0; i<size ; i++)
		printf("%d ",arr[i]);
	printf("\n");
}
/* it copy the contents of A to B
	but puts the negatives first
	then positives come
*/
void divideAndCopy(int A[], int B[], int size)
{
	int i,start=0, end=size;
	for(i=0; i<size ; i++)
		if(A[i] <=0)
			B[start++] = A[i];
		else
			B[--end] = A[i];
}

 
int main()
{
	int arr[]={1,2,-3,-4,5,6,-7,8};
	int arr2[8];
	divideAndCopy(arr,arr2,8);
	print(arr2,8);

}
