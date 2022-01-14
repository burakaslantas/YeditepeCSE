// *****************************************************************************************
// 07.04.2021 - Wednesday
/* how to store and process exam grades and averages of a number of students */
#include <stdio.h>
#define SIZE 4
void print_array( const int A[], int size ){
    int i;
    printf("\n");
    for( i = 0; i < size; i++ ) printf( "%d ", A[ i ] );
    printf("\n");
}
void print_array_double( const double A[], int size ){
    int i;
    printf("\n");
    for( i = 0; i < size; i++ ) printf( "%f ", A[ i ] );
    printf("\n");
}
int main()
{
    int ID[ SIZE ], Midterm[ SIZE ], Final[ SIZE ];
    double Overall[ SIZE ];
    int i;
    int max = 0, min = 0;
    
    for( i = 0; i < SIZE; i++ ){
        printf( "Enter ID, Midterm and Final grades for student %d: ", i );
        scanf( "%d %d %d", &ID[ i ], &Midterm[ i ], &Final[ i ] );
        //                   ID + i
        
        Overall[ i ] = Midterm[ i ] * 0.4 + Final[ i ] * 0.6;
    }
    
    print_array( ID, SIZE );
    print_array( Midterm, SIZE );
    print_array( Final, SIZE );
    
    print_array_double( Overall, SIZE );
    
    // find and print the ids of the students with max and min overall grades
    for( i = 1; i < SIZE; i++ ){
        if( Overall[ i ] > Overall[ max ] ) max = i;
        else if ( Overall[ i ] < Overall[ min ] ) min = i;
    }
    
    printf( "ID of best: %d and overall: %f.\n", ID[ max ], Overall[ max ] );
    printf( "ID of worst: %d and overall: %f.\n", ID[ min ], Overall[ min ] );
    return 0;
}









// *****************************************************************************************
// 12.04.2021 - Monday
// print digits of a decimal number
#include <stdio.h>
void print_array( const int A[], int size ){
    int i;
    printf("\n");
    for( i = 0; i < size; i++ ) printf( "%d ", A[ i ] );
    printf("\n");
}
int main()
{
    int ids_gardes[ 100 ][ 2 ] = { {111, 50}, {222} };
    int i, x, j;
    
    for( i = 0; i < 2; i++ ){
        printf( "Enter the id of student %d: ", i );
        scanf( "%d", &x );
        ids_gardes[ i ][ 0 ] = x;
        
        printf( "Enter the grade of student %d: ", i );
        scanf( "%d", &ids_gardes[ i ][ 1 ] );
    }
    
    print_array( ids_gardes[ 0 ], 2 );
    print_array( ids_gardes[ 1 ], 2 );
    print_array( ids_gardes[ 2 ], 2 );
    
    for( i = 0; i < 100; i++ ){
        for( j = 0; j < 2; j++ ) printf( "%d ", ids_gardes[ i ][ j ] );
        printf( "\n" );
    }
    
    return 0;
}


// print digits of a decimal number
#include <stdio.h>
int main(){
    int x, y = 20;
    int *p, *q;
    int **r; // r can hold the address of an integer pointer
    
    p = &x;
    q = &y;
    
    //r = &x; incompatible
    
    r = &p;
    
    printf( "Enter x: " );
    //scanf( "%d", &x );
    scanf( "%d", p );
    
    printf( "\nx: %d\n", x );
    
    // x = x + 1;
    // *p: indirection operator
    // x = *p + 1;
    *p = *p + 1;
    printf( "\nx: %d\n", *p );
    
    *p = *q;
    printf( "\nx: %d\n", x );
    
    **r = 3; // equiv to *p = 3   equiv to x = 3
    printf( "\nx:%d y: %d\n", x, y );
    
    r = &q;
    **r = 8; // equiv to *q = 8   equiv to y = 8
    printf( "\nx:%d y: %d\n", x, y );
    
    
    
    return 0;
}


#include<stdio.h>
void func1( int x, int y ){
    printf( "\n\nx: %d  y: %d  \n\n", x, y );
    x++;
    y--;
    printf( "\n\nx: %d  y: %d  \n\n", x, y );
}
void func2( int *k, int *l ){
    printf( "\n\n*k: %d  *l: %d  \n\n", *k, *l );
    (*k)++; // *k++ is different, increments the address first
    (*l)--;
    printf( "\n\n*k: %d  *l: %d  \n\n", *k, *l );
}
int main(){
    int a = 10, b = 20;
    
    printf( "\n\na: %d  b: %d  \n\n", a, b );    
    func1( a, b );    
    printf( "\n\na: %d  b: %d  \n\n", a, b );
    
    func2( &a, &b ); 
    printf( "\n\na: %d  b: %d  \n\n", a, b );
              
}
