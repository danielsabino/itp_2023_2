#include <stdio.h>
#include <stdlib.h>

int * adiciona(int *v, int tam, int n){
    // Se o vetor está vazio
    if(tam == 0){
        v = malloc(sizeof(int));
    }    
    else{ // Se já continha valores
        v = realloc(v, (tam+1) * sizeof(int));        
    }
    v[tam] = n;
    return v;
}

int * soma(int *a, int *b, int tam){
    int *c = malloc(sizeof(int) * tam);
    for(int i = 0; i < tam; i++){
        c[i] = a[i] + b[i];
    }
    return c;
}

void imprime(int *v, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){    
    // n: valor de entrada
    // c: caracter lido junto do valor de entrada
    // continua: informa se a leitura deve continuar
    // *a, *b: ponteiros para os vetores contendo os números
    // *s: ponteiro com a soma de a e b
    // tam_a, tam_b: tamanhos dos vetores a e b
    int n;
    char c;
    int *a, *b, *s;
    int tam_a = 0, tam_b = 0;

    // Leitura do primeiro vetor
    do{
        scanf("%d%c", &n, &c);
        a = adiciona(a, tam_a++, n);
        
    }while(c != '\n');

    // Leitura do segundo vetor
    do{
        scanf("%d%c", &n, &c);
        b = adiciona(b, tam_b++, n);
        
    }while(c != '\n');

    // Verifica se são do mesmo tamanho
    if(tam_a == tam_b){
        s = soma(a, b, tam_a);
        imprime(s, tam_a);
        free(s);
    }
    else{
        printf("Vetores de tamanhos diferentes!\n");
    }

    free(a);
    free(b);

    return 0;
}