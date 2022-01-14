#include <stdio.h>

void  print(int arr[], int size)
{
    int i;
	for(i=0; i<size ; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int countN(int arr[],int size, int n)
{
	int i,count=0;
	for(i=0; i<size ; i++)
		if(arr[i] == n)
			count++;
	return count;
}

 
int main()
{
	int arr[]={3,1, 3,5, 3,1, 3,3};


	printf("in all array: %d\n",countN(arr,8,3)); // in all the array
	printf("in the first half: %d\n",countN(arr,4,3)); // in the first half
	printf("in the second half: %d\n",countN(arr+4,4,3)); // in the second half
	printf("in the third quarter: %d\n",countN(arr+4,2,3)); // in the third quarter

}
