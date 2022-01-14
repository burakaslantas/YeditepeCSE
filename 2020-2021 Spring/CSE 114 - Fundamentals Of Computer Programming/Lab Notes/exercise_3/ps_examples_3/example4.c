#include <stdio.h>
int main()
{
	char small, capital;
	printf("Enter a capital letter\n");
	scanf("%c", &capital);
	printf("Enter a small letter\n");
	
	scanf(" %c", &small);
	
	while (capital <= small)
	{
		printf("%c ", capital);
		capital++;
	}
	return 0;
}