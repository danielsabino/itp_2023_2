#include <stdio.h>

int main(){
    // Declaração das variáveis
    // n e m: tamanho do mapa
    // indice: índice de sobrevivência
    // x e y: local mais adequado
    // diferenca: diferença entre o valor da área e o índice de sobrevivência
    // soma: guarda o potencial de sobreviência da região analisada
    // melhor: guarda o melhor valor encontrado até o momento
    // primeiro: indica que é a primeira região analisada

    int n, m;
    int indice;
    int x, y;
    int diferenca, soma;
    int melhor, primeira = 1;

    // Leitura do tamanho do mapa e do índice de sobrevivência
    scanf("%d %d %d", &n, &m, &indice);

    // Declaração do mapa
    int mapa[n][m];
    // Leitura do mapa
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &mapa[i][j]);
        }
    }

    // Varredura do mapa
    // Percorre somente posições mais internas para poder verificar áreas de 9 posições
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            soma = 0;
            for(int k=i-1;k<=i+1;k++){
                for(int l=j-1;l<=j+1;l++){
                    soma += mapa[k][l];
                }
            }
            diferenca = indice - soma;
            if(diferenca < 0){
                diferenca *= -1;
            }
            if(primeira){
                // Altera a flag para indicar que a primeira região já foi analisada
                primeira = 0;
                // Como é a primeira região, ela é a melhor até o momento
                melhor = diferenca;
                // A posição a ser indicada
                x = i;
                y = j;
            }
            else{
                if(diferenca < melhor){
                    melhor = diferenca;
                    x = i;
                    y = j;
                }

            }
        }
    }
    printf("A melhor area para exploracao eh %d %d com valor %d\n", x, y, melhor);
    return 0;
}