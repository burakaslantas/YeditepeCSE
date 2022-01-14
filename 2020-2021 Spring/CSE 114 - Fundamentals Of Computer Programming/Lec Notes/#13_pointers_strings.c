// *****************************************************************************************
// 26.04.2021 - Monday
#include <stdio.h>
#define SIZE 10
void print_array( const int A[], int size ){
    int i;
    printf("\n");
    for( i = 0; i < size; i++ ) printf( "%d ", A[ i ] );
    printf("\n");
}
int main(){
    int A[ SIZE ];
    int *P[ SIZE ];
    int i, j = 0;
    int **q;
    
    for( i = SIZE-1; i >= 0; i-- ){
        P[ j ] = A + i; // = &A[ i ]
        j++;
    }
    
    q = P; // q = &P[0]
    
    // P[0]: A + SIZE - 1
    // P[1]: A + SIZE - 2
    //...
    // P[SIZE-1]: A
    
    for( i = 0; i < SIZE; i++ ){
        *P[ i ] = SIZE - 1 - i;
    }
    // *P[0] = 0 eqv A[ SIZE-1 ] = 0
    
    print_array( A, SIZE );
    
    // prints the array in normal order
    for( i = SIZE-1; i >= 0; i-- ){
        printf( "%d ", *P[ i ] );
    }
    printf( "\n" );
    
    // prints the array in reverse order
    for( i = 0; i < SIZE; i++ ){
        printf( "%d ", *P[ i ] );
    }
    printf( "\n" );
    
    // prints the array in reverse order
    for( i = 0; i < SIZE; i++ ){
        printf( "%d ", **q );
        q++;
    }
    printf( "\n" );
    
    // increment each element of A, starting with its first element
    q--; // q points to P[ 9 ]
    for( i = 0; i < SIZE; i++ ){
        **q = **q + 1;
        q--;
    }
    print_array( A, SIZE );
}


// write a function which reurns a pointer to the last occurence of 
// a number n inside an array
#include <stdio.h>
void print_array( const int A[], int size ){
    int i;
    printf("\n");
    for( i = 0; i < size; i++ ) printf( "%d ", A[ i ] );
    printf("\n");
}
int *last_occurence( int *p, int *q, int n ){
    while( q >= p ){
        if( *q == n ) return q;
        q--;
    }
    return NULL;
}
int main(){
    int A[ 10 ] = { 1, 2, 3, 8, 8, 1, 2, 8, 2, 8 };
    int *p, n = 8, count = 0;
    
    p = last_occurence( A, A+9, n );
    
    if( p ) printf( "index of last_occurence of %d is: %d.\n", n, p-A );
    else printf( "%d does not appear inside A.\n", n );
    
    // count number n inside a using this function
    while( p ){
        count++;
        p = last_occurence( A, p-1, n );
    }
    printf( "There are %d %d's in the array.\n", count, n );
    
}




// *****************************************************************************************
// 28.04.2021 - Wednesday
// write a function which returns the length of a string (strlen in string.h)
#include <stdio.h>
int string_length( char str[] ){
    int i;
    for( i = 0; str[ i ] != '\0'; i++ );
    // for( i = 0; str[ i ] != 0; i++ ); ... for( i = 0; str[ i ]; i++ );    
    /*
    i = 0;
    while( str[ i ] != '\0' ){
        i++;
    }
    */
    return i;
}
int main(){
    //char str[ 100 ] = { 'A', 'b' };
    char str[ 100 ] = "Abc0";
    //char str[ 100 ] = { 'A', 'b', 'c', '0' };
    //char str[ 100 ] = { 80, 50, 51, 40 };
    
    printf("The length of \"%s\" is: %d.\n", str, string_length( str ) );
}











// *****************************************************************************************
// 03.05.2021 - Monday
// Write a function which counts the words in a string
// Assume single spaces between words, no spaces in the beginning and at the end.
// Write another function without the above assumptions
#include <stdio.h>
int word_count_1( char str[] ){
    // the number of words = 1 + the number of spaces (if non-empty)
    int i, count = 0;
    if( str[ 0 ] == '\0' ) return 0;
    for( i = 1; str[ i ] != 0; i++ ) if( str[ i ] == ' ' ) count++;
    return 1 + count;
}
int word_count_2( char *p ){
    int count = 0;
    if( *p != 0 && *p != ' ' ) count++;
    p++;
    while( *p ){
        if( *p == ' ' && *(p+1) != ' ' && *(p+1) != 0 ) count++;
        p++;
    }
    return count;
    
    // each word (except the first word in a non-empty string not starting with a space)
    // will be preceded with a space char.
    // "aaa     bb    ccc   ddd     "  count should start with 1
    //         **    **    **
    
    // " aaa     bb    ccc   ddd     "
    //  **      **    **    **
    
    
    
}
int main(){
    char str[ 50 ] = "x     a  bbb    cc    ";
    printf( "# of words in \"%s\": %d.\n", str, word_count_1( str ) );
    printf( "# of words in substring \"%s\": %d.\n", &str[ 3 ], word_count_1( &str[ 3 ] ) );
    
    printf( "\n\nREsults with the second function: \n" );
    printf( "# of words in \"%s\": %d.\n", str, word_count_2( str ) );
    printf( "# of words in substring \"%s\": %d.\n", str + 3, word_count_2( str + 3 ) );
}

// Write a function which copies a string into another
// Write a function for partial copy (n characters)
#include <stdio.h>
// strcpy in string.h
void string_copy( char dest[], char source[] ){
    int i;
    for( i = 0; source[ i ]; i++ ) dest[ i ] = source[ i ];
    dest[ i ] = source[ i ]; // dest[ i ] = 0;
}
// strncpy in string.h
void string_n_copy( char *d, char *s, int n ){
    while( n-- && *s ) *d++ = *s++;
    
    /*
    while( n != 0 && *s != '\0' ){
       *d = *s;
       d++;
       s++;
       n--
    }
    */
}

int main(){
    char str1[ 50 ] = "123456 789";
    char str2[ 50 ] = "aaaa";
    
    printf( "Strings before copying...\n" );
    printf( "str1: \"%s\" str2: \"%s\" \n", str1, str2 );
    
    printf( "Strings after copying...\n" );
    string_copy( str2, str1 );
    printf( "str1: \"%s\" str2: \"%s\" \n", str1, str2 );
    
    printf( "Strings after partial copying...\n" );
    string_copy( str2, str1+5 );
    printf( "str1: \"%s\" str2: \"%s\" \n", str1, str2 );
    
    printf( "Strings after n-copy...\n" );
    string_n_copy( str2, str1, 3 );
    printf( "str1: \"%s\" str2: \"%s\" \n", str1, str2 );
    
    printf( "Strings after n-copy from str2 to str1\n" );
    string_n_copy( str1, str2, 10 );
    printf( "str1: \"%s\" str2: \"%s\" \n", str1, str2 );
    
    printf( "Strings after second n-copy from str2 to str1\n" );
    string_n_copy( str1 + 5, str2, 10 );
    str1[ 10 ] = 0;
    printf( "str1: \"%s\" str2: \"%s\" \n", str1, str2 );
}











// *****************************************************************************************
// 05.05.2021 - Wednesday
// Write a function which checks whether a string is palindromic (symmetric) or not
#include<stdio.h>
#include<string.h>
int is_palindromic( char *p ){
    char *q;
    for( q = p; *q; q++ ); q--; // not inside the loop - loop is empty
    while( q > p ){
        if( *p != *q ) return 0;
        p++; q--;
    }
    return 1;
    // abcdcba0
    //  p   q
}
int main(){
    char str[ 30 ] = "bbcdcb";
    char *p = str+1;
    int result = is_palindromic( p );
    printf( "The string %s has length %d and ", p, strlen( p ) );
    if( result ) printf( "is palindromic.\n" ); else printf( "is not palindromic.\n" );
}












// *****************************************************************************************
// 10.05.2021 - Monday

// string compare function - strcmp in string.n 
// return 0 is strings are same; a negative value if the first string 
// comes before the other in the dictionary; positive value otherwise
#include <stdio.h>
int string_compare( char *str1, char *str2 ){
    // "abc" - "abc"  return 0
    // "abc" - "abe"  return 'c' - 'e' ... return -2
    // "abc" - "abcd" return 0 - 'd'  ... return -4
    while( *str1 != 0 && *str2 != 0 ){
        if( *str1 != *str2 ) return *str1 - *str2;
        str1++; str2++;
    }
    if( *str1 || *str2 ) return *str1 - *str2;
    return 0;
}
int main(){
    char str1[ 20 ] = "abca";
    char str2[ 20 ] = "abc";
    int result = string_compare( str1, str2 );
    
    if( result == 0 ) printf( "The strings are same.\n" );
    else if( result < 0 ) printf( "str1 comes first.\n" );
    else printf( "str2 comes first.\n" );
    return 0;
}



// copy the words inside a sting to different strings (in an array of strings)
#include <stdio.h>
int main(){
    char str1[ 50 ] = "  aa   bb   abc   x";
    char words[ 20 ][ 50 ];
    int i = 0, j;
    char *p = str1, *q = words[ 0 ];
    
    while( p != '\0' ){
        while( *p == ' ' ) p++;
        if( *p == 0 ) break;
        while( *p != 0 && *p != ' ' ){
            *q = *p;
            p++; q++;
        }
        *q = 0; // to make sure the next char of each word is null
        i++;
        q = words[ i ];
    }
    // break brings you here
    
    for( j = 0; j < i; j++ ) printf( "%s\n", words[ j ] );
    
    return 0;
}
