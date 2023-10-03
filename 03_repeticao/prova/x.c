#include <stdio.h>

int main(){
    // Variaveis
    // n: quantidade de linhas de entrada
    // c: caracter para imprimir
    int n;
    char c;

    // Leitura da entrada
    scanf("%d %c", &n, &c);

    // Impressão do X
    // Linhas - 1
    for(int i=0;i<n-1;i++){
        // Imprime as colunas certas
        for(int j=0;j<n;j++){
            if(j == i || j == n-2-i){
                printf("%c", c);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}