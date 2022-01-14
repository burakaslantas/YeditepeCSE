//
// Created by Burak Aslantaş on 10.03.2021.
//

/* Write a program to print the letter grade of a student
 * 90 <= grade <= 100 --- letter grade: 'A'
* 80 <= grade < 90 --- letter grade: 'B'
* 70 <= grade < 80 --- letter grade: 'C'
* 0 <= grade < 70 --- letter grade: 'F'
 */
#include<stdio.h>

int main(){
    int grade; char letter_grade;

    printf( "Enter the grade: " ); scanf( "%d", &grade );

/*  if( 90 <= grade ) letter_grade = 'A';
    else
        if( 80 <= grade ) letter_grade = 'B';
        else
            if( 70 <= grade ) letter_grade = 'C';
            else
                letter_grade = 'F';*/

    if( 90 <= grade ) letter_grade = 'A';
    else if( 80 <= grade ) letter_grade = 'B';
    else if( 70 <= grade ) letter_grade = 'C';
    else letter_grade = 'F';

    printf( "\n\nLetter grade is: %c.\n\n", letter_grade );


}


// Find the maximum of four integers using functions
// The conditional statements are allowed only in the function which finds the larger of two integers
#include<stdio.h>
int max_of_two( int x, int y ){
    printf( "\n\nmax_of_two runs with %d %d \n\n", x, y );
    if( x > y ) return x;
    return y;
    //return (x>y)*x + (y>x)*y;
}
int max_of_three( int p, int q, int r ){
    /* int temp;
    temp = max_of_two( p, q );
    return max_of_two( temp, r ); */
    printf( "\n\nmax_of_three runs with %d %d %d \n\n", p, q, r );
    return max_of_two( max_of_two( p, q ), r );
}
int max_of_four( int k, int l, int m, int n ){
    printf( "\n\nmax_of_four runs with %d %d %d %d \n\n", k, l, m, n );
    return max_of_two( max_of_three( k, l, m ), n );
}
int max_of_four_new( int k, int l, int m, int n ){
    printf( "\n\nmax_of_four_new runs with %d %d %d %d \n\n", k, l, m, n );
    return max_of_two( max_of_two( k, l ), max_of_two( m, n ) );
}

int main(){
    int a, b, c, d, max;
    printf( "Enter four integers: " ); scanf( "%d%d%d%d", &a, &b, &c, &d );
    max = max_of_four_new( a, b, c, d );

    printf( "\n\nMax is: %d.\n\n", max );
}