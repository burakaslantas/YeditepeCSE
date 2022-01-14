#include <stdio.h>


//print reverse of the given array

/*

printReverse(arr,5) 1

printReverse(arr+1, 4) 2

printReverse(arr+2, 3) 3

						4

printReverse(arr+4, 1) 5

printReverse (arr+5,0)



*/


void printReverse(int * arr, int size)
{
	if(size != 0)
	{	
		printReverse(arr+1,size-1);
		
		printf("%d ",*arr);
	}
	else
		printf("\n");
}


int main()
{
	int arr[]={1,2,3,4,5};
	printReverse(arr,5);
}
