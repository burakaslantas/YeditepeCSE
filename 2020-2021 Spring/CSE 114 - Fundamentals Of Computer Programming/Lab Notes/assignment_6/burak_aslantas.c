/*  hmdhhdy:  /md    .mm- .mmhhhdy-    .dmmo    -mm` .yms        :mmm/    :hdddhs  omy       -mmm+    :mmd/   ym:.hhhmmdhhs   -mmm+    -ydddhs
    NMo`.yMm  +MM    .MM- -MM:`.hMm   `dMoNM:   :MM./mN+`       `mNoMN.   NMy.`.-  yMd      `dMoMN-   /MmNM+  dM/ ...NMs..`  `mMoMN-   mMh.`.-
    NMdsyNN+  +MM    .MM- -MMs+smm+   oMy +Mm.  :MMyMm.         hMo yMd`  +mNdy+.  yMd      sMs oMm`  /Md-mMo dM/    NMo     yMs sMd`  /mNmy+-
    NMs-:+MN/ +MM    .MM- -MMsodMy`  :MMo+oNMh  :MM/mMs`       +MNo+oMMs   `-+hMN: yMd     /MMo+oMMy  /Md -mMsdM/    NMo    /MMo+oMMs   `-+yMN/
    NMs--/NM+ -NMs--:yMd` -MM- `dMy `mMs++++NM+ :MM``yMd-     -NNo+++oMM:`o:--/MM/ yMm:::-.NMo+++oNM+ /Md  .dMMM/    NMo   .NMo+++oMM/`o:--/MM+
    yhyyyyo:   .ohhhhy+`  .hh.  .hh:/hs     /hy`-hh`  +hy.    oh+     ohs`oyhhhs:  +hhyyys+ho     +hy :hs   `shh-    yh/   oho     +hy`oyhhhs:  */
#include <stdio.h>
#include <stdlib.h>
#define MATRIX_ROW_SIZE 10
#define MATRIX_COLUMN_SIZE 10
#define SEARCHED_ARRAY_SIZE 2

void fill_table(int table[MATRIX_ROW_SIZE][MATRIX_COLUMN_SIZE])
{
    //This function is responsible for filling the table.
    //The last element of the must be equal to 0.
    for(int i = 0; i < MATRIX_ROW_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_COLUMN_SIZE; j++)
        {
            *(*(table + i) + j) = rand() % 9 + 1;
            if(i==9 && j==9)
            {
                *(*(table + i) + j) = 0;
            }
        }
    }
}

void print_table(int table[MATRIX_ROW_SIZE][MATRIX_COLUMN_SIZE])
{
    //This function is responsible for printing all integers in the table.
    for(int i = 0; i < MATRIX_ROW_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_COLUMN_SIZE; j++)
        {
            printf("%d ", *(*(table + i) + j));
        }
        printf("\n");
    }
}

void reverse(int * array1, int position, int *array2, int len2)
{
    for(int i = 0; i < len2; i++)
    {
        *(array1 + position + i) = *(array2 + len2 - 1 - i);
    }
}

int find_and_replace_array(int *array1, int *array2, int len1, int len2)
{
    //This function finds all occurrences of array2 in the array1 and
    //calls the reverse function with appropriate parameters for them to be reversed.
    int counter = 0;
    for(int i = 0; i <= len1 - len2; i++)
    {
        int same_flag = 1;
        for(int j = 0; j < len2; j++)
        {
            if(*(array1 + j + i) != *(array2 + j))
            {
                same_flag = 0;
            }
        }
        if(same_flag == 1)
        {
            reverse(array1, i, array2, len2);
            i += len2 - 1;
            counter++;
        }
    }
    return counter;
}

void find_and_replace_table(int table[MATRIX_ROW_SIZE][MATRIX_COLUMN_SIZE], int *array, int len1, int len2)
{
    //This function reverses all occurrences of the array in all integers available
    //in the table by calling appropriate functions.
    int total = 0;

    for(int i = 0; i < len1; i++)
    {
        total += find_and_replace_array(*(table+i), array, len1, len2);
    }
    printf("%d times occurrence found.\n", total);
}

int main()
{
    int table[MATRIX_ROW_SIZE][MATRIX_COLUMN_SIZE], searched_array[SEARCHED_ARRAY_SIZE] = {7, 9}, *ptr_searched_array = searched_array;
    printf("Before:\n");
    fill_table(table);
    print_table(table);

    printf("\n\n");
    printf("Find the below array in the table and reverse it.\n");

    for(int i = 0; i < SEARCHED_ARRAY_SIZE; i++)
    {
        printf("%d ", *ptr_searched_array);
        ptr_searched_array++;
    }
    ptr_searched_array -= SEARCHED_ARRAY_SIZE;

    printf("\n\n");
    printf("After:\n");
    find_and_replace_table(table, ptr_searched_array, MATRIX_COLUMN_SIZE, SEARCHED_ARRAY_SIZE);
    print_table(table);
}
