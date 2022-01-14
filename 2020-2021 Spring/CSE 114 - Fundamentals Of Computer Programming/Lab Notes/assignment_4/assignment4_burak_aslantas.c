/*  hmdhhdy:  /md    .mm- .mmhhhdy-    .dmmo    -mm` .yms        :mmm/    :hdddhs  omy       -mmm+    :mmd/   ym:.hhhmmdhhs   -mmm+    -ydddhs
    NMo`.yMm  +MM    .MM- -MM:`.hMm   `dMoNM:   :MM./mN+`       `mNoMN.   NMy.`.-  yMd      `dMoMN-   /MmNM+  dM/ ...NMs..`  `mMoMN-   mMh.`.-
    NMdsyNN+  +MM    .MM- -MMs+smm+   oMy +Mm.  :MMyMm.         hMo yMd`  +mNdy+.  yMd      sMs oMm`  /Md-mMo dM/    NMo     yMs sMd`  /mNmy+-
    NMs-:+MN/ +MM    .MM- -MMsodMy`  :MMo+oNMh  :MM/mMs`       +MNo+oMMs   `-+hMN: yMd     /MMo+oMMy  /Md -mMsdM/    NMo    /MMo+oMMs   `-+yMN/
    NMs--/NM+ -NMs--:yMd` -MM- `dMy `mMs++++NM+ :MM``yMd-     -NNo+++oMM:`o:--/MM/ yMm:::-.NMo+++oNM+ /Md  .dMMM/    NMo   .NMo+++oMM/`o:--/MM+
    yhyyyyo:   .ohhhhy+`  .hh.  .hh:/hs     /hy`-hh`  +hy.    oh+     ohs`oyhhhs:  +hhyyys+ho     +hy :hs   `shh-    yh/   oho     +hy`oyhhhs:  */
#include <stdio.h>

int factorial(int n)
{
    int res = 1;
    for(int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
int power(int x, int y)
{
    int res = 1;
    for(int i = y; i >= 1; i--)
    {
        res *= x;
    }
    return res;
}
int combination(int n, int r)
{
    int res;
    res = factorial(n) / ( factorial(r) * factorial(n - r) );
    return res;
}

int main() {
    int n;
    double res = 0;
    printf("Enter n:");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        double numerator = 0, denominator = 0;
        for(int z = 1; z <= n-i; z++)
        {
            numerator += power(i, z);
        }
        for(int j = 1; j <= i; j++)
        {
            denominator += (double) ( power(j, n) * combination(n, j) ) / (double) (factorial(n));
        }
        res += numerator / denominator;
    }

    printf("result is:%.2f\n", res);
}