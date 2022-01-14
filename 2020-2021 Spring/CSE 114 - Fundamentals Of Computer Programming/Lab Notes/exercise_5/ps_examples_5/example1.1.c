#include <stdio.h>
#define MSIZE 2

void increase(int arr[], int size)
{
    int i,sum=0;
    for(i=0; i<size; i++)
    {
      arr[i] = arr[i] + 1;
    }
}
 
void print_arr(int arr[], int size)
{
    int i,sum=0;
    for(i=0; i<size; i++)
    {
      printf("%d ",arr[i]);
    }
    printf("\n");
}
/* this example is to show that array is passed by referance to functions.
   as it is seen from the result. In increase function, values in the array changes.
   This affects the array in the main function where the function called.
   this is important because normally it is different in the non-array variables like int, float etc.
*/
int main()
{
  int arr[]={1,2,3};
  print_arr(arr,3);
  increase(arr,3);
  print_arr(arr,3);

}
