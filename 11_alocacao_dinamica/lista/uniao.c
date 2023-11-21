#include <stdio.h>
#include <stdlib.h>

typedef struct conjunto{
    int tam;
    int *vetor;
}Conjunto;

Conjunto * inicializa(int n){
    Conjunto *v;
    v = malloc(sizeof(Conjunto));
    v->vetor = malloc(sizeof(int) * n);
    v->tam = n;
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
    Conjunto *conj_u = malloc(sizeof(Conjunto));
    conj_u->vetor = malloc(sizeof(int) * conj_a->tam);
    conj_u->tam = conj_a->tam;
    
    for(int i = 0; i < conj_a->tam; i++){
        conj_u->vetor[i] = conj_a->vetor[i];
    }

    for(int i = 0; i < conj_b->tam; i++){
        if(!repetido(conj_b->vetor[i], conj_u)){
            conj_u->tam++;
            conj_u->vetor = realloc(conj_u->vetor, conj_u->tam * sizeof(int));
            conj_u->vetor[conj_u->tam-1] = conj_b->vetor[i];
        }
    }
    return conj_u;
}

Conjunto * intersecao(Conjunto *conj_a, Conjunto *conj_b){
    Conjunto *conj_i = malloc(sizeof(Conjunto));
    conj_i->tam = 0;

    for(int i = 0; i < conj_b->tam; i++){
        for(int j = 0; j < conj_a->tam; j++){
            if(conj_b->vetor[i] == conj_a->vetor[j]){
                if(!repetido(conj_b->vetor[i], conj_i)){
                    conj_i->tam++;
                    conj_i->vetor = realloc(conj_i->vetor, conj_i->tam * sizeof(int));
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
    int n;
    Conjunto *a, *b, *u, *i;

    scanf("%d", &n);
    a = inicializa(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a->vetor[i]);
    }

    scanf("%d", &n);
    b = inicializa(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &b->vetor[i]);
    }

    u = uniao(a, b);
    i = intersecao(a, b);
    imprime(u, "união");
    imprime(i, "interseção");
    return 0;
}