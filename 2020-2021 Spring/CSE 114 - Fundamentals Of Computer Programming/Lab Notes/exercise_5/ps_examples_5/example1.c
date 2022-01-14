#include <stdio.h>
#define MSIZE 2

void  print(int arr[], int size)
{
    int i;
	for(i=0; i<size ; i++)
		printf("%d ",arr[i]);
	printf("\n");
}
 

void  printReverse(int arr[], int size)
{
    int i;
	for(i=size-1; i>=0 ; i--)
		printf("%d ",arr[i]);
	printf("\n");
}

void copyReverse(int arr[], int dest[], int size)
{
	int i,j=0;
	for(i=size-1; i>=0 ; i--)
		dest[j++]=arr[i];
}

void printPositive(int arr[], int size)
{
	int i;
	for(i=0; i<size ; i++)
		if(arr[i] > 0)
			printf("%d ",arr[i]);
	printf("\n");
}


int main()
{
	int arr[]={2,-1,2,3,-5};
	int arrReverse[5];

	printReverse(arr,5);
	copyReverse(arr,arrReverse,5);
	print(arrReverse,5);
	printPositive(arr,5);


}
