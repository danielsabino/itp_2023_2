#include <stdio.h>

int main()
{
    // Variáveis
    // n, m: tamanho da matriz
    // opcao: escolha do usuário para linha/coluna
    // coord: linha ou coluna para verificar o maior elemento
    // maior: guarda o maior elemento
    int n, m;
    char opcao;
    int coord, maior;

    // Lê o tamanho da matriz
    scanf("%d %d", &n, &m);

    // Declara a matriz
    int matriz[n][m];

    // Lê a matriz
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    // Lê a opção e a linha/coluna para char o maior
    scanf(" %c %d", &opcao, &coord);

    if(opcao == 'l'){
        for(int i=0;i<m;i++){
            // O maior valor começa sempre com o primeiro elemento
            if(i == 0){
                maior = matriz[coord][i];
            }
            else{
                if(matriz[coord][i] > maior){
                    maior = matriz[coord][i];
                }
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            // O maior valor começa sempre com o primeiro elemento
            if(i == 0){
                maior = matriz[i][coord];
            }
            else{
                if(matriz[i][coord] > maior){
                    maior = matriz[i][coord];
                }
            }
        }
    }

    // Imprime saída
    printf("%d\n", maior);

    return 0;
}