#include <stdio.h>

int main(){
    // n: número de registros a serem lidos
    // validos: quantidade de registros válidos
    // reg: registro sendo lido
    // soma: valor acumulado dos registros
    int n, validos = 0;
    float reg, soma = 0;

    // Leitura da quantidade de registros a serem a serem lidos posteriormente
    scanf("%d", &n);

    // Leitura dos registros
    for(int i = 0; i < n; i++){
        scanf("%f", &reg);
        if(reg > -1){
            soma += reg;
            validos++;
        }
    }
    
    // Impressão da saída
    if(validos){
        printf("%.2f\n", soma/(float)validos);
    }
    else{
        printf("A competicao nao possui dados historicos!\n");
    }

    return 0;
}