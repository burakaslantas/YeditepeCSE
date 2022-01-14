// write functions to copy an array inside another in normal and reverse order
#include <stdio.h>
#define SIZE 5
void print_array( const int A[], int size ){
    int i;
    printf("\n\n");
    for( i = 0; i < size; i++ ) printf( "%d ", A[ i ] );
    printf("\n\n");
}
// assumes the sizes of the arrays are same
void copy_array( int dest[], const int source[], int size ){
    int i;
    for( i = size - 1; i >= 0; i-- ) dest[ i ] = source[ i ];
    // source[ 0 ] = 8; will fire a compiler error because attempting to write
    // to the source array... const means it is read-only
}
// assumes the sizes of the arrays are same
void copy_array_reverse( int dest[], const int source[], int size ){
    int i, j;
    for( i = 0, j = size - 1; i < size; i++, j-- ) dest[ i ] = source[ j ];
}
int main()
{
    int A[ SIZE ] = { 3, 5, 7, 2, 0 }, B[ SIZE ], C[ SIZE ];
    
    print_array( A, SIZE );
    print_array( B, SIZE );
    copy_array( B, A, SIZE );
    print_array( B, SIZE );
    
    print_array( C, SIZE );
    copy_array_reverse( C, B, SIZE );
    print_array( C, SIZE );
    
    copy_array( C, A, 2 ); // will copy only the first 2 elements from A to C
    print_array( C, SIZE );
    
    printf("\n\n");
    return 0;
}


// write a function which returns both min and max of an array
#include <stdio.h>
#define SIZE 5
void print_array( const int A[], int size ){
    int i;
    printf("\n\n");
    for( i = 0; i < size; i++ ) printf( "%d ", A[ i ] );
    printf("\n\n");
}
// assume unique elements and size > 1
void min_max( const int A[], int size, int Results[] ){
    int i;
    
    Results[ 0 ] = A[ 0 ] < A[ 1 ] ? A[ 0 ] : A[ 1 ];
    Results[ 1 ] = A[ 0 ] < A[ 1 ] ? A[ 1 ] : A[ 0 ];
    
    for( i = 2; i < size; i++ ){
        if( A[ i ] > Results[ 1 ] ) Results[ 1 ] = A[ i ];
        else if( A[ i ] < Results[ 0 ] ) Results[ 0 ] = A[ i ];
    }
}
int main()
{
    int A[ SIZE ] = { 10, 20, -30 }, B[ 2 ];
    
    print_array( A, SIZE );
    
    // call the function
    min_max( A, SIZE, B );
    printf( "Min is: %d, max is: %d.\n\n", B[ 0 ], B[ 1 ] );
    
    printf("\n\n");
    return 0;
}
