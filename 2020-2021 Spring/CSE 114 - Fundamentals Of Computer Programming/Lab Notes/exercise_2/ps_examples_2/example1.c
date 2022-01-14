
/* * 

Read a number and print valid whether 
it is even and divisible by 5 

&& --> AND operator
|| --> OR operator

*/


#include <stdio.h>

int main()
{

	int number;

	printf("enter a number:");
	scanf("%d", &number);

	if( number%2==0 && number%5==0)
	{
		printf("%d is valid \n", number);
	}else
		printf("%d is invalid\n", number);


	return 0;
}
