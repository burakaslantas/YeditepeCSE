#include <stdio.h>
void concatString(char str1[], char str2[])
{
    int i = 0, j = 0;
    while(str1[i] != '\0')
    {
        i++;
    }
    
    while(str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int main()
{
    char str1[50] = "CSE";
    char str2[] = "114";
    concatString(str1, str2);
    puts(str1);
    return 0;
}