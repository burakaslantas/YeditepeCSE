/*  hmdhhdy:  /md    .mm- .mmhhhdy-    .dmmo    -mm` .yms        :mmm/    :hdddhs  omy       -mmm+    :mmd/   ym:.hhhmmdhhs   -mmm+    -ydddhs
    NMo`.yMm  +MM    .MM- -MM:`.hMm   `dMoNM:   :MM./mN+`       `mNoMN.   NMy.`.-  yMd      `dMoMN-   /MmNM+  dM/ ...NMs..`  `mMoMN-   mMh.`.-
    NMdsyNN+  +MM    .MM- -MMs+smm+   oMy +Mm.  :MMyMm.         hMo yMd`  +mNdy+.  yMd      sMs oMm`  /Md-mMo dM/    NMo     yMs sMd`  /mNmy+-
    NMs-:+MN/ +MM    .MM- -MMsodMy`  :MMo+oNMh  :MM/mMs`       +MNo+oMMs   `-+hMN: yMd     /MMo+oMMy  /Md -mMsdM/    NMo    /MMo+oMMs   `-+yMN/
    NMs--/NM+ -NMs--:yMd` -MM- `dMy `mMs++++NM+ :MM``yMd-     -NNo+++oMM:`o:--/MM/ yMm:::-.NMo+++oNM+ /Md  .dMMM/    NMo   .NMo+++oMM/`o:--/MM+
    yhyyyyo:   .ohhhhy+`  .hh.  .hh:/hs     /hy`-hh`  +hy.    oh+     ohs`oyhhhs:  +hhyyys+ho     +hy :hs   `shh-    yh/   oho     +hy`oyhhhs:  */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void print_array(int arr[], int size_of_arr)
{
    for(int i = 0; i < size_of_arr; i++)
    {
        printf("%d ", arr[i]);
    }
}

int frequency_of_number(int arr[], int size_of_arr, int number)
{
    int res = 0;
    for(int i = 0; i < size_of_arr; i++)
    {
        if (arr[i] == number) res++;
    }
    return res;
}

void find_highest_two_ints(int arr[], int size_of_arr)
{
    int first_highest_frequency = 0, second_highest_frequency = 0, first_frequented_int = -1, second_frequented_int = -1;
    for(int i = 0; i < size_of_arr; i++)
    {
        if (first_highest_frequency < arr[i])
        {
            second_highest_frequency = first_highest_frequency;
            second_frequented_int = first_frequented_int;
            first_highest_frequency = arr[i];
            first_frequented_int = i;
        }
        else if (second_highest_frequency < arr[i] && first_highest_frequency != arr[i])
        {
            second_highest_frequency = arr[i];
            second_frequented_int = i;
        }
    }
    printf("\nTwo integers with highest frequency: %d, %d", first_frequented_int, second_frequented_int);
}

int main()
{
    int random_ints[SIZE];
    int frequency_of_ints[10];
    for(int i = 0; i < SIZE; i++)
    {
        random_ints[i] = rand() % 10;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("\n%d has appeared %d times.", i, frequency_of_number(random_ints, SIZE, i));
        frequency_of_ints[i] = frequency_of_number(random_ints, SIZE, i);
    }
    find_highest_two_ints(frequency_of_ints, 10);
    printf("\n");
}
