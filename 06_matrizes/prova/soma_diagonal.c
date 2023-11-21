#include <stdio.h>

int main(){
    // Declaração de variáveis
    // n: dimensão da matriz
    // soma: acumulo dos valores da diagonal
    int n, soma = 0;

    // Leitura do tamanho da matriz
    scanf("%d", &n);

    // Declaração da matriz
    int matriz[n][n];

    // Leitura dos valores
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    // Varre a matriz e soma os valores da diagonal principal
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j){
                soma += matriz[i][j];
            }
        }
    }
    // Imprime o resultado
    printf("%d\n", soma);
    return 0;
}