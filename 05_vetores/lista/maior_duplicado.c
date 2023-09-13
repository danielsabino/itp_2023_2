#include <stdio.h>

int main(){
    // Declaração de variáveis
    // n: quantidade de elementos do vetor
    // primeiro: marcar o primeiro elementos duplicado encontrado
    int n, maior, primeiro = 1;

    // Faz a leitura da quantidade elementos do vetor
    scanf("%d", &n);

    // Declara o vetor
    int vetor[n];

    // Faz a leitura do vetor
    for(int i=0;i<n;i++)
        scanf("%d", &vetor[i]);

    for(int i=0;i<n;i++){        
        // Percorre todo o vetor buscando duplicatas
        for(int j=0;j<n;j++){
            // Para todos os valores que não seja o item de análise
            if(i != j){
                // Se é valor duplicado
                if(vetor[i] == vetor[j]){
                    if(primeiro){
                        maior = vetor[i];
                        primeiro = 0;
                    }
                    if(vetor[i] > maior){
                        maior = vetor[i];
                    }
                }
            }
        }
    }

    // Imprime a saída
    printf("%d\n", maior);

    return 0;
}