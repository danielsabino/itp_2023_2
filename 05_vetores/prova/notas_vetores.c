#include <stdio.h>

int main(){
    // n: número de alunos
    // num_aprovados: número de alunos aprovados
    // num_recuperacao: número de alunos em recuperação
    // num_reprovados: número de alunos reprovados
    int n, num_aprovados = 0, num_recuperacao = 0, num_reprovados = 0;

    // Lê o número de alunos
    scanf("%d", &n);

    // chamada: número dos alunos na chamada
    // notas: notas parciais dos alunos
    // aprovados: guarda os índices dos alunos aprovados
    // recuperacao: guarda os índices dos alunos em recuperação
    // reprovados: guarda os índices dos alunos reprovados
    int chamada[n];
    float notas[n];
    int aprovados[n], recuperacao[n], reprovados[n];

    // Lê as entradas
    for(int i=0;i<n;i++){
        scanf("%d - %f", &chamada[i], &notas[i]);
    }

    // Contagem de alunos aprovados, em recuperação e aprovados.
    for(int i=0;i<n;i++){
        if(notas[i] >= 7){
            aprovados[num_aprovados] = i;
            num_aprovados++;
        }
        else if(notas[i] >= 5){
            recuperacao[num_recuperacao] = i;
            num_recuperacao++;
        }
        else{
            reprovados[num_reprovados] = i;
            num_reprovados++;
        }
    }

   // Imprime saída

    printf("Aprovados: ");
    for(int i=0;i<num_aprovados;i++){
        printf("%d (%.1f)", aprovados[i] + 1, notas[aprovados[i]]);
        if(i < num_aprovados - 1){
            printf(", ");
        }     
    }
    printf("\n");

    printf("Recuperação: ");
    for(int i=0;i<num_recuperacao;i++){
        printf("%d (%.1f)", recuperacao[i] + 1, notas[recuperacao[i]]);
        if(i < num_recuperacao - 1){
            printf(", ");
        }        
    }
    printf("\n");

    printf("Reprovados: ");
    for(int i=0;i<num_reprovados;i++){
        printf("%d (%.1f)", reprovados[i] + 1, notas[reprovados[i]]);
        if(i < num_reprovados - 1){
            printf(", ");
        }        
    }
    printf("\n");


    return 0;
}