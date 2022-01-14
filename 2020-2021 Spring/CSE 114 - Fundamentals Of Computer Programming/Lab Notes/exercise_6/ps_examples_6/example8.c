#include <stdio.h>
#define LEN 5

// Program to print the address of maximum element in the array using pointers
int *getAdrMaxElement(int *ptr, int size)
{
    int *max = ptr;
    int i;
    for (i = 0; i < size; i++)
    {
        if (*(ptr + i) > *max)
        {
            max = (ptr + i);
        }
    }
    return max;
}

int main()
{
    int array[LEN] = {2, 9, 7, 12, 3};
    int *first = array;

    for (int i = 0; i < LEN; i++)
    {
        printf("Address of %d:%p\n", array[i], &array[i]);
    }
    int *maxElement = getAdrMaxElement(first, LEN);
    printf("Max element:%d index:%ld address:%p\n", *maxElement, maxElement - array, maxElement);
    return 0;
}
