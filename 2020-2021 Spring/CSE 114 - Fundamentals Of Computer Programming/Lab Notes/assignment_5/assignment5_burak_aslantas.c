/*  hmdhhdy:  /md    .mm- .mmhhhdy-    .dmmo    -mm` .yms        :mmm/    :hdddhs  omy       -mmm+    :mmd/   ym:.hhhmmdhhs   -mmm+    -ydddhs
    NMo`.yMm  +MM    .MM- -MM:`.hMm   `dMoNM:   :MM./mN+`       `mNoMN.   NMy.`.-  yMd      `dMoMN-   /MmNM+  dM/ ...NMs..`  `mMoMN-   mMh.`.-
    NMdsyNN+  +MM    .MM- -MMs+smm+   oMy +Mm.  :MMyMm.         hMo yMd`  +mNdy+.  yMd      sMs oMm`  /Md-mMo dM/    NMo     yMs sMd`  /mNmy+-
    NMs-:+MN/ +MM    .MM- -MMsodMy`  :MMo+oNMh  :MM/mMs`       +MNo+oMMs   `-+hMN: yMd     /MMo+oMMy  /Md -mMsdM/    NMo    /MMo+oMMs   `-+yMN/
    NMs--/NM+ -NMs--:yMd` -MM- `dMy `mMs++++NM+ :MM``yMd-     -NNo+++oMM:`o:--/MM/ yMm:::-.NMo+++oNM+ /Md  .dMMM/    NMo   .NMo+++oMM/`o:--/MM+
    yhyyyyo:   .ohhhhy+`  .hh.  .hh:/hs     /hy`-hh`  +hy.    oh+     ohs`oyhhhs:  +hhyyys+ho     +hy :hs   `shh-    yh/   oho     +hy`oyhhhs:  */
#include <stdio.h>
#include <stdlib.h>
#define COLUMNS 5

void print_matrix(int matrix[][COLUMNS], int rows)
{
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < COLUMNS; column++)
        {
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_array(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int find_path(int source_matrix[][COLUMNS], int destination_array[], int number_of_rows_in_the_source_matrix)
{
    int sum = 0, row = 0, column = 0;

    for(int i = 0; i < number_of_rows_in_the_source_matrix + COLUMNS - 1 ; i++)
    {
        int current_value = source_matrix[row][column];
        sum += current_value;
        destination_array[i] = current_value;

        if(column == COLUMNS-1)
        {
            row++;
        }
        else if(source_matrix[row+1][column] > source_matrix[row][column+1])
        {
            row++;
        }
        else if(source_matrix[row+1][column] < source_matrix[row][column+1])
        {
            column++;
        }
    }
    return sum;
}

int main()
{
    int sum, columns = 5, rows = 9 + 5, source_matrix[rows][columns], destination_array[rows + columns - 1];

    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            source_matrix[row][column] = rand() % 99 + 1;
        }
    }

    print_matrix(source_matrix, rows);
    sum = find_path(source_matrix, destination_array, rows);
    print_array(destination_array, rows + columns - 1);
    printf("Sum of the numbers in the path is %d\n", sum);
}

