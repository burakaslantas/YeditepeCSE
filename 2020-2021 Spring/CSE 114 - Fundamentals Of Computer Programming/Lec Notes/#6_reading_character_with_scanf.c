#include <stdio.h>
#include <stdlib.h>

/*
 We have added a code example about the issue of reading characters with scanf.  This example code shows how scanf can read characters correctly when you need to use scanf consecutively. There is also an explanation in the code why we face such an issue.
 */

void correct()
{
    char x,y;
    printf("enter a char: ");
    scanf("%c",&x);
    printf("ascii %d, char -%c-\n",x,x);
    printf("enter a char: ");
    /*
        the space character in the scanf before the %c, consumes the \n character
        remaining from the previous scanf. For that, %c reads the correct character
    */
    scanf(" %c",&y);
    printf("ascii %d, char -%c-\n",y,y);

}q

void incorrect()
{
    char x,y;
    printf("enter a char: ");
    scanf("%c",&x);
    printf("ascii %d, char -%c-\n",x,x);
    printf("enter a char: ");
    /*
        There is \n character remaining from the previous scanf.
        If you do not put a space character, %c will read the newline and put it to the y variable
    */
    scanf("%c",&y);
    printf("ascii %d, char -%c-\n",y,y);

}

int main()
{
    correct();
    //incorrect();

    return 0;
}
