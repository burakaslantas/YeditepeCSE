// Program to take 5 values from the user and store them in an array
// Print the elements stored in the array
#include <stdio.h>


void print_array(int arr[], int size)
{

  for(int i=0; i<size; i++)
  {
  	printf("%d\n", arr[i]);
  }


}

int main() {
  
  int our_array[5];

  /*
  our_array[0] = 1;
  our_array[1] = 2;
	*/

  printf("enter 5 integers:");

  for(int i=0; i<5; i++)
  {
  	scanf("%d", &our_array[i]);
  }


  printf("displaying integer of our_array\n");

  print_array(our_array, 5);

}