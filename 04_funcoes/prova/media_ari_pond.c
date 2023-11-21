#include <stdio.h>

float calculaMedia(char tipo, float n1, float n2, float n3){
    if(tipo == 'A'){
        return (n1 + n2 + n3)/3;
    }
    else{
        return (n1*4 + n2*5 + n3*6)/15;
    }
}

int main(){
    // Variáveis
    // tipo: tipo de média
    // n1, n2, n3: notas das unidades
    // media: média calculada de acordo com o tipo
    char tipo;
    float n1, n2, n3, media;

    // Faz a leitura do tipo de média
    scanf("%c", &tipo);

    // Faz a leitura das notas
    scanf("%f %f %f", &n1, &n2, &n3);

    // Chama a função para calcular a média
    media = calculaMedia(tipo, n1, n2, n3);

    // Imprime o resultado
    printf("Média %.2f\n", media);

    return 0;
}