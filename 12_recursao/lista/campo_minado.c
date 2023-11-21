#include <stdio.h>

void imprime(int l, int c, int m[l][c]){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    // m, n: temanho do campo minado
    // b: número de bombas no campo
    int m, n, b;

    // Leitura do tamanho do campo minado e da quantidade de bombas
    scanf("%d %d %d", &m, &n, &b);

    // campo: mapa do campo minado
    int campo[m][n];

    // Inicialização do campo minado
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            campo[i][j] = 0;
        }
    }

    // Localização das bombas
    for(int i = 0; i < b; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        campo[x-1][y-1] = 1;
    }
    imprime(m, n, campo);
    return 0;
}