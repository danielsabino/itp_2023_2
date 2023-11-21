#include <stdio.h>

int main(){

    // Declaração de variáveis
    // n: tamanho dos vetores
    int n;

    // Faz a leitura do tamanho dos vetores
    scanf("%d", &n);

    // Declaração dos três vetores de entrada e o que vai armazenar a soma
    int a[n], b[n], c[n], d[n];

    // Leitura do vetor A
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    // Leitura do vetor B
    for(int i=0;i<n;i++)
        scanf("%d", &b[i]);
    // Leitura do vetor C
    for(int i=0;i<n;i++)
        scanf("%d", &c[i]);

    // Calcula a soma
    for(int i=0;i<n;i++)
        d[i] = a[i] + b[i] + c[i];
    

    // Imprime a saída
    for(int i=0;i<n;i++)
        printf("%d ", d[i]);
    printf("\n");
    
    return 0;
}