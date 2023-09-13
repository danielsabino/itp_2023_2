#include <stdio.h>

int main(){
    // Variáveis para armazenzar a capacidade dos vetores
    int n, m;
    // Variável para fazer o controle da quantidade de elementos inseridos no vetor uniao
    int count = 0;
    // Variável para verificar se um valor é repetido
    int repetido = 0;

    // Faz a leitura da quantidade de elementos dos vetores
    scanf("%d %d", &n, &m);

    // Declaração dos vetores
    int a[n], b[m];
    // Vetor que vai armazenar o resultado da união com tamanho suficiente para acomodar todos os possíveis valores
    int uniao[m+n];

    // Leitura do vetor 1
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    // Leitura do vetor 2
    for(int i=0;i<m;i++){
        scanf("%d", &b[i]);
    }

    // Realiza a união dos vetores

    // Insere todos os valores de A no vetor união
    for(int i=0;i<n;i++){
        uniao[i] = a[i];
        count++;
    }

    // Insere os valores de B que já não estão presentes no conjunto união
    for(int i=0;i<m;i++){
        // Percorre todo o conjunto A
        repetido = 0;
        for(int j=0;j<n;j++){
            if(b[i] == a[j]){
                repetido = 1;
            }
        }
        // Se não for um elemento repetido, insere no conjunto união
        if(!repetido){
            uniao[count] = b[i];
            count++;
        }        
    }

    for(int i=0;i<count;i++){
        printf("%d ", uniao[i]);
    }
    printf("\n");


    return 0;
}