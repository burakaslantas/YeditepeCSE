#include<stdio.h>



int main()
{
  int number;
  printf("enter a number: ");
  scanf("%d",&number);


  if( number%2==0 && (number>100 || number<40))
    printf("valid\n");
  else
    printf("invalid\n");


}
