#include <stdio.h>
#define LEN 6

// Program to print elements of integer array using pointers
void printArray(int *ptr1, int *ptr2)
{
	while(ptr1<=ptr2)
	{
		printf("%d ",*ptr1);
		ptr1++;
	}
	printf("\n");
}

int main()
{
    int array[LEN] = {2, 4, 6, 8, 10, 12};
    int *first = array, *last = array + LEN - 1;
    printArray(first, last);
	printArray(first+4, last);
    return 0;
}
