#include <stdio.h>

int main(){
    // n: número de entrada
    // reverso: número de entrada invertido
    // aux: número para manipulação
    int n, aux, reverso = 0;

    // Leitura do valor de entrada
    scanf("%d", &n);

    // Guarda o valor do número inicial
    aux = n;
    
    // Faz a inversão do número
    while(n != 0){
        // Obtém o último dígito
        int r = n % 10;
        // Monta o número pelo acúmulo dos valores aumentando a ordem de grandeza a cada interação
        reverso = reverso * 10 + r;
        // Reduz a ordem de grandeza a cada interação (remove o último dígito)
        n /= 10;
    }
    // Verifica se é palíndromo
    if(reverso == aux){
        printf("%d é Palíndromo e ", aux);
    }
    else{
        printf("%d não é Palíndromo e ", aux);
    }

    // Verifica se é par
    if(aux % 2 == 0){
        printf("par.\n");
    }
    else{
        printf("impar.\n");
    }

    return 0;
}