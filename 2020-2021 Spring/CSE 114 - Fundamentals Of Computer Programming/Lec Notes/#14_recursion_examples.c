// *****************************************************************************************
// 17.05.2021 - Monday
// Find n! using recursion
// n! = n * (n-1) * (n-2) ... 2 * 1
// How can i find n! if (n-1)! is equal to x
// n! = n * x
// 0! = 1
#include <stdio.h>
int factorial( int n ){
    if( n == 0 ) return 1;
    printf( "n: %d, not base case, recalling with %d.\n", n, n-1 );
    return n * factorial( n - 1 );
}
int main(){
    int n, result;
    printf( "Enter n: " ); scanf( "%d", &n );
    result = factorial( n );
    printf( "\n%d! = %d.\n\n", n, result );
    return 0;
}



// Fibonacci Numbers
// f(0) = f(1) = 1 and f(n) = f(n-2) + f(n-1) for n >= 2
// 1 1 2 3 5 8 13 21 34 ...
// 0 1 2 3 4 5 6  7  8
#include <stdio.h>
int fibonacci( int n ){
    if( n < 2 ) return 1;
    printf( "n: %d, not base case, recalling with %d and %d.\n", n, n-2, n-1 );
    return fibonacci( n - 2 ) + fibonacci( n - 1 );
}
int main(){
    int n, result;
    printf( "Enter n: " ); scanf( "%d", &n );
    result = fibonacci( n );
    printf( "\nf(%d) = %d.\n\n", n, result );
    return 0;
}



// Find n % m recursively
// 3 % 4: 3
// 10 % 4 = 6 % 4 = 2 % 4: 2
#include <stdio.h>
int mod( int n, int m ){
    if( n < m ) return n;
    return mod( n - m, m );
}
int main(){
    int n, m, result;
    printf( "Enter n and m: " ); scanf( "%d %d", &n, &m );
    result = mod( n, m );
    printf( "\n%d mod %d = %d.\n\n", n, m, result );
    return 0;
}










// *****************************************************************************************
// 24.05.2021 - Monday
// find a^b recursively

#include <stdio.h>
// assume b >= 0
int power( int a, int b ){
    if( !b ) return 1;
    return a * power( a, b-1 );
}
int main(){
    int a = 5, b = -2;
    printf( "%d^%d = %d.\n", a, b, power( a, b ) );
    return 0;
}



// find the sum of the elements of an integer array

#include <stdio.h>
void print_array( const int A[], int size ){
    int i;
    printf("\n\n");
    for( i = 0; i < size; i++ ) printf( "%d ", A[ i ] );
    printf("\n\n");
}
int sum( int A[], int size ){
    if( size == 0 ) return 0;
    print_array( A, size );
    //return A[ size - 1 ] + sum( A, size - 1 );
    return A[ 0 ] + sum( A + 1, size - 1 );
    //return A[ 0 ] + sum( &A[ 1 ], size - 1 );
    
    // n! is n times (n-1)!
    // sum of the elements is first element plus sum of the rest 
}
int main(){
    int A[] = { 1, 2, 3, 4 };
    printf( "sum: %d.\n", sum( A, sizeof( A ) / sizeof( int ) ) );
    return 0;
}



// find the average of the elements of an integer array

#include <stdio.h>
void print_array( const int A[], int size ){
    int i;
    printf("\n\n");
    for( i = 0; i < size; i++ ) printf( "%d ", A[ i ] );
    printf("\n\n");
}
double average( int A[], int size ){
    if( !size ) return 0.0;
    return ( ( size - 1 ) * average( A + 1, size - 1 ) + A[ 0 ] ) / size;
}
int main(){
    int A[] = { 1, 2, 3, 4 };
    printf( "average: %.2f.\n", average( A, sizeof( A ) / sizeof( int ) ) );
    return 0;
}



// count n in A

#include <stdio.h>
void print_array( const int A[], int size ){
    int i;
    printf("\n\n");
    for( i = 0; i < size; i++ ) printf( "%d ", A[ i ] );
    printf("\n\n");
}
int count( int A[], int size, int n ){
    int result = 0;
    if( !size ) return 0;
    result = count( A + 1, size - 1, n );
    if( A[ 0 ] == n ) return 1 + result;
    return result;
}
int main(){
    int A[] = { 3, 3, 3, 4 }, n = 3;
    printf( "count: %d.\n", count( A, sizeof( A ) / sizeof( int ), n ) );
    return 0;
}



// *****************************************************************************************
// 26.05.2021 - Wednesday

// ############################# vvv BURAYA SONRA BAK vvv #############################

#include <stdio.h>
// length of a string
int strlen_rec( char *p /* char A[] */){
    if( !*p ) return 0;
    printf( "%s\n", p );
    return 1 + strlen_rec( p + 1 );
}

int main(){
    char A[ 100 ] = "", B[ 100 ] = "abc.";
    int len = strlen_rec( A );
    
    printf( "length of \"%s\" = %d.\n", A, len );
    return 0;
}

// ############################# ^^^ BURAYA SONRA BAK ^^^ #############################


#include <stdio.h>
//print an integer array recursively
void print_array_rec( int A[], int size ){
    if( size ){
        printf( "%d ", A[ 0 ] );
        print_array_rec( A + 1, size - 1 );
    }
}
//print an integer array recursively in reverse order
void print_array_reverse_rec( int A[], int size ){
    if( size ){
        printf( "%d ", A[ size - 1 ] );
        print_array_reverse_rec( A, size - 1 );
    }
}
int main(){
    int A[ 10 ] = { 1, 2, 3, 4 };
    
    print_array_rec( A, 10 );
    printf( "\n" );
    print_array_reverse_rec( A, 10 );
    return 0;
}

#include <stdio.h>
//print the digits of an integer
void print_digits_reverse( int n ){
    if( n ){
        printf( "%d ", n % 10 );
        print_digits_reverse( n / 10 );
    }
}
void print_digits( int n ){
    if( n ){
        print_digits( n / 10 );
        printf( "%d ", n % 10 );
    }
}
int main(){
    int n = 345;
    
    print_digits_reverse( n );
    printf( "\n" );
    print_digits( n );
    return 0;
}
