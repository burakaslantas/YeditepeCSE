// *****************************************************************************************
// 19.04.2021 - Monday


#include <stdio.h>
#define SIZE 10 // assume SIZE is even
int is_symmetric( int *first, int *last ){
    // we assume that first <= last
    // 5 6 5
    while( first < last ){
        if( *first != *last ) return 0;
        first++;
        last--;
    }
    return 1;
}
int main(){
    int A[ SIZE ] = { 1, 2, 3, 1, 1, 1, 2, 3, 2, 1 };

    if( is_symmetric( A, A + SIZE - 1 ) )
        printf( "Symmetric\n" );
    else printf( "Not symmetric\n" );

    //check whether the first half is symmetric
    printf( "The first half is " );
    if( is_symmetric( A, A + SIZE/2 - 1 ) )
        printf( "Symmetric\n" );
    else printf( "Not symmetric\n" );

    //check whether the second half is symmetric
    printf( "The second half is " );
    if( is_symmetric( A + SIZE/2, A + SIZE - 1 ) )
        printf( "Symmetric\n" );
    else printf( "Not symmetric\n" );

    //check whether the second quarter is symmetric
    printf( "The second quarter is " );
    if( is_symmetric( A + SIZE/4 + 1, A + SIZE/2 - 1 ) )
        printf( "Symmetric\n" );
    else printf( "Not symmetric\n" );

    return 0;
}


// copy the elements of an array into another one
// first even elements, then odd elemets
#include <stdio.h>
#define SIZE 10
void print_array( const int A[], int size ){
    int i;
    printf("\n");
    for( i = 0; i < size; i++ ) printf( "%d ", A[ i ] );
    printf("\n");
}
void even_odd_copy( int *dest, int *source, int size ){
    int *last = dest + SIZE - 1, *last_of_souce = source + SIZE - 1;
    while( source <= last_of_souce ){
        if( *source % 2 ){
            *last = *source;
            last--;
        }
        else{
            *dest = *source;
            dest++;
        }
        source++;
    }
}
int main(){
    int A[ SIZE ] = { 1, 2, 3, 8, 6, 1, 2, 3, 2, 1 };
    int B[ SIZE ];

    print_array( A, SIZE );
    print_array( B, SIZE );

    even_odd_copy( B, A, SIZE );

    print_array( A, SIZE );
    print_array( B, SIZE );

    even_odd_copy( B + SIZE/2, A, SIZE/2 );
    // this call results in copying the first half of A inside second half
    // of B - evens first then odd elements

    return 0;
}


// ############################# vvv SONRA BAK vvv #############################

// return a pointer to the max element of an array
#include <stdio.h>
#define SIZE 10
int *max_of_array( int *p, int *q ){
    int *max = p;
    p++;
    while( p <= q ){
        if( *p > *max ) max = p;
        p++;
    }

    return max;

    //    5      10    4    20
    //                             p
    //                     max
}
int main(){
    int A[ SIZE ] = { 1, 2, 3, 8, 6, 1, 2, 3, 2, 1 };
    int *q = max_of_array( A, A + SIZE - 1 );

    printf( "Max of A is: %d with index %d.\n", *q, q - A );

    return 0;
}

// ############################# ^^^ SONRA BAK ^^^ #############################


// *****************************************************************************************
// 21.04.2021 - Wednesday

// count n in an array
#include <stdio.h>
#define SIZE 10
int count_in_array( int *p, int size, int n ){
    int count = 0, i;
    for( i = 0; i < size; i++ ){
        if( *p == n ) count++;
        p++;
    }
    return count;
}
int main(){
    int A[ SIZE ] = { 1, 2, 3, 8, 6, 1, 2, 3, 2, 1 }, n = 5, count;

    count = count_in_array( A, SIZE, n );
    printf( "%d appears %d time(s) in A.\n", n, count );

    return 0;
}


// return min and max of an array
#include <stdio.h>
#define SIZE 10
void min_max( int *p, int size, int *min, int *max ){
    int i;

    if( *p > *(p+1) ){
        *max = *p;
        *min = *(p+1);
    }
    else{
        *max = *(p+1);
        *min = *p;
    }

    p += 2;

    for( i = 2; i < size; i++ ){
        if( *p > *max ){
            *max = *p;
        }
        else{
            if( *p < *min ){
                *min = *p;
            }
        }
        p++;
    }
}
int main(){
    int A[ SIZE ] = { 1, 2, 3, -8, 6, 1, 2, 3, 2, 1 }, min, max;

    min_max( A, SIZE, &min, &max );
    printf( "min: %d max: %d.\n", min, max );

    return 0;
}
