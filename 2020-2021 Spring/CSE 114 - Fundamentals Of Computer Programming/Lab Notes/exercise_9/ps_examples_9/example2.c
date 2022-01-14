// C program to calculate length of
// a string using recursion
#include <stdio.h>
 
/* Function to calculate length */
int recLen(char* str)   
{
    // if we reach at the end of the string
    if (*str == '\0')
        return 0;
    else
        return 1 + recLen(str + 1);
}
 

int main()
{
    char str[] = "CSE";
    printf("%d\n", recLen(str)); 
    return 0;
}