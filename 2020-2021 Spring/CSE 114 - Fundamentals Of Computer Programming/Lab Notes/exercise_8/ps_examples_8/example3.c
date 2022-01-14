#include <stdio.h>

/*
 * sum the content of the array
 */


int sumArr(int * arr, int size)
{
	if(size != 0)
	{	
		return   *arr + sumArr(arr+1,size-1);
	}
	else
	{
		return 0;
	}
}


int main()
{
	int arr[]={1,2,3,4,5};
	printf("sum: %d\n",sumArr(arr,5));
}
