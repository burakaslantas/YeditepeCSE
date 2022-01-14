#include <stdio.h>
#define LEN 12
// Program to print the number of "n" in the given integer array using pointers
void printArray(int *ptr1, int *ptr2, int n)
{
    int count = 0;
    while (ptr1 <= ptr2)
    {
		if(*ptr1 == n)
			count++;
        
        ptr1++;
    }
    printf("Total number of %d in this array is: %d\n", n, count);
}

int main()
{
    int array[LEN] = {2, 4, 4, 3, 5, 7, 7, 2, 3, 3, 2, 2};
    int *first = array, *last = array + LEN - 1;
    printArray(first, last, 2);
    return 0;
}
