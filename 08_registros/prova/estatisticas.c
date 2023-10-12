#include <stdio.h>

typedef struct time{
    char nome[100];
    int gols_marcados;
    int gols_sofridos;
}Time;

// Função para ordenar o vetor de times de acordo com o número de gols marcados
void ordena(int n, Time times[n]){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(times[i].gols_marcados < times[j].gols_marcados){
                Time swap = times[i];
                times[i] = times[j];
                times[j] = swap;
            }
        }
    }
}

void imprime(int n, Time times[n]){
    int count = 1;
    for(int i=0;i<n;i++){
        printf("%d - %s\n", count, times[i].nome);
        printf("Gols marcados: %d\n", times[i].gols_marcados);
        printf("Gols sofridos: %d\n", times[i].gols_sofridos);
        count++;
    }    
}

int main(){
    // Variáveis
    // n: número de times
    int n;

    // Leitura do número de times
    scanf("%d", &n);

    // Declaração do vetor para armazenar os times
    Time times[n];

    // Leitura dos valores dos times
    for(int i=0;i<n;i++){
        scanf(" %[^\n]", times[i].nome);
        scanf("%d", &times[i].gols_marcados);
        scanf("%d", &times[i].gols_sofridos);
    }
    ordena(n, times);
    imprime(n, times);

    return 0;
}