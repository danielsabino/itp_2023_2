#include <stdio.h>

void sort(int n, int array[]){
    int aux;
    for(int i=0; i < n-1; i++){
        for(int j=i+1; j<n; j++){
            if(array[i] > array[j]){
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}
int existe(int v, int n, int vetor[]){
    for (int i=0; i < n; i++){
        if(vetor[i] == v) return 1;
    }
    return 0;
}
int main(void){
    // Declaração das variáveis iniciais
    int n, cont = 0;
    // Leitura do tamanho do vetor
    scanf("%d", &n);
    // Declaração do vetor e do vetor auxiliar
    int vetor[n], unique[n];
    // Leitura do vetor
    for(int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    // Primeira entrada é certa de estar no array final
    unique[0] = vetor[0];
    cont++;
    // Transferência dos valores únicos    
    for (int i=1; i < n; i++){
        // Verifica se o valor de vetor já apareceu antes
        if(!existe(vetor[i], cont, unique)){
            // Adiciona o novo valor único ao array final
            unique[cont] = vetor[i];
            // Atualiza contagem de valores únicos.
            cont++;
        }
    }
    // Ordena do vetor
    sort(cont, unique);
    // Impressão do resultado
    for (int i=0; i < cont; i++){
        printf("%d ", unique[i]);
    }
    printf("\n");
    return 0;
}