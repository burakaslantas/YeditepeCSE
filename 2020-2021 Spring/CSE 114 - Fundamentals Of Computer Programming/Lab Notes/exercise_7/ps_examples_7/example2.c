#include <stdio.h>

// fgets gets all string including spaces.
int main()
{
    char name[30];
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);  // read string
    printf("Name: %s\n", name);
    puts(name);    // display string
    return 0;
}