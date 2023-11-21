#include <stdio.h>

int main(){

    // Vetores A, B, C e D
    int a[3], b[3], c[3], d[3];
    // Vetores para armazenar os valores das operações de soma e multiplicação da expressão
    int op1[3], op2[3];

    // Leitura da entrada
    scanf("%d %d %d", &b[0], &b[1], &b[2]);
    scanf("%d %d %d", &c[0], &c[1], &c[2]);
    scanf("%d %d %d", &d[0], &d[1], &d[2]);

    // Operação 01: B + C
    for(int i=0; i<3; i++){
        op1[i] = b[i] + c[i];
    }

    // Operação 02: 5D
    for(int i=0; i<3; i++){
        op2[i] = d[i] * 5;
    }

    // Operação final: A = B + C - 5D ou A = op1 - op2
    for(int i=0; i<3; i++){
        a[i] = op1[i] - op2[i];
    }

    // Impressão da saída
    printf("A = [%d,%d,%d]\n", a[0], a[1], a[2]);

    return 0;
}