#include <stdio.h>



void printLetter(int grade )
{
  if(grade > 90)
    printf("AA\n");
  else if(grade > 85)
    printf("BA\n");
  else if (grade > 80)
    printf("BB\n");
  else if (grade > 70)
    printf("CB\n");
  else if (grade > 60)
    printf("CC\n");
  else if (grade > 50)
      printf("DC\n");
  else if (grade > 40)
    printf("DD\n");
  else
    printf("FF\n");
}


void printLetter2(int grade )
{
  if(grade > 90)
    printf("AA\n");
  if(grade > 85)
    printf("BA\n");
  if (grade > 80)
    printf("BB\n");
  if (grade > 70)
    printf("CB\n");
  if (grade > 60)
    printf("CC\n");
  if (grade > 50)
      printf("DC\n");
  if (grade > 40)
    printf("DD\n");
  else
    printf("FF\n");
}



int main(int argc, char const *argv[]) {

  int grade;
  printf("what is your grade (try 95): ");
  scanf("%d",&grade);
  printf("testing printLetter:\n");
  printLetter(grade);
  printf("testing printLetter2:\n");
  printLetter2(grade);

  return 0;
}
