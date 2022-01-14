#include <stdio.h>


void reverse(int * start,int * end)
{
	int temp;
	while(start<end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}

}

int main()
{
    int arr[] = {3,1,5,7,9};

    reverse(arr,arr+4);

    //printing the array
	for(int i=0;i<5;i++)
		printf("%d ",arr[i]);
	printf("\n");

    return 0;
}
