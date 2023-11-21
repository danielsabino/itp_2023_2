#include <stdio.h>

// Implementa a soma das linha e coluna centrais 
int somaLinhaMatrizMeio(int m, int n, int matriz[m][n]){
    // Variáveis
    // lc, cc: linha central e coluna central
    // soma: guarda a soma dos valores
    int lc, cc;
    int soma = 0;

    // Divisão inteira para pegar o elemento central
    lc = m / 2;
    cc = n / 2;

    // Percorre a matriz e soma somente os elementos corretos
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i == lc || j == cc){
                soma += matriz[i][j];
            }
            if(i == lc && j == cc){
                soma += matriz[i][j];
            }
        }
    }

    // Retorna o valor da soma
    return soma;
}

int main(){
    // Variáveis
    // m, n: número de linhas e colunas da matriz
    // soma: valor da soma das linha e coluna centrais
    int m, n, soma;

    // Leitura do tamanho da matriz
    scanf("%d %d", &m, &n);

    // Declaração da matriz
    int matriz[m][n];

    // Leitura da matriz
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    // Chama a função que calcula a soma
    soma = somaLinhaMatrizMeio(m, n, matriz);

    // Imprime o resultado
    printf("%d\n", soma);
    return 0;
}