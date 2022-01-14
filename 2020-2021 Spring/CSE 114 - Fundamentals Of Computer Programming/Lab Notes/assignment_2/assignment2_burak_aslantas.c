/*  hmdhhdy:  /md    .mm- .mmhhhdy-    .dmmo    -mm` .yms        :mmm/    :hdddhs  omy       -mmm+    :mmd/   ym:.hhhmmdhhs   -mmm+    -ydddhs
    NMo`.yMm  +MM    .MM- -MM:`.hMm   `dMoNM:   :MM./mN+`       `mNoMN.   NMy.`.-  yMd      `dMoMN-   /MmNM+  dM/ ...NMs..`  `mMoMN-   mMh.`.-
    NMdsyNN+  +MM    .MM- -MMs+smm+   oMy +Mm.  :MMyMm.         hMo yMd`  +mNdy+.  yMd      sMs oMm`  /Md-mMo dM/    NMo     yMs sMd`  /mNmy+-
    NMs-:+MN/ +MM    .MM- -MMsodMy`  :MMo+oNMh  :MM/mMs`       +MNo+oMMs   `-+hMN: yMd     /MMo+oMMy  /Md -mMsdM/    NMo    /MMo+oMMs   `-+yMN/
    NMs--/NM+ -NMs--:yMd` -MM- `dMy `mMs++++NM+ :MM``yMd-     -NNo+++oMM:`o:--/MM/ yMm:::-.NMo+++oNM+ /Md  .dMMM/    NMo   .NMo+++oMM/`o:--/MM+
    yhyyyyo:   .ohhhhy+`  .hh.  .hh:/hs     /hy`-hh`  +hy.    oh+     ohs`oyhhhs:  +hhyyys+ho     +hy :hs   `shh-    yh/   oho     +hy`oyhhhs:  */

#include <stdio.h>
double streaming_a(int);
double streaming_n(int);
double streaming_h(int);

int main(){
    int number_of_devices;
    char streaming_service_type;
    double result;

    printf("Enter number of devices and streaming service: ");
    scanf("%d %c", &number_of_devices, &streaming_service_type);

    if (streaming_service_type == 'A'){
        result = streaming_a(number_of_devices);
    }
    else if (streaming_service_type == 'N'){
        result = streaming_n(number_of_devices);
    }
    else{
        result = streaming_h(number_of_devices);
    }
    printf("yearly membership cost for %c: %.2lf$\n", streaming_service_type, result);
    return 0;
}

//Amazon Prime service cost yearly
double streaming_a(int number_of_devices){
    double service_costs_monthly;

    if (number_of_devices <= 2){
        service_costs_monthly = 7.99;
    }
    else{
        service_costs_monthly = 12.99;
    }
    return (12 * service_costs_monthly);
}

//Netflix service cost yearly
double streaming_n(int number_of_devices){
    double service_costs_monthly;

    if (number_of_devices <= 3){
        service_costs_monthly = 12.99;
    }
    else if ((4 <= number_of_devices) && (number_of_devices < 7)){
        service_costs_monthly = 14.99;
    }
    else{
        service_costs_monthly = 24.99;
    }
    return (12 * service_costs_monthly);
}

//HBO service cost yearly
double streaming_h(int number_of_devices){
    double service_costs_monthly;

    if (number_of_devices <= 4){
        service_costs_monthly = 14.99;
    }
    else if ((5 <= number_of_devices) && (number_of_devices < 10)){
        service_costs_monthly = 24.99;
    }
    else{
        service_costs_monthly = 34.99;
    }
    return (12 * service_costs_monthly);
}