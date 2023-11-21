#include <stdio.h>

int main(){
    char letra;
    int qtd;
    float indice;

    scanf("%c %d %f", &letra, &qtd, &indice);
    printf("A popularidade de %c é %.1f\n", letra, qtd*indice);
    return 0;
}