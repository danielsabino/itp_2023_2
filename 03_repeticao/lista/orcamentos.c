#include <stdio.h>

int main(){
    // qtd, valor: quantidade e valor de cada item lido
    // total_qtd, total_valor: quantidade e valor total
    int qtd, total_qtd = 0;
    float valor, total_valor = 0;

    // Leitura da entrada
    scanf("%d", &qtd);
    while(qtd != -1){
        scanf("%f", &valor);
        total_qtd += qtd;
        total_valor += qtd * valor;
        scanf("%d", &qtd);
    }
    printf("%d %.2f\n", total_qtd, total_valor);
    return 0;
}