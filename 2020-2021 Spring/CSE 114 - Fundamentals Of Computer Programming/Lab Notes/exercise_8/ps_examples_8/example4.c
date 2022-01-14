#include <stdio.h>

/*
 * check string is palindrom or not
 */


int isPalindrome(char * start, char * end)
{
	if(start == end)
	{
		return 1;
	}
	if(*start != *end)
	{
		return 0;	
	}
	if (start < end + 1 )
	{
		isPalindrome(start+1,end-1);
	}
	return 1; // assume that we have only one char in a string
}


int main()
{
	char noPal[]="wrong";
	char yesPal[]="radar";
	printf("no: %d\n",isPalindrome(noPal,noPal+4));
	printf("yes: %d\n",isPalindrome(yesPal,yesPal+4));
}
