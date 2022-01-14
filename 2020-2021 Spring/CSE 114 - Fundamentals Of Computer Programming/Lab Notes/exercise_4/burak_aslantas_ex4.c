/*  hmdhhdy:  /md    .mm- .mmhhhdy-    .dmmo    -mm` .yms        :mmm/    :hdddhs  omy       -mmm+    :mmd/   ym:.hhhmmdhhs   -mmm+    -ydddhs
    NMo`.yMm  +MM    .MM- -MM:`.hMm   `dMoNM:   :MM./mN+`       `mNoMN.   NMy.`.-  yMd      `dMoMN-   /MmNM+  dM/ ...NMs..`  `mMoMN-   mMh.`.-
    NMdsyNN+  +MM    .MM- -MMs+smm+   oMy +Mm.  :MMyMm.         hMo yMd`  +mNdy+.  yMd      sMs oMm`  /Md-mMo dM/    NMo     yMs sMd`  /mNmy+-
    NMs-:+MN/ +MM    .MM- -MMsodMy`  :MMo+oNMh  :MM/mMs`       +MNo+oMMs   `-+hMN: yMd     /MMo+oMMy  /Md -mMsdM/    NMo    /MMo+oMMs   `-+yMN/
    NMs--/NM+ -NMs--:yMd` -MM- `dMy `mMs++++NM+ :MM``yMd-     -NNo+++oMM:`o:--/MM/ yMm:::-.NMo+++oNM+ /Md  .dMMM/    NMo   .NMo+++oMM/`o:--/MM+
    yhyyyyo:   .ohhhhy+`  .hh.  .hh:/hs     /hy`-hh`  +hy.    oh+     ohs`oyhhhs:  +hhyyys+ho     +hy :hs   `shh-    yh/   oho     +hy`oyhhhs:  */
#include <stdio.h>

int power_of_two(int num)
{
    int res = 1;

    for (int i = 0; i < num; i++)
    {
        res *= 2;
    }

    return res;
}

int make_greater_sign(int num)
{
    for (int a = 0; a < num; a++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("  ");
        }

        printf("%d %d\n", power_of_two(a), power_of_two(a));
    }
    for (int b = num-1; b > 0; b--)
    {
        for (int j = b-1; j > 0; j--)
        {
            printf("  ");
        }
        printf("%d %d\n", power_of_two(b-1), power_of_two(b-1));
    }
}

int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    make_greater_sign(num);
}
