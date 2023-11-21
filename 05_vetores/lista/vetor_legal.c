#include <stdio.h>

int main(){
    // Variáveis
    // n: tamanho do vetor
    // legal: informa se é legal ou não
    int n, legal = 1;

    // Leitura do tamanho do vetor
    scanf("%d", &n);

    // Declaração do vetor e leitura do vetor
    int vetor[n];

    for(int i=0;i<n;i++){
        scanf("%d", &vetor[i]);
    }

    // Verificação da condição do vetor
    for(int i=1;i<n;i++){
        if((vetor[i] - vetor[i-1]) % 2 != 0){
            // Condição para ser legal foi descumprida
            legal = 0;
            // Pode interromper o loop
            break;
        }
    }

    if(legal){
        printf("Legal\n");
    }
    else{
        printf("Chato\n");
    }

    return 0;
}