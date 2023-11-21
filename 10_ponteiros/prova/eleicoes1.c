#include <stdio.h>

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted){
    // chapas: contabiliza os votos para cada chapa
    // maior, segundo_maior: indica as chapas mais votadas
    int chapas[10], maior, segundo_maior;
    
    // Inicializa o vetor com valores zero
    for(int i = 0; i < 10; i++){
        chapas[i] = 0;
    }
    
    // Percorre o vetor de votos para fazer a contabilização
    for(int i = 0; i < n; i++){
        int voto = votes[i];
        chapas[voto-1] += 1;
    }

    // Percorre o vetor para determinar o mais votado
    maior = 0;
    for(int i = 0; i < 10; i++){
        if(chapas[i] > maior){
            *most_voted = i;
            maior = chapas[i];
        }
    }
    // Percorre o vetor para determinar o segundo mais votado
    segundo_maior = 0;
    for(int i = 0; i < 10; i++){
        if(chapas[i] > segundo_maior && i != *most_voted){
            *second_most_voted = i;
            segundo_maior = chapas[i];
        }
    }
    *most_voted += 1;
    *second_most_voted += 1;
}

int main(){
    // n: número de votos
    // most_voted: chapa mais votada
    // second_most_voted: segunda chapa mais votada
    int n, most_voted, second_most_voted;

    // Leitura do número de votos
    scanf("%d", &n);

    // votes: votos 
    int votes[n];
    // Leitura dos votos
    for(int i = 0; i < n; i++){
        scanf("%d", &votes[i]);
    }

    compute_votes(n, votes, &most_voted, &second_most_voted);
    printf("%d %d\n", most_voted, second_most_voted);

    return 0;
}