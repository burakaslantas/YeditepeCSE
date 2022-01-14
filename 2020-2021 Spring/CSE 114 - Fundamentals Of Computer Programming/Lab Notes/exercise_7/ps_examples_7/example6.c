#include <stdio.h>

/* 
int isPalindrome(char str[])
{
    int start = 0, end = 0;
    while(str[end+1] != '\0')
    {
        end++;
    }
    while(start < end)
    {
        if(str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    return 1;
} 
*/


int string_length(char *pointer)
{
    int c = 0;

    while (*(pointer + c) != '\0')
        c++;

    return c;
}

int isPalindrome(char *str)
{
    int len = string_length(str);
    char * start = str;
    char * end = str + len - 1;

   
    while(start < end)
    {
        if(*start != *end)
            return 0;
        start++;
        end--;
    }
    return 1;
}

int main()
{
    char str1[] = "madam";
    char str2[] = "racecar";
    char str3[] = "letter";
    printf("%s %d\n%s %d\n%s %d \n", str1, isPalindrome(str1), str2, isPalindrome(str2), str3, isPalindrome(str3));
    return 0;
}