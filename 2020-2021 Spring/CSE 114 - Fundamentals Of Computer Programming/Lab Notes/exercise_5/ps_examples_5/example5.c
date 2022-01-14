
// C program to generate random numbers 
#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    // This program will create same sequence of  
    // random numbers on every program run  
  
    for(int i = 0; i<5; i++) 
        printf(" %d ", rand()%10); 
    return 0; 
} 
 