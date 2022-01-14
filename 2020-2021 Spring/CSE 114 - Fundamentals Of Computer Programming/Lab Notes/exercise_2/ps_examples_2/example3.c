
#include <stdio.h>

int main()
{
	int x, y;

	printf("enter x and y:");
	scanf("%d %d", &x, &y);

	if ( x>=2 && x<=5 && y>=1 && y<=4)
		printf("inside\n");
	else
		printf("outside\n");

	return 0;

}

