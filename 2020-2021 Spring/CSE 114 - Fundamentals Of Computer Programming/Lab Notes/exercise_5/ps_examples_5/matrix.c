#include	<stdio.h>
#define	MSIZE	3

int	isSymmetric(int	matrix[MSIZE][MSIZE])
{
	int	i,j;
	for(i=0;	i<MSIZE;	i++)
	{
		for(j=0;	j<MSIZE;	j++)
		{
			if(matrix[i][j]	!=	matrix[j][i])
				return	0;
		}
	}
	return	1;
}

 
void printMatrix(int	matrix[MSIZE][MSIZE])
{
	int i,j;
	for(i=0; i<MSIZE; i++)
	{
		for(j=0; j<MSIZE; j++)
		{
			printf("%d ",matrix[1][0]); 
		}
		printf("\n");
	}
	printf("\n");
}
int	main()
{
	int matrix[MSIZE][MSIZE] = {
	     {1,0,0}, // matrix [0][0] matrix [0][1] matrix [0][2] 
		{0,1,0},  // matrix [1][0] matrix [1][1] matrix [1][2] 
		{0,0,1}   // matrix [2][0] matrix [2][1] matrix [2][2] 
	};
	printMatrix(matrix);
	printf("is isSymmetric: %d\n",isSymmetric(matrix));
}
