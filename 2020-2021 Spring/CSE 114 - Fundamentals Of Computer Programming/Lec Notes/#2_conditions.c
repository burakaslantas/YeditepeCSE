//
// Created by Burak Aslantaş on 8.03.2021.
//

#include<stdio.h>

int main(){
    int x = 15 , y = 10, z = 20;

/* condition to check whether x is in the range [y, z]
 * y <= x <= z will be logically incorrect, but no compiler error
 * first y <= x is evaluated to 0 or 1
 * then {0 or 1} <= z is evaluated
 * so for example if z is larger than 0, always we will have 1 as a result
 * regardless of the value of x
 * we should write it as: (y <= x) && (x <= z)
 * p: y <= x     q: x <= z
 * p': x < y       q': x > z
 *
 * condition to check whether x is outside the range [y, z]
 * !( (y <= x) && (x <= z) )
 * equivalent to: x < y || x > z
 * !(p && q) = p' || q'   --- we have found the De Morgan Rule
 * !(p || q) = p' && q'
*/
    printf( "%d.\n\n", y <= x && x <= z );

    x = 1;
    if( x ){
        printf( "True.\n" );
        printf( "True 2.\n" );
    }

    x = 0;
    y = -10;
    z = 20;
    if( y > 0 ){
        if( z > 0 )
            x = 5;
    }
    else
        x = -5;

/*    if( y > 0 )
        if( z > 0 )
            x = 5;
    else
        x = -5;*/

    printf( "x: %d.\n\n", x );


    x = 0;
    y = -10;
    z = 20;
/*    if( y > 0 )
        x = 5;
        z = 5;
    else
        x = -5;
         * compiler error because z = 5; does not belong to previous if
         * so we have a new statement afterwards starting with else!
         * */

    if( y > 0 ){
        x = 5;
        z = 5;
    }
    else
        x = -5;

    printf( "x: %d.\n\n", x );
}