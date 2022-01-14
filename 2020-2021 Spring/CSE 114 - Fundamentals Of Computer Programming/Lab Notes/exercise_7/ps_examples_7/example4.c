#include <stdio.h>

//copy str1 to str2

void copyString(char str1[], char str2[])
{
    int i = 0;
    while(str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}

int main()
{
    char str1[] = "source";
    char str2[] = "destination";
    puts(str1);
    puts(str2);
    copyString(str1, str2);
    puts(str1);
    puts(str2);
    return 0;
}