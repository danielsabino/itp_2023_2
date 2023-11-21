#include <stdio.h>

void binario(int n){
    if(n / 2 > 0){
        binario(n/2);
    }
    printf("%d", n % 2);
}

int main(){
    // n: número de entrada
    int n;

    // Leitura da entrada
    scanf("%d", &n);

    binario(n);
    printf("\n");

    return 0;
}