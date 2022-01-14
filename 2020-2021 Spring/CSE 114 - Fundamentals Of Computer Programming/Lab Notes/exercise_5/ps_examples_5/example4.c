#include <stdio.h>
#define MSIZE 2

void  print(int arr[], int size)
{
    int i;
	for(i=0; i<size ; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int countN(int arr[],int size, int n)
{
	int i,count=0;
	for(i=0; i<size ; i++)
		if(arr[i] == n)
			count++;
	return count;
}
 
void maxRepeated(int arr[],int size)
{
	int i,count,maxCount=-1,maxRepNumber=-1;
	for(i=0; i<size ; i++)
	{
		count = countN(arr,size,arr[i]);
		if(count > maxCount ){
			maxCount = count;
			maxRepNumber = arr[i];
		}
	}
	printf("maximum repeted number is %d and it is repeated %d times\n",maxRepNumber,maxCount);
}


int main()
{
	int arr[]={3,1,3,5,3,1,3,3};


	maxRepeated(arr,8);

}
