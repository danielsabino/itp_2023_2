#include <stdio.h>

void flatten(int l, int c, int m[l][c], int vetor[], int ordem){
    int cont = 0;
    if(ordem == 0){
        for (int i = 0; i < l; i++){
            for (int j = 0; j < c; j++){
                vetor[cont] = m[i][j];
                cont++;
            }       
        }
    }
    else {
        for (int j = 0; j < c; j++){
            for (int i = 0; i < l; i++){
                vetor[cont] = m[i][j];
                cont++;
            }        
        }
    }
}

int main(void){
    // Variáveis
    int l, c, ordem;
    // Leitura dos valores iniciais
    scanf("%d", &ordem);
    scanf("%d %d", &l, &c);
    // Declaração da Matriz
    int matriz[l][c];
    int vetor[l*c];
    // Leitura da Matriz
    for (int i=0; i < l; i++){
        for (int j=0; j < c; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    // Chamada da função
    flatten(l, c, matriz, vetor, ordem);
    // Impressão do resultado
    for (int i=0; i< l*c; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}