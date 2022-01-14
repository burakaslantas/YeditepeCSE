#include <stdio.h>


//find value is divisible by using only substraction


int divisible(int value, int x)
{
	if(value == 0)
		return 1;
	else if (value < 0)
		return 0;
	else
		return divisible(value-x,x);
}


int main()
{
	printf("result: %d\n",divisible(10,3));
	printf("result: %d\n",divisible(10,5));
}
