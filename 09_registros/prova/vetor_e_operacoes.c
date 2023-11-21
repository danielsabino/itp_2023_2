#include <stdio.h>

#define MAX 100

// Declaração do registro que representa o vetor
// Está como global porque vai ser usado pelas funções
typedef struct vetor{
    int d;
    double valores[MAX];
}Vetor;

Vetor soma(Vetor v1, Vetor v2){
    Vetor res;
    for(int i=0;i<v1.d;i++){
        res.valores[i] = v1.valores[i] + v2.valores[i];
    }
    return res;
}

double produto(Vetor v1, Vetor v2){
    double res = 0;
    for(int i=0;i<v1.d;i++){
        res += v1.valores[i] * v2.valores[i];
    }
    return res;
}

int main(){

    // Variáveis
    // dim: dimensões do vetor
    // v_produto: valor do produto interno entre dois vetores
    int dim;
    double v_produto;

    // Leitura do tamanho do vetor
    scanf("%d", &dim);
    
    // Declara os dois vetores de entrada e os dois vetores de saída
    Vetor v1, v2, v_soma;
    // Configura as dimensões dos vetores
    v1.d = dim;
    v2.d = dim;
    v_soma.d = dim;    

    // Leitura dos valores dos vetores
    for(int i=0;i<dim;i++){
        scanf("%lf", &v1.valores[i]);
    }
    for(int i=0;i<dim;i++){
        scanf("%lf", &v2.valores[i]);
    }

    v_soma = soma(v1,v2);
    v_produto = produto(v1,v2);
    
    // for(int i=0;i<dim;i++){
    //     printf("%.2lf ", v1.valores[i]);
    // }
    // for(int i=0;i<dim;i++){
    //     printf("%.2lf ", v2.valores[i]);
    // }
    
    // Impressão da saída
    for(int i=0;i<dim;i++){
        printf("%.2lf ", v_soma.valores[i]);
    }
    printf("\n");
    printf("%.2lf\n", v_produto);
    
    return 0;
}