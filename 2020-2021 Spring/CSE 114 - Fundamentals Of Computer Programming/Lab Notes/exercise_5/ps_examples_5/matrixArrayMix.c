#include	<stdio.h>
#define	MSIZE	3

void	printMatrix(int	matrix[MSIZE][MSIZE])
{
			int i,j;
	    for(i=0; i<MSIZE; i++)
	    {
	      for(j=0; j<MSIZE; j++)
	      {
	        printf("%d ",matrix[i][j]);
	      }
				printf("\n");
	    }
			printf("\n");
}

 
/*
	return the row index if it is same with the arr
	return -1 otherwise
*/
int	findRow(int	matrix[MSIZE][MSIZE], int arr[MSIZE])
{
		int	i,j,flag;
		for(i=0;	i<MSIZE;	i++)
		{
			flag = 1;
			for(j=0;	j	<	MSIZE;	j++)
			{
				if(matrix[i][j]	!= arr[j])
					flag = 0;
			}
			if(flag == 1)
				return i;
		}
		return -1;
}



int	main()
{
		int matrix[MSIZE][MSIZE] = {
	      {1,0,0},
				{0,1,0},
				{0,0,1}
		};
		int arr1[]={0,1,0};
		int arr2[]={2,1,0};

		printf("The row is : %d\n",findRow(matrix,arr1));
		printf("The row is : %d\n",findRow(matrix,arr2));
}
