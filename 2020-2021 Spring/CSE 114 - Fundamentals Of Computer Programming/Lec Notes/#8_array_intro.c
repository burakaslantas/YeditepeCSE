#include<stdio.h>
int main( void ) {
    int prime_lt_100[] = {2.0, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}, n;
    
    n = sizeof( prime_lt_100 ) / sizeof( double );
    
    printf( "The size of the array is: %d.\n", n );
    
    printf( "\n\n" );
    return 0;    
}
