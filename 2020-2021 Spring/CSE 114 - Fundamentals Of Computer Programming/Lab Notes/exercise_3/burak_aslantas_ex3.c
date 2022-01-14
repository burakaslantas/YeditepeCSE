/*  hmdhhdy:  /md    .mm- .mmhhhdy-    .dmmo    -mm` .yms        :mmm/    :hdddhs  omy       -mmm+    :mmd/   ym:.hhhmmdhhs   -mmm+    -ydddhs
    NMo`.yMm  +MM    .MM- -MM:`.hMm   `dMoNM:   :MM./mN+`       `mNoMN.   NMy.`.-  yMd      `dMoMN-   /MmNM+  dM/ ...NMs..`  `mMoMN-   mMh.`.-
    NMdsyNN+  +MM    .MM- -MMs+smm+   oMy +Mm.  :MMyMm.         hMo yMd`  +mNdy+.  yMd      sMs oMm`  /Md-mMo dM/    NMo     yMs sMd`  /mNmy+-
    NMs-:+MN/ +MM    .MM- -MMsodMy`  :MMo+oNMh  :MM/mMs`       +MNo+oMMs   `-+hMN: yMd     /MMo+oMMy  /Md -mMsdM/    NMo    /MMo+oMMs   `-+yMN/
    NMs--/NM+ -NMs--:yMd` -MM- `dMy `mMs++++NM+ :MM``yMd-     -NNo+++oMM:`o:--/MM/ yMm:::-.NMo+++oNM+ /Md  .dMMM/    NMo   .NMo+++oMM/`o:--/MM+
    yhyyyyo:   .ohhhhy+`  .hh.  .hh:/hs     /hy`-hh`  +hy.    oh+     ohs`oyhhhs:  +hhyyys+ho     +hy :hs   `shh-    yh/   oho     +hy`oyhhhs:  */

#include <stdio.h>

int main()
{
    int n, a, even_counter=0, closest=0;

    printf("Enter a positive integer\n");
    scanf("%d", &n);
    printf("n=%d\n", n);

    while(even_counter < n)
    {
        printf("Enter an integer\n");
        scanf(" %d", &a);

        if ((a > 100) && (closest == 0 || a < closest))
        {
            closest = a;
        }
        if (a % 2 == 0)
        {
            even_counter += 1;
        }
    }
    printf("The closest number to 100 is %d\n", closest);
}