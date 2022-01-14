#include <stdio.h>
#define LEN 6

// Program to print maximum element of integer array using pointers
int getMaxElement(int *ptr, int size)
{
	int maxValue = *ptr;
	for(int i=0; i < size; i++)
	{
		printf("%d\n",*(ptr+i) );

		int temp = *(ptr+i); // arr[i]

		if(temp > maxValue)
			maxValue = temp;
	}
	return maxValue;
}

int main()
{
    int array[LEN] = {2, 16, 9, 7, 12, 3};
    int *first = array;
    printf("Max element in array is: %d\n", getMaxElement(first,LEN));
    return 0;
}
