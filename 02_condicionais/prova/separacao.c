#include <stdio.h>

int main(){
    // Variáveis
    // n: número de entrada
    int n;

    // Leitura da entrada
    scanf("%d", &n);

    if(n / 100000 > 0){
        printf("%d\n", n/100000);
        n %= 10000;
    }
    if(n / 10000 > 0){
        printf("%d\n", n/10000);
        n %= 10000;
    }
    if(n / 1000 > 0){
        printf("%d\n", n/1000);
        n %= 1000;
    }
    if(n / 100 > 0){
        printf("%d\n", n/100);
        n %= 100;
    }
    if(n / 10 > 0){
        printf("%d\n", n/10);
        n %= 10;
    }
    if(n > 0){
        printf("%d\n", n);
    }
    return 0;
}