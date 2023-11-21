#include<stdio.h>

int calc_mdc(int x, int y){
    int resto;
    
    resto = x % y;
    if(resto == 0){
        return y;
    }
    
    return calc_mdc(y, resto);
}

int calc_mmc(int x, int y){
    return (x * y) / calc_mdc(x, y);
}

void calc_mdc_mmc (int x, int y, int *mdc, int *mmc){
    *mmc = calc_mmc(x,y);
    *mdc = calc_mdc(x,y);
}

int main(void){
    int x, y, mdc, mmc;

    scanf("%d %d", &x, &y);
    calc_mdc_mmc(x, y, &mdc, &mmc);
    printf("MDC = %d, MMC = %d\n", mdc, mmc);
    return 0;
}