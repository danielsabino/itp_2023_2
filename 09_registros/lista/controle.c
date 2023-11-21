#include <stdio.h>
#include <string.h>

// Definição da struct com nome e status (se está ou não trabalhando)
typedef struct membro{
    char nome[50];
    int status;
}Membro;

int localizar(char nome[50], int n, Membro pessoas[n]){
    for(int i = 0; i < n; i++){
        if(strcmp(pessoas[i].nome, nome) == 0){
            return i;
        }
    }
    return -1;
}

void imprimir(int n, Membro pessoas[n]){
    printf("Atualmente trabalhando:\n");
    for(int i = 0; i < n; i++){
        if(pessoas[i].status == 1){
            printf("%s\n", pessoas[i].nome);
        }
    }
    printf("\n");
}

int main(){
    // n: número de entradas a serem lidas
    // count: número de pessoas trabalhando
    // instrução: comando que vai guiar o que deve ser feito com cada nome
    // nome: nome fornecido na entrada
    int n, count = 0;
    char instrucao[10], nome[50];

    // Leitura do número de pessoas
    scanf("%d", &n);

    // Vetor para armazenzar as pessoas 
    Membro pessoas[n];

    // Leitura dos registros
    for(int i = 0; i < n; i++){
        scanf(" %s", instrucao);
        if(strcmp(instrucao, "INSERIR") == 0){
            scanf(" %s", nome);            
            strcpy(pessoas[count].nome, nome);
            pessoas[count].status = 1;
            count++;
            
        }
        else if(strcmp(instrucao, "REMOVER") == 0){
            scanf(" %s", nome);
            int idx = localizar(nome, n, pessoas);
            if(idx > -1){
                pessoas[idx].status = 0;
            }
        }
        else{
            imprimir(n, pessoas);
        }
        
    }

    return 0;
}