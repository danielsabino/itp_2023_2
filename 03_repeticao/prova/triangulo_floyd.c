#include <stdio.h>

// Determina a quantidade de dígitos de um número
int digitos(int n){
    int cont = 0;
    while(n != 0){
        cont++;
        n /= 10;
    }
    return cont;
}


int main(){
    // Variáveis
    // n: quantidade de linhas do triângulo
    // atual: guarda o valor atual a ser impresso
    // maior: maior número possível no triângulo
    // espacos: número de espaços antes do caracter impresso
    int n, atual = 1, maior, espacos;

    // Leitura da entrada
    scanf("%d", &n);

    // Teste de entrada
    if(n > 0){    
        // Determinar qual o maior número possível da sequência
        maior = (n * n - n) / 2 + n;
        // Determina o número de espaços de preenchimento à esquerda a ser impresso antes de cada caracter
        espacos = digitos(maior);
        // Impressão do triângulo de Floyd
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                printf("%*d ", espacos, atual);
                atual++;
            }
            printf("\n");
        }
    }
    else{
        printf("Você entrou com %d, tente de novo na próxima\n", n);
    }
    // printf("%d\n", espacos);
    return 0;
}