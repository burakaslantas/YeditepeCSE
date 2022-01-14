
// Print the digits of a decimal number in reverse order
#include<stdio.h>
void print_reverse( int );
int main( void ) {
    int n;
    printf( "Enter n: " ); scanf( "%d", &n );
    print_reverse( n );

    printf( "\n\n" );
    return 0;
}
void print_reverse( int n ){
    /* n % 10 gives me the rightmost digit
     * print this digit and then get rid of it ( integer division... n/10)
     * get the next digit from right using mod operator again
     * continue like this until you have a non-zero number
     */
    while( n ){
        printf( "%d ", n % 10 );
        n /= 10;
    }
}


// Print the digits of a decimal number in normal order
#include<stdio.h>
void print_normal( int );
int main( void ) {
    int n;
    printf( "Enter n: " ); scanf( "%d", &n );
    print_normal( n );

    printf( "\n\n" );
    return 0;
}
void print_normal( int n ){
    /* say n is 354
     * divide by 10: 35
     * divide by 10: 3 --- print 3 ... how to obtain 54 then?
     * what if we start dividing n with 100 (why 100?)
     * 354/100: 3 --- print 3
     * 354 - 3*100 = 54
     * then divide by 10
     * log10 1000 = 3 and log10 100 = 2 so log10 354 is 2.xxx
     * pow( 10, 2 ) will give me 100
     * we are not allowed to use library functions, so we have to find
     * the first power of 10 to be used, with a loop
     */

    int temp = n, power = 1;
    while( temp > 9 ){
        power *= 10;
        temp /= 10;
    }

    // we have found the first power of 10, print in order now
    while( n ){
        temp = n / power;
        n -= temp * power;
        power /= 10;
        printf( "%d ", temp );
    }
    /* say n=2345 ... power: 1000
     * 2345/1000    temp: 2
     * 2345 - 2*1000 : 345  new power: 1000/10: 100
     * 345/100: temp:3
     * 345 - 3*100:  45 power: 10
     */


}


/* Print a right-triangle using * characters... get the base from the user
 * *
 * **
 * ***
 * ****   base is base
*/
#include<stdio.h>
void print_triangle( int );
int main( void ) {
    int base;
    printf( "Enter base: " ); scanf( "%d", &base );
    print_triangle( base );

    printf( "\n\n" );
    return 0;
}
void print_triangle( int base ){
    int i, star = 1;
    while( star <= base ){
        // print star number of *'s, print new line, update star
        i = 0;
        while( i < star ){
            printf( "*" );
            i++;
        }
        printf( "\n" );
        star++;
    }
}
