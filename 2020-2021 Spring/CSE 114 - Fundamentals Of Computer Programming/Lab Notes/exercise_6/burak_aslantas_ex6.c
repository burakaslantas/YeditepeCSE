/*  hmdhhdy:  /md    .mm- .mmhhhdy-    .dmmo    -mm` .yms        :mmm/    :hdddhs  omy       -mmm+    :mmd/   ym:.hhhmmdhhs   -mmm+    -ydddhs
    NMo`.yMm  +MM    .MM- -MM:`.hMm   `dMoNM:   :MM./mN+`       `mNoMN.   NMy.`.-  yMd      `dMoMN-   /MmNM+  dM/ ...NMs..`  `mMoMN-   mMh.`.-
    NMdsyNN+  +MM    .MM- -MMs+smm+   oMy +Mm.  :MMyMm.         hMo yMd`  +mNdy+.  yMd      sMs oMm`  /Md-mMo dM/    NMo     yMs sMd`  /mNmy+-
    NMs-:+MN/ +MM    .MM- -MMsodMy`  :MMo+oNMh  :MM/mMs`       +MNo+oMMs   `-+hMN: yMd     /MMo+oMMy  /Md -mMsdM/    NMo    /MMo+oMMs   `-+yMN/
    NMs--/NM+ -NMs--:yMd` -MM- `dMy `mMs++++NM+ :MM``yMd-     -NNo+++oMM:`o:--/MM/ yMm:::-.NMo+++oNM+ /Md  .dMMM/    NMo   .NMo+++oMM/`o:--/MM+
    yhyyyyo:   .ohhhhy+`  .hh.  .hh:/hs     /hy`-hh`  +hy.    oh+     ohs`oyhhhs:  +hhyyys+ho     +hy :hs   `shh-    yh/   oho     +hy`oyhhhs:  */
#include <stdio.h>

int array_existance(int *start1, int *start2, int size1, int size2)
{
    int res = 0;
    for(int i = 0; i < size1; i++)
    {
        for(int j = 0; j < size2; j++)
        {
            if(*(start1 + i) == *(start2 + j))
            {
                res++;
            }
        }
    }
    /*
    while(start1 < start1 + size1)
    {
        if(*start1 == *start2)
        {
            start1++;
            start2++;
            if(*start2 == 3)
            {
                res++;
            }
        }
        else if(*start1 != *start2)
        {
            start1++;
        }
    }*/
    return res / size2;
}


int main()
{
    int array_1[9] = {2, 3, 1, 5, 7, 1, 2, 3, 7};
    int array_2[2] = {2, 3};
    //int *start_array_1 = array_1, *start_array_2 = array_2;
    int res = array_existance(array_1, array_2, 9, 2);

    printf("Result: %d", res);
}
