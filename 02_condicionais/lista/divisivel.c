#include <stdio.h>

int main(){
    // a, b: valores de entrada
    int a,b;

    // Leitura da entrada
    scanf("%d %d", &a, &b);
    if(a % b == 0){
        printf("Resultado: %d\n", a / b);
    }
    return 0;
}