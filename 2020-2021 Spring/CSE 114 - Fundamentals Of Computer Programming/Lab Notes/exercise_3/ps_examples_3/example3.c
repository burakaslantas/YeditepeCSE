#include <stdio.h>
int main()
{
   int i=1, j=1;
   while (i <= 10 && j <= 5)
   {
	printf("%d %d\n",i, j);
	i++;
	j++;
   }
   return 0;
}