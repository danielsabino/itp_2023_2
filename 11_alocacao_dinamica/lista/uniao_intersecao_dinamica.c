#include <stdio.h>
#include <stdlib.h>

typedef struct conjunto{
    int *vetor;
    int tam;
} Conjunto;

// Inicializa um vetor com tamanho t
Conjunto * inicializa(int t){
    Conjunto *v;
    v = malloc(sizeof(Conjunto));
    v->tam = t;
    v->vetor = malloc(sizeof(int) * t);
    return v;
}

int repetido(int v, Conjunto *c){    
    for(int i = 0; i < c->tam; i++){
        if(v == c->vetor[i]){
            return 1;
        }
    }
    return 0;
}

Conjunto * uniao(Conjunto *conj_a, Conjunto *conj_b){
    // conj_u: conjunto união
    Conjunto *conj_u = malloc(sizeof(Conjunto));
    // Aloca inicialmente o tamanho do vetor de C para ser igual ao de A
    conj_u->vetor = malloc(sizeof(int) * conj_a->tam);
    // Inicializa o tamanho de C para ser do mesmo tamanho que A
    conj_u->tam = conj_a->tam;
    // Atribui todos os elementos de A para C
    for(int i = 0; i < conj_a->tam; i++){
        conj_u->vetor[i] = conj_a->vetor[i];
    }
    // Adiciona os elementos de B em C que já não estão presentes no conjunto
    for(int i = 0; i < conj_b->tam; i++){
        if(!repetido(conj_b->vetor[i], conj_u)){
            conj_u->tam++;
            conj_u->vetor = realloc(conj_u->vetor, sizeof(int) * conj_u->tam);
            conj_u->vetor[conj_u->tam-1] = conj_b->vetor[i];
        }
    }
    return conj_u;
}

Conjunto * intersecao(Conjunto *conj_a, Conjunto *conj_b){
    // conj_i: conjunto intersecao
    Conjunto *conj_i = malloc(sizeof(Conjunto));
    // Inicializa o tamanho da interseção com zero
    conj_i->tam = 0;

    // Verifica quais elementos são comuns nos dois conjuntos
    for(int i = 0; i < conj_b->tam; i++){
        for(int j = 0; j < conj_a->tam; j++){
            if(conj_b->vetor[i] == conj_a->vetor[j]){
                // Verifica se o elemento já não está presente no conjunto interseção
                if(!repetido(conj_b->vetor[i], conj_i)){
                    // Incrementa o número de elementos do conjunto interseção
                    conj_i->tam++;
                    // Aumenta o tamanho do vetor de interseção para comportar o novo elemento
                    conj_i->vetor = realloc(conj_i->vetor, sizeof(int) * conj_i->tam);
                    // Adiciona o elemento ao conjunto interseção
                    conj_i->vetor[conj_i->tam-1] = conj_b->vetor[i];
                }
            }
        }
    }
    return conj_i;
}

void imprime(Conjunto *v, char *tipo){
    printf("A %s B == {", tipo);
    if(v->tam > 0){
        for(int i = 0; i < v->tam; i++){
            printf("%d", v->vetor[i]);
            if(i < v->tam-1){
                printf(" ");
            }
        }
    }
    else{
        printf("vazio");
    }
    printf("}\n");
}

int main(){
    // a, b: vetores A e B
    // u, i: vetores união e intersecao
    // n: tamanho do vetor lido
    Conjunto *a, *b, *u, *i;
    int n;

    // Leitura do tamanho e elementos do vetor A
    scanf("%d", &n);
    a = inicializa(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a->vetor[i]);
    }

    // Leitura do tamanho e elementos do vetor B
    scanf("%d", &n);
    b = inicializa(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &b->vetor[i]);
    }

    // Faz a união e intersecao
    u = uniao(a, b);
    i = intersecao(a, b);
    imprime(u, "união");
    imprime(i, "interseção");

    return 0;
}