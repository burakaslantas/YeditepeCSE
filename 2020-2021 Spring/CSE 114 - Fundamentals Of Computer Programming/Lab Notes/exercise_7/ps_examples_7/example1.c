#include <stdio.h>

// If you enter a string including space, scanf will get until the space.


int main()
{
    char name[20];
    printf("Enter name: ");
	//scanf("%s", &name); This is wrong 
    scanf("%s", name);
    printf("Your name is %s.", name);
    return 0;
}