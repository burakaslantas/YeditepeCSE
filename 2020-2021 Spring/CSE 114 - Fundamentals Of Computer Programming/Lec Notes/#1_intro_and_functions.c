//
// Created by Burak Aslantaş on 8.03.2021.
//

// You can have comments on a C program... This is a single line commnet, starts with double slashs
/* This is a multiple line comment, starts with slash asterics
We will write a program, which converts a distance from miles to kilometers
Multiple line comments end with star slash */
#include<stdio.h> // for printf and scanf definitions
#define KMS_PER_MILE 1.609 // conversion constant
int main( void ){
    double miles, // distance in miles
    kms; // equivalent distance in kilometers

    // generally before input, we print a prompt message
    printf( "Enter the distance in miles: " );
    scanf( "%lf", &miles );

    // make the conversion
    kms = miles * KMS_PER_MILE;

    printf( "That equals % f %f kilometers.\n", kms );
    // place holders... whenever we have a variable value inside a format string, we use place holders
    // %d for integers both inside printf and scanf
    // %f for double inside printf
    // %lf for double inside scanf
    // %c for char

    return 0;
}
// Week 3 - Monday
#include<stdio.h> // for printf and scanf definitions
int main( void ){
    int m, n;
    double p, x, y, fractional;

    m = 8;
    n = 3;
    p = 2.0;

    x = m / (double) n;
    printf( "The value of x: %4.2f.\n\n", x );

    /* x = m / p;
    printf( "The value of x: %f.\n\n", x ); */

    /*
    fractional = x - (int) x;
    printf( "The value of fractional: %f.\n\n", fractional );
    n = (int) x;
    if( fractional >= 0.5 ) n = n + 1;
     */

    n = (int) (x + 0.5);

    printf( "The value of n: %-15d.\n\n", n );
    printf( "The value of n: %-15d.\n\n", 6 );
    printf( "The value of n: %-15d.\n\n", 243 );

    return 0;
}
/* Read two numbers from the user, find the sum and the product of the two
 * using functions (assume that main function cannot do arithmetic operations)
 * and present the results to the user. */
#include<stdio.h>
int add( int, int );
int multiply( int, int );
int main( void ){
    int a, b, sum, product;

    printf( "Enter two integers: " );
    scanf( "%d %d", &a, &b );

    sum = add( a, b );

    product = multiply( a, b );

    //product = 50;

    //result = 15;

    printf( "\n\n%d + %d = %d, %d * %d = %d \n\n", a, b, sum, a, b, product );

    return 0;
}
int add( int m, int n ){
    int result;
    result = m + n;
    m = m + 1;
    // because we use "CALL BY VALUE"
    // instead of "CALL BY REFERENCE"
    // changing the value of a local variable does not affect
    // the variables of the calling function
    // that's why a of main, does not change
    return result;
    // could be done without declaring result, as:
    // return m + n;
}
int multiply( int p, int q ){
    return p * q;
}
/* Functions with no arguments and no return type (void)
 * Write functions to draw rectangles and triangles on the screen using '*'s
 * Draw the shapes by calling these functions from main*/
#include<stdio.h>
void rectangle( );
void triangle( void );
int main( ){
    rectangle();
    triangle();
    rectangle();
    rectangle();

    return 0;
}
void rectangle( ){
    printf( "\n\n" );
    printf( "*****\n" );
    printf( "*   *\n" );
    printf( "*****\n" );
    printf( "\n\n" );
}
void triangle( void ){
    printf( "\n\n" );
    printf( "  *\n" );
    printf( " * *\n" );
    printf( "*****\n" );
    printf( "\n\n" );
}
/* Write a function which receives an uppercase letter and converts it to lowercase.
 * Write a function which receives an lowercase letter and converts it to uppercase.*/
#include<stdio.h>
char to_lower( char );
char to_lower_with_check( char ch );
char to_upper( char )
int main( ){
    char ch1, ch2;
    printf( "Enter an uppercase letter: " );
    scanf( "%c", &ch1 );
    // call the function
    ch2 = to_lower_with_check( ch1 );
    printf( "Your lowercase letter is: %c.\n\n", ch2 );
    scanf( "%c", &ch1 );

    printf( "Enter an lowercase letter: " );
    scanf( "%c", &ch1 );
    // call the function
    ch2 = to_upper( ch1 );
    printf( "Your uppercase letter is: %c.\n\n", ch2 );

    return 0;
}
char to_lower( char ch ){
    // this function assumes that ch is an uppercase letter
    char result;
    // find the order of ch among capital letters
    // then add this to 'a' to find the corresponding lowercase letter
    result = 'a' + ( ch - 'A' ); // ch + ('a'-'A'); ch + 32;
    return result;
}
char to_lower_with_check( char ch ){
    // this function does not assume that ch is an uppercase letter
    char result;

    if( ch >= 'A'  && ch <= 'Z' ){
        // find the order of ch among capital letters
        // then add this to 'a' to find the corresponding lowercase letter
        result = 'a' + ( ch - 'A' ); // ch + ('a'-'A'); ch + 32;
        return result;
    }
    return ch;
}
/* A    B  C  D   E
 * 50 51 52 53 54
 *
 * 'D' - 'A' : 3
 *
 * a   b   c   d   e
 * 90 91 92 93 94
 *
 * 'd' - 'a': 3
 * 'a' + 3 = 90 + 3 = 93
 *
 */
char to_upper( char ch ){
    // this function assumes that ch is an lowercase letter
    char result;
    // find the order of ch among small letters
    // then add this to 'A' to find the corresponding uppercase letter
    result = 'A' + ( ch - 'a' ); // ch - ('a'-'A'); ch - 32;
    return result;
}
/* Write functions to find the are of a cylinder*/
#include<stdio.h>
#include<math.h>
double rectangle( double, double );
double circle( double );
double cylinder( double, double );
int main( ){
    double r, h, area;
    printf( "Enter r and h: " );
    scanf( "%lf %lf", &r, &h );
    // when you declare a function, it doesn't mean that that function will always
    // be called inside main. Other functions can call that function also.
    area = cylinder( r, h );
    printf( "The area is: %f.\n\n", area );

    return 0;
}
double rectangle( double a, double b ){
    printf( "The rectangle function runs with %f %f.\n\n", a, b );
    return a * b;
}
double circle( double r ){
    printf( "The circle function runs with %f.\n\n", r );
    return M_PI * r *r;
}
double cylinder( double r, double h ){
    printf( "The cylinder function runs with %f %f.\n\n", r, h );
    return 2 * circle( r ) + rectangle( 2 * M_PI * r, h );
}
