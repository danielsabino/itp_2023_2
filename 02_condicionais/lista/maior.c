#include <stdio.h>

int main(){
    // a, b, c, d: números
    // maior: maior número
    int a, b, c, d;
    int maior;

    // Leitura da entrada
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Verificações
    if(a >= b && a >= c && a >= d){
        maior = a;
    }
    else if(b >= a && b >= c && b >= d){
        maior = b;
    }
    else if(c >= a && c >= b && c >= d){
        maior = c;
    }
    else if(d >= a && d >= b && d >= c){
        maior = d;
    }
    printf("Maior: %d\n", maior);
    return 0;
}