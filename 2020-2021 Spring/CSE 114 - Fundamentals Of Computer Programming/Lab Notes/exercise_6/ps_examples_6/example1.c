// Example of Pointer demonstrating the use of & and *


#include <stdio.h>
int main()
{
    /* Pointer of integer type, this can hold the
    * address of a integer type variable.
    */

	int var;
    int *p;

    /* Assigning the address of variable var to the pointer
    * p. The p can hold the address of var because var is
    * an integer type variable.
    */
	var = 10;
    p = &var;

    printf("Value of variable var is: %d\n", var);

	printf("\nAddress of variable var is: %p\n", &var);
	printf("\nvalue of  p is: %p\n", p);
	printf("\nAddress of pointer p is: %p\n", &p);

    printf("\nValue of variable var is: %d\n", *p);

    printf ( "\nValue of var is: %d\n", *( &var));
    return 0;
}
