#include <stdio.h>

// Quantidade máxima de elementos no vetor
#define MAX 10

int main(){
    // Quantidade de elementos de cada vetor
    int n;
    // Vetores de entrada com tamanho igual ao máximo
    int a[MAX], b[MAX], soma[MAX];
    // PS: poderia também ler o tamanho da entrada e só depois declarar os vetores com tamanho definido por n

    // Leitura do tamanho dos vetores
    scanf("%d", &n);

    // Verifica se tamanho é maior que limite
    if(n > 10){
        printf("Muitos elementos\n");
    }
    else{
        // Leitura do primeiro vetor
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        // Leitura do segundo vetor
        for(int i=0;i<n;i++){
            scanf("%d", &b[i]);
        }

        // Cálculo da soma dos vetores
        for(int i=0;i<n;i++){
            soma[i] = a[i] + b[i];
        }

        // Impressão da saída
        for(int i=0;i<n;i++){
            printf("%d ", soma[i]);
        }
        printf("\n");
        }    

    return 0;
}