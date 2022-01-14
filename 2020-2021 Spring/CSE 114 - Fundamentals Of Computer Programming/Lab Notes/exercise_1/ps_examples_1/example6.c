// this program asks users to enter the amount of cash they want to deposit
// then prints which type of customer they are

#include <stdio.h> // for printf, scanf

// how much cash users deposit determines their customer type (A/B/C)
char GetCustomerType(double cash)
{
	if (cash > 500)
	{
		return 'A'; // users who deposit more than 500 dollars are type A customers
	}
	if (cash > 100)//tell me why this is not else if
	{
		return 'B'; // users who deposit 100 < cash <= 500 dollars are type B customers
	}
	return 'C'; // users who deposit cash <= 100 dollars are type C customers
}

int main()
{
	printf("How much cash would you like to deposit?\n");

	double amount;

	scanf("%lf", &amount); // must be %lf not %f

	char type = GetCustomerType(amount); // note that the names do not have to match (cash-amount)

	// both %lf and %f are ok here
	printf("You deposited %lf dollars. That makes you a type %c customer.\n", amount, type);

	return 0; // this is optional
}
