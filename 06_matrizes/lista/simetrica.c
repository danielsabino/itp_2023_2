#include <stdio.h>

int main(){
    // Variáveis
    // n, m: altura e largura da matriz
    // simetrica: indica se a matriz é simétrica ou não
    int n, m;
    int simetrica = 1;

    // Faz a leitura do tamanho da matriz
    scanf("%d %d", &n, &m);

    // Declara a matriz
    int matriz[n][m];

    // Leitura da matriz
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &matriz[i][j]);            
        }
    }

    // Verifica se é simétrica
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // Se pelo um elemento for diferente, a matriz já não é simétrica
            if(matriz[i][j] != matriz[j][i]){
                simetrica = 0;
                break;
            }
        }
    }
    if(simetrica){
        printf("Matriz Simétrica\n");
    }
    else{
        printf("Matriz não Simétrica\n");
    }
    return 0;
}