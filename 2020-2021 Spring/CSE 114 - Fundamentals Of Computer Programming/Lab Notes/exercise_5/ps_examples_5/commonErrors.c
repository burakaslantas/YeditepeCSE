#include <stdio.h>
#define MSIZE 2

int sum_arr(int arr[], int size)
{
	int i,sum=0;
	for(i=0; i<size; i++)
	{
		sum+=arr[i];
	}
	return sum;
}

/*
	show that this line will give an error

	because in c, if you deal with multidimensional arrays
	you have to give size of all dimensions except the first
	otherwise you have to use pointers but you do not know it yet.
*/
//int sum_matrix(int matrix[][]) //wrong
//int sum_matrix(int matrix[MSIZE][MSIZE]) //correct
int sum_matrix(int matrix[][MSIZE]) //correct
{
	int i,j,sum=0;
	for(i=0; i<MSIZE; i++)
	{
		for(j=0; j<MSIZE; j++)
		{
			sum+=matrix[i][j];
		}
	}
	return sum;
}
/*
	in c, if you deal with multidimensional arrays
	you have to give size of all dimensions except the first
	otherwise you have to use pointers but you do not know it yet.
*/
int main()
{
	int arr[]={1,4,5}; // the size will be automaticly	3
	//int arr2[]; // this line give an error. You have to either define size or give the input

	int result = sum_arr(arr,3);
	//result = sum_arr(int arr,3); //wrong
	//result = sum_arr(int arr[],3); // wrong
	//result = sum_arr(int arr[3],3); // wrong
	//result = sum_arr(arr[0],3); // you send the first element of the array so wrong
	printf("%d\n",result);

	int matrix[][2]={{1,1},{1,1}}; // correct
	//int matrix[2][2]={{1,1},{1,1}}; // correct
	//int matrix[][]={{1,1},{1,1}}; // wrong, you have to give size of all dimensions except the first


	result = sum_matrix(matrix);
	//result = sum_matrix(int matrix);//wrong
	//result = sum_matrix(matrix[0][0]);//wrong
	printf("%d\n",result);
}
