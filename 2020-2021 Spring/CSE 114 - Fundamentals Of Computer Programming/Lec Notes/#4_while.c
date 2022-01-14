//
// Created by Burak Aslantaş on 16.03.2021.
//

// print 1, 2, 3 ... 100 on the screen
// print 2, 4, 6, ... 100
// print 99, 97, ... 3, 1
#include<stdio.h>
int main(){
    int i; // this, we will use to control the loop; that's why it is called
    // loop control variable and we should update it inside the loop

    // before the loop starts executing, is necessary initial values should
    // be assigned to the variables used... initialization
    i = 1;
/*     while( i <= 100 ){
         printf( "%d, ", i );
         i = i + 1;
     }*/
    while( i <= 100 ) printf( "%d, ", i++ );
    printf( "\n\n" );

    /* instead of i = i + 1 we can write i += 1;
     * var1 operator= var2 is equivalent to var1 = var1 operator var2;
     * x *= 2 eqv to x = x * 2;
     *
     * furthermore, instead of i += 1 (incrementing, increasing by 1)
     * we can use (unary) increment operator:
     * i++ (post-increment)   OR ++i (pre-increment)
     *
     * while evaluating expressions, increment operation is done after the
     * evaluation, if we use post-increment
     * it is done before the evaluation, if we use pre-increment
     *
     * i = 10;   x = 50;
     *
     * x = x + i++;           x = x + ++i;
     * x: 60     i: 11            x: 61   i: 11
     *
     * similarly, we have post and pre-decrement operators
     * i--   and  --i
     */

    i = 2;
    while( i <= 100 ){
        printf( "%d, ", i );
        i += 2;
    }
    printf( "\n\n" );

    //printf( "%d, ", i );
    i = i - 3; //i = 99;
    while( i >= 1 ){
        printf( "%d, ", i );
        i -= 2;
    }
    printf( "\n\n" );

}



// write a program which reads numbers from the user until a specific
// value is entered (this value we will name as: SENTINEL
// print the average in the end
#include<stdio.h>
#define SENTINEL 0
int main(){
    int n, sum = 0, count = 0;
    double avg;

    printf( "Enter the first number: " );
    scanf( "%d", &n );

    while( n != SENTINEL ){
        // if we are here, that means a valid number has arrived
        sum += n;
        count++;
        printf( "Enter the next number: " );
        scanf( "%d", &n );
    }

    if( count ){
        avg = sum / (double) count;
        printf( "You have entered %d numbers.\n ", count );
        printf( "The average is: %f.\n\n ", avg );
    }
    else printf( "No numbers!\n\n " );

    printf( "\n\n" );

}



// write a program which reads numbers from the user until a specific
// value is entered (this value we will name as: SENTINEL
// print the average in the end
// use do-while statement
#include<stdio.h>
#define SENTINEL 0
int main(){
    int n, sum = 0, count = 0;
    double avg;

    do{
        printf( "Enter the next number: " );
        scanf( "%d", &n );
        // if we are here, that does not mean a valid number has arrived
        // n might be equal to SENTINEL
        //if( n != SENTINEL ){
        sum += n;
        count++;
        //}
    } while ( n != SENTINEL );

    // we made an error inside the loop: updated sum and count values
    // for the last (SENTINEL) value also; now we should fix it
    sum -= SENTINEL;
    count--;

    if( count ){
        avg = sum / (double) count;
        printf( "You have entered %d numbers.\n", count );
        printf( "The average is: %f.\n\n ", avg );
    }
    else printf( "No numbers!\n\n " );

    printf( "\n\n" );

}


// write a program to check whether a number is prime or not
#include<stdio.h>
#include<math.h>
#define FALSE 0
#define TRUE 1
int is_prime( int );
int main(){
    int n;
    printf( "Enter an integer: " );
    scanf( "%d", &n );

    //if( is_prime( n ) == 1 )
    if( is_prime( n ) ) printf( "Your number is a prime number.\n " );
    else printf( "Your number is not a prime number.\n " );

    printf( "\n\n" );

}
int is_prime( int n ){
    // let's say, n = 100
    // check whether 2 divides my number
    // check 3, 4, 5, 6, ... up to ?
    // up to n/3 will be enough, because if a number larger k, than n/3
    // properly divides n, n will be equal to k * m and m will be smaller
    // than or equal to 3... and i will have already checked for 3
    // actually checking up to sqrt( n ) is enough
    // 100 = 10 * 10
    // 100 = 20 * 5
    int limit = (int) sqrt( (double) n ), k = 2;

    while( k <= limit ){
        if( n % k == 0 ) return FALSE;
        k++;
    }
    return TRUE;
}