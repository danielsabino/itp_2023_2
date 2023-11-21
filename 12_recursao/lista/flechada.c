#include <stdio.h>

typedef struct tesouro{
    char nome[21];
    int peso, valor;
}Tesouro;

int calcula_peso(Tesouro *m, int qtd){
    int soma = 0;
    for(int i = 0; i < qtd; i++){
        soma += m->peso;
    }
    return soma;
}

int coleta(Tesouro *t, int q, Tesouro *m, int qtd, int p, int *total){
    int peso_atual = calcula_peso(m, qtd);
    if(peso_atual > p){
        return 0;
    }    
    for(int i = 0; i < q; i++){
        
        *total += coleta(t, q, )
    }
}

int main(){
    // q: quantidade de itens na caverna
    // p: peso máximo que o aventureiro consegue carregar
    int q, p;

    // Leitura de Q e P
    scanf("%d %d", &q, &p);

    // tesouros: tesouros presente na caverna
    // mochila: mochila do aventureiro com itens que ele vai carregar
    Tesouro tesouros[q];
    Tesouro mochila[q];

    // Leitura dos tesouros
    for(int i = 0; i < q; i++){
        scanf(" %s", tesouros[i].nome);
        scanf("%d", &tesouros[i].valor);
        scanf("%d", &tesouros[i].peso);
    }
    return 0;
}