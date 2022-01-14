


/*
  Find the sum of even numbers from 100 down to 50.
 */


#include <stdio.h>

int main()
{
    int i = 100;
    int sum = 0;


    while(i>=50)
    {

        
        if(i%2 == 0) // contorls if our integer i is an even number or not
        {    
            sum = sum + i;
        }
        i--;
    }


    printf("Sum of even numbers from 100 down to 50= %d\n", sum);


    return 0;
}
