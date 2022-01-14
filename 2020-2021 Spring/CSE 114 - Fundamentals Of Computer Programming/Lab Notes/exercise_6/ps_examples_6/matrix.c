#include	<stdio.h>
#define	MSIZE	3

/*  In memory representation

matrix [0][0]
matrix [0][1]
matrix [0][2]
matrix [1][0]
matrix [1][1]
matrix [1][2]
matrix [2][0]
matrix [2][1]
matrix [2][2]
*/


void printMatrix(int matrix[MSIZE][MSIZE])
{
	int i,j;
	for(i=0; i<MSIZE; i++)
	{
		for(j=0; j<MSIZE; j++)
		{
			printf("%d ", *(*(matrix + i)+j) ); 
		}
		printf("\n");
	}
	printf("\n");
}
int	main()
{
	int matrix[MSIZE][MSIZE] = {
	     {1,2,3}, // matrix [0][0] matrix [0][1] matrix [0][2] 
		{4,5,6},  // matrix [1][0] matrix [1][1] matrix [1][2] 
		{7,8,9}   // matrix [2][0] matrix [2][1] matrix [2][2] 
	};
	printMatrix(matrix);
}
