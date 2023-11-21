#include <stdio.h>

int main(){
    // Variáveis
    // combo: número do combo escolhido pelo cliente
    // dinheiro: quantidade de dinheiro dada pelo cliente
    // troco: troco a ser dado, quando for o caso
    int combo;
    float dinheiro, troco;

    // Leitura da entrada
    scanf("%d %f", &combo, &dinheiro);

    // Cálculo do troco de acordo com a escolha
    switch (combo)
    {
    case 1:
        troco = dinheiro - 12;
        break;
    case 2:
        troco = dinheiro - 23;
        break;
    case 3:
        troco = dinheiro - 31;
        break;
    case 4:
        troco = dinheiro - 28;
        break;
    case 5:
        troco = dinheiro - 15;
        break;
    default:
        break;
    }
    if(troco > 0){
        printf("Troco = %.0f reais\n", troco);
    }
    else if(troco == 0){
        printf("Deu certim!\n");
    }
    else{
        printf("Saldo insuficiente! Falta %.0f reais\n", troco * -1);
    }
    return 0;
}