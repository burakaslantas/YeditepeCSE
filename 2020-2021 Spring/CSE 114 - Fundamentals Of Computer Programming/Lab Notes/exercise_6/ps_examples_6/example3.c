
#include <stdio.h>
#define LEN 10

int main()
{
    int array[LEN] = {2,4,6,8,10,12,14,16,18,20};
    int *ptr = array;

    //  Prints addresses of all elements
    for (int i = 0; i < LEN; i++)
    {
        printf("Address of %d: %p\n", array[i], &array[i]);
    }


	printf("\n\n");
	printf("Address of variable var is: %p\n", ptr);  // current content printed, Pointer moves to the next int position (as if it was an array)
    printf("Address of variable var is: %p\n", ptr++);  // current content printed, Pointer moves to the next int position (as if it was an array)
    printf("Address of variable var is: %p\n", ++ptr);  // Pointer moves to the next int position, next content will be printed (as if it was an array)
   
    printf("*** Now with the pointer ***\n\n");

    for (int i = 0; i < LEN - 2 ; i++)
    {
        printf("Address of %d: %p\n", *(ptr+i), ptr+i);
        
        
    }

    
    return 0;
}
