#include <stdio.h>
#include <string.h>

// Definição do enum
typedef enum tipochocoloates{
    BRANCO, 
    AMARGO, 
    AO_LEITE, 
    COM_CASTANHAS
}TipoChocolates;

// Declaração do struct para guardar as informações dos chocolates
typedef struct chocolate{
    char nome[50];
    float peso;
    float preco;
    TipoChocolates tipo;
}Chocolate;

TipoChocolates map(char tipo[15]){
    if(strcmp(tipo, "BRANCO") == 0) return BRANCO;
    else if(strcmp(tipo, "AMARGO") == 0) return AMARGO;
    else if(strcmp(tipo, "AO_LEITE") == 0) return AO_LEITE;
    else if(strcmp(tipo, "COM_CASTANHAS") == 0) return COM_CASTANHAS;
    else return -1;
}

void calcula_total(int n, Chocolate vetor[n], int total[4]){
    for(int i = 0; i < n; i++){
        switch (vetor[i].tipo)
        {
        case BRANCO:
            total[BRANCO]++;
            break;
        case AMARGO:
            total[AMARGO]++;
            break;
        case AO_LEITE:
            total[AO_LEITE]++;
            break;
        case COM_CASTANHAS:
            total[COM_CASTANHAS]++;
            break;
        }
    }
}

int mais_caro(int n, Chocolate vetor[n]){
    int maior = vetor[0].preco;
    int ind = 0;
    for(int i = 1; i < n; i++){
        if(vetor[i].preco > maior){
            maior = vetor[i].preco;
            ind = i;
        }
    }
    return ind;
}

int mais_barato(int n, Chocolate vetor[n]){
    int menor = vetor[0].preco;
    int ind = 0;
    for(int i = 0; i < n; i++){
        if(vetor[i].preco < menor){
            menor = vetor[i].preco;
            ind = i;
        }
    }
    return ind;
}

void imprime(int total[4]){
    printf("Total de chocolates BRANCO: %d\n", total[0]);
    printf("Total de chocolates AMARGO: %d\n", total[1]);
    printf("Total de chocolates AO_LEITE: %d\n", total[2]);
    printf("Total de chocolates COM_CASTANHAS: %d\n", total[3]);
}

int main(){
    // Variáveis
    // n: quantidade de chocolates
    // tmp: armazena temporariamente a string do tipo de chocolate
    // total: vetor com total de cada tipo
    // caro, barato: indica a posição no vetor dos chocolates mais caro e mais barato
    int n;
    char tmp[15];
    int total[4] = {0,0,0,0};
    int caro, barato;


    // Leitura da quantidade de chocolates
    scanf("%d", &n);

    // Declaração do vetor que vai guardar os chocolates
    Chocolate vetor[n];

    for(int i=0;i<n;i++){
        scanf(" %[^\n]", vetor[i].nome);
        scanf("%f", &vetor[i].peso);
        scanf("%f", &vetor[i].preco);
        scanf(" %[^\n]", tmp);
        vetor[i].tipo = map(tmp);
    }

    // Chama função para computar o total de cada tipo de chocolate
    calcula_total(n, vetor, total);

    // Chama função para achar o chocolate mais caro
    caro = mais_caro(n, vetor);

    // Chama função para achar o chocolate mais barato
    barato = mais_barato(n, vetor);

    // Chama função para imprimir quantidade de cada tipo
    imprime(total);

    // Imprime os chocolates mais caro e mais barato
    printf("Chocolate mais caro: %s - R$%.2f\n", vetor[caro].nome, vetor[caro].preco);
    printf("Chocolate mais barato: %s - R$%.2f\n", vetor[barato].nome, vetor[barato].preco);

    return 0;
}