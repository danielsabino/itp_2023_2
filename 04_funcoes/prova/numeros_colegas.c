#include <stdio.h>
#include <stdlib.h>


int main(){
    // Variaveis
    // a, b: valores de entrada
    // soma_a, soma_b: soma dos divisores de A e B
    int a,b;
    int soma_a = 1, soma_b = 1;
    // Leitura dos valores
    scanf("%d %d", &a, &b);

    // Verificação se números são colegas
    // Calcula a soma dos divisors de A
    for(int i=2; i<a; i++){
        if(a % i == 0){
            soma_a += i;
        }
    }

    // Calcula a soma dos divisors de B
    for(int i=2; i<b; i++){
        if(b % i == 0){
            soma_b += i;
        }
    }
    // Verifica se diferenca é válida para tornar números colegas e imprime mensagem de acordo
    if(abs(soma_a - b) > 2 || abs(soma_b - a) > 2){
        printf("N\n");
    }
    else{
        printf("S\n");
    }
    return 0;
}