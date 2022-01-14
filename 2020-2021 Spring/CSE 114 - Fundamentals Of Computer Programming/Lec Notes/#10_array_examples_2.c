// write a function which searches for a number in an array - return TRUE or FALSE
// write a function which counts a number in an array - return the count 
#include <stdio.h>
#define SIZE 5
#define TRUE 1
#define FALSE 0

void print_array( const int A[], int size ){
    int i;
    printf("\n\n");
    for( i = 0; i < size; i++ ) printf( "%d ", A[ i ] );
    printf("\n\n");
}
int search( int A[], int size, int n ){
    int i = 0;
    while( i < size ){
        if( A[ i ] == n ) return TRUE;
        i++;
    }
    return FALSE;
}
int count( int A[], int size, int n ){
    int i = 0, count = 0;
    while( i < size ){
        if( A[ i ] == n ) count++;
        i++;
    }
    return count;
}

int main(){
    int A[ SIZE ] = { 1, 5, 30, 40, 5 }, n = 5, x;
    
    if( search( A, SIZE, n ) == TRUE ) printf( "%d appears inside the array.\n", n );
    else printf( "%d does not appear inside the array.\n", n );
    
    x = count( A, SIZE, n );
    if( x ){
        printf( "%d appears inside the array.\n", n );
        printf( "%d appears %d times inside the array.\n", n, x );
    }
    else printf( "%d does not appear inside the array.\n", n );
}

// write a fuction to check whether an array is symmetric or not
#include <stdio.h>
#define SIZE 6
#define TRUE 1
#define FALSE 0

int is_symmetric( int A[], int size ){
    int left = 0, right = size - 1;
    while( left < right ){
        if( A[ left ] != A[ right ] ) return FALSE;
        left++;
        right--;
    }
    return TRUE;
}

int main(){
    int A[ SIZE ] = { 1, 5, 30, 30, 5, 1 };
    
    if( is_symmetric( A, SIZE ) == TRUE ) printf( "symmetric.\n" );
    else printf( "not symmetric.\n" );
    
}

// write a function which copies the contents of an array inside another
// in this order: negatives on the left, 0's in the middle and positives on the right
#include <stdio.h>
#define SIZE 9
void print_array( const int A[], int size ){
    int i;
    printf("\n\n");
    for( i = 0; i < size; i++ ) printf( "%d ", A[ i ] );
    printf("\n\n");
}
void special_copy( int dest[], const int source[], int size ){
    int i = 0, left = 0, right = size - 1;
    while( i < size ){
        if( source[ i ] < 0 ){
            dest[ left ] = source[ i ];
            left++;
        }
        else{
            if( source[ i ] > 0 ){
                dest[ right ] = source[ i ];
                right--;
            }
        }
        i++;
    }
}

int main(){
    int A[ SIZE ] = { 1, 5, -30, -30, 0, 0, 8, 9, -10 }, B[ SIZE ] = { 0 };
    
    special_copy( B, A, SIZE );
    print_array( B, SIZE );
    
}
