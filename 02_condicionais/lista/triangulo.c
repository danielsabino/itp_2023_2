#include <stdio.h>

int main(){
    // a, b, c: lados do triângulo
    int a, b, c;

    // Leitura da entrada
    scanf("%d %d %d", &a, &b, &c);

    // Verificações
    if(a < b + c && b < a + c && c < a + b){
        printf("possivel\n");
    }
    else{
        printf("impossivel\n");
    }
    return 0;
}