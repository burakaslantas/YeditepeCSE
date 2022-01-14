/*  hmdhhdy:  /md    .mm- .mmhhhdy-    .dmmo    -mm` .yms        :mmm/    :hdddhs  omy       -mmm+    :mmd/   ym:.hhhmmdhhs   -mmm+    -ydddhs
    NMo`.yMm  +MM    .MM- -MM:`.hMm   `dMoNM:   :MM./mN+`       `mNoMN.   NMy.`.-  yMd      `dMoMN-   /MmNM+  dM/ ...NMs..`  `mMoMN-   mMh.`.-
    NMdsyNN+  +MM    .MM- -MMs+smm+   oMy +Mm.  :MMyMm.         hMo yMd`  +mNdy+.  yMd      sMs oMm`  /Md-mMo dM/    NMo     yMs sMd`  /mNmy+-
    NMs-:+MN/ +MM    .MM- -MMsodMy`  :MMo+oNMh  :MM/mMs`       +MNo+oMMs   `-+hMN: yMd     /MMo+oMMy  /Md -mMsdM/    NMo    /MMo+oMMs   `-+yMN/
    NMs--/NM+ -NMs--:yMd` -MM- `dMy `mMs++++NM+ :MM``yMd-     -NNo+++oMM:`o:--/MM/ yMm:::-.NMo+++oNM+ /Md  .dMMM/    NMo   .NMo+++oMM/`o:--/MM+
    yhyyyyo:   .ohhhhy+`  .hh.  .hh:/hs     /hy`-hh`  +hy.    oh+     ohs`oyhhhs:  +hhyyys+ho     +hy :hs   `shh-    yh/   oho     +hy`oyhhhs:  */
#include <stdio.h>

void printRoman(int num)
{
    while(num > 0)
    {
        if (num >= 50)
        {
            printf("L");
            num -= 50;
        }
        else if(num >= 40)
        {
            printf("X");
            num += 10;
        }
        else if(num >= 10)
        {
            printf("X");
            num -= 10;
        }
        else if(num >= 9)
        {
            printf("I");
            num += 1;
        }
        else if(num >= 5)
        {
            printf("V");
            num -= 5;
        }
        else if(num >= 4)
        {
            printf("I");
            num += 1;
        }
        else
        {
            printf("I");
            num -= 1;
        }
    }
}

int main()
{
    int input_num;

    while (1)
    {
        printf("Enter a number between 1 and 89, Enter 0 to quit:\n");
        scanf(" %d", &input_num);

        if(input_num == 0){
            printf("Goodbye!");
            break;
        }
        if (input_num < 0 || input_num > 89){
            printf("Invalid number!\n");
            continue;
        }

        printRoman(input_num);
        printf("\n");
    }
}